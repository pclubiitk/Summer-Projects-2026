from fastapi import HTTPException, Depends
from fastapi.security import HTTPBasic, HTTPBasicCredentials

security = HTTPBasic()

def authenticate(credentials: HTTPBasicCredentials = Depends(security)):
    if credentials.username != "admin" or credentials.password != "password":
        raise HTTPException(status_code=401, detail="Unauthorized")
    return True