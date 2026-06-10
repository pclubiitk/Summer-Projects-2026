



import asyncio
import websockets

SERVER_URI = "ws://localhost:8765"


INITIAL_DELAY = 1      
MAX_DELAY     = 30    


async def connect_and_run():
    """
    Main loop. Keeps trying to connect forever.
    Returns only when the program is interrupted (Ctrl+C).
    """
    retry_delay = INITIAL_DELAY

    while True:   
        try:
            print(f"\n[→] Connecting to {SERVER_URI} ...")

           
            async with websockets.connect(SERVER_URI) as ws:
                print("[✓] Connected!  Resetting retry delay to 1s.")
                retry_delay = INITIAL_DELAY   # ← Reset on success

                
                print("[~] Staying alive for 10s (server will ping us)...")
                await asyncio.sleep(10)

                
                print("[!] Simulating crash — no longer responding to pings.")
                print("    (Server reaper will kill us in ~15s)")
                await asyncio.sleep(60)   # pretend we are frozen

        
        except websockets.ConnectionClosed as e:
            print(f"[✗] Connection closed by server: {e}")

        except OSError as e:
           
            print(f"[✗] Could not connect: {e}")

        except Exception as e:
            print(f"[✗] Unexpected error: {e}")

        
        print(f"[↺] Reconnecting in {retry_delay}s ...")
        await asyncio.sleep(retry_delay)

        
        retry_delay = min(retry_delay * 2, MAX_DELAY)
        print(f"    (Next retry delay will be {retry_delay}s if this fails)")



if __name__ == "__main__":
    print("=" * 50)
    print("  WebSocket Client with Exponential Backoff")
    print(f"  Server : {SERVER_URI}")
    print(f"  Backoff : {INITIAL_DELAY}s → doubles → max {MAX_DELAY}s")
    print("=" * 50)
    try:
        asyncio.run(connect_and_run())
    except KeyboardInterrupt:
        print("\n[!] Client stopped by user.")