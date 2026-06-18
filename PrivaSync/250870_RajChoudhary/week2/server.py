import asyncio
import time
import uuid
import websockets
from websockets.server import WebSocketServerProtocol

PING_INTERVAL = 5
PONG_TIMEOUT  = 15


class ConnectionManager:
    def __init__(self):
        self.clients:   dict[str, WebSocketServerProtocol] = {}
        self.last_pong: dict[str, float] = {}

    def register(self, ws: WebSocketServerProtocol) -> str:
        cid = str(uuid.uuid4())[:8]
        self.clients[cid]   = ws
        self.last_pong[cid] = time.time()
        print(f"Client connected:    {cid}")
        return cid

    def unregister(self, cid: str):
        self.clients.pop(cid, None)
        self.last_pong.pop(cid, None)

    def record_pong(self, cid: str):
        self.last_pong[cid] = time.time()

    async def ping_all(self):
        for cid, ws in list(self.clients.items()):
            try:
                # ping() returns a future that resolves when the pong arrives
                pong = await ws.ping()
                asyncio.ensure_future(self._wait_pong(cid, pong))
            except Exception:
                pass

    async def _wait_pong(self, cid: str, pong_waiter):
        try:
            await pong_waiter
            self.record_pong(cid)
        except Exception:
            pass

    async def reap(self):
        now = time.time()
        for cid, last in list(self.last_pong.items()):
            if now - last > PONG_TIMEOUT:
                print(f"Closing inactive client: {cid}")
                ws = self.clients.get(cid)
                if ws:
                    try:
                        await ws.close()
                    except Exception:
                        pass
                self.unregister(cid)


manager = ConnectionManager()


async def background_tasks():
    while True:
        await asyncio.sleep(PING_INTERVAL)
        await manager.ping_all()
        await manager.reap()


async def handler(ws):
    cid = manager.register(ws)
    try:
        async for _ in ws:
            pass
    except websockets.ConnectionClosed:
        pass
    finally:
        manager.unregister(cid)
        print(f"Client disconnected: {cid}")


async def main():
    asyncio.create_task(background_tasks())
    async with websockets.serve(handler, "localhost", 8765):
        print("Server listening on ws://localhost:8765")
        await asyncio.Future()


if __name__ == "__main__":
    asyncio.run(main())
