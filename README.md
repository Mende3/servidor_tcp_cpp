📡 Small Server in C++

This project is a small server developed in C++, designed to provide multiple features and functionalities, despite not being a large-scale server.

Since this server is not intended to handle high traffic or multiple concurrent requests, it was designed using the Singleton design pattern, ensuring that only one network instance exists throughout the application’s lifecycle.

Using the Singleton pattern helps to:

Maintain strict control over the network instance

Centralize networking logic

Reduce complexity for small to medium-sized applications

This server is suitable for use cases such as:

Local applications

Internal tools

Prototypes and architectural studies in C++
