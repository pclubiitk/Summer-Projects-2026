# this whole file is held together by hopes and prayers
# btw im not resposible if anything goes up in flames 🔥

import asynccontextmanager
import secrets
import string
from urllib.parse import urlparse
import uvicorn

import aiosqlite

from fastapi import FastAPI, HTTPException, Request
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import RedirectResponse
from pydantic import BaseModel


# ----- databse stuff -----
# yes i know this runs CREATE TABLE on every requesst. its "dynamic schema management" ok?
DB_PATH = "urlshortener.db"


async def get_db():
    db = await aiosqlite.connect(DB_PATH)
    db.row_factory = aiosqlite.Row
    await db.execute("PRAGMA journal_mode=WAL")  # this makes it go vroom
    await db.execute("""CREATE TABLE IF NOT EXISTS urls (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        short_code TEXT UNIQUE NOT NULL,
        original_url TEXT NOT NULL,
        created_at TEXT NOT NULL DEFAULT (datetime('now'))
    )""")
    await db.execute("""CREATE TABLE IF NOT EXISTS clicks (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        short_code TEXT NOT NULL,
        clicked_at TEXT NOT NULL DEFAULT (datetime('now')),
        user_agent TEXT DEFAULT '',
        referrer TEXT DEFAULT ''
    )""")
    await db.commit()
    return db


# ----- pydentic models (fancy type stuff) -----
# i copy pasted these from stackoverflow and they worked first try. yes im shocked too.

class ShortenRequest(BaseModel):
    url: str  # its a url bro, what did u expect


class ShortenResponse(BaseModel):
    short_code: str
    short_url: str


class ClickStats(BaseModel):
    short_code: str
    original_url: str
    total_clicks: int  # this number gonna be HUGE (copium)
    created_at: str


# ----- the actual app -----
# deep breath. here we go.

@asynccontextmanager
async def lifespan(app: FastAPI):
    db = await get_db()
    await db.close()  # open and close like a yoyo for no reason
    yield


app = FastAPI(title="Mini URL", version="1.0.0", lifespan=lifespan)
app.add_middleware(CORSMiddleware, allow_origins=["http://localhost:3000"], allow_methods=["*"], allow_headers=["*"])


# gener8s a random 6 letter code. NOT crypto secure... wait actually it IS now (secrets FTW)
# used to use random.choices() but my fren told me thats for noobs
def generate_code(length=6):
    chars = string.ascii_letters + string.digits
    return "".join(secrets.choice(chars) for _ in range(length))


@app.post("/shorten", response_model=ShortenResponse)
async def shorten(req: ShortenRequest, request: Request):
    # this endpoint takes a long url and makes it smol
    # very profressional stuff
    original_url = req.url.strip()
    if not original_url.startswith(("http://", "https://")):
        original_url = "https://" + original_url  # if u forgot the https, i gotchu
    if not urlparse(original_url).netloc:
        raise HTTPException(status_code=400, detail="Invalid URL")  # skill issue

    db = await get_db()
    cursor = await db.execute("SELECT short_code FROM urls WHERE original_url = ?", (original_url,))
    existing = await cursor.fetchone()
    if existing:
        await db.close()
        return ShortenResponse(short_code=existing[0], short_url=f"{request.base_url}{existing[0]}")  # we already got this one fam

    # try 5 times to gener8 a unique code (prayge)
    for _ in range(5):
        code = generate_code()
        cursor = await db.execute("SELECT id FROM urls WHERE short_code = ?", (code,))
        if not await cursor.fetchone():
            break  # we found a free one lesgooo
    else:
        # this runs if the for loop never broke (which means all 5 tries collided)
        # astronomically unlikely but i gotchu covered anyway
        await db.close()
        raise HTTPException(status_code=500, detail="Failed to generate unique code")

    await db.execute("INSERT INTO urls (short_code, original_url) VALUES (?, ?)", (code, original_url))
    await db.commit()  # commit or quit amirite
    await db.close()
    return ShortenResponse(short_code=code, short_url=f"{request.base_url}{code}")


@app.get("/{short_code}")
async def redirect(short_code: str, request: Request):
    # this is where the magic happens (aka redirect)
    # if u see 404 it means someone sneezed on the server
    db = await get_db()
    cursor = await db.execute("SELECT original_url FROM urls WHERE short_code = ?", (short_code,))
    row = await cursor.fetchone()
    if not row:
        await db.close()
        raise HTTPException(status_code=404, detail="Short code not found")  # sad reacts only

    # log the click so we can flex later
    await db.execute("INSERT INTO clicks (short_code, user_agent, referrer) VALUES (?, ?, ?)",
                     (short_code, request.headers.get("user-agent", ""), request.headers.get("referer", "")))
    await db.commit()
    await db.close()
    return RedirectResponse(url=row[0], status_code=307)  # bye bye, go to ur destination


@app.get("/{short_code}/stats", response_model=ClickStats)
async def stats(short_code: str):
    # this shows how many ppl clicked ur link
    db = await get_db()
    cursor = await db.execute("SELECT original_url, created_at FROM urls WHERE short_code = ?", (short_code,))
    row = await cursor.fetchone()
    if not row:
        await db.close()
        raise HTTPException(status_code=404, detail="Short code not found")  # again, sad

    cursor = await db.execute("SELECT COUNT(*) FROM clicks WHERE short_code = ?", (short_code,))
    count_row = await cursor.fetchone()
    await db.close()
    return ClickStats(short_code=short_code, original_url=row[0], total_clicks=count_row[0], created_at=row[1])

# run the server directly
uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)