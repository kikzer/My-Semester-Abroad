# Communication to Backend

This document describes how the ESP32 parking tile communicates with the backend server via WebSocket.

---

## WebSocket Endpoint

```
ws://<backend-ip>:5000/ws/{device_id}
```

---

## ESP32 WebSocket Example

```cpp
#include <WiFi.h>
#include <WebSocketsClient.h>

const char* WIFI_SSID = "your-wifi-ssid";
const char* WIFI_PASSWORD = "your-wifi-password";

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("Connected!");
      webSocket.sendTXT("{\"type\":\"hello\",\"token\":\"TOKEN_PARKING\"}");
      break;
    case WStype_TEXT:
      Serial.printf("Received: %s\n", payload);
      break;
    case WStype_DISCONNECTED:
      Serial.println("Disconnected!");
      break;
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  webSocket.begin("192.168.178.100", 5000, "/ws/parking_tile");
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
}
```

### Required Library

Install via Arduino Library Manager:

- **WebSockets** by Markus Sattler

> **Reference:** [Random Nerd Tutorials – ESP32 WebSocket Server](https://randomnerdtutorials.com/esp32-websocket-server-arduino/)  
> This tutorial explains WebSocket concepts and provides step-by-step examples for ESP32.

---

## Backend Configuration

To register the parking tile in the backend, add it to `config.yaml`:

```yaml
devices:
  parking_tile_1:
    ip: "192.168.178.50"
    secret: "PARKING_SECRET"
    token: "TOKEN_PARKING"
```

---

## Data Flow Diagram

```
┌─────────────────┐                                              ┌─────────────────┐
│                 │                                              │                 │
│   ESP32         │          WebSocket /ws/parking_tile        │    Backend      │
│   Parking Tile  │ ◀─────────────────────────────────────────▶  │    Server       │
│                 │                                              │                 │
└─────────────────┘                                              └─────────────────┘
        │                                                                 │
        │  Ultrasonic                                                     │
        │  Sensor Data                                                    │
        ▼                                                                 ▼
   ┌─────────┐                                                    ┌─────────────┐
   │ HC-SR04 │                                                    │  Database   │
   └─────────┘                                                    │  / Logs     │
                                                                  └─────────────┘
```
