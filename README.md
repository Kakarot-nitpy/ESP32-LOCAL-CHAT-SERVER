# ESP32 Local Chat Server

## Overview

The **ESP32 Local Chat Server** is a real-time messaging application built using the ESP32 microcontroller. The ESP32 acts as a Wi-Fi Access Point and hosts a web-based chat interface, allowing multiple users connected to the same network to exchange messages without requiring an internet connection.

## Features

* ESP32 Wi-Fi Access Point (AP Mode)
* Browser-based chat interface
* Real-time communication using WebSockets
* Supports multiple connected users
* No internet connection required
* Lightweight and responsive design
* Easy to deploy and expand

## Hardware Requirements

* ESP32 Development Board
* USB Cable
* Breadboard (optional)
* Jumper Wires (optional)

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WebSockets Library
* Web Browser (Chrome, Edge, Firefox, etc.)

## How It Works

1. The ESP32 creates its own Wi-Fi hotspot.
2. Users connect their devices to the ESP32 network.
3. The ESP32 hosts a web page containing the chat interface.
4. Messages are transmitted in real time using WebSockets.
5. Every connected client instantly receives new messages.

## Applications

* Offline communication systems
* Classroom and laboratory demonstrations
* Embedded networking projects
* IoT communication prototypes
* Disaster recovery or local communication networks

## Future Enhancements

* User authentication
* Private messaging
* Chat history storage
* File sharing
* End-to-end encryption
* Emoji support
* Message timestamps

## Technologies Used

* ESP32
* C++
* Arduino Framework
* Wi-Fi Networking
* HTTP Server
* WebSockets
* HTML
* CSS
* JavaScript

## Author

Developed as an embedded networking project using the ESP32 platform to demonstrate real-time local communication over Wi-Fi.
