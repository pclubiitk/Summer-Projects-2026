from contextlib import asynccontextmanager
from typing import Optional

from fastapi import FastAPI, HTTPException, Depends
from pydantic import BaseModel, Field
from utils import find_item

import redis.asyncio as redis

redis_client = None


@asynccontextmanager
async def lifespan(app: FastAPI):
    global redis_client

    redis_client = redis.Redis(
        host="localhost",
        port=6379,
        decode_responses=True
    )

    yield

    await redis_client.close()


app = FastAPI(lifespan=lifespan)


async def get_redis():
    return redis_client

inventory = [
    {
        "id": 1,
        "name": "Treasure",
        "quantity": 3
    }
]


def authenticate():
    return True



class Item(BaseModel):
    name: str
    quantity: int


class ItemUpdate(BaseModel):
    name: Optional[str] = Field(
        None,
        description="Optional name of the item"
    )

    quantity: Optional[int] = Field(
        None,
        description="Optional quantity of the item"
    )


@app.get("/")
async def root():
    return {"message": "FastAPI + Redis Running"}


@app.get("/items")
async def get_items():
    return {"items": inventory}


@app.get("/items/{item_id}")
async def get_item(item_id: int):

    item, idx = find_item(
        inventory,
        lambda x: x["id"] == item_id
    )

    if idx == -1:
        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    return {"item": item}


@app.post("/items")
async def add_item(data: Item):

    item = {
        "id": len(inventory) + 1,
        "name": data.name,
        "quantity": data.quantity
    }

    inventory.append(item)

    return item

@app.patch("/items/{item_id}")
async def update_item(
    item_id: int,
    item_update: ItemUpdate
):

    item, idx = find_item(
        inventory,
        lambda x: x["id"] == item_id
    )

    if idx == -1:
        raise HTTPException(
            status_code=404,
            detail="Item not found"
        )

    if item_update.name is not None:
        item["name"] = item_update.name

    if item_update.quantity is not None:
        item["quantity"] = item_update.quantity

    inventory[idx] = item

    return item


@app.get("/cached-items/{item_id}")
async def read_cached_item(
    item_id: int,
    redis_db=Depends(get_redis)
):

    cached_item = await redis_db.get(f"item:{item_id}")

    if cached_item:
        return {
            "item": cached_item,
            "source": "cache"
        }

    # Simulate database fetch
    item = f"Item {item_id}"

    # Save in Redis
    await redis_db.set(
        f"item:{item_id}",
        item,
        ex=10
    )

    return {
        "item": item,
        "source": "database"
    }


@app.get("/data/{key}")
async def get_cached_data(
    key: str,
    redis_db=Depends(get_redis)
):

    cached_val = await redis_db.get(key)

    if cached_val:
        return {
            "data": cached_val,
            "source": "cache"
        }

    val = f"Real data for {key}"

    await redis_db.set(
        key,
        val,
        ex=5
    )

    return {
        "data": val,
        "source": "db"
    }