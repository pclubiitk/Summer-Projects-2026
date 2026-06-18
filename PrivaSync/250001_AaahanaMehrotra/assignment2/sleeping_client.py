import asyncio
import time
import websockets

uri = "ws://localhost:8764"


async def hello_client():
    while True:
        try:
            print(f"Attempting to connect to {uri}...")
            async with websockets.connect(uri) as websocket:
                print("Successfully connected to the server!")
                print("Operating normally for 10 seconds (responding to pings)...")
                await asyncio.sleep(10)
                print("CRASH SIMULATION: Pausing websocket transport")
                transport = websocket.transport
                transport.pause_reading()
                await asyncio.sleep(20)   # loop runs, but no frames are read
                # transport.resume_reading()
        except (websockets.exceptions.ConnectionClosed, OSError) as e:
            print(f"Disconnected from server: {e}")
            retry_delay = 1
            while retry_delay <= 30:
                print(f"Attempting to reconnect in {retry_delay} seconds...")
                await asyncio.sleep(retry_delay)
                retry_delay = retry_delay*2
            else:
                print("Couldn't connect to server")
                break


if __name__ == "__main__":
    try:
        asyncio.run(hello_client())
    except KeyboardInterrupt:
        print("Client stopped.")