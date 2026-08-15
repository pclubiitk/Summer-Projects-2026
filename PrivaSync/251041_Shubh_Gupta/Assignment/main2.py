import asyncio
import json
import time

from fastapi import FastAPI, WebSocket, WebSocketDisconnect

app = FastAPI()


class ConnectionManager:
    def __init__(self):
        self.connections = []
        self.last_pong = {}

    async def connect(self, websocket: WebSocket):
        await websocket.accept()
        self.connections.append(websocket)
        self.last_pong[websocket] = time.time()

    def disconnect(self, websocket: WebSocket):
        if websocket in self.connections:
            self.connections.remove(websocket)

        self.last_pong.pop(websocket, None)

    async def broadcast_chat(self, sender: WebSocket, text: str):
        payload = json.dumps({"type": "chat", "msg": text})

        for ws in self.connections.copy():
            if ws is sender:
                continue

            try:
                await ws.send_text(payload)
            except WebSocketDisconnect:
                self.disconnect(ws)

    async def reap_connections(self):
        while True:
            await asyncio.sleep(5)

            now = time.time()

            for ws in self.connections.copy():
                if now - self.last_pong.get(ws, 0) > 15:
                    print(f"Closing inactive client: {id(ws)}")
                    await ws.close()
                    self.disconnect(ws)


manager = ConnectionManager()


@app.on_event("startup")
async def startup():
    asyncio.create_task(manager.reap_connections())


@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await manager.connect(websocket)

    try:
        while True:
            data = await websocket.receive_text()

            try:
                message = json.loads(data)
            except json.JSONDecodeError:
                message = {"type": "chat", "msg": data}

            if message["type"] == "heartbeat":
                manager.last_pong[websocket] = time.time()

            elif message["type"] == "chat":
                text = message.get("msg") or message.get("text") or ""
                await manager.broadcast_chat(websocket, text)

    except WebSocketDisconnect:
        manager.disconnect(websocket)