import asyncio
import websockets

async def server(websocket):
    print("Connected")
    await websocket.send("Hello from server")
    message = await websocket.recv()
    print("User said:", message)

async def main():
    async with websockets.serve(server, "localhost", 8000):
        print("Server running at localhost:8000")
        await asyncio.Future()   

asyncio.run(main())