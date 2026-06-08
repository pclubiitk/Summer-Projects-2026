from fastapi import FastAPI, WebSocket, WebSocketDisconnect
import redis.asyncio as redis

app = FastAPI()
r = redis.Redis(host='localhost', port=6379, decode_responses=True)

@app.get("/set/{key}/{value}")
async def set_value(key: str, value: str):
    await r.set(key, value)
    return {"status": "ok"}

@app.get("/get/{key}")
async def get_value(key: str):
    return {"value": await r.get(key)}

@app.websocket("/ws")
async def websocket_endpoint(ws: WebSocket):
    await ws.accept()
    try:
        while True:
            data = await ws.receive_text()
            await ws.send_text(f"Echo: {data}")
    except WebSocketDisconnect:
        print("Client disconnected")
