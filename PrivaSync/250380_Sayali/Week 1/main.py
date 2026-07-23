from fastapi import FastAPI, HTTPException, Depends
from pydantic import BaseModel
from middleware import authenticate
 
app = FastAPI()
 
# Pydantic model

class Book(BaseModel):
    title: str
    author: str
    price: float
    in_stock: bool = True          # optional field with a default value
 
#Fake database, just a list in memory
books_db = [
    {"id": 1, "title": "The Red Rising",        "author": "Pierce Brown", "price": 335.99, "in_stock": True},
    {"id": 2, "title": "Dune", "author": "Frank Herbert", "price": 442.00, "in_stock": True},
    {"id": 3, "title": "The Three-Body Problem",          "author": "Cixin Liu",    "price": 318.50, "in_stock": False},
]
 
#root endpoint
@app.get("/")
async def home():
    return {"message": "Welcome to the Book Store API :) "}
 
 
# Path parameter :  /books/{book_id}
# The value after "/" is captured directly from the URL

@app.get("/books/{book_id}")
async def get_book(book_id: int):
    # Search for the book in our fake DB
    for book in books_db:
        if book["id"] == book_id:
            return book
    # Raise a 404 with a helpful message if not found

    raise HTTPException(
        status_code=404,
        detail={"error": "Book not found", "book_id": book_id}
    )
 
 
# Query parameters :  /books?author=...&max_price=... ──────────────────
# Values come after "?" in the URL: /books?author=J.R.Tolkein&max_price=20
@app.get("/books")
async def list_books(author: str = None, max_price: float = None):
    results = books_db
 
    if author:
        results = [b for b in results if author.lower() in b["author"].lower()]
 
    if max_price is not None:
        results = [b for b in results if b["price"] <= max_price]
 
    return {"count": len(results), "books": results}
 
 
# Body parameter :  POST /books
# Client sends JSON in the request body; FastAPI + Pydantic validate it.

# Example body: {"title": "Atomic Habits", "author": "James Clear", "price": 315.00}

@app.post("/books")
async def add_book(book: Book):
    new_id = len(books_db) + 1
    new_book = {"id": new_id, **book.model_dump()}
    books_db.append(new_book)
    return {"message": "Book added successfully", "book": new_book}
 
 
# Protected endpoint using Depends (authentication middleware)
# The Depends(authenticate) acts as a checkpoint:
# FastAPI calls authenticate first; only if it passes does this function run.
@app.delete("/books/{book_id}")
async def delete_book(book_id: int, _: bool = Depends(authenticate)):
    for i, book in enumerate(books_db):
        if book["id"] == book_id:
            removed = books_db.pop(i)
            return {"message": "Book deleted", "book": removed}
    raise HTTPException(
        status_code=404,
        detail={"error": "Book not found", "book_id": book_id}
    )
