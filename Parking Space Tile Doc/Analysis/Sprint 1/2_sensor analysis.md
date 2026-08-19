# Sensor Analysis

This document evaluates sensor technologies for detecting whether a parking slot is occupied or vacant, **specifically in the context of the 30x30 cm Parking-Tile test environment**. The analysis focuses on the unique requirements of this compact, energy-efficient, and clearly arranged test setup. Each option is assessed for functionality, technical specifications, power consumption, practical drawbacks, and suitability for the 30x30 cm Parking Tile.

## 1. PIR Motion Sensor (Passive Infrared)

### Overview (Suitability for 30x30 cm Tile)

- Detects infrared radiation emitted by warm objects.
- Power consumption: 50 µA (very low).
- Issues: False triggers due to temperature changes and direct sunlight; cannot detect static objects (problematic for parked cars).

### Technical Specifications

| Parameter         | Value              |
| ----------------- | ------------------ |
| Detection Range   | 3 – 7 meters       |
| Power Consumption | 50 µA              |
| Operating Voltage | 5V – 24V DC        |
| Output Signal     | Digital (High/Low) |

### Pros (for the Parking Tile)

- Very low power consumption.
- Simple integration with microcontrollers.
- Cost-effective.

### Cons

- Cannot detect static (parked) objects – not suitable for parking slot detection.
- Prone to false triggers from environmental changes (sunlight, temperature).

> Reference: [PIR Sensor Guide – Pktatiwal](https://pktatiwal.com/hw-416b-passive-infrared-pir-motion-sensor-module-a-complete-guide/)

## 2. Ultrasonic Sensor (e.g., HC-SR04)

### Overview (Suitability for 30x30 cm Tile)

- Measures distance using ultrasonic waves.
- Reflective waves are detected to calculate object distance.
- Suitable for detecting static objects (parked cars) in a small, defined area.
- Compact modules fit well on the 30x30 cm tile.

### Technical Specifications

| Parameter         | Value         |
| ----------------- | ------------- |
| Measurement Range | 2 cm – 400 cm |
| Operating Voltage | 5V DC         |
| Power Consumption | 15 mA         |

### Pros (for the Parking Tile)

- Accurate distance measurement.
- Detects static objects.
- Works in all lighting conditions.

### Cons

- Affected by temperature, humidity, and surface texture.
- Requires clear line-of-sight.
- Higher power consumption.

> References: [HC-SR04 Tutorial – Maker Guides](https://www.makerguides.com/hc-sr04-arduino-tutorial/)  
> [HC-SR04 Datasheet – Components101](https://components101.com/sensors/ultrasonic-sensor-working-pinout-datasheet)  
> [HC-SR04 Guide – HWLibre](https://en.hwlibre.com/hc-sr04/)

## 3. Laser + LDR (Light Dependent Resistor)

### Overview (Suitability for 30x30 cm Tile)

- A laser beam is projected; an LDR detects light intensity.
- Object presence is indicated by reduced light intensity.
- Can be used for slot detection, but alignment is critical in a small area.
- Laser modules may pose safety concerns in public demos.

### Technical Specifications

#### Laser Module (e.g., HW-493)

| Parameter         | Value  |
| ----------------- | ------ |
| Wavelength        | 650 nm |
| Power Consumption | 30 mA  |

#### LDR

- Measures light intensity; resistance changes with illumination.

> Reference: [Laser Module – MakerSelectronics](https://makerselectronics.com/product/laser-module-board-hw-493/)  
> Reference: [LDR Guide – Studio Smart Cities](https://studiosmartcities.nl/embedded/components/ldr/)

## 4. LED + LDR (Light Dependent Resistor)

### Overview (Suitability for 30x30 cm Tile)

- Proposed solution based on LED-LDR light barrier principle.
- LED emits light; LDR measures intensity at the parking slot.
- Object blocking the beam reduces light → LDR detects change → slot occupied.
- Alignment and ambient light can affect reliability in a small, open tile.

### Technical Specifications

#### LED Module

| Parameter          | Value       |
| ------------------ | ----------- |
| Luminous Intensity | 150–200 mcd |
| Power Consumption  | 16–18 mA    |

#### LDR

- Measures light intensity; resistance changes with illumination.

> Reference: [LED Module – SparkFun](https://www.sparkfun.com/led-basic-yellow-5mm.html)  
> Reference: [LDR Guide – Studio Smart Cities](https://studiosmartcities.nl/embedded/components/ldr/)

### Comparison Table (Focus: 30x30 cm Tile)

| Feature                | PIR | Ultrasonic | Laser + LDR | LED + LDR |
| ---------------------- | --- | ---------- | ----------- | --------- |
| Detects static objects | ❌  | ✅         | ✅          | ✅        |
| Reliable detection     | ❌  | ✅         | ❌          | ❌        |
| Works in all lighting  | ❌  | ✅         | ❌          | ❌        |
| Easy to implement      | ✅  | ✅         | ❌          | ✅        |
| Safe & low-risk        | ✅  | ✅         | ❌ (laser)  | ✅        |

## Conclusion

**For the 30x30 cm Parking Tile, the Ultrasonic sensor is the most practical, reliable, and cost-effective solution.**

The analysis shows that the Ultrasonic sensor meets all requirements of the compact test environment: It reliably detects parked vehicles, works in all lighting conditions, and is easy to integrate. This makes it the best choice for detecting parking slot occupancy on the 30x30 cm Parking Tile.
