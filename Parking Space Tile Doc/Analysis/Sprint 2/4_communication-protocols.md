# Embedded Communication Protocols Analysis

This page provides an overview of the most important communication protocols for embedded systems. The goal is to minimize the number of required pins and ensure the expandability of the [Parking Tile](https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/d01377dc529f039666e19c4d236781c5d39156a1/docs/parking%20space%20tile/1_parking-road.md) system. The choice of protocol depends on the [specific use case](https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/main/docs/parking%20space%20tile/5_tile%20design.md?ref_type=heads).

## Overview

1. [Introduction](#1-introduction)
2. [UART (Serial)](#2-uart-serial)
3. [I2C (Inter-Integrated Circuit)](#3-i2c-inter-integrated-circuit)
4. [SPI (Serial Peripheral Interface)](#4-spi-serial-peripheral-interface)
5. [CAN (Controller Area Network)](#5-can-controller-area-network)
6. [References](#6-references)

## 1. Introduction

To scale the Parking Tile system from a single prototype to a network of connected tiles, efficient communication is essential. A key challenge is to minimize the microcontroller's pin usage while still allowing easy expansion with additional sensors, tiles, and features.

At the same time, the system should be able to send real-time data to a backend for monitoring and visualization. This requires both efficient internal communication and reliable external connectivity.

This analysis evaluates various communication protocols in terms of scalability, pin efficiency, and integration potential to determine the most suitable approach for the Parking Tile system.

## 2. UART (Serial)

UART stands for "Universal Asynchronous Receiver-Transmitter" [2]

- Requires only 3 wires: **TX** (Transmit), **RX** (Receive), **GND** (Ground) [1]
- Asynchronous serial communication [1]
- Operates at a fixed baud rate [1]
- Commonly used for debugging/logging [1]

### 2.1 Key Parameters [1]

| Parameter    | Meaning                                |
| ------------ | -------------------------------------- |
| Baud rate    | Number of bits transmitted per second  |
| Data bits    | Number of data bits                    |
| Stop bits    | End of a data frame                    |
| Parity bit   | Error detection during transmission    |
| Flow Control | Protection against overflow (optional) |

### 2.2 Advantages & Disadvantages for Parking Tile [3]

| Advantages                  | Disadvantages                   |
| --------------------------- | ------------------------------- |
| Simple wiring (3 wires) [1] | Only connects two devices [1,3] |
| Easy debugging [1,3]        | No device addressing [1,3]      |
| Common on ESP32 [3]         | Not scalable for multi-tile [3] |

## 3. I2C (Inter-Integrated Circuit)

I2C is a serial communication protocol that allows multiple devices (tiles, sensors, displays) to communicate over just two lines (SDA, SCL). It is commonly used to connect microcontrollers with various peripherals in embedded systems. [4]

### 3.1 Advantages & Disadvantages for Parking Tile [5]

| Advantages                     | Disadvantages                  |
| ------------------------------ | ------------------------------ |
| 2 wires for many devices [4,5] | Slower than SPI [4,5]          |
| Device addressing [4,5]        | Needs pull-up resistors [4,5]  |
| Easy to expand tiles [5]       | Limited cable length [4,5]     |
| ESP32 support [5]              | Address conflicts possible [5] |

## 4. SPI (Serial Peripheral Interface)

The Serial Peripheral Interface (SPI) protocol is used for fast data transfer in embedded systems. Further information can be found in the reference section. [6]

### 4.1 Comparison [6,7]

| Advantages                | Disadvantages                   |
| ------------------------- | ------------------------------- |
| Very fast transfer [6,7]  | Needs many wires [6,7]          |
| Good for fast sensors [7] | Not scalable for many tiles [7] |
| Simple protocol [6]       | No device addressing [6,7]      |
| Full duplex [6]           | High pin usage on ESP32 [7]     |

## 5. CAN (Controller Area Network)

The Controller Area Network short for CAN is a serial bus (communication) system for vehicles and maschines. Further information can be found in the reference section. [8,9]

### 5.1 Comparison [8,9]

| Advantages                | Disadvantages                      |
| ------------------------- | ---------------------------------- |
| Reliable, robust [8,9]    | Needs extra CAN hardware [8,9]     |
| Good for many devices [8] | Complex for Parking Tile [8,9]     |
| Error detection [8,9]     | Overkill for small tile system [9] |
| Industrial standard [8]   | More parts than I2C/SPI [8,9]      |

## Recommendation

Based on the analysis above, I2C is the recommended communication protocol for the Parking Tile system. I2C offers an optimal balance between pin efficiency, expandability, and ease of integration. With only two wires required for communication and built-in device addressing, I2C allows for straightforward expansion as more sensors or tiles are added. It is widely supported by microcontrollers and peripheral devices, making it a practical and scalable choice for both prototyping and future development. While SPI and CAN have their own advantages, they either require more pins or add unnecessary complexity for this use case. UART, while simple, does not support multi-device communication as efficiently as I2C.

## Conclusion

For the Parking Tile system, I2C stands out as the most suitable protocol. It minimizes wiring complexity, supports multiple devices, and is well-supported in the embedded ecosystem. Adopting I2C will ensure the system remains scalable, maintainable, and easy to expand as new features or sensors are introduced.

## 6. References

[6. References](#6-references)

[1] UART Serial Communication Guide: Principles, Parsing & Visualization, Fr2ed0m, [devresourcehub.com](https://devresourcehub.com/uart-serial-communication-guide-principles-parsing-visualization.html), accessed 26.03.2026

[2] Universal asynchronous receiver-transmitter, [Wikipedia](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter), accessed 26.03.2026

[3] Basics of UART Communication, Scott Campbell, https://www.circuitbasics.com/basics-uart-communication/, accessed 26.03.2026

[4] I2C Communication Protocol, https://www.geeksforgeeks.org/computer-organization-architecture/i2c-communication-protocol/, accessed 26.03.2026

[5] Basics of the I2C Communication Protocol, https://www.circuitbasics.com/basics-of-the-i2c-communication-protocol/, accessed 26.03.2026

[6] What is Serial Peripheral Interface (SPI)?, https://www.geeksforgeeks.org/electronics-engineering/what-is-serial-peripheral-interface-spi/, accessed 31.03.2026

[7] Basics of the SPI Communication Protocol, https://www.circuitbasics.com/basics-of-the-spi-communication-protocol/, accessed 31.03.2026

[8] Controller Area Network (CAN) Protocol Overview, https://www.ni.com/en/shop/seamlessly-connect-to-third-party-devices-and-supervisory-system/controller-area-network--can--overview.html, accessed 31.03.2026

[9] CAN Bus Explained - A Simple Intro [2025], https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial, accessed 31.03.2026
