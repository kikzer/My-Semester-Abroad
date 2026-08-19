# Advice: Circuit Board Selection for the Parking Tile System  
**Author:** Niklas Kiess  
**Date:** 23.04.2026  
**Version:** V2  
**Mayor:** Gerald Stap  


## Context  

The Parking Tile system is designed to integrate sensors, LEDs, and a microcontroller into a durable and scalable hardware platform for urban deployment. Because the system will eventually operate in public environments, the choice of circuit board is critical. It directly affects precision, long-term reliability, cost efficiency, and how easily the system can move from early prototypes to large-scale production.

This advice evaluates the most suitable circuit board types for each development phase and provides a clear recommendation.


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


## 1. Introduction  

To determine the best solution, three common circuit board types are considered: **Printed Circuit Boards (PCBs)**, **CNC-milled boards**, and **perfboards (protoboards)**. Each differs significantly in how it is produced, how reliable it is, and how suitable it is for prototyping versus final deployment.


## 2. Board Types Overview  

### 2.1 Printed Circuit Boards (PCBs)  

PCBs are manufactured using industrial processes where copper layers are precisely etched onto a substrate. This enables highly accurate electrical connections and supports complex, compact circuit layouts, including multilayer designs [1].

Because of this controlled and repeatable process, PCBs are widely used in professional electronic products and provide stable and consistent performance over time [1].


### 2.2 CNC-Milled Circuit Boards  

CNC-milled boards are produced by mechanically removing copper from a substrate. This allows fast and local production without chemical processes, making it suitable for rapid prototyping [2][5].

However, the mechanical process limits precision and usually restricts designs to simpler, often single-layer configurations [2][5].


### 2.3 Perfboards (Protoboards)  

Perfboards consist of pre-drilled hole grids where components are manually connected using wires. They are commonly used for prototyping due to their simplicity and flexibility [3][4].

However, because all connections are made manually, the quality and reliability depend on the assembly process, which can lead to inconsistencies and errors in more complex circuits [3][4].


## 3. Comparison  

| Board Type | Precision | Reliability | Cost | Manufacturing Effort | Best Use Case |
|------------|-----------|-------------|------|----------------------|--------------|
| PCB        | High (industrial fabrication accuracy) [1] | High (used in professional products) [1] | Economical in volume production [6] | Industrial manufacturing required | Final product |
| CNC-Milled | Moderate (limited by mechanical milling) [2][5] | Moderate (suitable for prototypes) [2] | Higher per unit than mass PCBs [6] | Requires CNC equipment | Prototype |
| Perfboard  | Low (manual wiring) [3] | Low–moderate (depends on assembly quality) [3][4] | Low-cost materials | Manual assembly required | Early prototype |


## 4. Conclusion  

The analysis shows that each board type fulfills a specific role based on its technical characteristics:

- Perfboards enable flexible prototyping but depend heavily on manual assembly, reducing precision and consistency.  
- CNC-milled boards improve structural consistency and allow faster prototyping than industrial production, but remain limited in complexity.  
- PCBs provide the highest precision and reliability due to standardized industrial manufacturing processes and are widely used in professional systems [1].  

Overall, the differences are mainly driven by manufacturing methods, which directly influence reliability, scalability, and design complexity.


## 5. Recommendation  

The **Parking Tile system is developed under a very strict time constraint of only two weeks**, which strongly determines the choice of hardware platform.

Since the project includes sensors, LEDs, and display units, and hardware/software are being developed simultaneously, the focus must be on **speed, flexibility, and immediate debugging capability** rather than long-term production optimization.

### Final Recommendation

**Use perfboards (protoboards) for the entire development phase**

Perfboards are the most suitable solution for this project because:

- They allow **immediate assembly without waiting for manufacturing or delivery delays**
- They support **fast wiring changes during debugging of sensors, LEDs, and display logic**
- They are **low-cost and easy to replace**, which is ideal during experimental development
- They enable direct hardware iteration while Arduino software is still evolving

### Why other options are not suitable

- **PCBs** require design finalization and manufacturing time, which is not compatible with a 2-week schedule [1][6]  
- **CNC-milled boards** still require setup and machining time, which slows down iteration compared to manual prototyping [2][5]  

### Project Fit

Because the developer has limited hardware experience and is still learning embedded systems, perfboards also provide a lower barrier to entry and allow mistakes to be corrected quickly without redesign overhead.


## 6. References (APA 6th edition)  

[1] Printed Circuit Board (PCB) Technology for Electrochemical Sensors and Sensing Platforms. (n.d.). MDPI. https://www.mdpi.com/2079-6374/10/11/159 (date of retrieval: 19.04.2026)  

[2] CNC PCB Milling: How It Works, When to Use It, and Its Limits. (n.d.). China Machining Solutions. https://chinamachiningsolutions.com/cnc-pcb-milling/ (date of retrieval: 19.04.2026)  

[3] What is Perf Board Printed Circuit Boards PCBs? Perf Board vs Breadboard. (n.d.). BestPCBs. https://www.bestpcbs.com/blog/2025/05/what-is-perf-board-printed-circuit-boards-pcbs-perf-board-vs-breadboard/ (date of retrieval: 19.04.2026)  

[4] Comparing Breadboards, Perfboards, and PCBs for Modern Electronics Prototyping. (n.d.). BestFPC. https://www.bestfpc.com/news/comparing-breadboards-perfboards-and-pcbs-for-modern-electronics-prototyping.html (date of retrieval: 19.04.2026)  

[5] What is PCB Milling, Process, and Tools Recommended. (n.d.). FSCircuits. https://www.fscircuits.com/pcb-milling/ (date of retrieval: 19.04.2026)  

[6] PCBWay. (2026). Online quote. https://www.pcbway.com/ (date of retrieval: 19.04.2026)  

[7] Sustainable CNC machining operations, a review. (2024). https://www.sciencedirect.com/science/article/pii/S2666412724000035 (date of retrieval: 30.04.2026)  

---
*Note: An AI was used as support for creating this document.*