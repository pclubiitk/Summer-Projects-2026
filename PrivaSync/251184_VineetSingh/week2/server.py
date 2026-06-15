

import asyncio
import time
import websockets


class ConnectionManager:
    def __init__(self):
        
        self.clients: dict[int, websockets.WebSocketServerProtocol] = {}

        
        self.last_pong: dict[int, float] = {}

        
        self._next_id = 1

    
    def register(self, ws) -> int:
        """Called when a new client connects. Returns the assigned client_id."""
        client_id = self._next_id
        self._next_id += 1

        self.clients[client_id] = ws
        self.last_pong[client_id] = time.time()   # seed pong time = now

        print(f"[+] Client {client_id} connected  (total: {len(self.clients)})")
        return client_id

    def unregister(self, client_id: int):
        """Remove a client from both dictionaries."""
        self.clients.pop(client_id, None)
        self.last_pong.pop(client_id, None)
        print(f"[-] Client {client_id} removed    (total: {len(self.clients)})")

   
    def record_pong(self, client_id: int):
        """Called by the pong_handler callback when a PONG frame arrives."""
        self.last_pong[client_id] = time.time()
        print(f"[✓] Pong received from client {client_id}")

  
    async def ping_task(self):
        """
        Runs forever.
        Every 5 seconds: send a PING to every connected client.
        websockets.ping() sends a WebSocket-level PING control frame
        (not an application message). The browser/client library replies
        automatically with a PONG frame.
        """
        while True:
            await asyncio.sleep(5)
            if self.clients:
                print(f"[~] Pinging {len(self.clients)} client(s)...")
            for client_id, ws in list(self.clients.items()):
                try:
                    await ws.ping()
                except Exception as e:
                    print(f"[!] Ping failed for client {client_id}: {e}")

    async def reaper_task(self):
        """
        Runs forever.
        Every 5 seconds: check every client's last pong time.
        If more than 15 seconds have passed without a pong → kill it.

        Why 15 seconds?
        Pings go out every 5s.  A healthy client will pong back quickly.
        15s = 3 missed pings in a row → definitely dead.
        """
        while True:
            await asyncio.sleep(5)
            now = time.time()
            for client_id, ws in list(self.clients.items()):
                silence = now - self.last_pong.get(client_id, 0)
                if silence > 15:
                    print(f"[✗] Closing inactive client: {client_id}  "
                          f"(silent for {silence:.1f}s)")
                    try:
                        await ws.close()
                    except Exception:
                        pass
                    self.unregister(client_id)



manager = ConnectionManager()



async def handle_client(ws):
    """
    Called once for every new WebSocket connection.
    Registers the client, wires up the pong callback, then just
    keeps the connection alive by consuming any incoming messages
    until the client disconnects or the reaper kills it.
    """
    client_id = manager.register(ws)

    
    ws.pong_callback = lambda data: manager.record_pong(client_id)

    try:
        
        async for message in ws:
            print(f"[MSG] Client {client_id} says: {message}")
    except websockets.ConnectionClosed as e:
        print(f"[~] Client {client_id} connection closed: {e}")
    finally:
        manager.unregister(client_id)



async def main():
    print("=" * 50)
    print("  WebSocket Reaper Server starting on ws://localhost:8765")
    print("  Ping interval : 5s")
    print("  Reaper timeout: 15s")
    print("=" * 50)

    
    asyncio.create_task(manager.ping_task())
    asyncio.create_task(manager.reaper_task())

    
    async with websockets.serve(handle_client, "localhost", 8765):
        await asyncio.Future()   


if __name__ == "__main__":
    asyncio.run(main())