import asyncio
import json
import websockets

CURRENT_AVG = 0

async def connect_global():

    global CURRENT_AVG

    uri = "ws://localhost:8765"

    async with websockets.connect(uri) as websocket:

        print("Connected to Global Server")

        while True:

            samples = int(input("Samples : "))
            weights = float(input("Weights : "))

            data = {
                "samples": samples,
                "weights": weights
            }

            await websocket.send(json.dumps(data))

            print("Update sent")

            reply = await websocket.recv()

            reply = json.loads(reply)

            CURRENT_AVG = reply["federated_avg"]

            print("New Federated Average =", CURRENT_AVG)


if __name__ == "__main__":
    asyncio.run(connect_global())