from fastapi import FastAPI
import redis

app = FastAPI()

# connect to redis
redis_client = redis.Redis(host='localhost', port=)

@app.get("/items/{item_id}")
async def read_item(item_id: int):
    cached_item = redis_client.get(f"item_{item_id}")

    if cached_item:
        return {"item_id": item_id, "cached": True, "data": cached_item.decode('utf-8')}

    item_data = f"Item data for {item_id}"

    redis_client.set(f"item_{item_id}", item_data)

    return {"item_id": item_id, "cached": False, "data": item_data}



