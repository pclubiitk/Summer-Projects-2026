import asyncio
import websockets

async def run():
    retry_delay = 1
    while True:
        try:
            async with websockets.connect("ws://localhost:8000/ws/client1") as ws:
                print("Connected!")
                retry_delay = 1
                async def handle_messages():
                    try:
                        async for message in ws:
                            if message == "ping":
                                await ws.send("pong")
                    except asyncio.CancelledError:
                        return

                listen_task = asyncio.create_task(handle_messages())
                await asyncio.sleep(10)
                print("Simulating crash - stopping responses")
                listen_task.cancel()
                try:
                    await ws.wait_closed()
                except Exception:
                    pass
                raise ConnectionError("WebSocket closed")
        except Exception as e:
            print(f"Disconnected. Retrying in {retry_delay}s...")
            await asyncio.sleep(retry_delay)
            retry_delay = min(retry_delay * 2, 30)

asyncio.run(run())