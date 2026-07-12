from fastapi import (
    FastAPI,
    HTTPException,
    Depends,
    UploadFile,
    File
)

from pydantic import BaseModel
from typing import Optional

from starlette.responses import FileResponse

import os

from database import SessionLocal, DBItem
from middleware import authenticate

app = FastAPI()

# ------------------------------------------------
# CREATE UPLOADS FOLDER
# ------------------------------------------------

if not os.path.exists("uploads"):
    os.makedirs("uploads")

# ------------------------------------------------
# MODELS
# ------------------------------------------------

class Item(BaseModel):
    name: str
    quantity: int

class ItemUpdate(BaseModel):
    name: Optional[str] = None
    quantity: Optional[int] = None

# ------------------------------------------------
# HOME ROUTE
# ------------------------------------------------

@app.get("/")
async def home():

    return {
        "message": "FastAPI Inventory App"
    }

# ------------------------------------------------
# GET ALL ITEMS
# ------------------------------------------------

@app.get("/items")
async def get_items():

    db = SessionLocal()

    items = db.query(DBItem).all()

    return {
        "items": items
    }

# ------------------------------------------------
# GET SINGLE ITEM
# ------------------------------------------------

@app.get("/items/{item_id}")
async def get_item(item_id: int):

    if item_id <= 0:

        raise HTTPException(
            status_code=400,
            detail="Invalid item ID"
        )

    db = SessionLocal()

    item = (
        db.query(DBItem)
        .filter(DBItem.id == item_id)
        .first()
    )

    if not item:

        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    return {
        "item": item
    }

# ------------------------------------------------
# CREATE ITEM
# ------------------------------------------------

@app.post("/items")
async def create_item(
    item: Item,
    authenticated: bool = Depends(authenticate)
):

    db = SessionLocal()

    new_item = DBItem(
        name=item.name,
        quantity=item.quantity
    )

    db.add(new_item)

    db.commit()

    db.refresh(new_item)

    return {
        "item": new_item
    }

# ------------------------------------------------
# UPDATE ITEM
# ------------------------------------------------

@app.patch("/items/{item_id}")
async def update_item(
    item_id: int,
    item: ItemUpdate,
    authenticated: bool = Depends(authenticate)
):

    db = SessionLocal()

    db_item = (
        db.query(DBItem)
        .filter(DBItem.id == item_id)
        .first()
    )

    if not db_item:

        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    if item.name is not None:
        db_item.name = item.name

    if item.quantity is not None:
        db_item.quantity = item.quantity

    db.commit()

    db.refresh(db_item)

    return {
        "item": db_item
    }

# ------------------------------------------------
# DELETE ITEM
# ------------------------------------------------

@app.delete("/items/{item_id}")
async def delete_item(
    item_id: int,
    authenticated: bool = Depends(authenticate)
):

    db = SessionLocal()

    db_item = (
        db.query(DBItem)
        .filter(DBItem.id == item_id)
        .first()
    )

    if not db_item:

        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    db.delete(db_item)

    db.commit()

    return {
        "message": "Item deleted"
    }

# ------------------------------------------------
# FILE UPLOAD
# ------------------------------------------------

@app.patch("/item-image/{item_id}")
async def upload_file(
    item_id: int,
    file: UploadFile = File(...),
    authenticated: bool = Depends(authenticate)
):

    db = SessionLocal()

    db_item = (
        db.query(DBItem)
        .filter(DBItem.id == item_id)
        .first()
    )

    if not db_item:

        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    file_path = os.path.join(
        "uploads",
        file.filename
    )

    with open(file_path, "wb") as f:

        f.write(await file.read())

    db_item.image_src = file.filename

    db.commit()

    db.refresh(db_item)

    return {
        "message": "Image uploaded",
        "item": db_item
    }

# ------------------------------------------------
# SERVE FILE
# ------------------------------------------------

@app.get("/static/{file_name}")
async def serve_file(file_name: str):

    file_path = os.path.join(
        "uploads",
        file_name
    )

    if not os.path.exists(file_path):

        raise HTTPException(
            status_code=404,
            detail="File not found"
        )

    return FileResponse(file_path)

# ------------------------------------------------
# GLOBAL ERROR HANDLER
# ------------------------------------------------

@app.exception_handler(Exception)
async def global_exception_handler(
    request,
    exc
):

    return {
        "message": "Something went wrong"
    }