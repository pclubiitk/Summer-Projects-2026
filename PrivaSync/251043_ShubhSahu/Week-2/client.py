import asyncio
import websockets

SERVER_URI = "ws://localhost:8765"

MAX_RETRY_DELAY = 30  


async def connect():
    retry_delay = 1  

    while True:
        try:
            print(f"Attempting to connect to {SERVER_URI} ...")
            async with websockets.connect(SERVER_URI) as websocket:
                print("Connected, Resetting retry delay to 1s.")
                retry_delay = 1  
                print("Sleeping 10s (server will ping during this time)...")
                await asyncio.sleep(10)
                print("Simulating crash: no longer responding to anything.")
                await asyncio.sleep(99999) 
                
        except (websockets.ConnectionClosed, websockets.ConnectionClosedError,
                websockets.ConnectionClosedOK) as e:
            print(f"Disconnected: {e}")

        except (OSError, websockets.InvalidURI,
                websockets.WebSocketException, ConnectionRefusedError) as e:
            print(f"Connection failed: {e}")

        print(f"Reconnecting in {retry_delay}s ...")
        await asyncio.sleep(retry_delay)
        retry_delay = min(retry_delay * 2, MAX_RETRY_DELAY)


if __name__ == "__main__":
    asyncio.run(connect())
