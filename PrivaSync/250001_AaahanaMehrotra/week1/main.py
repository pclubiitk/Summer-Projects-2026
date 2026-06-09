from contextlib import asynccontextmanager
from fastapi import FastAPI
import redis.asyncio as redis

redis_client = None

@asynccontextmanager
async def lifespan(app: FastAPI):
    global redis_client
    redis_client = redis.Redis(host='localhost', port=6379, decode_responses=True)
    yield
    await redis_client.close()

app = FastAPI(lifespan=lifespan)

from fastapi import Depends

async def get_redis():
    return redis_client

@app.get("/data/{key}")
async def get_cached_data(key: str, redis=Depends(get_redis)):
    cached_val = await redis.get(key)
    if cached_val:
        print("returning cache val")
        return {"data": cached_val, "source": "cache"}
    
    val = f"Real data for {key}" 
    await redis.set(key, val, ex=5)
    return {"data": val, "source": "db"}
