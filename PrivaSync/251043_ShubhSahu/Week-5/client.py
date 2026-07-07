import asyncio
import websockets

async def client():
    async with websockets.connect("ws://localhost:8000") as ws:
        msg = await ws.recv()
        print(msg)
        await ws.send("Hi from client")

asyncio.run(client())