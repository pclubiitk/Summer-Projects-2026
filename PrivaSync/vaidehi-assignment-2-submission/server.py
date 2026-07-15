import asyncio
import time
import websockets


class ConnectionManager:
    def __init__(self):
        self.clients = set()
        self.last_pong = {}

    async def register(self, websocket):
        self.clients.add(websocket)
        self.last_pong[websocket] = time.time()
        print(f"Client connected: {id(websocket)}")

    async def unregister(self, websocket):
        self.clients.discard(websocket)
        self.last_pong.pop(websocket, None)

    async def ping_clients(self):
        while True:

            for ws in list(self.clients):

                try:
                    pong_waiter = await ws.ping()

                    await asyncio.wait_for(
                        pong_waiter,
                        timeout=5
                    )

                    self.last_pong[ws] = time.time()

                except Exception:
                    pass

            await asyncio.sleep(5)

    async def reaper(self):
        while True:

            now = time.time()

            for ws in list(self.clients):

                last_seen = self.last_pong.get(ws, 0)

                if now - last_seen > 15:

                    print(
                        f"Closing inactive client: {id(ws)}"
                    )

                    try:
                        await ws.close()
                    except Exception:
                        pass

                    await self.unregister(ws)

            await asyncio.sleep(5)


manager = ConnectionManager()


async def handler(websocket):
    await manager.register(websocket)

    try:
        async for message in websocket:
            print(f"Received: {message}")

    except websockets.exceptions.ConnectionClosed:
        pass

    finally:
        await manager.unregister(websocket)
        print(f"Client disconnected: {id(websocket)}")


async def main():

    server = await websockets.serve(
        handler,
        "localhost",
        8765
    )

    asyncio.create_task(manager.ping_clients())
    asyncio.create_task(manager.reaper())

    print("Server running on ws://localhost:8765")

    await server.wait_closed()


if __name__ == "__main__":
    asyncio.run(main())                                      