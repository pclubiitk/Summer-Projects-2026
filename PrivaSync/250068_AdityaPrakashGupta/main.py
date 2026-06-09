from fastapi import FastAPI, HTTPException, Depends, Request
from pydantic import BaseModel
from middleware import authenticate
from fastapi.responses import JSONResponse
# import aioredis
from database import SessionLocal, DBItem

fastapi = FastAPI()

# redis = aioredis.from_url("redis://localhost")

# inventory = [
#   { "id": 1, "name": "Pikachu", "power": 100 },
# ]

class Pokemon(BaseModel):
  name: str
  power: int

@fastapi.get("/items")
async def get_items():
  db = SessionLocal()
  items = db.query(DBItem).all()
  return { "items": items }


@fastapi.post("/items")
def create_item(item: Pokemon, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    new_item = DBItem(name=item.name, power=item.power)
    db.add(new_item)
    db.commit()
    db.refresh(new_item)
    return {"item" :new_item}

@fastapi.get("/items/{item_id}")
# async def get_item(item_id: int):
  
#   cached_item = await redis.get(f"item:{item_id}")
#   if cached_item:
#       return JSONResponse(content=cached_item)
  
#   item = f"Item {item_id}"
#   await redis.set(f"item:{item_id}", item)
#   return {"item": item}
def get_item(item_id: int):
    db = SessionLocal()
    item = db.query(DBItem).filter(DBItem.id == item_id).first()
    if not item:
        raise HTTPException(status_code=404, detail="Item not found")
    return {"item": item}
  
  
@fastapi.exception_handler(Exception)
async def global_exception_handler(request: Request, exc: Exception):
    return JSONResponse(
        status_code=500,
        content={"message": "error occurred. please try again."}
    )
