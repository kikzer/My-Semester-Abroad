# Analysis of Circuit Board Types

**Author:** Niklas Kiess, Junior Embedded & Robotics Developer  
**Classification:** Internal  
**Project:** Parking Tile Project  
**Target audience:** Technically skilled Urban Planner / Smart City Technology Officer  
**Date:** 03.06.2026  
**Version:** V0.4  

**Note: This document contains proprietary information and is intended solely for internal use by the development team and authorized stakeholders. Unauthorized distribution, reproduction, or external sharing is strictly prohibited.**



## Table of Contents

1. [Introduction](#1-introduction)  
2. [Requirements Considered](#2-requirements-considered)  
3. [Methods](#3-methods)  
4. [Results](#4-results)  
   - [4.1 Printed Circuit Boards (PCBs)](#41-printed-circuit-boards-pcbs)  
   - [4.2 CNC-Milled Circuit Boards](#42-cnc-milled-circuit-boards)  
   - [4.3 Perfboards/Protoboards](#43-perfboardsprotoboards)  
5. [Conclusion](#5-conclusion)  
6. [Recommendation](#6-recommendation)  
7. [Additional Notes](#7-additional-notes)  
8. [References](#8-references)  



## 1. Introduction

In this sprint, the focus shifts from system design and communication planning to the physical realization of the Parking Tile. The previously developed concepts, including the communication protocol and system architecture, now need to be integrated into a finalized hardware solution.

The challenge is not only connecting the components, but also selecting a board type that supports reliable operation, simple assembly, and future expansion. The Parking Tile must integrate sensors, LEDs for visual feedback, and a microcontroller into a compact and maintainable system. In addition, the tile should clearly communicate parking availability through lighting and support future upgrades such as additional sensors or charging features.

The selected circuit board solution directly affects manufacturing speed, cost, reliability, maintainability, and scalability. Because the project is developed within a short two-week sprint and a limited budget, rapid prototyping and easy modification are important factors during the decision-making process. The hardware solution must therefore balance development speed and low production costs while still remaining functional and reliable.

To determine the most suitable solution, several circuit board types are analyzed and compared based on the project requirements.

## Research Question

What is the most suitable fixed circuit board solution for the Parking Tile, considering precision, reliability, manufacturing cost, and integration of all required components, so that the system provides clear parking availability, supports authorized access, and remains robust and maintainable for long-term use, while also being feasible to complete within a two-week development timeline and limited project budget?

### Sub-Questions

1. Which circuit board type best balances speed, cost, reliability, and assembly effort for the Parking Tile?
2. How can sensors and LEDs be integrated to ensure reliable detection and clear visual feedback?
3. How can stable power distribution and safe signal routing be ensured on the board?
4. Which design choices support maintainability, scalability, and future upgrades?



## 2. Requirements Considered

The following requirements were considered during the analysis:

- The solution must support future expansion and modular upgrades.
- The hardware must be reliable and maintainable.
- The board must provide stable power distribution and safe signal routing.
- The design and assembly must be achievable within a two-week sprint.
- Manufacturing and material costs must remain within budget.
- Components such as sensors, LEDs, and the microcontroller must be easy to mount and integrate.
- The system should allow future upgrades such as additional sensors or charging stations.



## 3. Methods

The analysis was performed through literature research and comparison of three common circuit board types used in electronics projects:

- Printed Circuit Boards (PCBs)
- CNC-milled circuit boards
- Perfboards/protoboards

Each board type was evaluated using the same criteria:

- Precision and reliability
- Ease of manufacturing and assembly
- Cost and production speed
- Flexibility during development
- Maintainability and scalability
- Suitability for integrating sensors, LEDs, and microcontrollers

The findings from the literature were then compared to the requirements of the Parking Tile project.



## 4. Results

### 4.1 Printed Circuit Boards (PCBs)

#### Context

PCBs are professionally manufactured boards with copper traces and solder masks that provide organized and highly reliable electrical connections. They are commonly used in commercial electronics because they support compact layouts, accurate routing, and large-scale production [3].

For the Parking Tile, PCBs would allow all sensors, LEDs, and control electronics to be integrated into a clean and structured design. Their organized routing also improves electrical reliability and reduces the risk of wiring mistakes.

#### Sub-Question 1: Speed, Cost, and Assembly

PCBs provide excellent reliability and precision, but they require external manufacturing. This increases both production time and cost, especially for small quantities or prototypes [3]. Because the sprint only lasts two weeks, waiting for production and delivery would significantly slow development.

#### Sub-Question 2: Sensor and LED Integration

PCBs support precise placement of sensors and LEDs, which improves signal quality and ensures clear visual feedback [3]. The structured layout also reduces interference between components. However, once the PCB is manufactured, changes are difficult and expensive to make.

#### Sub-Question 3: Power Distribution and Signal Routing

PCBs can use multiple layers to separate power and signal lines [3]. This improves electrical stability and reduces noise, which is important for reliable sensor readings and LED control.

#### Sub-Question 4: Maintainability and Scalability

PCBs are highly scalable and suitable for long-term systems because designs can be reproduced consistently [3]. Their structured layouts also make maintenance easier in professional environments.

#### Advantages

- High manufacturing precision, which improves reliability [3]  
- Structured routing reduces wiring errors and interference [3]  
- Multi-layer designs improve stable power distribution [3]  
- Suitable for scalable and long-term production [3]  
- Professional appearance and organized component layout [3]  

#### Disadvantages

- External manufacturing causes long lead times [3]  
- High setup costs make them less suitable for prototypes [3]  
- Difficult to modify after production [3]  
- Less practical for rapid iteration during a short sprint [3]  

#### Sub-Conclusion

PCBs provide the highest precision, reliability, and scalability of the analyzed solutions. However, the required external manufacturing process increases production time and costs, which reduces their suitability for rapid prototyping within a short sprint.



### 4.2 CNC-Milled Circuit Boards

#### Context

CNC-milled boards are produced by mechanically removing copper from a board using a milling machine. They resemble PCBs but are generally less precise and usually limited to single-layer designs [2, 4].

For the Parking Tile, CNC milling could allow faster local production without depending on industrial PCB manufacturing. This makes it useful for testing layouts and early prototypes.

#### Sub-Question 1: Speed, Cost, and Assembly

CNC-milled boards are faster and cheaper than ordering professional PCBs for small quantities [2, 4]. However, they still require access to specialized milling equipment and are less suitable for highly detailed circuits.

#### Sub-Question 2: Sensor and LED Integration

The boards allow flexible placement of sensors and LEDs, but the limited precision and single-layer routing can complicate more advanced integrations [2].

#### Sub-Question 3: Power Distribution and Signal Routing

Because CNC-milled boards are usually single-layer, routing power and signal lines becomes more difficult as complexity increases [2, 4]. This can increase the risk of interference and inefficient layouts.

#### Sub-Question 4: Maintainability and Scalability

CNC-milled boards are useful for prototyping and testing, but they are less suitable for scalable or long-term systems because of their lower precision and manufacturing consistency [2, 4].

#### Advantages

- Faster prototyping compared to industrial PCB production [2, 4]  
- Allows quick design changes during development [4]  
- No chemical etching required [2]  
- Suitable for small prototype runs [4]  

#### Disadvantages

- Limited precision compared to industrial PCBs [2]  
- Single-layer routing reduces design flexibility [2]  
- Surface quality and reliability are lower [4]  
- Requires access to CNC equipment [2]  
- Less suitable for complex or scalable systems [2, 4]  

#### Sub-Conclusion

CNC-milled boards offer a balance between professional PCB layouts and rapid prototyping flexibility. They reduce production time compared to industrial PCBs but remain limited in routing complexity, scalability, and manufacturing precision.



### 4.3 Perfboards/Protoboards

#### Context

Perfboards and protoboards are generic boards with pre-drilled holes that allow components to be connected manually using wires and soldering [5, 1]. Unlike PCBs, they do not contain predefined copper traces, which makes them highly flexible during development.

For the Parking Tile project, perfboards allow components to be added, removed, or repositioned quickly. This flexibility is useful during rapid prototyping and experimentation within a short sprint.

#### Sub-Question 1: Speed, Cost, and Assembly

Perfboards are inexpensive and very fast to assemble [5, 1]. They do not require external manufacturing, which makes them suitable for projects with limited time and budget. Their low material cost also reduces financial risk during experimentation and testing [1].

#### Sub-Question 2: Sensor and LED Integration

Sensors and LEDs can be positioned freely and adjusted during development [5]. This flexibility makes testing easier. However, because all wiring is done manually, careful assembly is necessary to avoid connection errors [1].

#### Sub-Question 3: Power Distribution and Signal Routing

Power and signal routing must be created manually [1]. While this provides flexibility, it can also result in messy wiring and a higher risk of unstable connections if not carefully organized.

#### Sub-Question 4: Maintainability and Scalability

Perfboards are highly suitable for experimentation and rapid modification [5, 1]. However, as systems become larger and more complex, maintenance becomes more difficult due to the manual wiring structure.

#### Advantages

- Very low manufacturing cost [5, 1]  
- Fast assembly without external production [5, 1]  
- Easy to modify during development [5]  
- Flexible placement of components [5]  
- Ideal for prototyping within short timelines [1]  

#### Disadvantages

- Manual wiring increases the risk of assembly mistakes [1]  
- Less organized structure compared to PCBs [5]  
- Reduced long-term reliability [1]  
- Difficult to scale for larger systems [5, 1]  
- Wiring can become messy in complex designs [1]  

#### Sub-Conclusion

Perfboards/protoboards provide the highest flexibility and fastest assembly process for short-term development. Their low cost and ease of modification make them highly suitable for rapid prototyping, although manual wiring reduces long-term reliability and scalability.



## 5. Conclusion

The analysis shows clear differences between the three circuit board solutions in terms of reliability, production speed, flexibility, and scalability.

PCBs provide the highest precision, best signal routing, and strongest long-term reliability. Their structured layouts and scalability make them highly suitable for professional and large-scale systems. However, the required manufacturing process increases both production time and cost.

CNC-milled boards provide faster local production and allow prototype testing without industrial manufacturing. Nevertheless, their lower precision and routing limitations reduce their suitability for more advanced or scalable systems.

Perfboards/protoboards provide the greatest flexibility during development and can be assembled quickly without external production. Their low cost and ease of modification make them highly suitable for rapid prototyping within a short sprint. However, manual wiring reduces organization, scalability, and long-term reliability compared to PCB-based solutions.



## 6. Recommendation

Based on the project requirements and sprint constraints, perfboards/protoboards are the most suitable circuit board solution for the current Parking Tile sprint.

The short two-week timeline and limited budget make rapid assembly and easy modification more important than long-term manufacturing quality. Perfboards allow sensors, LEDs, and microcontrollers to be integrated quickly while still supporting changes during development and testing.

For future versions of the Parking Tile or larger-scale production, a transition to a PCB-based design would provide improved reliability, scalability, and overall system organization.



## 7. Additional Notes

This document focuses on selecting the most suitable circuit board type for the current sprint phase of the Parking Tile project. The decision is strongly influenced by the short development timeline, the need for flexibility during testing, and budget limitations.



## 8. References

[1] Comparing Breadboards, Perfboards, and PCBs for Modern Electronics Prototyping  
https://www.bestfpc.com/news/comparing-breadboards-perfboards-and-pcbs-for-modern-electronics-prototyping.html  
(date of retrieval 19.04.2026)

[2] CNC PCB Milling: How It Works, When to Use It, and Its Limits  
https://chinamachiningsolutions.com/cnc-pcb-milling/  
(date of retrieval 19.04.2026)

[3] Printed Circuit Board (PCB) Technology for Electrochemical Sensors and Sensing Platforms  
https://www.mdpi.com/2079-6374/10/11/159  
(date of retrieval 19.04.2026)

[4] What is PCB Milling, Process, and Tools Recommended  
https://www.fscircuits.com/pcb-milling/  
(date of retrieval 19.04.2026)

[5] What is Perf Board Printed Circuit Boards PCBs? Perf Board vs Breadboard  
https://www.bestpcbs.com/blog/2025/05/what-is-perf-board-printed-circuit-boards-pcbs-perf-board-vs-breadboard/  
(date of retrieval 19.04.2026)

---

*An AI was used as support during the creation of this document.*