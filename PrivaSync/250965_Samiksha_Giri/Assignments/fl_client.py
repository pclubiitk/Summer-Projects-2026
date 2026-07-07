import asyncio
import websockets
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Embedding, LSTM, Dense
from sqlalchemy import create_engine, Column, Integer, PickleType
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
import pickle
import os

Base = declarative_base()

class ModelWeights(Base):
    __tablename__ = "model_weights"
    
    id = Column(Integer, primary_key=True, index=True)
    epoch = Column(Integer)
    weights = Column(PickleType)

DATABASE_URL = os.getenv("DATABASE_URL", "sqlite:///./todos.db")

engine = create_engine(
    DATABASE_URL,
    connect_args={"check_same_thread": False}
)

SessionLocal = sessionmaker(
    autocommit=False,
    autoflush=False,
    bind=engine
)

Base.metadata.create_all(bind=engine)

def build_model(vocab_size, embedding_dim, seq_length):
    model = Sequential([
        Embedding(input_dim=vocab_size, output_dim=embedding_dim, input_length=seq_length),
        LSTM(128, return_sequences=True),
        LSTM(64),
        Dense(vocab_size, activation='softmax')
    ])
    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
    return model

async def perform_local_training(dataset, model):
    for x, y in dataset:
        with tf.GradientTape() as tape:
            predictions = model(x, training=True)
            loss = tf.reduce_mean(tf.keras.losses.sparse_categorical_crossentropy(y, predictions))

        gradients = tape.gradient(loss, model.trainable_variables)
        optimizer = tf.keras.optimizers.Adam(learning_rate=0.01)
        optimizer.apply_gradients(zip(gradients, model.trainable_variables))

    return model

async def upload_model_weights(model):
    async with websockets.connect("ws://localhost:8765") as ws:
        await ws.send(pickle.dumps(model.get_weights()))

async def main():
    vocab_size = int(os.getenv("VOCAB_SIZE", 10000))
    embedding_dim = int(os.getenv("EMBEDDING_DIM", 256))
    seq_length = int(os.getenv("SEQ_LENGTH", 32))
    
    model = build_model(vocab_size, embedding_dim, seq_length)
    
    try:
        x = tf.random.uniform((20, seq_length), maxval=vocab_size, dtype=tf.int32) #test dataset 
        y = tf.random.uniform((20,), maxval=vocab_size, dtype=tf.int32)

        dataset = tf.data.Dataset.from_tensor_slices((x, y)).batch(4) # Should be a list of (input_sequences, labels) tuples
        session = SessionLocal()
        
        for epoch in range(10): 
            model = await perform_local_training(dataset, model)
            
            new_weights = ModelWeights(epoch=epoch, weights=model.get_weights())
            session.add(new_weights)
            session.commit()
        
    except Exception as e:
        print(f"Error: {e}")
    
    finally:
        if 'session' in locals():
            session.close()

    # await upload_model_weights(model)
    # print("Model weights uploaded successfully.")
asyncio.run(main())
