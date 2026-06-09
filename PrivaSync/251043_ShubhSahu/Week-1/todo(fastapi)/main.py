from fastapi import FastAPI, Depends
from sqlalchemy.orm import Session
import redis
import json

from database import SessionLocal, engine
from models import Todo
from schemas import TodoCreate
import models


models.Base.metadata.create_all(bind=engine)

app = FastAPI()


redis_client = redis.Redis(
    host="localhost",
    port=6379,
    decode_responses=True
)

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


@app.get("/")
def home():
    return {"message": "Todo API Running"}


@app.get("/todos")
def get_todos(db: Session = Depends(get_db)):

    cached_todos = redis_client.get("todos")

    if cached_todos:
        return {
            "source": "cache",
            "data": json.loads(cached_todos)
        }

    todos = db.query(Todo).all()

    result = []

    for todo in todos:
        result.append({
            "id": todo.id,
            "title": todo.title,
            "completed": todo.completed
        })

    redis_client.setex(
        "todos",
        60,
        json.dumps(result)
    )

    return {
        "source": "database",
        "data": result
    }


@app.post("/todos")
def create_todo(todo: TodoCreate, db: Session = Depends(get_db)):

    new_todo = Todo(
        title=todo.title,
        completed=False
    )

    db.add(new_todo)
    db.commit()
    db.refresh(new_todo)

    redis_client.delete("todos")

    return {
        "message": "Todo created",
        "todo": {
            "id": new_todo.id,
            "title": new_todo.title,
            "completed": new_todo.completed
        }
    }


@app.delete("/todos/{todo_id}")
def delete_todo(todo_id: int, db: Session = Depends(get_db)):

    todo = db.query(Todo).filter(Todo.id == todo_id).first()

    if not todo:
        return {"error": "Todo not found"}

    db.delete(todo)
    db.commit()

    redis_client.delete("todos")

    return {"message": "Todo deleted"}