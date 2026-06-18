import asyncio
import time
from datetime import datetime
import websockets

HEARTBEAT_INTERVAL = 5
last_pong = {}

async def pinger(websocket):
    while True:
        await asyncio.sleep(HEARTBEAT_INTERVAL)
        # last_pong[websocket.remote_address]["last_pong_time"] = time.now()
        # print(datetime.now())
        try:
            pong_waiter = await websocket.ping()
            latency = await asyncio.wait_for(pong_waiter, timeout=5)
            last_pong[websocket.remote_address]["last_pong_time"] = datetime.now()
            print(f"[{websocket.remote_address}]: latency: {latency}")
        except:
            print(f"[{websocket.remote_address}]: No reponse from client")
            last_pong[websocket.remote_address]["missed_pings"] += 1

        if last_pong[websocket.remote_address]["missed_pings"] >= 3:
            print(f"[{websocket.remote_address}]: Connection lost for >15 seconds")
            await websocket.close()
            if websocket.close_code == 1000:
                print(f"[{websocket.remote_address}]: Websocket closed successfully")
                last_pong.pop(websocket.remote_address)
                print(f"Current connected Clients: {len(last_pong)}")
                print(last_pong)

            else:
                print(f"[{websocket.remote_address}]: Error closing websocket {websocket.close_code}")
            break

    
async def echo_handler(websocket):
    print(f"New Client Connected: {websocket.remote_address}")
    last_pong[websocket.remote_address] = {
        "last_pong_time": None,
        "missed_pings": 0
    }
    print(f"Current connected Clients: {len(last_pong)}")

    await pinger(websocket)

    
async def main():
    print("Server started... Waiting for clients to connect")
    async with websockets.serve(echo_handler, "localhost", 8764):
        await asyncio.Future() 

if __name__ == "__main__":
    asyncio.run(main())
