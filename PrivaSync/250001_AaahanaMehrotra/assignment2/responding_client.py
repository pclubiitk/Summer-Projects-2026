import asyncio
import time
import websockets
import json

uri = "ws://localhost:8764"

async def hello_client():
    while True:
        try:
            async with websockets.connect(uri) as websocket:
                while True:
                    await asyncio.sleep(1)
                    if websocket.state != 1:
                        break
        except:
            retry_delay = 1
            while retry_delay <= 30:
                print(f"Attempting to reconnect in {retry_delay} seconds...")
                await asyncio.sleep(retry_delay)
                retry_delay = retry_delay*2
            else:
                print("Couldn't connect to server")
                break



if __name__ == "__main__":
    asyncio.run(hello_client())
