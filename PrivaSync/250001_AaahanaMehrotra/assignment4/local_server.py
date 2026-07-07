import asyncio
import json
import websockets

CURRENT_FEDERATED_AVG = 0

async def send_messages():
    global CURRENT_FEDERATED_AVG
    uri = "ws://localhost:8765"
    
    async with websockets.connect(uri) as websocket:
        print("Connected to the server!")
        
        for i in range(5):
            local_trained_on_samples = int(input("Enter the number of samples trained on: "))
            local_total_weights = float(input("Enter the total weights: "))

            data = {
                "message": "Local server update",
                "trained_on_samples": local_trained_on_samples,
                "total_weights": local_total_weights
            }
            await websocket.send(json.dumps(data))
            print(f"Sent: {data}")
            
            reply = await websocket.recv()

            data_reply = json.loads(reply)
            CURRENT_FEDERATED_AVG = data_reply["federated_avg"]
            local_trained_on_samples = 0
            local_total_weights = 0
            print(f"Updated Federated Average: {CURRENT_FEDERATED_AVG}")
            


if __name__ == "__main__":
    asyncio.run(send_messages())
