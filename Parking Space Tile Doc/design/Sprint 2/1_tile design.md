
# Tile Design

## Table of Contents

1. Context, Requirements, and Problem Statement
2. Introduction
3. Layout Overview
4. Component Summary
5. Parking Space Design
6. Display Placement
7. Detection Principle
8. Wiring Diagram
9. Communication with the Backend
10. Conclusion and Recommendation

## 1. Context, Requirements, and Problem Statement

**Context:**
This document is part of a smart city simulation project, focusing on the design of a modular parking lot tile. The tile is intended for use in educational and prototyping environments, where real-time detection and display of parking space availability are required.

**Requirements:**
- Detect the presence of vehicles in parking spaces reliably in all lighting conditions
- Indicate parking space status visually
- Display the number of available spaces in real-time
- Use modular, easily replaceable components
- Ensure the design is suitable for demonstration and learning purposes

**Target Audience:**
- Students and educators in smart city, IoT, and embedded systems courses
- Developers and researchers prototyping smart parking solutions

**Problem Statement:**
Efficiently managing and communicating parking space availability is a common challenge in urban environments. The goal is to design a tile that can detect occupancy, provide clear visual feedback, and display aggregated information to users, supporting both learning and prototyping needs.
## 2. Introduction

This document provides an overview of the design and functionality of the parking lot tile used in the smart city simulation project. The parking tile is a modular unit designed to detect vehicle presence, indicate parking availability, and display real-time information about free spaces. It integrates sensors, LEDs, and displays to create an interactive and informative parking solution suitable for educational and prototyping environments. The following sections detail the physical layout, components, detection principles, and wiring of the tile.

## 3. Layout Overview

![alt text](../../../assets/TileDesign.png)

**Parking orientation:** Parallel to the street (lengthwise)

## 4. Component Summary

| Component                          | Quantity | Purpose                                      |
|-----------------------------------|----------|----------------------------------------------|
| **Ultrasonic Sensor (HC-SR04)**   | 4        | Detect parking occupancy via distance measurement |
| **RGB LED**                       | 4        | Indicate space status (placed on the side, replaces red/green LEDs; to be added) |
| **Display**                       | 2        | Show number of free spaces (1× left, 1× right) |

## 5. Parking Space Design

Each of the four parking spaces includes:

| Component             | Position    | Description                                                    |
| --------------------- | ----------- | -------------------------------------------------------------- |
| **"P" Symbol**        | Center      | Visual marking to identify parking spot                        |
| **Ultrasonic Sensor** | Under "P"   | Detects whether the space is occupied via distance measurement |
| **RGB LED**           | Side of tile | Will indicate space status (available/occupied) with color; to be added |

## 6. Display Placement

- **Display 1:** Located on the **right side** of the road
- **Display 2:** Located on the **left side** of the road

Both displays show the **number of free parking spaces** (0–4) in real-time.

## 7. Detection Principle

The **Ultrasonic sensors (HC-SR04)** work by measuring distance:

- Each sensor is positioned in the ground of the parking space pointing updwards
- When a car is present, the measured distance is **short** (object detected)
- When the space is free, the measured distance is **long** (no object)
- A configurable **threshold distance** (e.g., 10 cm) determines occupancy
- This method works **reliably in all lighting conditions**

## 8. Wiring Diagram

![alt text](../../../assets/ParkingTileWiring.png)

### Description:

- Red = Power
- Black = Ground
- Purple = Echo
- Yellow = Trigger
- Cyan = SCL
- Ocker = SDA
- Pink = RGB Red Connection
- Green = RGB Green Connection
- Resistor = 220 Ohm
- Oled is not the in use, because there is no model in fritzing for it


## 9. Communication with the Backend

![alt text](../../../assets/BackendCommunication.png)

The following diagram illustrates the interaction between the embedded system (parking tile) and the backend:

**System Overview:**

- The **Ultrasonic Sensor** detects whether a car is present in a parking space (True or False).
- The sensor's status is sent to the **RGB LED**, which visually indicates the parking space status (green or red light).
- The **OLED Display** shows the current status of the parking tile, specifically the number of free slots using the information given by the backend.
- The embedded system sends the current parking lot status to the **backend**.
- The **backend** is responsible for:
	- Saving parking lot status logs
	- Storing the total number of available parking lots
	- Tracking the number of occupied parking lots
	- Sending the current number of free parking lots back to the embedded system for display on the OLED

This communication ensures that the parking tile provides real-time feedback to users, and keeps the backend updated for further processing and data logging. For more information on how the backend communicates with the embedded system, look into the Backend documentation.


## 10. Conclusion and Recommendation

The parking tile design addresses the need for real-time, reliable detection and communication of parking space availability in a modular and educational format. By placing RGB LEDs on the side of the tile, the design improves visibility and flexibility for indicating different statuses. It is recommended to proceed with the integration of RGB LEDs and to further develop the display logic for enhanced user feedback. This design is well-suited for smart city demonstrations and as a learning tool for IoT and embedded systems.

**Note:** This diagram and description represent a top view of the parking tile.

**Retrieval date:** April 6, 2026
