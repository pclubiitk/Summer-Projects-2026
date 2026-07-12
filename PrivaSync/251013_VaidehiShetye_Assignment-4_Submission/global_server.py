import asyncio
import json
import websockets


async def handler(websocket):
    print("Local backend connected!")

    try:
        command = {
            "command": "train_model",
            "epochs": 5,
            "model": "demo_model"
        }

        await websocket.send(json.dumps(command))
        print("Training command sent.")

        async for message in websocket:
            data = json.loads(message)

            print("\n===== Training Result =====")
            print(f"Status            : {data['status']}")
            print(f"Samples Trained   : {data['samples_trained']}")
            print(f"Accuracy          : {data['accuracy']}")
            print(f"Loss              : {data['loss']}")
            print("===========================\n")

            response = {
                "status": "received",
                "message": "Training results received successfully."
            }

            await websocket.send(json.dumps(response))

    except websockets.exceptions.ConnectionClosed:
        print("Local backend disconnected.")


async def main():
    server = await websockets.serve(
        handler,
        "localhost",
        8765
    )

    print("Global Server Running")
    print("Listening on ws://localhost:8765")

    await server.wait_closed()


if __name__ == "__main__":
    asyncio.run(main())