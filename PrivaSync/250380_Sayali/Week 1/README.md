
# Book Store API

## Setup

```bash
pip install fastapi uvicorn
uvicorn main:app --reload
```

Then open: http://127.0.0.1:8000/docs  ← interactive Swagger UI

---

## Endpoints

| Method | URL | Type | Description |
|--------|-----|------|-------------|
| GET | `/` | - | Welcome message |
| GET | `/books/{book_id}` | Path param | Get one book by ID |
| GET | `/books?author=X&max_price=Y` | Query params | Filter books |
| POST | `/books` | Body (JSON) | Add a new book |
| DELETE | `/books/{book_id}` | Path + Auth | Delete a book (requires login) |

---

## How to test each endpoint

### Path parameter
```
GET http://127.0.0.1:8000/books/1
```

### Query parameters
```
GET http://127.0.0.1:8000/books?author=Cal Newport
GET http://127.0.0.1:8000/books?max_price=20
GET http://127.0.0.1:8000/books?author=Cal&max_price=250
```

### Body parameter (POST)
```bash
curl -X POST http://127.0.0.1:8000/books \
  -H "Content-Type: application/json" \
  -d '{"title": "Atomic Habits", "author": "James Clear", "price": 315.00}'
```

### Protected DELETE (HTTP Basic Auth)
```
Username: admin
Password: bookstore123

DELETE http://127.0.0.1:8000/books/1
```
