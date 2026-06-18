import asyncio
import websockets

URL = "ws://localhost:8080"
MAX_RETRY_DELAY = 30
INITIAL_RETRY_DELAY =1 

async def connect():
    retry_delay = INITIAL_RETRY_DELAY
    while True:
        try:
            print(f"Connecting to {URL}...")
            async with websockets.connect(URL) as websocket:
                print("Connected!")
                retry_delay = INITIAL_RETRY_DELAY
                await websocket.send("Hello from client!")
                response = await websocket.recv()
                print(f"Server said: {response}")

                await asyncio.sleep(10)
                await asyncio.sleep(60)
        except (
            websockets.exceptions.ConnectionClosed,
            websockets.exceptions.InvalidHandshake,
            OSError,
        ) as e:
            print(f"Disconnected: {e}")
            print(f"Reconnecting in {retry_delay}s...")
            await asyncio.sleep(retry_delay)
            retry_delay = min(retry_delay * 2, MAX_RETRY_DELAY)
            
if __name__ == "__main__":
    asyncio.run(connect())
        