# Analysis of Circuit Board Types

## Table of Contents

- [Summary](#summary)
- [Introduction](#introduction)
- [Research Question](#research-question)
- [Requirements Considered](#requirements-considered)
- [Methods](#methods)
- [Results](#results)
  - [1. Printed Circuit Boards (PCBs)](#1-printed-circuit-boards-pcbs)
  - [2. CNC-Milled Circuit Boards](#2-cnc-milled-circuit-boards)
  - [3. Perfboards/Protoboards](#3-perfboardsprotoboards)
- [Comparison Table](#comparison-table)
- [Conclusion and Recommendation](#conclusion-and-recommendation)
- [Additional Notes](#additional-notes)
- [References](#references)



## Summary

This document analyzes three different circuit board solutions for the Parking Tile project: printed circuit boards (PCBs), CNC-milled circuit boards, and perfboards/protoboards. The analysis focuses on precision, reliability, manufacturing speed, cost, maintainability, and scalability.

The goal is to determine which board type is most suitable for integrating sensors, LEDs, and a microcontroller into a working Parking Tile within a short two-week sprint and limited budget. Each board type is evaluated using the same requirements and sub-questions.

The results show that perfboards/protoboards are the most suitable option for this sprint because they are inexpensive, quick to assemble, and flexible during development. PCBs provide the highest reliability and professional quality but are less suitable due to production time and cost. CNC-milled boards offer a middle ground for prototyping but are limited in complexity and scalability.



# Introduction

In this sprint, the focus shifts from system design and communication planning to the physical realization of the Parking Tile. The previously developed concepts, including the communication protocol and system architecture, now need to be integrated into a finalized hardware solution.

The challenge is not only connecting the components, but also selecting a board type that supports reliable operation, simple assembly, and future expansion. The Parking Tile must integrate sensors, LEDs for visual feedback, and a microcontroller into a compact and maintainable system. In addition, the tile should clearly communicate parking availability through lighting and support future upgrades such as additional sensors or charging features.

The selected circuit board solution directly affects manufacturing speed, cost, reliability, maintainability, and scalability. Because the project is developed within a short sprint, rapid prototyping and easy modification are important factors during the decision-making process.

To determine the best solution, several circuit board types are analyzed and compared based on the project requirements.

# Research Question

What is the most suitable fixed circuit board solution for the Parking Tile, considering precision, reliability, and integration of all required components, so that the system provides clear parking availability, supports authorized access, and remains robust and maintainable for long-term use, while also being feasible to complete within a short development timeline and given cost constraints?

### Sub-Questions

1. Which circuit board type best balances speed, cost, reliability, and assembly effort for the Parking Tile?

2. How can sensors and LEDs be integrated to ensure reliable detection and clear visual feedback?

3. How can stable power distribution and safe signal routing be ensured on the board?

4. Which design choices support maintainability, scalability, and future upgrades?



# Requirements Considered

The following requirements were considered during the analysis:

- The solution must support future expansion and modular upgrades.
- The hardware must be reliable and maintainable.
- The board must provide stable power distribution and safe signal routing.
- The design and assembly must be achievable within a two-week sprint.
- Manufacturing and material costs must remain within budget.
- Components such as sensors, LEDs, and the microcontroller must be easy to mount and integrate.
- The system should allow future upgrades such as additional sensors or charging stations.



# Methods

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



# Results

## 1. Printed Circuit Boards (PCBs)

### Context

PCBs are professionally manufactured boards with copper traces and solder masks that provide organized and highly reliable electrical connections. They are commonly used in commercial electronics because they support compact layouts, accurate routing, and large-scale production [1].

For the Parking Tile, PCBs would allow all sensors, LEDs, and control electronics to be integrated into a clean and structured design. Their organized routing also improves electrical reliability and reduces the risk of wiring mistakes.

### Sub-Question 1: Speed, Cost, and Assembly

PCBs provide excellent reliability and precision, but they require external manufacturing. This increases both production time and cost, especially for small quantities or prototypes [1]. Because the sprint only lasts two weeks, waiting for production and delivery would significantly slow development.

### Sub-Question 2: Sensor and LED Integration

PCBs support precise placement of sensors and LEDs, which improves signal quality and ensures clear visual feedback [1]. The structured layout also reduces interference between components. However, once the PCB is manufactured, changes are difficult and expensive to make.

### Sub-Question 3: Power Distribution and Signal Routing

PCBs can use multiple layers to separate power and signal lines [1]. This improves electrical stability and reduces noise, which is important for reliable sensor readings and LED control.

### Sub-Question 4: Maintainability and Scalability

PCBs are highly scalable and suitable for long-term systems because designs can be reproduced consistently [1]. Their structured layouts also make maintenance easier in professional environments.

### Advantages

- High manufacturing precision, which improves reliability [1]
- Structured routing reduces wiring errors and interference [1]
- Multi-layer designs improve stable power distribution [1]
- Suitable for scalable and long-term production [1]
- Professional appearance and organized component layout [1]

### Disadvantages

- External manufacturing causes long lead times [1]
- High setup costs make them less suitable for prototypes [1]
- Difficult to modify after production [1]
- Less practical for rapid iteration during a short sprint [1]



## 2. CNC-Milled Circuit Boards

### Context

CNC-milled boards are produced by mechanically removing copper from a board using a milling machine. They resemble PCBs but are generally less precise and usually limited to single-layer designs [2, 5].

For the Parking Tile, CNC milling could allow faster local production without depending on industrial PCB manufacturing. This makes it useful for testing layouts and early prototypes.

### Sub-Question 1: Speed, Cost, and Assembly

CNC-milled boards are faster and cheaper than ordering professional PCBs for small quantities [2, 5]. However, they still require access to specialized milling equipment and are less suitable for highly detailed circuits.

### Sub-Question 2: Sensor and LED Integration

The boards allow flexible placement of sensors and LEDs, but the limited precision and single-layer routing can complicate more advanced integrations [2].

### Sub-Question 3: Power Distribution and Signal Routing

Because CNC-milled boards are usually single-layer, routing power and signal lines becomes more difficult as complexity increases [2, 5]. This can increase the risk of interference and inefficient layouts.

### Sub-Question 4: Maintainability and Scalability

CNC-milled boards are useful for prototyping and testing, but they are less suitable for scalable or long-term systems because of their lower precision and manufacturing consistency [2, 5].

### Advantages

- Faster prototyping compared to industrial PCB production [2, 5]
- Allows quick design changes during development [5]
- No chemical etching required [2]
- Suitable for small prototype runs [5]

### Disadvantages

- Limited precision compared to industrial PCBs [2]
- Single-layer routing reduces design flexibility [2]
- Surface quality and reliability are lower [5]
- Requires access to CNC equipment [2]
- Less suitable for complex or scalable systems [2, 5]



## 3. Perfboards/Protoboards

### Context

Perfboards and protoboards are generic boards with pre-drilled holes that allow components to be connected manually using wires and soldering [3, 4]. Unlike PCBs, they do not contain predefined copper traces, which makes them highly flexible during development.

For the Parking Tile project, perfboards allow components to be added, removed, or repositioned quickly. This flexibility is useful during rapid prototyping and experimentation within a short sprint.

### Sub-Question 1: Speed, Cost, and Assembly

Perfboards are inexpensive and very fast to assemble [3, 4]. They do not require external manufacturing, which makes them ideal for projects with limited time and budget.

### Sub-Question 2: Sensor and LED Integration

Sensors and LEDs can be positioned freely and adjusted during development [3]. This flexibility makes testing easier. However, because all wiring is done manually, careful assembly is necessary to avoid connection errors [4].

### Sub-Question 3: Power Distribution and Signal Routing

Power and signal routing must be created manually [4]. While this provides flexibility, it can also result in messy wiring and a higher risk of unstable connections if not carefully organized.

### Sub-Question 4: Maintainability and Scalability

Perfboards are highly suitable for experimentation and rapid modification [3, 4]. However, as systems become larger and more complex, maintenance becomes more difficult due to the manual wiring structure.

### Advantages

- Very low manufacturing cost [3, 4]
- Fast assembly without external production [3, 4]
- Easy to modify during development [3]
- Flexible placement of components [3]
- Ideal for prototyping within short timelines [4]

### Disadvantages

- Manual wiring increases the risk of assembly mistakes [4]
- Less organized structure compared to PCBs [3]
- Reduced long-term reliability [4]
- Difficult to scale for larger systems [3, 4]
- Wiring can become messy in complex designs [4]



# Comparison Table

| Board Type | Precision & Reliability | Speed | Cost | Flexibility | Scalability |
|||||||
| PCB | Very high | Slow | High | Low after production | Excellent |
| CNC-Milled Board | Medium | Medium | Medium | Medium | Limited |
| Perfboard/Protoboard | Lower | Very fast | Low | Very high | Limited |



# Conclusion and Recommendation

Based on the analysis and project requirements, perfboards/protoboards are the most suitable choice for the Parking Tile during this sprint.

The most important reason is that they support rapid development and easy modifications within the limited two-week timeline. Their low cost and flexibility make it possible to quickly integrate sensors, LEDs, and microcontrollers while still allowing design changes during development.

PCBs provide the best long-term reliability, structured layouts, and scalability [1]. However, their higher manufacturing costs and longer lead times make them less suitable for rapid prototyping during this sprint.

CNC-milled boards offer a compromise between PCBs and perfboards, but their routing limitations and lower reliability reduce their suitability for a more advanced and maintainable system [2, 5].

For future versions or mass production, transitioning to a PCB-based design would be the preferred solution because of its improved reliability, scalability, and professional structure [1].



# Additional Notes

This document focuses on selecting the most suitable circuit board type for the current sprint phase of the Parking Tile project. The decision is strongly influenced by the short development timeline, the need for flexibility during testing, and budget limitations.

An AI was used as support during the creation of this document.



# References

[1] Printed Circuit Board (PCB) Technology for Electrochemical Sensors and Sensing Platforms  
https://www.mdpi.com/2079-6374/10/11/159  
(date of retrieval 19.04.2026)

[2] CNC PCB Milling: How It Works, When to Use It, and Its Limits  
https://chinamachiningsolutions.com/cnc-pcb-milling/  
(date of retrieval 19.04.2026)

[3] What is Perf Board Printed Circuit Boards PCBs? Perf Board vs Breadboard  
https://www.bestpcbs.com/blog/2025/05/what-is-perf-board-printed-circuit-boards-pcbs-perf-board-vs-breadboard/  
(date of retrieval 19.04.2026)

[4] Comparing Breadboards, Perfboards, and PCBs for Modern Electronics Prototyping  
https://www.bestfpc.com/news/comparing-breadboards-perfboards-and-pcbs-for-modern-electronics-prototyping.html  
(date of retrieval 19.04.2026)

[5] What is PCB Milling, Process, and Tools Recommended  
https://www.fscircuits.com/pcb-milling/  
(date of retrieval 19.04.2026)