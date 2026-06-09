import asyncio
import websockets
import time
import uuid

class ConnectionManager:
    def __init__(self):

        self.clients: dict[str, websockets.WebSocketServerProtocol] = {}
        self.last_pong: dict[str, float] = {}

    def register(self, client_id: str, websocket):
        self.clients[client_id] = websocket
        self.last_pong[client_id] = time.time()
        print(f"Client connected:  {client_id}")

    def unregister(self, client_id: str):
        self.clients.pop(client_id, None)
        self.last_pong.pop(client_id, None)

    def record_pong(self, client_id: str):
        self.last_pong[client_id] = time.time()
        print(f"Pong received from:  {client_id}")

    async def ping_task(self):
        while True:
            await asyncio.sleep(5)
            for client_id, ws in list(self.clients.items()):
                try:
                    pong_waiter = await ws.ping()
                    print(f"Ping sent to:  {client_id}")
                    asyncio.ensure_future(self._wait_for_pong(client_id, pong_waiter))
                except Exception as e:
                    print(f"Ping failed for {client_id}: {e}")

    async def _wait_for_pong(self, client_id: str, pong_waiter):
        try:
            await asyncio.wait_for(pong_waiter, timeout=14)
            self.record_pong(client_id)
        except asyncio.TimeoutError:
            pass  
        except Exception:
            pass

    async def reaper(self):
        while True:
            await asyncio.sleep(5)
            now = time.time()
            for client_id, last in list(self.last_pong.items()):
                if now - last > 15:
                    print(f"Closing inactive client:  {client_id}")
                    ws = self.clients.get(client_id)
                    if ws:
                        try:
                            await ws.close()
                        except Exception:
                            pass
                    self.unregister(client_id)


manager = ConnectionManager()


async def handler(websocket):
    client_id = str(uuid.uuid4())[:8]
    manager.register(client_id, websocket)
    try:
        async for message in websocket:
            print(f"[msg] {client_id}: {message}")
    except websockets.ConnectionClosed:
        print(f"Connection closed:  {client_id}")
    finally:
        manager.unregister(client_id)


async def main():
    print("WebSocket server starting on ws://localhost:8765")
    asyncio.create_task(manager.ping_task())
    asyncio.create_task(manager.reaper())

    async with websockets.serve(handler, "localhost", 8765):
        await asyncio.Future()  


if __name__ == "__main__":
    asyncio.run(main())
