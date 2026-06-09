from fastapi import Depends, FastAPI, HTTPException, Query
from typing import Generator, Optional, List
from contextlib import asynccontextmanager
import json
from sqlmodel import Field, SQLModel, create_engine, Session, select
import redis.asyncio

class User(SQLModel, table=True):
    id: Optional[int] = Field(default=None, primary_key=True)
    name: str


sqlurl = "sqlite:///data.db"
engine = create_engine(sqlurl, echo=True)


@asynccontextmanager
async def lifecycle(app: FastAPI):
    global redis_client
    SQLModel.metadata.create_all(engine)
    redis_client = redis.asyncio.Redis(decode_responses=True) # port:6379
    await redis_client.ping()
    yield
    await redis_client.close()

app = FastAPI(lifespan=lifecycle)


@app.get("/")
async def home():
    return {"data": "Hello World"}


async def get_session():
    with Session(engine) as session:
        yield session
async def get_redis():
    return redis_client

@app.get("/users", response_model=List[User])

def read_users(
    session: Session = Depends(get_session),
    offset: int = 0,
    limit: int = Query(default=100, le=100)
):
    statement = select(User).offset(offset).limit(limit)
    users = session.exec(statement).all()

    return users

@app.get("/user/{id}")
async def get_user(session: Session = Depends(get_session), id: int = None,redis:redis.asyncio.Redis =Depends(get_redis)):
    # user = await 
    key = f"user:{id}"
    user =await redis.get(key)
    if(user):
        print("returning from cache")

        return {
            "source":"cache",
            "user": json.loads(user),
        }
    
    user = session.get(User, id)
    
    if user is None:
        raise HTTPException(status_code=404, detail="User not found")
    data = user.model_dump()
    await redis.set(key,json.dumps(data),ex=10)
    print("returning from cache")
    return {
            "source":"databases",
            "user":user,
        }

@app.post("/add", response_model=User)
def create_user(
    user: User,
    session: Session = Depends(get_session)
):
    try:
        session.add(user)
        session.commit()
        session.refresh(user)

        return user

    except Exception as e:
        raise HTTPException(
            status_code=500,
            detail={
                "error": "User can't be inserted",
                "message": str(e)
            }
        )