Author: Niklas Kiess \
Date: 01.10.2026 \
Version: V1.0 

# Communication Protocol for the Parking Tile System

## Table of Contents
1. [Context](#context)
2. [Objective](#objective)
3. [Analysis Summary](#analysis-summary)
4. [Recommendation](#recommendation)
5. [Business Case](#business-case-for-the-mayor)
6. [Final Conclusion](#final-conclusion)
7. [References](#references)


## Context
The City of New Amsterdam is piloting a **smart Parking Tile system** to monitor parking spaces in real-time.  
My goal is to expand this system from a single prototype to a scalable network of connected tiles, ensuring **efficient communication, minimal hardware complexity, and cost-effectiveness**.

The system collects and transmits occupancy data to a central backend, enabling:

- **Real-time monitoring** of parking spaces  
- **Dynamic parking guidance** for drivers  
- **Data-driven city planning**  

Choosing the right communication protocol is crucial for achieving these goals while keeping the solution maintainable and scalable.


## Objective
I aim to recommend the most suitable embedded communication protocol that balances:

- **Scalability:** Easily add more tiles and sensors  
- **Simplicity:** Minimal wiring and hardware complexity  
- **Reliability:** Accurate and real-time data transfer  
- **Cost-efficiency:** Avoid unnecessary components  

**Goal:** Obtain approval to adopt the recommended protocol for all future Parking Tile installations.


## Analysis Summary
I evaluated four common protocols for embedded systems: UART, SPI, I2C, and CAN.

| Protocol | Key Pros | Key Cons | Suitability for Parking Tile |
|----------|----------|----------|-----------------------------|
| **UART** | Simple, low cost, easy to debug | Point-to-point only, limited devices | Not scalable for multiple tiles [1][2][3] |
| **SPI** | Fast, full duplex | High pin usage, low scalability | Overkill for small-scale tile network [6][7] |
| **I2C** | Only 2 wires, supports multiple devices, built-in addressing | Slightly slower, requires pull-up resistors | **Optimal balance of scalability, simplicity, and cost** [4][5] |
| **CAN** | Reliable, multi-node support | Requires extra hardware, more complex | Suitable for industrial systems, unnecessary for Parking Tile [8][9] |

**Section Conclusion:**  
I2C stands out as the best fit for the Parking Tile system due to its balance of scalability, simplicity, and cost-effectiveness.


## Recommendation
I **recommend adopting I2C** (Inter-Integrated Circuit) as the communication protocol for the Parking Tile system.

**Why I2C?** 
1. **Minimal Wiring:** Only 2 lines needed for all devices (SDA, SCL).  
2. **Scalable Network:** Supports multiple tiles and sensors on the same bus.  
3. **Built-in Addressing:** Each tile and sensor can be uniquely identified.  
4. **Widely Supported:** Compatible with most microcontrollers and peripheral devices.  
5. **Cost-effective:** Avoids extra components required by CAN or SPI.

**Section Conclusion:**  
I2C is the optimal protocol for the Parking Tile system, meeting all requirements for scalability, simplicity, and cost.


## Business Case
- **Cost Savings:** Reduces hardware and wiring complexity, lowering deployment and maintenance costs.  
- **Faster Deployment:** Easy to install and expand, enabling rapid rollout across city parking zones.  
- **Smart City Advantage:** Real-time parking data reduces traffic congestion and improves citizen experience.  
- **Future-proofing:** Supports new features like dynamic pricing, sensor upgrades, and integration with other IoT city systems.  

**Impact:** Adopting I2C ensures a **scalable, reliable, and maintainable Parking Tile network** while demonstrating the city’s commitment to smart, cost-efficient urban solutions.

**Section Conclusion:**  
The business case for I2C enables cost savings, rapid deployment, and future-proofing for the city’s smart parking initiatives.


## Final Conclusion
In summary, after a thorough analysis of embedded communication protocols for the Parking Tile system, **I2C** is the clear choice. It offers the best combination of scalability, simplicity, and cost-effectiveness, directly supporting the city’s smart parking goals. By standardizing on I2C, the City New Amsterdam can efficiently expand its smart parking infrastructure, reduce costs, and ensure reliable, real-time data for both city planners and citizens.


## References
1. UART Serial Communication Guide: Principles, Parsing & Visualization, Fr2ed0m, [devresourcehub.com](https://devresourcehub.com/uart-serial-communication-guide-principles-parsing-visualization.html), accessed 26.03.2026  
2. Universal asynchronous receiver-transmitter, [Wikipedia](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter), accessed 26.03.2026  
3. Basics of UART Communication, Scott Campbell, [circuitbasics.com](https://www.circuitbasics.com/basics-uart-communication/), accessed 26.03.2026  
4. I2C Communication Protocol, [GeeksforGeeks](https://www.geeksforgeeks.org/computer-organization-architecture/i2c-communication-protocol/), accessed 26.03.2026  
5. Basics of the I2C Communication Protocol, [CircuitBasics](https://www.circuitbasics.com/basics-of-the-i2c-communication-protocol/), accessed 26.03.2026  
6. What is Serial Peripheral Interface (SPI)?, [GeeksforGeeks](https://www.geeksforgeeks.org/electronics-engineering/what-is-serial-peripheral-interface-spi/), accessed 31.03.2026  
7. Basics of the SPI Communication Protocol, [CircuitBasics](https://www.circuitbasics.com/basics-of-the-spi-communication-protocol/), accessed 31.03.2026  
8. Controller Area Network (CAN) Protocol Overview, [NI](https://www.ni.com/en/shop/seamlessly-connect-to-third-party-devices-and-supervisory-system/controller-area-network--can--overview.html), accessed 31.03.2026  
9. CAN Bus Explained - A Simple Intro [2025], [CSSElectronics](https://www.csselectronics.com/pages/can-bus-simple-intro-tutorial), accessed 31.03.2026