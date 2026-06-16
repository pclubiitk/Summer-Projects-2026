import asyncio
import time

class connectionManager:
    def __init__(self):
        self.clients = set()
        self.lastPong={}
    async def add(self, ws):
        self.clients.add(ws)
        self.lastPong[ws]=time.time()
    async def remove(self, ws):
        self.clients.discard(ws)
        self.lastPong.pop(ws, None)
    async def getClients(self):
        return self.clients
    async def updatePong(self, ws):
        self.lastPong[ws]=time.time()
    async def sendPing(self):
        while True:
            await asyncio.sleep(5)
            for ws in list(self.clients):
                pong = await ws.ping()
                asyncio.create_task(self.TrackPongs(ws,pong))
    async def TrackPongs(self,ws,pong):
        await pong
        self.lastPong[ws]=time.time()
    async def reaper(self):
        while True:
            await asyncio.sleep(5)
            for ws in list(self.clients):
                print(time.time() - self.lastPong[ws])
                if time.time() - self.lastPong[ws] > 15:
                    print(f"Closing inactive client: {ws}")
                    await ws.close()
                    await self.remove(ws)


import websockets
manager = connectionManager()

async def handler(ws):
    await manager.add(ws)
    try:
        await ws.wait_closed()
    finally:
        await manager.remove(ws)

async def main():
    server = await websockets.serve(handler,"localhost",8765,ping_interval=None)
    asyncio.create_task(manager.sendPing())
    asyncio.create_task(manager.reaper())
    print("Server running on ws://localhost:8765")
    await server.wait_closed()

asyncio.run(main())
