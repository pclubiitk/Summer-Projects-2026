import asyncio
import websockets

SERVER_URL = "ws://localhost:8765"
MIN_DELAY  = 1      #first retry waits 1 sec
MAX_DELAY  = 30     #backoff never exceeds 30 sec

async def run():
    retry_delay = MIN_DELAY
    attempt = 0

    while True:
        attempt += 1
        print(f"\n[>] Connection attempt #{attempt} (retry_delay={retry_delay}s)")

        try:
            async with websockets.connect(SERVER_URL) as websocket:     #performs Wensocket handshake
                print("[Success] Connected to server!")
                retry_delay = MIN_DELAY     #Resets retry_delay to 1

                print("[~] Sleeping 10s (letting server ping us)...")
                await asyncio.sleep(10)

                print("[!] Going silent — simulating crash")
                await asyncio.Future()      #returns a Future object that never resolves

        except websockets.exceptions.ConnectionClosedError as e:        #abrupt disconnect, no Close frame
            print(f"[X] Connection closed unexpectedly: {e}")
        except websockets.exceptions.ConnectionClosedOK:        #reaper sent a Close frame
            print("[=] Server closed the connection cleanly (reaper struck)")
        except OSError as e:                        #couldn't even establish a TCP connection. Server not running, wrong port, etc
            print(f"[!] Could not connect: {e}")
        except Exception as e:          #catch-all for anything unexpected
            print(f"[?] Unexpected error: {e}")

        print(f"[~] Waiting {retry_delay}s before reconnecting...")
        await asyncio.sleep(retry_delay)        #waits before reconnecting
        retry_delay = min(retry_delay * 2, MAX_DELAY)       #doubles the delay for next time


if __name__ == "__main__":
    asyncio.run(run())