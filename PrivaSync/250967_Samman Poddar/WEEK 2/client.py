import asyncio
import websockets
URL = "ws://localhost:8765"
async def main():
    retry_delay = 1
    while True:
        try:
            async with websockets.connect(URL,ping_interval=None) as websocket:
                print("Connected")
                retry_delay = 1
                await asyncio.sleep(10)
                print("inentionally closing connection")
                websocket.transport.abort()
                raise ConnectionError("Simulated crash")
        except Exception as e:
            print(f"Connection error: {e}. Retrying in {retry_delay} seconds...")
            await asyncio.sleep(retry_delay)
            retry_delay = min(retry_delay * 2, 30)  # Exponential backoff with a max delay
asyncio.run(main())