import asyncio
import time
import websockets
from websockets.asyncio.server import ServerConnection
PING_INTERVAL = 5
REAP_INTERVAL = 5
PONG_TIMEOUT  = 15

class ConnectionManager:
 
    def __init__(self):
        self.clients   = {}
        self.last_pong = {}
        self._counter  = 0
    def dereg(self, clientid):
        self.clients.pop(clientid, None)
        self.last_pong.pop(clientid, None)

    def register(self, ws):
        self._counter += 1
        clientid = f"client-{self._counter}"
        self.clients[clientid] = ws
        self.last_pong[clientid] = time.monotonic()
        print(f"Connected {clientid}")
        return clientid
    
    def record_pong(self, clientid, latency_ms):
        self.last_pong[clientid] = time.monotonic() #client is alive nd updates pong time
        print(f"Pong received {clientid}  ({latency_ms:.1f} ms)")


    async def track_pong(self, clientid, pong_future):
      try:
        latency_sec = await pong_future #wait for pong
        self.record_pong(clientid, latency_sec * 1000)
      except Exception:
        pass

    async def ping_task(self):
       while True:
        await asyncio.sleep(PING_INTERVAL)
        for clientid, ws in list(self.clients.items()):
            try:
                pong_future = await ws.ping()
                asyncio.create_task(track_pong(clientid, pong_future))
            except Exception:
                pass


    async def reaper_task(self):
      while True:
        await asyncio.sleep(REAP_INTERVAL)
        now = time.monotonic()
        for clientid, ws in list(self.clients.items()):
            silent_for = now - self.last_pong.get(clientid, 0)
            if silent_for > PONG_TIMEOUT:
                print(f"closing inactive client: {clientid}")
                try:
                    await ws.close(1001, "timeout so connection is closed.")
                except Exception:
                    pass
                dereg(clientid)


manager = ConnectionManager()
async def handler(ws):
    clientid = register(ws)
    try:
        async for message in ws:
            await ws.send(f"echo: {message}")
    except websockets.ConnectionClosed:
        pass
    finally:
        dereg(clientid)


async def main():
    asyncio.create_task(ping_task())
    asyncio.create_task(reaper_task())
    async with websockets.serve(handler, "localhost",8765):
        await asyncio.Future()


if __name__ == "__main__":
    asyncio.run(main())
