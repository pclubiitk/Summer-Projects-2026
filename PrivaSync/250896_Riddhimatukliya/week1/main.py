import os
from fastapi import FastAPI, HTTPException, Depends, File, UploadFile, Request
from fastapi.responses import JSONResponse
from fastapi.security import HTTPBasicCredentials
from pydantic import BaseModel, Field
from typing import Optional
from starlette.responses import FileResponse

from .database import SessionLocal, DBItem
from .middleware import authenticate

fastapi = FastAPI()

class Item(BaseModel):
    name: str
    quantity: int

class ItemUpdate(BaseModel):
    name: Optional[str] = Field(None, description="Optional name")
    quantity: Optional[int] = Field(None, description="Optional quantity")


@fastapi.get("/items")
async def get_items():
    db = SessionLocal()
    items = db.query(DBItem).all()
    return {"items": items}

@fastapi.get("/items/{item_id}")
def get_item(item_id: int):
    db = SessionLocal()
    item = db.query(DBItem).filter(DBItem.id == item_id).first()
    if not item:
        raise HTTPException(status_code=404, detail="Item not found")
    return {"item": item}

@fastapi.post("/items")
def create_item(item: Item, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    new_item = DBItem(name=item.name, quantity=item.quantity)
    db.add(new_item)
    db.commit()
    db.refresh(new_item)
    return {"item": new_item}

@fastapi.patch("/items/{item_id}")
def update_item(item_id: int, item: ItemUpdate, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    db_item = db.query(DBItem).filter(DBItem.id == item_id).first()
    if not db_item:
        raise HTTPException(status_code=404, detail="Item not found")
    if item.name is not None:
        db_item.name = item.name
    if item.quantity is not None:
        db_item.quantity = item.quantity
    db.commit()
    db.refresh(db_item)
    return {"item": db_item}

@fastapi.delete("/items/{item_id}")
def delete_item(item_id: int, authenticated: bool = Depends(authenticate)):
    db = SessionLocal()
    db_item = db.query(DBItem).filter(DBItem.id == item_id).first()
    if not db_item:
        raise HTTPException(status_code=404, detail="Item not found")
    db.delete(db_item)
    db.commit()
    return {"message": "Item deleted"}


@fastapi.patch("/item-image/{item_id}")
async def upload_file(item_id: int, file: UploadFile = File(...)):
    db = SessionLocal()
    db_item = db.query(DBItem).filter(DBItem.id == item_id).first()
    if not db_item:
        raise HTTPException(status_code=404, detail="Item not found")
    os.makedirs("uploads", exist_ok=True)
    file_path = os.path.join("uploads", file.filename)
    with open(file_path, "wb") as f:
        f.write(await file.read())
    db_item.image_src = file.filename
    db.commit()
    db.refresh(db_item)
    return {"item": db_item}

@fastapi.get("/static/{file}")
async def serve_file(file: str):
    return FileResponse(os.path.join("uploads", file))


@fastapi.exception_handler(Exception)
async def global_exception_handler(request: Request, exc: Exception):
    return JSONResponse(status_code=500, content={"message": "An unexpected error occurred."})