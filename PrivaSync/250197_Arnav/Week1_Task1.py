from fastapi import FastAPI
from pydantic import BaseModel

fastapi = FastAPI()
class Item(BaseModel):
    name: str
    price: float
    is_offer: bool = None

@fastapi.get("/")
def read_root():
    return{"message":"Welcome to FastAPI"}

@fastapi.get("/items/{item_id}")
def read_item(item_id: int):
    return {"item_id": item_id, "status": "Found"}

@fastapi.post("/items/")
def create_item(item: Item):
    return {"message": f"Item '{item.name}' created successfully!", "data": item}