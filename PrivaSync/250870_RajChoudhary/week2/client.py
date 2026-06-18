import asyncio
import websockets

URL    = "ws://localhost:8765"
MAX_DELAY  = 30


async def main():
    retry_delay = 1

    while True:
        try:
            async with websockets.connect(URI) as ws:
                print("Connected to server")
                retry_delay = 1  # reset on successful connect

                # Stay alive for 10s so the server can ping us, then go silent
                await asyncio.sleep(10)
                print("Simulating crash — ignoring all further traffic")

                # Block forever without processing anything (simulated crash)
                await asyncio.Future()

        except (websockets.ConnectionClosed, OSError) as e:
            print(f"Disconnected: {e} — retrying in {retry_delay}s")
            await asyncio.sleep(retry_delay)
            retry_delay = min(retry_delay * 2, MAX_DELAY)


if __name__ == "__main__":
    asyncio.run(main())
