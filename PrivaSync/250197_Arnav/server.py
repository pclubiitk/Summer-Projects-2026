import asyncio         # for async/await
import time             # for time.time()
import uuid             # generates random unique IDs
import websockets       # handshake, framing, ping/pong frames, close frames, etc

class ConnectionManager:
    def __init__(self):         #initialisation
        self.clients = {}       # a dictionary
        self.last_pong = {}     # another dict

    def register(self, client_id, websocket):       #called when a new client connects.Adds them to both dicts
        self.clients[client_id] = websocket
        self.last_pong[client_id] = time.time()
        print(f"[+] Client connected:    {client_id}")

    def unregister(self, client_id):        #called when a client leaves.Removes it from both the dicts
        self.clients.pop(client_id, None)
        self.last_pong.pop(client_id, None)
        print(f"[-] Client unregistered: {client_id}")

    def record_pong(self, client_id):       #called everytime a pong frame arrives from a client
        self.last_pong[client_id] = time.time()
        print(f"[~] Pong received from:  {client_id}")


manager = ConnectionManager()


async def ping_task():      # makes a coroutine(a function that can be paused and resumed by asyncio)
    while True:
        await asyncio.sleep(5)      # pauses coroutine for 5 seconds
        if not manager.clients:     #If no clients are connected, skip the ping loop and go back to sleep
            continue
        print(f"\n[P] Pinging {len(manager.clients)} client(s)...")
        for client_id, websocket in list(manager.clients.items()):
            try:
                await websocket.ping()
            except Exception:
                pass


async def reaper_task():
    TIMEOUT = 15        # if a client hasn't ponged in 15 seconds, it's considered dead.
    while True:
        await asyncio.sleep(5)      #pauses coroutine for 5 sec
        now = time.time()       #capturs currnt timestamp
        for client_id, websocket in list(manager.clients.items()):
            idle_for = now - manager.last_pong.get(client_id, 0)
            if idle_for > TIMEOUT:
                print(f"\n[X] Closing inactive client: {client_id} (silent for {idle_for:.1f}s)")
                try:
                    await websocket.close()     #sends a close frame to the client
                except Exception:
                    pass
                manager.unregister(client_id)       #removes it from dict


async def handler(websocket):
    client_id = str(uuid.uuid4())[:8]       #generates random UUID and takes first 8 charactders
    manager.register(client_id, websocket)

    def on_pong(data):      #records the pong
        manager.record_pong(client_id)

    websocket.pong_handler = on_pong

    try:
        async for message in websocket:
            print(f"[M] Message from {client_id}: {message}")
    except websockets.exceptions.ConnectionClosedOK:
        print(f"[=] Clean close for:     {client_id}")
    except websockets.exceptions.ConnectionClosedError:
        print(f"[!] Abrupt close for:    {client_id}")
    finally:
        manager.unregister(client_id)


async def main():
    print("Server starting on ws://localhost:8765")
    async with websockets.serve(handler, "localhost", 8765):
        await asyncio.gather(       #runs multiple coroutines concurrently
            ping_task(),
            reaper_task(),
            asyncio.Future(),
        )


if __name__ == "__main__":
    asyncio.run(main())     #creates new asynchio event loop