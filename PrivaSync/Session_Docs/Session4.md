---
title: Privasync Session 4 notes

---

# Privasync Session 4 notes

### **Data Transformation** 
It is the process of converting data from one format, structure, or representation into another so it can be stored, analyzed, transmitted, or used by applications.

---


## Types of Data Transformation Techniques
### 1. Hashing:
Hashing coverts an input of any size into a fixed size string of characters using a mathematical algorithm. 
Importantly, it is irreversible i.e you cannot practically recover the original data from the hash.The conversion leads to information loss of the original input. A tiny change in the input produces a completely different hash.
Real world applications include Cryptography, Database indexing, Caches, etc.

### 2. Encryption
Converting readable (plaintext) input into encrypted output (ciphertext) is called encryption. Unlike hashing, the ciphertext can be decoded by a unique decryption key.
There are two types of encryption:
#### 1. Symmetric Encryption:
Same key is used for encyption as well as decryption. So anyone who has the key would be able to read the scrambled text.
> Plaintext -- Key --> Ciphertext (Encryption)
> Ciphertext -- Key --> Plaintext (Decryption)

#### 2. Asymmteric Encryption
As the name states, different keys, public and private, are used for encryption and decryption. A person who has access to just the public communication won't be able to hence decode it. Due to the obviously better security, asymmetric encryption is used in majority of the internet security protocols.
> Plaintext -- Public Key --> Ciphertext (Encryption)
> Ciphertext -- Private Key --> Plaintext (Decryption)

### 3. Encoding
Often incorrectly used synonymous to encryption, encoding is used to transform data with a different motive. It is the process to transform data in a format easily readable by different systems. That is, the algorithm to decode the data is publicly available. 
No confidential key is required here, for the **aim is data representation**, **not data security**.It is reversible.
This process is used to ensure the integrity and usability of data. A real life example is sending attachments (eg: image, pdf) with emails as binary files.
Popular algorithms include Base64 for binary to text encoding,UTF8 for character encoding, ASCII.

---
## Salting
Some tables known as "rainbow tables" have already been compiled by people containing precomputed hashes formed from common passwords. To get into a user's profile, they just have to match their hashes with the one in the backend (basically, brute force, but they may just get it in the end). This could lead to a serious security issue.
Hence, as a workaround, some extra characters are introduced after your password and then the entire string is hashed. The hash of the salt is compared with a DB in the backend and your password's hash is also verified. These extra random characters increase your password's security and render rainbow tables useless.

---
## JSON Web Tokens (JWT)
JWT is a secure way to send information between a client and a server. It is mainly used in APIs to enchance security and prevent unauthorized access.

A JWT consists of 3 parts separated by dots.
> Header.Payload.Signature

### 1. Header
Header includes the signing algorithm (eg: RS256) and the token type (always JWT)
```
{
    "alg": "RS256",
    "typ": "JWT"
}
```
This is then encoded in Base64.

### 2. Payload
Payload contains information about the user (claims). Their id, session expiry token, audience, role, and many more claims.
```
{
    "userID": 5678
    "role": "admin"
    "exp": 1384387490
}
```
This, too, is encoded in Base64.

### 3. Signature
This involves combining encoded-header.encoded-payload and transforming it using an algorithm (HMAC or hashing). This is again encoded in Base64 and added to the token.

Final token looks like:
> Encoded-Header.Encoded-Payload.Encoded-Signature

JWT is generated in the backend and then sent to the client. Here, validity and comparision of signatures is done for secure access.

---
## Stateful VS Stateless systems
These are the types in which system deals with the client data across sessions during interactions.
### Stateful
A stateful system retains the user context across sessions. For example, if you add an item to your shopping cart, it is remembered in all the sessions.

### Stateless
Server doesn't know the current 'state' of the user. It doesn't store any client session info. Each request from the client is treated as an independent transaction. 
JWT is stateless.
One disadvantage comes forth in such a case: Once a JWT is issued, it is valid for approx. 30 minutes. But if you get banned from the server after 10 minutes, JWT will continue to get validated till the 30 minutes have passed.

---
## Client-side storage
This allows some data to be stored locally on user's computer rather than sending everythig to the server.
This enables offline access, reduces server load and enchances performance.
Some storage options highlighted in the session:
1. **Session Storage**: this is tab specific, i.e if I have two separate tabs open, they will be treated as two different sessions. Hence, it is used for single-session tracking. 
2. **Local Storage**: not tab specific. Can include theme preferences, draft autosaves, etc.
3. **Cookies**: not tab specific. Used to store site data. They have an expiry of some days, but they are stateful. JWTs are often stored in cookies to get browser-level security, along with maintaining their stateless property.


---
## OAuth
Often while logging in to some third-party applications, we use popular sign in methods, eg: Signing in with Google or LinkedIn or GitHub or Facebook (if anyone still uses this XD).
This uses Open Authorization (OAuth). Basically, we verify our identity using the credentials of an application we trust. So, we log into the third-party application without ever giving our password. The process goes like this:
> Third party applications ---> main trusted provider (e.g. google)---> permission given--->  main provider issues an access token to third party ---> user logs into third party app without ever having users password

OAuth shouldn't be confused with SSO (Single-SignOn). They are complementary to  each other, but solve different issues in modern identity management. 
SSO does **Authentication**, i.e. verifies the user and the third-party app.
OAuth does **Authorization**, i.e. entails what all the third-party app as well as the user is allowed to do with all the available data.

Example (unrelated to third party OAuth login): 
User is *authenticated* to view pages but not *authorized* to be admin, so cant view admin related pages.

---
## Two techiques to improve client UX

### 1. Lazy-loading
It "scans the scroll", i.e. as user scrolls down, the images/ components will load, rather than loading the entire page at once. So, the off-screen components aren’t loaded.
Although this is optimal for infinite scrolling, user finds it hard to bookmark a specific spot or find the website's footer. 
Used in casual scrolling, social media, image galleries etc.

### 2. Pagination
Loads data in pre-defined chunks. To view more, you have to click on buttons like "Next" or "Previous". In such cases, indexing can be done easily and the user is in control of their location. But it requires the user to click a button and wait until the entire page loads for the next batch of results.
Used in email apps, e-commerce product listings.


