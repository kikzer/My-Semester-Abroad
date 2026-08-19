# Advice: Circuit Board Selection for the Parking Tile System  

**Author:** Niklas Kiess, Junior Embedded & Robotics Developer  
**Date:** 02.06.2026  
**Version:** V0.3  
**Target Audience:** Mayor

**Note: This document contains proprietary information and is intended solely for internal use by the development team and authorized stakeholders. Unauthorized distribution, reproduction, or external sharing is strictly prohibited.**


## Context  

The Parking Tile System is a smart parking solution that combines sensors, LEDs, displays, and a microcontroller into one integrated hardware platform. The system is intended for public urban environments and therefore requires hardware that is reliable, practical, and easy to develop within the available project timeframe.
The target audience for this advice is mayors.

Because the project is developed under a strict deadline of only two weeks, the choice of circuit board is especially important. The selected board must support fast assembly, easy debugging, flexible hardware changes, and stable operation during development.

This advice evaluates three common circuit board types and determines which option is most suitable for the Parking Tile System.


## Table of Contents  

1. [Introduction](#1-introduction)  
2. [Board Types Overview](#2-board-types-overview)  
   - [2.1 Printed Circuit Boards (PCBs)](#21-printed-circuit-boards-pcbs)  
   - [2.2 CNC-Milled Circuit Boards](#22-cnc-milled-circuit-boards)  
   - [2.3 Perfboards (Protoboards)](#23-perfboards-protoboards)  
3. [Comparison](#3-comparison)  
4. [Conclusion](#4-conclusion)  
5. [Recommendation](#5-recommendation)  
6. [References](#6-references)  


# 1. Introduction  

To determine the most suitable circuit board for the Parking Tile System, three commonly used board types are compared: Printed Circuit Boards (PCBs), CNC-milled boards, and perfboards (protoboards).

Each board type has different advantages and limitations related to manufacturing, reliability, flexibility, development speed, and cost. These differences are important because the Parking Tile System requires continuous testing and adjustments during both hardware and software development.

The following sections provide an explanation of each board type and compare their suitability for the project based on a previous analysis. [8]



# 2. Board Types Overview  


## 2.1 Printed Circuit Boards (PCBs)  

Printed Circuit Boards (PCBs) are manufactured using industrial production methods where copper traces are accurately etched onto a board substrate [1].

This manufacturing process allows compact and highly precise circuit layouts, including multilayer designs and complex connections [1]. Because the production process is standardized, PCBs provide stable performance and high reliability over long periods of use [1].

PCBs are commonly used in professional electronic systems because they are durable, scalable, and suitable for large-scale production.


## 2.2 CNC-Milled Circuit Boards  

CNC-milled boards are created by mechanically removing copper from a board surface using a CNC machine [2][5].

This process allows local and relatively fast production without chemical etching, making CNC milling useful for prototype development [2][5].

However, CNC milling has lower precision than industrial PCB manufacturing and is usually limited to simpler circuit designs [2][5]. The machining process also requires setup time and equipment, which can slow down rapid hardware iteration.


## 2.3 Perfboards (Protoboards)  

Perfboards are boards with pre-drilled holes that allow components to be connected manually using wires and soldering [3][4].

They are widely used for prototyping because they allow circuits to be assembled and modified quickly [3][4]. Components can easily be removed or rewired during testing, which makes debugging more practical during development.

Because all connections are created manually, perfboards are less precise and less reliable than professionally manufactured PCBs [3][4]. However, they provide high flexibility during early development stages.


# 3. Comparison  

The following table compares the three circuit board types based on the most important project requirements: precision, reliability, cost, manufacturing effort, and practical use case.

## Comparison Table (with Time Consumption)

| Board Type | Precision | Reliability | Cost | Manufacturing Effort | Time Consumption | Best Use Case |
|------------|-----------|-------------|------|----------------------|------------------|---------------|
| PCB | High due to industrial fabrication accuracy [1] | High and stable for long-term use [1] | Economical in volume production [6] | Requires industrial manufacturing and delivery time | ~1–5 days prototype fabrication + assembly (can vary depending on supplier and complexity) [10] | Final product |
| CNC-Milled | Moderate due to mechanical milling limitations [2][5] | Moderate and suitable for testing [2] | Higher per unit than mass-produced PCBs [6] | Requires CNC setup, milling and finishing time | ~30 minutes to a few hours total prototype workflow (setup + milling + adjustments) [5][7] | Functional prototype |
| Perfboard | Lower due to manual wiring [3] | Depends on assembly quality [3][4] | Low-cost materials [3] | Immediate manual assembly possible | Immediate to ~1–2 hours depending on circuit complexity (manual assembly only) [3][4] | Rapid prototyping |


# 4. Conclusion  

The comparison shows that each circuit board type serves a different purpose during hardware development.

Perfboards provide the highest flexibility during prototyping because circuits can be assembled and modified immediately. CNC-milled boards offer more structure and consistency, but still require machine setup and machining time. PCBs provide the highest precision and reliability due to standardized industrial manufacturing processes [1].

The manufacturing method directly influences the flexibility, reliability, and scalability of each board type.

For the Parking Tile System, fast development and easy debugging are the most important requirements. Because the project must be completed within two weeks while hardware and software are developed simultaneously, rapid iteration is essential.

Based on the comparison and project requirements, perfboards are the most practical solution for the current development phase of the Parking Tile System.


# 5. Recommendation  

### Final Recommendation  

**Perfboards are the most suitable solution for the Parking Tile System during the current development phase.**

### Reasons for this recommendation

- Immediate assembly without manufacturing or delivery delays  
- Fast hardware modifications during debugging and testing  
- Easy integration of sensors, LEDs, displays 
- Low-cost solution for experimental development  
- Simple replacement and rewiring when errors occur  
- Suitable for simultaneous hardware and software development  
- Practical for developers with limited embedded systems experience  

### Why the other options are less suitable

- **PCBs** require finalized designs and manufacturing time, which is not compatible with a two-week development schedule [1][6]  
- **CNC-milled boards** still require setup and machining time, making rapid iteration slower compared to perfboards [2][5]  


# 6. References 

[1] Printed Circuit Board (PCB) Technology for Electrochemical Sensors and Sensing Platforms. (n.d.). MDPI. https://www.mdpi.com/2079-6374/10/11/159 (date of retrieval: 19.04.2026)  

[2] CNC PCB Milling: How It Works, When to Use It, and Its Limits. (n.d.). China Machining Solutions. https://chinamachiningsolutions.com/cnc-pcb-milling/ (date of retrieval: 19.04.2026)  

[3] What is Perf Board Printed Circuit Boards PCBs? Perf Board vs Breadboard. (n.d.). BestPCBs. https://www.bestpcbs.com/blog/2025/05/what-is-perf-board-printed-circuit-boards-pcbs-perf-board-vs-breadboard/ (date of retrieval: 19.04.2026)  

[4] Comparing Breadboards, Perfboards, and PCBs for Modern Electronics Prototyping. (n.d.). BestFPC. https://www.bestfpc.com/news/comparing-breadboards-perfboards-and-pcbs-for-modern-electronics-prototyping.html (date of retrieval: 19.04.2026)  

[5] What is PCB Milling, Process, and Tools Recommended. (n.d.). FSCircuits. https://www.fscircuits.com/pcb-milling/ (date of retrieval: 19.04.2026)  

[6] PCBWay. (2026). Online quote. https://www.pcbway.com/ (date of retrieval: 19.04.2026)  

[7] Sustainable CNC machining operations, a review. (2024). https://www.sciencedirect.com/science/article/pii/S2666412724000035 (date of retrieval: 30.04.2026)  

[8] Kiess, N. (2026). Embedded Communication Protocols Analysis. https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/main/docs/parking%20space%20tile/Advise/Sprint%204/Advise_circuit_board_updated.md?ref_type=heads. (Date of retrieval: 02.06.2026)

[9] Mouser. (n.d.). PCBs & Breadboards Solder-in breadboard 2x2" 2.00mm pitch plated holes. https://nl.mouser.com/ProductDetail/Chip-Quik/SBBTH200P?qs=3Rah4i%252BhyCEW%252BPahlW9EPw%3D%3D  
Date of retrieval: 03.06.2026

[10] QueenEMS. (n.d.). PCB Fabrication Lead Time: How Long Will Your Board Actually Take?. https://www.queenems.com/blog/pcb-fabrication-lead-time/. Date of retrieval: 03.06.2026


---

*Note: AI was used as support during the creation of this document.*