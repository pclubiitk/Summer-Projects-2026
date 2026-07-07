from sqlalchemy import create_engine, Column, Integer, PickleType
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

DATABASE_URL = "sqlite:///./todos.db"

engine = create_engine(
    DATABASE_URL,
    connect_args={"check_same_thread": False}
)

SessionLocal = sessionmaker(
    autocommit=False,
    autoflush=False,
    bind=engine
)

Base = declarative_base()

class ModelWeights(Base):
    __tablename__ = "model_weights"
    
    id = Column(Integer, primary_key=True, index=True)
    epoch = Column(Integer)
    weights = Column(PickleType)

Base.metadata.create_all(bind=engine)