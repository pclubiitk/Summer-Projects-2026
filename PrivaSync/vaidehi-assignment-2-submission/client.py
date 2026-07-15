import asyncio
import websockets
import time


async def client():

    retry_delay = 1

    while True:

        try:

            print("Connecting...")

            async with websockets.connect(
                "ws://localhost:8765"
            ) as ws:

                retry_delay = 1

                print("Connected successfully")

                await asyncio.sleep(10)

                print("Simulating crash...")

                time.sleep(30)

                raise ConnectionError(
                    "Client became unresponsive"
                )

        except Exception as e:

            print(f"Connection lost: {e}")

            print(
                f"Retrying in {retry_delay}s..."
            )

            await asyncio.sleep(retry_delay)

            retry_delay = min(
                retry_delay * 2,
                30
            )


asyncio.run(client())