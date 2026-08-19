# Board Design

**Author:** Niklas Kiess, Junior Embedded & Robotics Developer  
**Date:** 02.06.2026  
**Version:** V0.3  
**Target Audience:** Technically skilled Urban Planner / Smart City Technology Officer

**Note: This document contains proprietary information and is intended solely for internal use by the development team and authorized stakeholders. Unauthorized distribution, reproduction, or external sharing is strictly prohibited.**

# Table of Contents

- [1. Summary](#1-summary)
- [2. Introduction](#2-introduction)
  - [2.1 Main Question](#21-main-question)
  - [2.2 Sub Questions](#22-sub-questions)
- [3. How can the selected hardware components support the functional requirements of the Parking Tile?](#3-how-can-the-selected-hardware-components-support-the-functional-requirements-of-the-parking-tile)
  - [3.1 Requirements Considered](#31-requirements-considered)
  - [3.2 Bill of Materials (BOM)](#32-bill-of-materials-bom)
  - [3.3 Sub Conclusion](#33-sub-conclusion)
  - [3.4 Power Requirements](#34-power-requirements)
- [4. How does the protoboard layout support reliable operation and integration of all components?](#4-how-does-the-protoboard-layout-support-reliable-operation-and-integration-of-all-components)
  - [4.1 Board Layout Overview](#41-board-layout-overview)
  - [4.2 Wiring Diagram](#42-wiring-diagram)
    - [4.2.1 Wiring Legend](#421-wiring-legend)
  - [4.3 Sub Conclusion](#43-sub-conclusion)
- [5. Why is the selected protoboard approach suitable for the current development phase?](#5-why-is-the-selected-protoboard-approach-suitable-for-the-current-development-phase)
  - [5.1 Sensor Integration](#51-sensor-integration)
  - [5.2 Visual Feedback](#52-visual-feedback)
    - [5.2.1 Positioning](#521-positioning)
  - [5.3 Communication and Processing](#53-communication-and-processing)
  - [5.4 Display Integration](#54-display-integration)
  - [5.5 Maintainability and Expansion](#55-maintainability-and-expansion)
  - [5.6 Sub Conclusion](#56-sub-conclusion)
- [6. Conclusion](#6-conclusion)
- [7. Recommendation](#7-recommendation)
- [8. References](#8-references)

# 1. Summary

This document describes the design and implementation of the protoboard used for the Parking Tile project. The board integrates an ESP32-S3 microcontroller, an ultrasonic sensor, an RGB LED module, and an OLED display into a modular and maintainable hardware solution.

The purpose of the design is to provide reliable parking space detection, real-time visual feedback, and communication with backend systems while remaining flexible for rapid prototyping and future expansion.

The selected protoboard approach supports quick assembly, low manufacturing cost, and easy modification during development. The document also provides an overview of the physical layout, component selection, wiring structure, and implementation considerations.

# 2. Introduction

This document is part of a smart city simulation project aimed at developing a scalable, modular, and real-time parking space monitoring system. The core component of this system is the Parking Tile, a physical prototype representing an individual parking space that can detect vehicle presence, display its occupancy status, and communicate with a central backend system.

The project is structured using Agile development methodology, specifically through time-boxed development cycles known as sprints. In this context, a sprint refers to a short, focused period (3 weeks) during which a specific set of development goals is achieved. Each sprint includes analysis, advise, design, and realise phases, enabling rapid iteration and continuous improvement.

In the current sprint, the focus shifted from high-level system architecture and circuit board selection to the hardware design of the Parking Tile. After evaluating various implementation options, including custom PCBs, pre-fabricated modules, and off-the-shelf development boards, a perfboard/protoboard approach was selected. This decision was driven by the need for rapid prototyping, modular component integration, and flexibility during testing, while remaining within the constraints of the sprint timeline and project budget. [7]

The proposed design integrates an ESP32-S3 microcontroller as the central processing unit, an HC-SR04 ultrasonic sensor for distance-based vehicle detection, a KY-016 RGB LED module for visual feedback, and an SSD1306 I2C OLED display for status visualization. The arrangement and interconnection of these components were designed to support reliable operation, maintainability, and future expansion.

This document focuses on the design of the Parking Tile protoboard and describes the rationale behind the selected components, board layout, wiring structure, and integration approach. Furthermore, it explains how the design supports the functional requirements of the system and provides a foundation for implementation, testing, and future development.

## 2.1 Main Question

**How can a protoboard-based hardware design provide a modular, maintainable, and functional foundation for the Parking Tile prototype within the constraints of the current sprint?**

## 2.2 Sub Questions

1. How can the selected hardware components support the functional requirements of the Parking Tile?
2. How does the protoboard layout support reliable operation and integration of all components?
3. Why is the selected protoboard approach suitable for the current development phase?

# 3. How can the selected hardware components support the functional requirements of the Parking Tile?

## 3.1 Requirements Considered (MoSCoW Prioritization)

### Must Have
These requirements are essential for the Parking Tile to function correctly and meet project objectives.

- The Parking Tile must provide clear visual feedback about parking availability. [8]
- The system must support reliable sensor readings and stable communication. [9]
- Components must be easy to replace and maintain.
- The design must support backend-driven LED control and data logging.

### Should Have
These requirements are important and add significant value but are not critical for initial functionality.

- The board must support modular expansion and future upgrades.
- The hardware should remain robust during testing and repeated assembly.

### Could Have
These requirements are desirable if time and resources permit.

- Additional expansion interfaces for future sensors or peripherals.
- Enhanced durability features beyond the minimum testing requirements.

### Won't Have (for this iteration)
These requirements are intentionally excluded from the current scope.

- Features that cannot be implemented within the sprint timeline or project budget. [7]
- Non-essential hardware upgrades that do not directly support the current Parking Tile objectives.


## Bill of Materials (BOM) für Parking Tile Protoboard

| Item | Description | Manufacturer | Part Number | Supplier | Price (€) | Datasheet Reference | Qty | Subtotal (€) |
|------|-------------|--------------|-------------|----------|-----------|---------------------|-----|--------------|
| RGB LED Module | KY-016 RGB LED module with integrated resistors | AZ-Delivery | N/A | AZ-Delivery [2] | 2.63 | [Datasheet](https://cdn.shopify.com/s/files/1/1509/1638/files/KY-016_LED_RGB_Modul_AZ-Delivery_Vertriebs_GmbH.pdf?6046459410546974998) | 4 | 10.52 |
| OLED Display | SSD1306 I2C OLED display, 128×64 | SplitKB | N/A | SplitKB [9] | 6.99 | [Datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf) | 2 | 13.98 |
| Ultrasonic Sensor | HC-SR04 ultrasonic distance sensor | MULTICOMP PRO | HC-SR04 | Farnell [1] | 4.40 | [Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf) | 4 | 17.60 |
| Perfboard |  PCBs & Breadboards Solder-in breadboard 2x2" 2.00mm pitch plated holes  | Chip Quik |  SBBTH200P  | Mouser [5] | 4.12 | [Datasheet](https://www.farnell.com/datasheets/2326969.pdf) | 1 | 4.12 |
| Microcontroller | ESP32-S3 development board | Espressif Systems | N/A | AliExpress [6] | 5.39 | [Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf) | 1 | 5.39 |
| Wires | Jumper wires, headers, connectors, resistors | krtkl | 15102200 | Mouser Electronics [4] | 8.94 | N/A | As needed | 8.94 |
| **Total price per tile** |  |  |  |  |  |  |  | **60.55 €** |

Table 1  
*Bill of material for the parking tile*

*Note: Supplier links and product availability may change over time and should be verified before ordering.*

## 3.3 Sub Conclusion

The selected components address the functional requirements identified for the Parking Tile. Together, they provide the necessary capabilities for vehicle detection, visual feedback, communication, maintainability, and future expansion while remaining within the constraints of the project budget and sprint timeline.

## 3.4 Power Requirements

The Parking Tile system operates entirely on a 3.3V power architecture to ensure compatibility across all integrated components and to simplify power distribution on the protoboard.

### System Voltage Requirements

All major components in the system are designed to operate at 3.3V logic levels:

- **ESP32-S3:** 3.3V native logic
- **Ultrasonic sensor:** 3.3V supply
- **SSD1306 OLED display (I2C version):** 3.3V compatible
- **KY-016 RGB LED module:** operated at 3.3V with adjusted current limiting behavior or 3.3V-compatible variant

As a result, the entire Parking Tile system is powered via a **single 3.3V DC supply rail**, reducing the need for multiple voltage domains and improving system simplicity.

### Power Supply Recommendation

To ensure stable operation, each Parking Tile should be powered using:

- **Recommended supply voltage:** 3.3V regulated supply (high-current capable)
- **Minimum current rating:** 1A per tile
- **Preferred method:** External 3.3V regulator fed from 5V USB input or centralized 3.3V power bus

### Sub Conclusion

The Parking Tile operates on a unified 3.3V power architecture, simplifying design and improving modularity.

# 4. How does the protoboard layout support reliable operation and integration of all components?

## 4.1 Board Layout Overview

The protoboard layout was designed to prioritize modularity, maintainability, and ease of assembly. Components are positioned to simplify wiring and reduce signal interference between communication and power lines.

The ESP32-S3 microcontroller acts as the central control unit and manages communication between the ultrasonic sensor, RGB LED module, and OLED display. The sensor is positioned to allow unobstructed distance measurements, while the RGB LED provides direct visual feedback regarding parking availability.

The OLED display is connected through the I2C interface to minimize wiring complexity and reduce required GPIO usage. Power and ground lines are distributed consistently across the board to improve stability and simplify troubleshooting.

The design also allows future expansion through additional sensors or communication modules.

## 4.2 Wiring Diagram

The following wiring diagram illustrates the complete electrical connections between the ESP32-S3 microcontroller and all peripheral components on the protoboard. This schematic provides a visual reference for assembly, troubleshooting, and future modifications. All connections follow standard color-coding conventions to ensure clarity and reduce assembly errors.

![Wiring Diagram](../../../assets/ProtoBoardWiringDiagram.jpg)

Figure 1
Parking Tile Protoboard Wiring Diagram

### 4.2.1 Wiring Legend

- **Red** → Power (VCC)
- **Black** → Ground (GND)
- **Purple** → Ultrasonic Echo
- **Yellow** → Ultrasonic Trigger
- **Cyan** → I2C SCL
- **Ocher** → I2C SDA
- **Pink** → RGB Red Channel
- **Green** → RGB Green Channel

The original OLED display is not included in the wiring diagram because no compatible Fritzing model was available during documentation.

## 4.3 Sub Conclusion

The protoboard layout supports the integration of all required components through a structured arrangement of communication, power, and signal connections. The wiring organization and component positioning contribute to reliable operation, simplified assembly, and easier troubleshooting during development.

# 5. Why is the selected protoboard approach suitable for the current development phase?

## 5.1 Sensor Integration

The HC-SR04 ultrasonic sensor is used for reliable, low-cost vehicle detection in parking spaces [1]. Its narrow 15° detection cone minimizes interference from adjacent tiles and ensures accurate distance measurement within a single parking spot [11]. This makes it ideal for precise occupancy sensing in urban smart parking systems.

## 5.2 Visual Feedback

The KY-016 RGB LED module provides clear visual feedback regarding parking availability. The KY-016 was selected because it features integrated current-limiting resistors, which eliminates the need for external components and reduces wiring complexity. It can also be used for a different colour display if more features are added to the car park in the future. [12]

### 5.2.1 Positioning

The RGB LED module was intentionally mounted on the floor surface of the parking tile, directly beneath the tile’s top layer, rather than on a pole, wall, or overhead structure. This design choice was not a permanent architectural decision, but a deliberate experimental test to evaluate a novel visual feedback concept: Can a parking space be effectively signaled as occupied purely through bottom-up illumination — i.e., light shining upward from beneath the floor?

This test was conducted to explore the feasibility and impact of invisible, embedded lighting as a form of smart city infrastructure.

## 5.3 Communication and Processing

The ESP32-S3 microcontroller was selected because it provides the performance, connectivity, and flexibility required for the Parking Tile system. As the central controller, it is responsible for sensor data processing, backend communication, and LED control while maintaining reliable real-time operation.

One of the main advantages of the ESP32-S3 is its integrated Wi-Fi and Bluetooth 5.0 capabilities, which allow the Parking Tile to communicate directly with backend services without requiring additional communication hardware. This supports the project's smart city objectives and provides a foundation for future wireless features, such as remote monitoring, device management, and data collection.

The ESP32-S3 also offers a large number of GPIO pins (34+ usable), making it well suited for interfacing with the ultrasonic sensor, RGB LED, OLED display, and other potential peripherals. This eliminates the need for external I/O expansion hardware, reducing both system complexity and cost.

Furthermore, the dual-core processor provides sufficient computational resources to handle sensor measurements, LED control, display updates, and network communication simultaneously without compromising system responsiveness. This ensures reliable operation even as additional functionality is added in future iterations of the project.

The development board includes a USB Type-C interface, which simplifies firmware deployment, debugging, and maintenance throughout the development lifecycle. Combined with its extensive documentation, community support, and proven reliability in IoT applications, the ESP32-S3 represents a robust and scalable platform for the Parking Tile system. [13]

## 5.4 Display Integration

The SSD1306 OLED display was selected for its low power consumption, high contrast, and clear visibility in various lighting conditions—ideal for real-time parking status feedback. [3, 20] The I2C interface was preferred because it requires only two signal lines (SCL and SDA) for communication, significantly reducing wiring complexity compared to SPI or parallel interfaces. This is especially important on a protoboard with limited space and high component density.  
The I2C protocol also allows multiple devices to share the same bus, improving modularity and scalability. [15]

## 5.5 Maintainability and Expansion

The protoboard (perfboard) layout was selected to enable maximum flexibility during the prototyping phase. Unlike custom PCBs, which require full redesign for any change, the modular nature of the protoboard allows components to be easily unplugged, swapped, or upgraded without soldering or re-routing. [7]

## 5.6 Sub Conclusion

The protoboard approach supports the goals of the current development phase by enabling rapid prototyping, straightforward component integration, and flexibility for testing and modification. These characteristics make it suitable for the iterative development process used within the project.

# 6. Conclusion

This document examined how a protoboard-based hardware design can provide a modular, maintainable, and functional foundation for the Parking Tile prototype within the constraints of the current sprint.

The first sub question showed that the selected hardware components support the functional requirements of the Parking Tile by enabling vehicle detection, visual feedback, communication, maintainability, and future expansion.

The second sub question demonstrated that the protoboard layout supports reliable operation through organized wiring, structured power distribution, and effective integration of all required components.

The third sub question established that the protoboard approach is suitable for the current development phase because it supports rapid prototyping, easy modification, and iterative development.

Based on these findings, the main question can be answered as follows: the protoboard-based hardware design provides a modular, maintainable, and functional foundation for the Parking Tile prototype while meeting the practical constraints of the current sprint.

# 7. Recommendation

Based on the findings presented in this document, the current protoboard implementation is suitable for prototyping, educational demonstrations, and early-stage system validation.

For future iterations or larger-scale deployment, transitioning to a custom PCB design is recommended. A PCB-based solution would improve signal routing, manufacturing consistency, long-term reliability, and overall system organization while reducing manual wiring complexity.

This recommendation follows directly from the evaluation of the current protoboard implementation and its intended role within the development process.

# 8. References

[1] Farnell. (n.d.). HC-SR04. https://nl.farnell.com/en-NL/multicomp-pro/hc-sr04/ultrasonic-sensor-40khz-4-5m/dp/4162009  
Date of retrieval: 02.06.2026

[2] AZ-Delivery. (n.d.). KY-016 FZ0455 3-colors RGB LED module 3 Color. https://www.az-delivery.de/en/products/led-rgb-modul  
Date of retrieval: 02.06.2026

[3] Mischianti, G. (n.d.). VCC-GND Studio YD-ESP32-S3 (DevKitC 1 Clone): High-Resolution Pinout and Specs. https://mischianti.org/vcc-gnd-studio-yd-esp32-s3-devkitc-1-clone-high-resolution-pinout-and-specs/  
Date of retrieval: 02.06.2026

[4] Mouser Electronics. (n.d.). Jumper Wires (Male-to-Male, 100 pcs). https://nl.mouser.com/ProductDetail/krtkl/15102200?qs=byeeYqUIh0NW0YWqQr%2Fz4Q%3D%3D  Date of retrieval: 02.06.2026

[5] Mouser. (n.d.). PCBs & Breadboards Solder-in breadboard 2x2" 2.00mm pitch plated holes. https://nl.mouser.com/ProductDetail/Chip-Quik/SBBTH200P?qs=3Rah4i%252BhyCEW%252BPahlW9EPw%3D%3D  
Date of retrieval: 03.06.2026

[6] AliExpress. (n.d.). ESP32-S3-N16R8/N8R2 Wi-Fi and Bluetooth Development Board (Dual Type-C Ports, Antenna Connectors). https://nl.aliexpress.com/item/1005010121791705.html  
Date of retrieval: 02.06.2026

[7] Kiess, N. (2026). Analysis of Circuit Board Types (Sprint 4). GitLab Repository – City New Amsterdam City Sim Learning Group.  
Date of retrieval: 02.06.2026

[8] Kotsis, G., Tsiatsis, V., Michael, S., & Muller, J. (2018). What is a smart device? A conceptualisation within the paradigm of the internet of things. *Smart Innovation, Systems and Technologies*, 87, 1–12. https://doi.org/10.1186/s40327-018-0063-8  
Date of retrieval: 02.06.2026

[9] SplitKB. (n.d.). SSD1306 OLED Display. https://splitkb.com/products/oled-display  
Date of retrieval: 02.06.2026

[10] Farnell. (n.d.). ESP32-S3 Development Board (ESP32-S3-DevKit-1). https://pt.farnell.com/espressif-systems/esp32-s3-devkit-1/esp32-s3-development-board/dp/4308187  
Date of retrieval: 02.06.2026

[11] Solomon Systech. (n.d.). SSD1306 OLED Controller Datasheet. https://www.datasheethub.com/wp-content/uploads/2022/08/SSD1306.pdf  
Date of retrieval: 02.06.2026

[12] Kiess, N. (2026). Embedded Communication Protocols Analysis. GitLab Repository – City New Amsterdam City Sim Learning Group.  
Date of retrieval: 02.06.2026

[13] Farnell. (n.d.). ESP32-S3 Development Board (ESP32-S3-DevKit-1). https://pt.farnell.com/espressif-systems/esp32-s3-devkit-1/esp32-s3-development-board/dp/4308187  
Date of retrieval: 02.06.2026

[14] Mischianti, G. (n.d.). VCC-GND Studio YD-ESP32-S3 (DevKitC 1 Clone): High-Resolution Pinout and Specs. https://mischianti.org/vcc-gnd-studio-yd-esp32-s3-devkitc-1-clone-high-resolution-pinout-and-specs/  
Date of retrieval: 02.06.2026

[15] Kiess, N. (2026). Embedded Communication Protocols Analysis. GitLab Repository – City New Amsterdam City Sim Learning Group.  
Date of retrieval: 02.06.2026

---

*AI-assisted tools were used to support the creation of this document.*