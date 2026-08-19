# Embedded Pin Optimization Analysis

This document analyzes strategies to minimize [microcontroller pin usage](https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/main/docs/parking%20space%20tile/5_tile%20design.md?ref_type=heads) when integrating LEDs and ultrasonic sensors (HC-SR04) for the [Parking Tile](https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/d01377dc529f039666e19c4d236781c5d39156a1/docs/parking%20space%20tile/1_parking-road.md) system. The goal is to save pins for future expansion while maintaining efficient sensing and visual feedback.

## 1. Introduction

In a scalable Parking Tile system, LEDs provide visual feedback for parking availability, and ultrasonic sensors detect vehicles. A major challenge is reducing pin usage to allow more sensors, LEDs, or tiles without redesigning the microcontroller interface.

Efficient pin management improves scalability, reduces wiring complexity, and enables smoother system expansion.

## 2. Using SN74HC595N with RGB LEDs [1]

The SN74HC595N shift register efficiently drives RGB LEDs while minimising the number of pins required. Further information about the SN74HC595N can be found in the references section.

### Planned Optimization

For the RGB LEDs, as described in the referenced source, I use a dedicated chip (such as a shift register or LED driver IC). This enables control of multiple RGB LEDs using significantly fewer microcontroller pins, since the LEDs are managed via a serial interface or bus system. This greatly optimizes pin usage and simplifies the circuit design.

## 3. Ultrasonic Sensor (HC-SR04) Pin Strategies

HC-SR04 sensors require **2 pins per sensor**: Trigger and Echo.
Further information can be found in the [Sensor Analysis](https://gitlab.fdmci.hva.nl/studio/smart-cities/projecten/2025-2026-semester-2/city-sim-learning-group/city-new-amsterdam-city-sim-learning-group/-/blob/main/docs/parking%20space%20tile/3_sensor%20analysis.md?ref_type=heads).

### Planned Optimization

For the ultrasonic sensors, I plan to use a single trigger pin shared among all sensors, but provide a separate echo (receiver) pin for each sensor. This approach reduces the number of pins needed for triggering, while still allowing individual distance measurements from each sensor.

## 6. References

[1] How 74HC595 Shift Register Works & Interface it with Arduino, https://lastminuteengineers.com/74hc595-shift-register-arduino-tutorial/, accessed 02.04.2026
