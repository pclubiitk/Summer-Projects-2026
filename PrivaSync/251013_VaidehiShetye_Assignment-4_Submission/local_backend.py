import asyncio
import json
import random
import websockets


async def train_model(epochs):
    print("\nStarting local model training...")
    print(f"Training for {epochs} epochs...\n")

    # Simulate training time
    await asyncio.sleep(5)

    training_result = {
        "status": "completed",
        "samples_trained": 500,
        "accuracy": round(random.uniform(0.88, 0.96), 4),
        "loss": round(random.uniform(0.05, 0.15), 4)
    }

    print("Training completed!\n")

    return training_result


async def connect_to_server():

    print("Connecting to global server...")

    async with websockets.connect(
        "ws://localhost:8765"
    ) as websocket:

        print("Connected to global server!\n")

        while True:

            message = await websocket.recv()

            data = json.loads(message)

            if data["command"] == "train_model":

                print("Training command received from server.\n")

                result = await train_model(
                    data["epochs"]
                )

                await websocket.send(
                    json.dumps(result)
                )

                print("Training results sent to server.\n")

                acknowledgement = await websocket.recv()

                ack = json.loads(acknowledgement)

                print("Server Response:")
                print(ack["message"])

                break


asyncio.run(connect_to_server())