import asyncio
import json
import websockets

TRAINED_ON_SAMPLES = 0
TOTAL_WEIGHTS = 0
FEDERATED_AVG = 0

async def handle_local_servers(websocket):
    global TRAINED_ON_SAMPLES, TOTAL_WEIGHTS, FEDERATED_AVG
    print("Local server connected!")
    try:

        async for message in websocket:
            print(f"Received from local server: {message}")
            data = json.loads(message)

            TRAINED_ON_SAMPLES += data["trained_on_samples"]
            TOTAL_WEIGHTS += data["total_weights"]

            FEDERATED_AVG = TOTAL_WEIGHTS / TRAINED_ON_SAMPLES if TRAINED_ON_SAMPLES > 0 else 0
            print(f"Updated Federated Average: {FEDERATED_AVG}")    

            response = {
                "message": f"server update the federated average to {FEDERATED_AVG}",
                "federated_avg": FEDERATED_AVG,
                "trained_on_samples": TRAINED_ON_SAMPLES,
                "total_weights": TOTAL_WEIGHTS
            }
            await websocket.send(json.dumps(response))
    except websockets.exceptions.ConnectionClosedOK:
        print("Local server disconnected cleanly.")
    except websockets.exceptions.ConnectionClosedError:
        print("Local server disconnected unexpectedly.")

async def main():

    async with websockets.serve(handle_local_servers, "localhost", 8765):
        print("WebSocket Server running on ws://localhost:8765")
        await asyncio.Future()

if __name__ == "__main__":
    asyncio.run(main())
