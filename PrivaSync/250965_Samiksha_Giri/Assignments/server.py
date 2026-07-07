import asyncio
from datetime import datetime
from fastapi import FastAPI, WebSocket, WebSocketDisconnect

app = FastAPI()

class ConnectionManager:
    def __init__(self):
        self.active_connections = {}
        self.last_pong = {}

    async def connect(self, client_id, websocket):
        await websocket.accept()
        self.active_connections[client_id] = websocket
        self.last_pong[client_id] = datetime.now()

    def disconnect(self, client_id):
        self.active_connections.pop(client_id, None)
        self.last_pong.pop(client_id, None)

    async def ping_task(self):
        while True:
            await asyncio.sleep(5)
            for client_id, ws in list(self.active_connections.items()):
                try:
                    await ws.send_text("ping")
                except:
                    self.disconnect(client_id)

    async def reaper_task(self):
        while True:
            await asyncio.sleep(5)
            now = datetime.now()
            for client_id, t in list(self.last_pong.items()):
                if (now - t).total_seconds() > 15:
                    print(f"Closing inactive client: {client_id}")
                    try:
                        await self.active_connections[client_id].close()
                    except:
                        pass
                    self.disconnect(client_id)

manager = ConnectionManager()

@app.on_event("startup")
async def startup():
    asyncio.create_task(manager.ping_task())
    asyncio.create_task(manager.reaper_task())

@app.websocket("/ws/{client_id}")
async def websocket_endpoint(websocket: WebSocket, client_id: str):
    await manager.connect(client_id, websocket)
    try:
        while True:
            data = await websocket.receive_text()
            if data == "pong":
                manager.last_pong[client_id] = datetime.now()
    except WebSocketDisconnect:
        manager.disconnect(client_id)