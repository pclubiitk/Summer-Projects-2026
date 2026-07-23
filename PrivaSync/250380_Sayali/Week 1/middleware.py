from fastapi import HTTPException, Depends
from fastapi.security import HTTPBasic, HTTPBasicCredentials
 
# HTTPBasic tells FastAPI to expect a username + password in the request headers.
security = HTTPBasic()
 
def authenticate(credentials: HTTPBasicCredentials = Depends(security)):
    """
    Dependency checkpoint for protected routes.
    1. If credentials are wrong : 401 Unauthorized (endpoint never runs).
    2. If credentials are correct : endpoint runs normally.
    """
    correct_username = "admin"
    correct_password = "bookstore123"
 
    if credentials.username != correct_username or credentials.password != correct_password:
        raise HTTPException(
            status_code=401,
            detail="Invalid credentials. Access denied."
        )
 
    return True   # signals "authentication passed" to the endpoint
