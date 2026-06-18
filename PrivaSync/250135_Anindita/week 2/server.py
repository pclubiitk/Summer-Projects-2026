import asyncio
import websockets
import time
import uuid 
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class ConnectionManager:
     
     def __init__(self):
          self.clients: dict[str, websockets.WebSocketServerProtocol] = {}
          self.last_pong: dict[str, float] = {}
     
     def register(self, websocket)-> str:
            client_id = str(uuid.uuid4())
            self.clients[client_id] = websocket
            self.last_pong[client_id] = time.time()
            logger.info(f"Client connected: {client_id}")
            return client_id
    
     def unregister(self, client_id: str):
            self.clients.pop(client_id, None)
            self.last_pong.pop(client_id, None)

     def record_pong(self, client_id: str):
           self.last_pong[client_id] = time.time()
           logger.info(f"Pong received from {client_id}")

     async def ping_all_clients(self):
        while True:
            await asyncio.sleep(5)
            for client_id, ws in list(self.clients.items()):
                try:
                      await ws.ping()
                      logger.info(f"Ping sent to {client_id}")
                except Exception as e:
                        logger.warning(f"Failed to ping {client_id}: {e}")
                        self.unregister(client_id)

     async def reap_dead_connections(self):
        while True:
            await asyncio.sleep(5)
            now=time.time()
            for client_id, last in list(self.last_pong.items()):
                  if now-last > 15:
                        logger.warning(f"CLOSING INACTIVE CLIENT: {client_id}")
                        ws = self.clients.get(client_id)
                        if ws:
                            try:
                                await ws.close()
                            except Exception:   
                                  pass
                        self.unregister(client_id)
manager = ConnectionManager()

async def handler(websocket):
    client_id = manager.register(websocket)
    websocket.pong_handler = lambda data: manager.record_pong(client_id)

    try:
        async for message in websocket:
            logger.info(f"Message from {client_id}: {message}")
            await websocket.send(f"Echo: {message}")
    except websockets.exceptions.ConnectionClosed:
        logger.info(f"Connection closed: {client_id}")
    finally:
        manager.unregister(client_id)
                         
async def main():
    async with websockets.serve(handler, "localhost", 8080):
        await asyncio.gather(
            manager.ping_all_clients(),
            manager.reap_dead_connections(),
            asyncio.Future(),
        )

if __name__ == "__main__":
    asyncio.run(main())