# Realisation of the ESP32-S3 Parking Tile Implementation

**Project:** ESP32-S3 Parking Tile  
**Sprint:** Sprint 4  
**Document type:** Realisation Report  
**Author:** Niklas Kiess, Junior Embedded & Robotics Developer  
**Date:** 03.06.2026  
**Version:** V0.6  
**Target Audience:** Central Municipal Administration and City Mayor's Office


**Note: This document contains proprietary information and is intended solely for internal use by the development team and authorized stakeholders. Unauthorized distribution, reproduction, or external sharing is strictly prohibited.**

## Table of Contents

1. [Introduction](#1-introduction)  
2. [Design Requirements and Implementation Status](#2-design-requirements-and-implementation-status)  
3. [Component Verification and Pre-Integration Testing](#3-component-verification-and-pre-integration-testing)  
4. [Traceability to the Design and Analysis Phase](#4-traceability-to-the-design-and-analysis-phase)  
5. [Hardware Realisation and Physical Assembly](#5-hardware-realisation-and-physical-assembly)  
6. [Cable Management and System Organisation](#6-cable-management-and-system-organisation)  
7. [Electrical Continuity and Solder Joint Verification](#7-electrical-continuity-and-solder-joint-verification)  
8. [System Testing and Functional Validation](#8-system-testing-and-functional-validation)  
9. [Proof of Functionality: Meeting the Requirements](#9-proof-of-functionality-meeting-the-requirements)  
10. [Conclusion and Findings](#10-conclusion-and-findings)  
11. [Handover Strategy and Future Roadmap](#11-handover-strategy-and-future-roadmap)  
12. [References](#12-references)  


## 1. Introduction

The Parking Tile is part of a smart parking system concept. It represents a modular parking detection unit with vehicle presence sensing, visual feedback, display output, and backend communication. The goal of the realisation phase was to move from an analysed and designed system to a working physical prototype that can be tested and validated.

Before this realisation, the system existed mainly as a prototyping setup. A protoboard-based implementation is suitable for experimentation; however, it is not stable for long-term use because connections can become loose, wiring can become unclear, and debugging becomes more difficult over time. Therefore, the final implementation was built on a perfboard (soldered prototype board) to ensure a more stable, durable, and structured hardware foundation. It should follow the principle of plug and play.

This document explains the final physical realisation of the Parking Tile hardware and software and demonstrates how the system fulfils all defined design requirements through structured implementation, verification, and testing.

### Main Question

**How can a modular and maintainable Parking Tile be successfully realised using an ESP32-S3 while fulfilling the functional and non-functional requirements identified during the analysis and design phases?**

### Sub-Questions

1. How was the software architecture implemented to ensure modularity, maintainability, and scalability?
2. How was the hardware prototype physically realised and assembled?
3. Which design adjustments were required during implementation and how were they solved?
4. How was the functionality and reliability of the system validated?
5. How does the physical realisation prove that all predefined system requirements have been successfully met?


## 2. Design Requirements and Implementation Status

This section defines the system requirements and compares them to the final implementation results.

The following requirements were established during the Design phase and must be verified through the realisation process:

| No. | Requirement           | Expected Design Result      | Realisation Evidence |
| --: | --------------------- | --------------------------- | -------------------- |
|   R1 | Visual feedback       | LED and display show status | RGB LED + OLED       |
|   R2 | Vehicle detection     | Reliable distance sensing   | HC-SR04 sensor       |
|   R3 | Backend communication | Wi-Fi JSON communication    | Backend module       |
|   R4 | Information display   | Parking information shown   | OLED updates         |
|   R5 | Modularity            | Class-based architecture    | Multiple modules     |
|   R6 | Expandability         | Add new components          | Scalable design      |
|   R7 | Hardware stability    | Reliable wiring             | Perfboard build      |
|   R8 | Testability           | System can be validated     | Testing performed    |
|   R9 | Correct operation     | Full system works           | Manual validation    |

**Table 1**  
*Requirement fulfilment of the ESP32-S3 Parking Tile system.*

### 2.1 Requirement Fulfilment Summary

The comparison between the defined requirements and the final implementation shows that all functional and non-functional requirements were successfully fulfilled. The system provides reliable vehicle detection, visual feedback, display output, backend communication, and a modular architecture. The implemented hardware and software design therefore fully meets the initial system specifications defined during the design phase.


## 3. Component Verification and Pre-Integration Testing

All components were tested individually before system integration to ensure reliable operation and reduce integration risks.

Electrical validation was performed using a multimeter to check continuity, verify correct power distribution, and ensure the absence of short circuits. Signal paths were also tested to confirm correct behaviour of sensors, LEDs, and communication interfaces. The OLED display communication via I²C was verified separately to ensure stable operation.

![Multimeter Test](../../../assets/MultiMeterTest.png)

**Figure 1**  
*Testing every pin/solder connection for continuity.*

In parallel, each software module was tested independently. The ultrasonic sensor module, OLED display module, RGB LED controller, and backend communication module were executed separately to ensure correct functionality before system integration.

![Sensor Test](../../../assets/TestPartsParkingTile.png)

**Figure 2**  
*Testing of each sensor to ensure correct functionality.*

![Oled Test](../../../assets/TestPartsBeforeSolder.png)

**Figure 3**  
*Testing of each OLED screen prior to soldering.*


The backend communication test code was tested as follows: if data was received in the backend:

```cpp
void testCycleParkingSpacesOccupied()
{
    static unsigned long lastToggle = 0;
    static bool toggle = false;

    unsigned long now = millis();

    if (now - lastToggle >= 20000UL)
    {
        lastToggle = now;
        toggle = !toggle;

        Serial.print("[TEST] Cycling parking space occupied states. Toggle: ");
        Serial.println(toggle ? "EVEN=occupied" : "ODD=occupied");

        for (size_t i = 0; i < parkingSpaceCount; ++i)
        {
            bool occupied = toggle ? (i % 2 == 0) : (i % 2 == 1);

            parkingSpaces[i].setOccupied(occupied);
            parkingSpaces[i].changeOperationMode(
                occupied ? MANUAL : AUTO
            );

            Serial.print("  ParkingSpace ");
            Serial.print(i + 1);
            Serial.print(": setOccupied=");
            Serial.print(occupied ? "true" : "false");
            Serial.print(", operationMode=");
            Serial.println(occupied ? "MANUAL" : "AUTO");
        }
    }
}
```

### 3.1 Component Verification Summary

The individual verification of hardware and software components reduced integration risks and ensured correct behaviour before system assembly. Electrical checks with a multimeter confirmed safe and correct wiring, while isolated software tests validated each module independently. This step established a stable foundation for system integration.


## 4. Traceability to the Design and Analysis Phase

The realisation of the Parking Tile was not an isolated activity but a direct execution of decisions made during the preceding Analysis and Design phases. This section establishes the traceability between the physical build and the engineering blueprints defined in the project documentation.

### 4.1 Board Selection Traceability

The decision to implement the system on a perfboard (protoboard) was directly derived from the **Analysis of Circuit Board Types** (V0.4). During the analysis phase, three board types were evaluated: Printed Circuit Boards (PCBs), CNC-milled boards, and Perfboards.

*   **Constraint Alignment:** The analysis concluded that PCBs, while offering high precision, required external manufacturing lead times incompatible with the two-week sprint timeline. CNC-milled boards offered a middle ground but lacked the necessary routing flexibility for the specific component mix.
*   **Realisation Decision:** Consequently, the realisation phase adhered to the recommendation to use **Perfboards/Protoboards**. This choice prioritised rapid assembly, low material cost, and the flexibility to modify wiring during testing, as specified in the Analysis document's recommendation section.
*   **Outcome:** The physical build reflects this decision by utilising a soldered perfboard that allows for component repositioning and manual wiring, balancing the need for stability with the sprint's time constraints.

### 4.2 Component and Architecture Traceability

The hardware architecture implemented in the realisation phase strictly follows the specifications outlined in the **Board Design** document (V0.3).

*   **Power Architecture:** The design document specified a unified **3.3V power architecture** to ensure compatibility across the ESP32-S3, HC-SR04 sensor, and SSD1306 OLED display. The realisation board was powered exclusively via a 3.3V regulated supply rail, eliminating the need for multiple voltage domains and simplifying the power distribution network as planned.
*   **Component Selection:** The Bill of Materials (BOM) defined in the design phase was followed precisely:
    *   **Microcontroller:** ESP32-S3 (Central Processing Unit).
    *   **Sensor:** HC-SR04 Ultrasonic Sensor (Vehicle Detection).
    *   **Feedback:** KY-016 RGB LED Module (Visual Status).
    *   **Display:** SSD1306 I²C OLED Display (Information Output).
*   **Wiring Standards:** The **Wiring Legend** defined in the design phase was implemented during assembly to ensure maintainability:
    *   **Red:** Power (VCC)
    *   **Black:** Ground (GND)
    *   **Purple/Yellow:** Ultrasonic Echo/Trigger
    *   **Cyan/Ocher:** I²C SCL/SDA
    *   **Pink/Green:** RGB Channels
    This colour-coding system was applied during the physical build to reduce assembly errors and facilitate debugging, directly reflecting the design specifications.

### 4.3 Design Documentation and Safety

The physical layout was guided by the schematic diagrams created during the design phase. Although the original OLED display model was not available in the Fritzing EDA software used for documentation, the logical connections were preserved in the wiring diagram and executed physically.

Furthermore, the fabrication process adhered to safety considerations noted during the analysis. While the analysis highlighted the risks associated with cutting and soldering FR-4 materials (dust and fumes), the realisation was executed in a controlled laboratory environment equipped with appropriate ventilation and safety gear, ensuring compliance with health and safety standards during the soldering process.

### 4.4 Traceability Summary

The realisation phase successfully translated the theoretical decisions from the Analysis and Design phases into a physical prototype. The choice of perfboard, the 3.3V power architecture, the specific component selection, and the wiring colour codes were all implemented as defined. This traceability ensures that the final system is not only functional but also aligned with the project's strategic constraints regarding time, budget, and maintainability.


## 5. Hardware Realisation and Physical Assembly

The system was implemented on a perfboard to improve its mechanical and electrical stability compared to a prototyping setup. All components were soldered and interconnected so that the system is now plug-and-play, with every component able to be removed or added to the microcontroller.

The system consists of an ESP32-S3 microcontroller, an HC-SR04 ultrasonic sensor, an SSD1306 OLED display, RGB LEDs, and a backend communication module. A 3D-printed housing supports the mechanical structure and improves usability.

![Board from below](../../../assets/BoardfromBelow.png)

**Figure 4**  
*The perfboard underside showing soldering connections.*

![Board from top](../../../assets/BoardfromTop.png)

**Figure 5**  
*The perfboard top side showing modular component interfaces.*

### 5.1 Implementation Constraints and Design Adaptations
Due to time constraints during the implementation phase, a hardware adjustment had to be made regarding the I²C communication architecture. One of the OLED displays could not be reconfigured to a different I²C address via hardware modification (e.g., solder bridge or address pin adjustment), as there was not sufficient time left to physically rework (re-solder) the component.

As a result, it was not possible to operate both OLED displays on a shared I²C bus without address conflicts. To resolve this issue within the project timeline, two separate I²C buses were implemented, each assigned to one OLED display.

Consequently, the OLED displays use different SDA and SCL pin pairs. This solution ensured functional operation without modifying the hardware components, while maintaining system stability and meeting the project deadlines.


## 6. Cable Management and System Organisation

A structured cable colour-coding system was used to improve readability and maintainability. Power lines were red, ground black, and signal lines were assigned distinct colours based on function. Each color was used as in the design file described.

This structure reduced wiring complexity and improved debugging efficiency. Components were grouped logically to shorten cable paths and increase system clarity.

![Cable View](../../../assets/CableManagment.png)

**Figure 6**  
*The tile underside showing cable management.*


## 7. Electrical Continuity and Solder Joint Verification

All solder joints and electrical connections were validated using a multimeter.

Short-circuit checks were performed to ensure electrical safety, while signal validation confirmed the correct operation of outputs such as LEDs and sensors. These tests confirmed that the hardware was electrically sound and reliable. Additionally, the code was checked to ensure that everything worked as intended.

### 7.1 Safety Protocols

The fabrication process adhered to the following safety standards:
*   **Ventilation:** All soldering was performed in a laboratory with active fume extraction (IPC J-STD-001H compliance).
*   **Temperature Control:** Temperature-controlled soldering iron set to 350°C to prevent component damage.
*   **Pre-Power Verification:** Digital multi-meter continuity and short-circuit tests performed before first power application.

### 7.2 Hardware Verification Summary

The transition from a prototyping setup to a perfboard-based implementation significantly improved mechanical stability and system reliability. During this process, design adjustments such as structured cable routing, colour-coded wiring, and improved physical organisation were necessary. These changes solved instability issues and resulted in a robust and maintainable hardware implementation.

## 8. System Testing and Functional Validation

### Unit and Hardware Testing Strategy

The Parking Tile system was validated using layered testing, combining unit tests, integration tests, and hardware smoke tests.

Unit tests ensured correctness of individual software components, including enumerations, timing functions, sensor abstractions, and system-level object relationships. These tests verified that each module behaves deterministically before integration.

```cpp
void test_parking_space_defaults_and_state_changes()
{
    UltraSonicSensor sensor(21, 20);
    ParkingSpace space(7, sensor, 4, 5);

    TEST_ASSERT_EQUAL(7, space.getId());
    TEST_ASSERT_TRUE(space.isOccupied());
    TEST_ASSERT_EQUAL(AUTO, space.getOperationMode());

    space.setOccupied(false);
    TEST_ASSERT_FALSE(space.isOccupied());

    space.changeOperationMode(MANUAL);
    TEST_ASSERT_EQUAL(MANUAL, space.getOperationMode());
}
```

Backend integration tests validated JSON-based command processing. The system correctly interpreted parking override commands and full tile updates, ensuring that only intended components were modified while others remained stable.

```cpp
void test_backend_tile_status_command()
{
    UltraSonicSensor sensor1(21, 20);
    UltraSonicSensor sensor2(48, 47);

    ParkingSpace spaces[] = {
        ParkingSpace(1, sensor1, 4, 5),
        ParkingSpace(2, sensor2, 6, 7)
    };

    OledScreen screens[] = {
        OledScreen(0, 6, 7, 0x3C)
    };

    ParkingTile tile(1, spaces, 2, screens, 1);

    String json = R"({
      "parkingTile": {
        "id": 1,
        "Status": "closed",
        "parkingSpaces": [
          { "id": 1, "operation": "manual", "led": "red" },
          { "id": 2, "operation": "auto" }
        ]
      }
    })";

    receiveParkingTileInstructions(tile, json);

    TEST_ASSERT_EQUAL(CLOSED, tile.getOperationMode());
    TEST_ASSERT_EQUAL(MANUAL, spaces[0].getOperationMode());
    TEST_ASSERT_TRUE(spaces[0].isOccupied());
    TEST_ASSERT_EQUAL(AUTO, spaces[1].getOperationMode());
}
```

Integration tests simulated realistic sequences of backend commands, confirming that the system remains consistent under mixed control scenarios.

```cpp
void test_backend_parking_space_override_command()
{
    UltraSonicSensor sensor1(21, 20);
    UltraSonicSensor sensor2(48, 47);

    ParkingSpace spaces[] = {
        ParkingSpace(1, sensor1, 4, 5),
        ParkingSpace(2, sensor2, 6, 7)
    };

    OledScreen screens[] = {
        OledScreen(0, 6, 7, 0x3C)
    };

    ParkingTile tile(1, spaces, 2, screens, 1);

    String json = R"({
      "command": {
        "type": "parking_override",
        "component_key": "parking_space_2",
        "mode": "manual",
        "status": "occupied"
      }
    })";

    receiveParkingTileInstructions(tile, json);

    TEST_ASSERT_EQUAL(MANUAL, spaces[1].getOperationMode());
    TEST_ASSERT_TRUE(spaces[1].isOccupied());
}
```

A hardware smoke test verified real sensor operation. The ultrasonic sensor was initialised on physical pins and tested through real distance measurement. A valid reading confirmed correct wiring and sensor functionality.

```cpp
bool run_ultrasonic_sensor_hardware_smoke_test()
{
    ensureTestSerial();

    UltraSonicSensor sensor(
        TEST_ULTRASONIC_TRIG_PIN,
        TEST_ULTRASONIC_ECHO_PIN);

    sensor.setup();

    long distanceCm = sensor.measureDistanceCM();

    Serial.print("[HARDWARE TEST] Ultrasonic distance: ");
    Serial.println(distanceCm);

    return distanceCm > 0;
}
```


The image below shows the final system test results of the Parking Tile. It confirms that all software modules and hardware components passed their tests, including sensor validation, display operation, LED control, and backend communication.

The results demonstrate successful system integration and correct behaviour across all subsystems.

![Embedded Test Results](../../../assets/EmbeddedTestParkingTile.png)

**Figure 7**  
*System test results of all the tests.*




The video demonstrates the Parking Tile in a real-world scenario. A physical object is placed on a parking space, simulating vehicle presence. The ultrasonic sensor detects this change and updates the system state.

As a result, the RGB LED changes from green to red, indicating occupancy. Both OLED displays update in real time, reflecting the reduced number of available parking spaces. The backend receives updated state information accordingly.

Additionally, the underside of the prototype is visible, showing the perfboard-based hardware implementation and wiring structure.

<video width="640" height="480" controls>
  <source src="../../../assets/RealiseVideoParkingTile.mp4" type="video/mp4">
</video>
**Figure 8**  
*System demonstration in real operation.*

### 8.1 Testing Summary

The testing results confirm that all requirements defined in Table 1 were successfully fulfilled: R1 – Visual Feedback, R2 – Vehicle Detection, R3 – Backend Communication, R4 – Information Display, R5 – Modularity, R6 – Expandability, R7 – Hardware Stability, R8 – Testability, and R9 – Correct Operation. The successful completion of unit tests, integration tests, hardware smoke tests, and real-world demonstrations validates both the functional and non-functional aspects of the Parking Tile, confirming that the system operates reliably and as intended.


## 9. Proof of Functionality: Meeting the Requirements

Once the diagnostic tests proved the board was electrically sound, the system was powered on. The physical hardware actively proves that all predefined requirements have been met through the following evidence:

## Proof of R1 – Visual Feedback

The visual feedback requirement was fulfilled through the implementation of an RGB LED that indicates the occupancy status of a parking space. During manual testing and the final system demonstration (Figure 8), the LED consistently changed from green (available) to red (occupied) when an object was detected by the ultrasonic sensor. This behaviour was repeatedly observed and matched the expected occupancy state. The successful operation of the LED subsystem is also reflected in the overall test results shown in Figure 7. Together, these results demonstrate that the system provides clear and immediate visual feedback to users.

## Proof of R2 – Vehicle Detection

The vehicle detection requirement was fulfilled through the integration of the HC-SR04 ultrasonic sensor. The hardware smoke tests implemented in `test_hardware.cpp` verified that the sensor produced valid distance measurements. Furthermore, integration tests contained in `test_all.cpp` confirmed that measured distances were correctly translated into parking occupancy states. The successful execution of these tests (Figure 7), combined with the real-world demonstration (Figure 8), provides evidence that the vehicle detection functionality operates correctly.

## Proof of R3 – Backend Communication

The backend communication requirement was fulfilled through Wi-Fi-based JSON communication. Integration tests implemented in `test_all.cpp` verified that parking status updates were transmitted correctly and that incoming commands were processed as expected. The successful test results shown in Figure 7 demonstrate reliable communication between the Parking Tile and the backend system, providing evidence that the communication requirement has been met.

## Proof of R4 – Information Display

The information display requirement was fulfilled through the integration of SSD1306 OLED displays. During manual testing, the displays correctly presented parking information and updated when occupancy states changed. This behaviour was further verified during the final demonstration shown in Figure 8, where the number of available parking spaces changed in response to vehicle detection. The successful operation of the display subsystem contributes to the overall test results presented in Figure 7.

## Proof of R5 – Modularity

The modularity requirement was fulfilled through the implementation of separate classes such as `UltraSonicSensor`, `ParkingSpace`, `OledScreen`, and `ParkingTile`. The ability to create dedicated unit tests in `test_all.cpp` for individual modules demonstrates that components can be tested independently of one another. This separation of responsibilities provides evidence of a modular software architecture.

## Proof of R6 – Expandability

The expandability requirement was fulfilled through the use of a class-based architecture and a hardware design that exposes additional GPIO connections. The successful integration of multiple independent modules, as verified through `test_all.cpp`, demonstrates that the architecture supports the addition of future components without requiring significant redesign. This provides evidence that the system can be expanded beyond its current functionality.

## Proof of R7 – Hardware Stability

The hardware stability requirement was fulfilled through the transition from a temporary breadboard prototype to a soldered perfboard implementation. Electrical continuity checks were performed before system operation, while the hardware smoke tests in `test_hardware.cpp` verified correct hardware functionality. The successful completion of these tests (Figure 7) and stable operation during the demonstration (Figure 8) provide evidence that the hardware implementation is reliable.

## Proof of R8 – Testability

The testability requirement was fulfilled through the implementation of a layered testing strategy. Unit tests, integration tests, and hardware smoke tests were developed and executed using `test_all.cpp` and `test_hardware.cpp`. The successful execution of all tests, shown in Figure 7, demonstrates that the system can be systematically validated and that faults can be isolated to specific components when required.

## Proof of R9 – Correct Operation

The correct operation requirement was fulfilled through successful end-to-end validation of the complete system. The tests implemented in `test_all.cpp` and `test_hardware.cpp` verified the correct behaviour of individual components and subsystem interactions, while the real-world demonstration (Figure 8) confirmed that vehicle detection, LED feedback, OLED updates, and backend communication functioned together as intended. The combination of automated tests, hardware verification, and practical demonstration provides evidence that the Parking Tile operates according to its design requirements.

## 10. Conclusion and Findings

This section consolidates the findings from the individual sub-conclusions and provides a final answer to the main research question.

The sub-conclusions show that all key aspects of the system were successfully implemented and validated. The requirement analysis confirmed that all functional and non-functional requirements were met, including vehicle detection, visual feedback, backend communication, and modular software design. The component verification phase demonstrated that both hardware and software modules function correctly in isolation, reducing integration risks. The hardware implementation on a perfboard introduced a stable and reliable physical structure, while necessary design adjustments such as structured wiring and improved cable organisation further increased robustness. Finally, the layered testing strategy confirmed correct system behaviour under real-world conditions through unit, integration, and hardware tests.

Together, these results show that both the individual components and the complete system operate as intended and form a consistent and reliable embedded solution.

### Final Answer to the Main Research Question

The Parking Tile can be successfully realised using an ESP32-S3 by combining a modular software architecture, a stable perfboard-based hardware implementation, and a structured validation process consisting of component verification, unit testing, integration testing, and hardware testing. This approach ensures that all functional and non-functional requirements are fulfilled, resulting in a reliable, maintainable, and scalable embedded system suitable for real-world application.


## 11. Handover Strategy and Future Roadmap

This section provides an engineering roadmap for successor developers who will inherit this project. The current perfboard implementation serves as a validated prototype, but several critical improvements are required for production deployment and scalability.

### 11.1 Centralised Microcontroller Architecture

**Mayor's Requirement:** All programs from other tiles must run on a single ESP32-S3 microcontroller, which acts as the central controller for the entire parking system.

**Current State:** Each Parking Tile currently operates with its own ESP32-S3 microcontroller. This distributed architecture works for prototyping but does not meet the centralised control requirement.

**Required Changes:**
1. **Single Controller Design:** One ESP32-S3 must be designated as the central controller for all parking tiles.
2. **Communication Protocol:** Tiles must communicate with the central controller via a serial bus (I²C, SPI, or UART) rather than independent Wi-Fi connections.

**Implementation Priority:** **HIGH** – This is a mandatory requirement from the Mayor's office and must be addressed before production deployment.

### 11.2 Power Supply Infrastructure

**Current State:** The system currently operates exclusively via USB-C connected to a computer. This is not viable for permanent installation or field deployment.

**Required Changes:**
1. **Independent Power Supply:** Each tile must be powered by a dedicated power supply with appropriate current rating.
2. **Power Distribution Network:** A centralised power distribution system must be designed to supply all tiles from a single power source.

**Implementation Priority:** **HIGH** – Without proper power infrastructure, the system cannot be deployed outside the laboratory environment.

### 11.3 Custom PCB Transition

**Current State:** The system is implemented on a perfboard with manual soldering and wiring. This is suitable for prototyping but not for production.

**Required Changes:**
1. **PCB Design:** Export the perfboard layout to KiCad or similar EDA software for custom PCB design.
2. **Multi-Layer Design:** Implement a 2-layer or 4-layer PCB for improved signal integrity and power distribution.
3. **Component Footprints:** Use standard component footprints to ensure availability and ease of replacement.
4. **Manufacturing:** Order PCBs from a professional manufacturer (e.g., JLCPCB, PCBWay) for consistent quality.
5. **Assembly:** Consider using PCB assembly services for soldering components, or establish a standardised assembly process for in-house production.

**Implementation Priority:** **MEDIUM** – Should be completed before the next sprint cycle to enable production deployment.

### 11.4 Contact Information for Handover

For questions regarding this project, successor developers should contact:

*   **Primary Contact:** Niklas Kiess (Junior Embedded & Robotics Developer)
*   **Repository:** GitLab – City New Amsterdam City Sim Learning Group
*   **Documentation:** All design documents, schematics, and firmware are stored in the project repository
*   **Testing Framework:** Unit tests and integration tests are documented in Section 8


## 12. References

[1] Espressif Systems. (2023). *ESP32-S3 Hardware Design Guidelines*. Technical Report.

[2] PCBSync. (n.a.). *J-STD-001 Explained: Complete Guide to Soldering Requirements & Certification*. https://pcbsync.com/j-std-001/. Date of retrieval: 04.06.2026

[3] Kiess, N. (2026). *Analysis of Circuit Board Types (Sprint 4)*. GitLab Repository – City New Amsterdam City Sim Learning Group.

[4] Kiess, N. (2026). *Board Design (V0.3)*. GitLab Repository – City New Amsterdam City Sim Learning Group.

---

*AI-assisted tools were used to support the creation of this document.*
