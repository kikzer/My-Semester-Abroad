# Parking Tile

## 1. General Description

This tile represents a straight road with four additional parking spaces. There are two on each side. Each parking space has a smart feature that detects whether it is occupied or empty. When a space is empty, a green light signals to drivers that the space is available. If a space is occupied, a red light appears. Additionally, two displays on both sides of the street visually show the remaining free parking spots.


## 2. Overview

- **Tile size:** 30 × 30 cm
- **Road layout:** Straight road with 4 parking spaces (2 on each side)
- **Sensors:** Each parking space has a smart sensor connected to an Arduino
- **Light indicators:**
  - Green → space available
  - Red → space occupied
- **Displays:** Two digital displays (one on each side of the street) showing the number of free parking spots
- **Purpose:** Demonstrates a compact sensor-based parking management system for smart city simulation


## 3. Functional Requirements

## Functional Requirements

- The tile features a straight road.
- There are two parking spaces on each side of the road.
- Each parking space is marked with a "P" symbol.
- Each parking space is equipped with a sensor that detects whether it is occupied or free.
- Each parking space has two LEDs (red, green), that indicate occupation or not
- Each side of the road has a digital display showing the number of remaining free parking spaces.


## 4. Non-Functional Requirements

- The system should be easily expandable to include more parking spaces.
- The LEDs and displays should be constantly illuminated
- The sensors should detect the status of the parking spaces in about a second and update the display and LED


## 5. Contributer

My name is Niklas Kiess, and I am a German exchange student in Amsterdam. During my studies at my home university, I focused solely on software, so I have no experience with Arduino coding or hardware coding in general. To change that, I chose to study robotics and embedded systems to broaden my horizons. The parking space project allows me to work on software and hardware to create a parking lot management system.
