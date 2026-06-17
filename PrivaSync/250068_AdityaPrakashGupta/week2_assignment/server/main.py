from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from datetime import datetime
import logging
import asyncio

from contextlib import asynccontextmanager

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


class ConnectionManager:
    def __init__(self):
        self.active_connections: dict[WebSocket, str] = {}
        self.last_pong: dict[WebSocket, float] = {}
        
        self.ping_task = None
        self.reap_task = None

    async def connect(self, websocket: WebSocket, username: str):
        await websocket.accept()
        self.active_connections[websocket] = username
        self.last_pong[websocket] = datetime.now().timestamp()
        logger.info(f" {username} connected. Total: {len(self.active_connections)}")
        
        if len(self.active_connections) == 1:
            logger.info("Starting background tasks")

            self.ping_task = asyncio.create_task(pinging())
            self.reap_task = asyncio.create_task(reaping())

    def disconnect(self, websocket: WebSocket):
        username = self.active_connections.get(websocket, "Unknown")
        if websocket in self.active_connections:
            del self.active_connections[websocket]
            logger.info(f"{username} disconnected. Total: {len(self.active_connections)}")
        if websocket in self.last_pong:
            del self.last_pong[websocket]
            
        if len(self.active_connections) == 0:
            logger.info("Stopping background tasks")

            if self.ping_task:
                self.ping_task.cancel()
                self.ping_task = None

            if self.reap_task:
                self.reap_task.cancel()
                self.reap_task = None
    
    async def send_conn_users(self):
        users = list(self.active_connections.values())
        dead_conn = []
        
        for ws in list(self.active_connections.keys()):
            try:
                await ws.send_json({"type": "users", "users": users})
            except Exception as e:
                logger.error(f"Error sending users to {self.active_connections.get(ws, 'Unknown')}: {e}")
                dead_conn.append(ws)
                
        for ws in dead_conn:
            self.disconnect(ws)
    
    async def ping_all(self):
        dead_conn = []
        
        for ws in list(self.active_connections.keys()):
            try:
                print("sending ping")
                await ws.send_json({"type": "ping"})
            except Exception as e:
                logger.error(f"Error sending ping to {self.active_connections.get(ws, 'Unknown')}: {e}")
                dead_conn.append(ws)
        
        for ws in dead_conn:
            self.disconnect(ws)
            
manager = ConnectionManager()

async def pinging():
    try:
        while True:
            await asyncio.sleep(5)
            await manager.ping_all()
    except asyncio.CancelledError:
        logger.info("ping task cancelled")
        raise

async def reaping():
    try:
        while True:
            await asyncio.sleep(5)
            now = datetime.now().timestamp()
        
            for ws in list(manager.active_connections.keys()):
                last_pong = manager.last_pong.get(ws, 0)
                if now - last_pong > 15:
                    username = manager.active_connections.get(ws, "Unknown")
                    logger.warning(f"Closing inactive client: {username}")
                    
                    try:
                        await ws.close()
                    except:
                        pass
                    
                    manager.disconnect(ws)
            
            await manager.send_conn_users()
    except asyncio.CancelledError:
        logger.info("reap task cancelled")
        raise
    
app = FastAPI()

@app.get("/")
async def root():
    return {"message": "ws server is running."}


@app.websocket("/ws/{username}")
async def websocket_endpoint(websocket: WebSocket, username: str):
    await manager.connect(websocket, username)
    await manager.send_conn_users()
    try:
        while True:
            data = await websocket.receive_json()
            if data.get("type") == "pong":
                manager.last_pong[websocket] = datetime.now().timestamp()
    except WebSocketDisconnect:
        manager.disconnect(websocket)
        await manager.send_conn_users()
    except Exception as e:
        logger.error(f"Error in websocket connection for {username}: {e}")
        manager.disconnect(websocket)
        await manager.send_conn_users()
