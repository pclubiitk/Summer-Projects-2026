---
title: Session2.md

---

#    Priva-Sync Session 2 - Backend and FastAPI

## Backend
### Protocols

Understood the working of network protocols. Studied HTTP and WebSockets in detail. gRPC and WebRTC are some other protocols
#### HTTP
HTTP stands for Hypertext Transfer Protocol, and it’s the system that allows communication between web browsers (like Google Chrome or Firefox) and web servers.

HTTP is a set of rules that lets your browser and web server communicate, ensuring websites load correctly.
When you visit a website, your browser uses HTTP to send a request to the server hosting that site, and the server sends back the data needed to display the page.
1. https://www.geeksforgeeks.org/blogs/http-full-form/
2. https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Overview

#### Web Sockets
Web applications handle data in two main ways: non-real-time, where updates occur only when the client requests them, and real-time, where information is delivered instantly as it changes. Choosing the right communication protocol is important for performance and user experience.

HTTP is used for non-real-time communication where the client requests data when needed.
WebSocket is used for real-time communication where data is delivered instantly between client and server.

1. https://www.geeksforgeeks.org/web-tech/what-is-web-socket-and-how-it-is-different-from-the-http/
2. https://developer.mozilla.org/en-US/docs/Web/API/WebSockets_API
#### gRPC
1. https://grpc.io/docs/what-is-grpc/introduction/
2. https://www.geeksforgeeks.org/software-engineering/what-is-grpc/
#### WebRTC
1. https://webrtc.org
2. https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API
3. https://www.geeksforgeeks.org/techtips/introduction-to-webrtc/

### HTTP Methods
#### GET
The GET method requests a representation of the specified resource. Requests using GET should only retrieve data and should not contain a request content.
#### POST
The POST method submits an entity to the specified resource, often causing a change in state or side effects on the server.
#### PUT
The PUT method replaces all current representations of the target resource with the request content.
#### DELETE
The DELETE method deletes the specified resource.

#### Other Methods: HEAD, CONNECT, OPTIONS, TRACE, PATCH
https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Methods

### Gateway Interfaces: ASGI v/s WSGI
1. https://medium.com/@commbigo/wsgi-vs-asgi-for-python-web-development-9d9a3c426aa9
2. https://dev.to/leapcell/wsgi-vs-asgi-the-crucial-decision-shaping-your-web-apps-future-in-2025-3pcd
## Building backend servers in Python using FastAPI
### OOPS
Object Oriented Programming empowers developers to build modular, maintainable and scalable applications. OOP is a way of organizing code that uses objects and classes to represent real-world entities and their behavior. In OOP, object has attributes thing that has specific data and can perform certain actions using methods.
#### Properties of OOPS: 
**Encapsulation**
Encapsulation is the bundling of data (attributes) and methods (functions) within a class, restricting access to some components to control interactions. A class is an example of encapsulation as it groups together member functions, variables and other related data in a single unit.

**Abstraction**
Abstraction hides the internal implementation details while exposing only the necessary functionality. It helps focus on "what to do" rather than "how to do it."

**Inheritance**
Inheritance allows a class (child class) to acquire properties and methods of another class (parent class). It supports hierarchical classification and promotes code reuse.

**Polymorphism**
Polymorphism means "same operation, different behavior." It allows functions or methods with the same name to work differently depending on the type of object they are acting upon.

#### Classes v/s Objects

**Class**
A class is a collection of objects. Classes are blueprints for creating objects. A class defines a set of attributes and methods that the created objects (instances) can have.  

**Object**
An Object is an instance of a Class. It represents a specific implementation of the class and holds its own data.

An object consists of:
**State:** represented by the attributes and reflects the properties of an object.
**Behavior:** represented by the methods of an object and reflects the response of an object to other objects.
**Identity:** gives a unique name to an object and enables one object to interact with other objects.

1. https://www.geeksforgeeks.org/python/python-oops-concepts/

### Decorators
Decorators are flexible way to modify or extend behavior of functions or methods, without changing their actual code.

A decorator is essentially a function that takes another function as an argument and returns a new function with enhanced functionality.

They are often used in scenarios such as logging, authentication and memoization, allowing us to add additional functionality to existing functions or methods in a clean, reusable way.

1. https://www.geeksforgeeks.org/python/decorators-in-python/?utm_source=copilot.com

### FastAPI

FastAPI is a modern and high-performance Python web framework used to build APIs quickly and efficiently. Designed with simplicity it allows developers to create RESTful APIs using Python's type hints which also enable automatic validation and error handling.

1. https://dorian599.medium.com/fastapi-getting-started-3294efe823a0
2. https://fastapi.tiangolo.com/tutorial/first-steps/

#### Why use FastAPI

1. https://medium.com/featurepreneur/why-fastapi-69fb172756b7

#### Comparison with Django and Flask

**Django:** Django is a full-stack web framework written in Python. It follows MTV (Model-Template-View) architectural pattern and promotes DRY principle (Don’t Repeat Yourself).

**Flask:** Flask is a micro web framework written in Python. Unlike Django, it doesn’t come with many built-in tools; instead, it gives developers flexibility to choose their own libraries.

1. https://www.geeksforgeeks.org/python/comparison-of-fastapi-with-django-and-flask/

#### Dependency injection in FastAPI
FastAPI has a very powerful but intuitive Dependency Injection system.

It is designed to be very simple to use, and to make it very easy for any developer to integrate other components with FastAPI.

##### What is "Dependency Injection"

"Dependency Injection" means, in programming, that there is a way for your code (in this case, your path operation functions) to declare things that it requires to work and use: "dependencies".

And then, that system (in this case FastAPI) will take care of doing whatever is needed to provide your code with those needed dependencies ("inject" the dependencies).

##### Why do we need dependency injections?

This is very useful when you need to:

1. Have shared logic (the same code logic again and again).
2. Share database connections.
3. Enforce security, authentication, role requirements, etc.

And many other things...
All these, while minimizing code repetition.
1. https://fastapi.tiangolo.com/tutorial/dependencies/
2. https://www.geeksforgeeks.org/python/dependency-injection-in-fastapi/

