# Proof Realise Challenge Report

## Introduction

This report documents how I implemented and validated the embedded test strategy
for the ESP32-S3 parking system challenge. It explains the requirements,
implementation decisions, test methods, and evidence that the solution meets
the requested goals.

## Challenge Requirements

The challenge required:

1. Embedded testing with unit tests.
2. At least two different testing methods.
3. Voltage check as part of testing.
4. Load testing over a longer period.
5. Integration tests.
6. Linter or static analysis evidence for coding standards.
7. Proof/realisation documentation and material suitable for stakeholder review
   ("mayor" audience).

## What I Implemented

### Test Files

- `test/test_all.cpp`
  Contains the Unity runner and all logical, integration, and hardware test
  entry points.
- `test/test_hardware.cpp`
  Contains hardware-focused helper functions used by the runner.

### Test Methods Used

The solution uses multiple test methods:

1. Unit tests
   - Enum value checks
   - Utility timing checks (`wait`)
   - Class state/getter checks (`ParkingSpace`, `ParkingTile`, `OledScreen`)
2. Integration tests
   - Backend JSON command handling integrated with `ParkingTile` and
     `ParkingSpace` state transitions
3. Hardware-in-the-loop tests
   - Real ultrasonic sensor smoke read
   - ADC voltage range test
   - Longer-duration ultrasonic load/soak test

## Subquestion: How did I test the system and meet the requirements?

I met the requirements by combining logical validation and real hardware
validation in one repeatable Unity test flow.

- Embedded unit tests are executed directly on the ESP32-S3 using PlatformIO
  test runner.
- Integration tests validate that backend JSON instructions cause the expected
  changes in tile and parking-space states.
- Voltage is checked through ADC reading and conversion to volts, then validated
  against an expected range.
- Load testing is performed as a timed loop that repeatedly reads ultrasonic
  values and verifies stability/range and minimum sample count.

## Hardware/Load Details

- Ultrasonic smoke test
  - Confirms one real sensor reading in valid range (0..400 cm).
- Voltage test
  - Reads ADC on `TEST_ADC_PIN`, calculates voltage, validates against
    `TEST_VOLTAGE_MIN_V..TEST_VOLTAGE_MAX_V`.
- Load test
  - Runs for `TEST_LOAD_DURATION_MS` with repeated distance reads.
  - Fails if out-of-range values appear or if sample count is too low.

These parameters are configurable in `test/test_hardware.cpp` via `#define`
macros.

## Coding Standards Check (Linter / Static Analysis)

Static checks are performed with PlatformIO's check/lint tooling.

Recommended command:

```powershell
C:\Users\Niklas\.platformio\penv\Scripts\platformio.exe check --environment esp32-s3-devkitm-1
```

Build/test pipeline commands used:

```powershell
C:\Users\Niklas\.platformio\penv\Scripts\platformio.exe test --verbose --environment esp32-s3-devkitm-1
```

## Proof Realise / Video Evidence Plan

To produce final proof material:

1. Record upload + test execution in terminal.
2. Show serial output of hardware smoke/voltage/load results.
3. Show pass/fail summary from Unity.
4. Show this report file and `test/README` for traceability.

This creates an auditable story from requirement to implementation to evidence.

## Summary

The testing setup now covers unit, integration, and hardware/load validation on
the ESP32-S3 target, including a voltage check and long-duration sensor read
scenario, and provides documentation suitable for challenge review.