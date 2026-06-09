from fastapi import FastAPI
from pydantic import BaseModel
app = FastAPI()
from sqlalchemy import Column, Integer, String, create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from fastapi import HTTPException, Depends
from fastapi.security import HTTPBasic, HTTPBasicCredentials
from middleware import authenticate
security = HTTPBasic()

DATABASE_URL = "sqlite:///./database.db"

engine = create_engine(DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
Base = declarative_base()



class User(Base):
    __tablename__ = "users"
    id = Column(Integer, primary_key=True, index=True)
    name = Column(String, index=True)
class UserSchema(BaseModel):
    id: int
    name: str
    
    class Config:
        from_attributes = True

Base.metadata.create_all(bind=engine)

def user_to_dict(user):
    return {"id": user.id, "name": user.name}

@app.post("/users/")
async def add_user(username: str, authenticated: bool = Depends(authenticate)):
   db = SessionLocal()
   user = User(name=username)
   db.add(user)
   db.commit()
   db.refresh(user)
   return user_to_dict(user)
   db.close()


@app.get("/users/")
def read_users(authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    try:
        users = db.query(User).all()
        return {"users": [user_to_dict(user) for user in users]}
    finally:
        db.close()



def create_user(userschema: UserSchema):
    db = SessionLocal()
    
    user = User(name=userschema.name, id=userschema.id)
    db.add(user)
    db.commit()
    db.refresh(user)
    result = user_to_dict(user)
    return result
    db.close()

@app.get("/users/{user_id}")
def read_user(user_id: int, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    user = db.query(User).filter(User.id == user_id).first()
    db.close()
    if user:
        return user_to_dict(user)
    return None
@app.patch("/users/{user_id}")
def update_user(user_id: int, new_name: str, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    user = db.query(User).filter(User.id == user_id).first()
    if user:
        user.name = new_name
        db.commit()
        db.refresh(user)
        result = user_to_dict(user)
        db.close()
        return result
    db.close()
    return None
@app.delete("/users/{user_id}")
def delete_user(user_id: int, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    user = db.query(User).filter(User.id == user_id).first()
    if user:
        db.delete(user)
        db.commit()
    db.close()
    return {"message": "User deleted"}
