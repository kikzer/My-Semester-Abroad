
**Board Design**


## Table of Contents

1. [Context, Requirements, and Problem Statement](#1-context-requirements-and-problem-statement)
2. [Introduction](#2-introduction)
3. [Layout Overview](#3-layout-overview)
4. [Component Overview](#4-component-overview)
5. [Wiring Diagram](#5-wiring-diagram)
6. [Conclusion and Recommendations](#6-conclusion-and-recommendations)
7. [References](#references)

---

### 1. Context, Requirements, and Problem Statement

**Context:**  
This document is part of a smart city simulation project, focusing on the design of a modular parking space tile. The tile is intended for educational and prototyping environments, where real-time detection and display of parking space availability are required.


**Requirements (Challenge-Oriented):**
- The Parking Tile must help users easily understand parking availability through clear, real-time visual feedback.
- The system must ensure that only authorized users can access parking spaces, supporting flexible control for special events or high-demand situations.
- The design must allow for modularity and easy replacement of components, supporting rapid prototyping and future scalability.
- The system must enable backend-driven decision-making (e.g., LED control), data logging, and reliable two-way communication between embedded hardware and backend.
- The physical implementation must be robust, with stable power distribution and reliable connections, and must be validated as a cohesive, connected unit.

**Consultation:**
The protoboard design and board selection were discussed with Gerald Stap (see Advise/Sprint 3/Advise_circuit_board.md for detailed analysis and recommendations).

**Target Audience:**  
- Students and educators in smart city, IoT, and embedded systems courses  
- Developers and researchers prototyping smart parking solutions

**Problem Statement:**  
Efficient management and communication of parking space availability is a common challenge in urban environments. The goal is to design a tile that can detect occupancy, provide clear visual feedback, and display aggregated information to users, supporting both learning and prototyping needs.

---

### 2. Introduction

This document describes the design and implementation of a protoboard for a smart parking tile. The solution integrates sensors, displays, and a microcontroller to detect parking space occupancy and communicate status information.

---

### 3. Layout Overview

The protoboard layout is designed for modularity and ease of assembly. All components are arranged to facilitate straightforward wiring and future expansion.

---



### 4. Bill of Materials (BOM)


| Item                   | Description                                 | Manufacturer/Part No.         | Supplier & Link                                                                 | Qty      |
|------------------------|---------------------------------------------|-------------------------------|--------------------------------------------------------------------------------|----------|
| RGB LED Module [1]     | KY-016 RGB LED, 3-color, with resistors     | KY-016                        | [Mauser](https://www.mauser.pt/catalog/product_info.php?products_id=046-0032)  | 1        |
| OLED Display [2]       | 0.96"/0.91" SSD1306 I2C OLED, 128x64/128x32 | DFR0650/DFR0648/DFR0647       | [Farnell](https://pt.farnell.com/dfrobot/dfr0650/oled-display-mod-0-96-128x64-i2c/dp/4308186) | 1        |
| Ultrasonic Sensor [3]  | HC-SR04 Ultrasonic Distance Sensor          | HC-SR04                       | [Mauser](https://www.mauser.pt/catalog/product_info.php?products_id=049-0001)  | 1        |
| Perfboard [4]          | Double-sided prototyping board              | -                             | [Farnell](https://pt.farnell.com/search?st=perfboard)                          | 1        |
| Microcontroller [5]    | ESP32-S3 Dev Board (e.g., WROOM-1-N16R8)    | ESP32-S3                      | [Farnell](https://pt.farnell.com/dfrobot/dfr0975/dev-board-xtensa-lx7-wi-fi-bluetooth/dp/4733231) | 1        |
| Misc. Components [6]   | Wires, headers, resistors, connectors, etc. | Jumpercables                             | [Aliexpress](https://nl.aliexpress.com/item/1005004631908016.html?algo_pvid=c87dac2d-c150-4e96-8af5-0fa5e53c5486&algo_exp_id=c87dac2d-c150-4e96-8af5-0fa5e53c5486-4&pdp_ext_f=%7B%22order%22%3A%229088%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%210.96%210.89%21%21%211.10%211.02%21%402103847817780649198296824e1df5%2112000029906596292%21sea%21NL%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A1c01e44a%3Bm03_new_user%3A-29895&curPageLogUid=FqKEH15Jcqmm&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005004631908016%7C_p_origin_prod%3A)                     | as needed|

*Note: All links are examples; check availability and specifications before ordering.*


---

### 5. Wiring Diagram

![Wiring Diagram](../../../assets/ProtoBoardWiringDiagram.jpg)

**Legend:**  
- Red: Power  
- Black: Ground  
- Purple: Echo  
- Yellow: Trigger  
- Cyan: SCL  
- Ocher: SDA  
- Pink: RGB Red Connection  
- Green: RGB Green Connection  

*Note: The OLED is not shown in the diagram due to the absence of a Fritzing model.*

---

### 6. Conclusion and Recommendations

The proposed protoboard design provides a modular, educational platform for smart parking solutions. It supports reliable vehicle detection, real-time status display, and easy integration with backend systems. The design is suitable for both classroom demonstrations and prototyping in research environments.

---





## References

[1] Mauser. (2026). KY-016 RGB LED Module. https://www.mauser.pt/catalog/product_info.php?products_id=046-0032
[2] Farnell. (2026). DFR0650 OLED Display Module, SSD1306. https://pt.farnell.com/dfrobot/dfr0650/oled-display-mod-0-96-128x64-i2c/dp/4308186
[3] Mauser. (2026). HC-SR04 Ultrasonic Distance Sensor. https://www.mauser.pt/catalog/product_info.php?products_id=049-0001
[4] Farnell. (2026). Perfboard, Double-sided Prototyping Board. https://pt.farnell.com/search?st=perfboard
[5] Farnell. (2026). ESP32-S3 Dev Board. https://pt.farnell.com/dfrobot/dfr0975/dev-board-xtensa-lx7-wi-fi-bluetooth/dp/4733231
[6] Farnell. (2026). Jumper Wires and Miscellaneous Components. https://pt.farnell.com/search?st=jumper%20wires