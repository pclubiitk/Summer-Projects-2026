from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

students = []

class Student(BaseModel):
    name : str
    email : str
    phone : int
    percentile : float

data1 = {
    "name": "Rohan K",
    "email":"rohan25",
    "phone":"2356",
    "percentile":"99.53"
}

data2 = {
    "name": "Rohit K",
    "email":"rohit25",
    "phone":"2357",
    "percentile":"99.83"
}
rohan = Student(**data1)
rohit = Student(**data2)

@app.get("/")
def read_root():
    return {"data":[rohan, rohit]}

@app.post("/students")
def add_students(student : Student):
    students.append(student)
    return{"message":"Student Created Successfully"}

@app.delete("/students")
def delete_student():
    students.pop()
    return{"message":"Student Deleted Successfully"}

@app.get("/students")
def get_students():
    return students
