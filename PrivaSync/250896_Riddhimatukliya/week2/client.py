import asyncio
import time
import websockets
alive_seconds = 10 #If alive seconds were 0 the client would crash 
#immediately before the server even sent a single ping, which wouldnt
# demonstrate the heartbeat mechanism.
SERVER_URI = "ws://localhost:8765"
delay=1
max_delay = 30
async def recvloop(ws):
    async for _ in ws:
        pass
async def run_client():
    retry_delay = delay
    attempt= 0

    while True:
        attempt += 1
        print(f"attempt {attempt} connecting to {SERVER_URI} ...")

        try:
            async with websockets.connect(SERVER_URI) as ws:

                retry_delay = delay
                print(f"Connected retry_delay reset → {delay}")

                print(f"phase 1 normal operation for {alive_seconds}")

                recv_task = asyncio.create_task(recvloop(ws)) #start receiver task
                try:
                 await asyncio.wait_for(asyncio.shield(recv_task), timeout=10)
                except asyncio.TimeoutError:
                    pass
                finally:
                    recv_task.cancel()
                    try:
                      await recv_task
                    except (asyncio.CancelledError, websockets.ConnectionClosed):
                     pass

                if ws.close_code is not None:
                 raise websockets.ConnectionClosed(ws.close_rcvd, ws.close_sent)

                print(f"crash occured receive loop stopped.")
                print(f"Waiting for server reaper to strike")
                await asyncio.wait_for(ws.wait_closed(), timeout=25)
                print(f"Server closed Code={ws.close_code}")

        except (
            websockets.ConnectionClosed,
            websockets.ConnectionClosedError,
            websockets.ConnectionClosedOK,
            ConnectionRefusedError,
            OSError,
        ) as exc:
                print(f"Disconnected {exc}")
        print(f"Retry in {retry_delay}s ...")
        await asyncio.sleep(retry_delay)
        retry_delay = min(retry_delay * 2,30) #exponential backoff
        print(f"(next failure → {retry_delay}s)")


if __name__ == "__main__":
    print("Websocket client exponential backoff")
    try:
        asyncio.run(run_client())
    except KeyboardInterrupt:
        print("stopped by user.") 