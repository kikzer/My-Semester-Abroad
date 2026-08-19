# Parts Description

This document sums up all the parts that are being used for the parking tile and how to use them on the ESP32 S3.


## Overview

- LDR
- OLED Display
- LED
- RGB LED
- Ultrasonic Sensor (HC-SR04)
## RGB LED

What you need for an RGB LED

- RGB LED (common cathode or anode, usually 4 pins)
- 3x Resistors (e.g., 220Ω for each color)
- 3 GPIO pins (one for each color: Red, Green, Blue)
- GND connection (for common cathode) or VCC (for common anode)

#### Example Code

```c++
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Red
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Green
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(1000);

  // Blue
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(1000);
}
```

#### Example Design

```
Pin 9 (ESP32-S3) ──[220Ω]──┬─|>─┐
                            │    │
Pin 10 (ESP32-S3) ──[220Ω]──┼─|>─┤ RGB LED
                            │    │
Pin 11 (ESP32-S3) ──[220Ω]──┴─|>─┘
                            │
                           GND
```

##### Example Outcomne

![alt text](../assets/RGBConnection.jpg)

> Note: For a common anode RGB LED, connect the common pin to 3.3V and use LOW to turn on each color.

> References: [RGB LED Tutorial](https://arduinogetstarted.com/tutorials/arduino-rgb-led)

## Light Dependent Resistor (LDR)

What you need for a LDR

- Resistor with 10k Ohm
- 3.3V power supply
- GND connection
- Pin connection

#### Example Code

```c++
const int LDR_PIN = 5;
const int THRESHOLD = 2000;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  if (ldrValue < THRESHOLD) {
    Serial.println("Dark");
  } else {
    Serial.println("Light");
  }

  delay(1000);
}
```

#### Example Design

```
3V3 ────[LDR]───────┬─────── Pin 5 (ESP32-S3)
                    │
                  [10kΩ]
                    │
                   GND

```

> References: [LDR-Datasheet](https://components101.com/resistors/ldr-datasheet)

## OLED Display

What you need for a OLED

- 3.3V power supply for VDD
- Pin for Serial Clock (SCL)
- Pin for Serial Data (SDA)
- Connection to GND
- Libaries Adafruit_GFX and Adafruit_SSD1306 for display control
- Wire for a locating to the correct pins

#### Example Code

```c++
// used libraries:
//Adafruit_GFX and Adafruit_SSD1306 for OLED display control
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define I2C_SDA 8
#define I2C_SCL 9

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8

const int MAX_SLOTS = 4;
int freeSlots = 0;
int currentLine = 0;

void printCentered(const char* text) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int y = currentLine * h;
  display.setCursor((SCREEN_WIDTH - w) / 2, y);
  display.println(text);
  currentLine++;
}

void printLeft(const char* text) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int y = currentLine * h;
  display.setCursor(0, y);
  display.println(text);
  currentLine++;
}

void resetCursor() {
  currentLine = 0;
}

void displaySlotInformation() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  resetCursor();

  printCentered("Parking:");
  printCentered("");

  char slotText[16];
  sprintf(slotText, "%d / %d", freeSlots, MAX_SLOTS);
  printCentered(slotText);

  display.display();
}

void setup() {
  Wire.begin(I2C_SDA, I2C_SCL);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  Serial.println(F("Connected"));
}

void loop() {
  displaySlotInformation();
  delay(2000);
  display.clearDisplay();
}
```

#### Example Design

| Component    | ESP32-S3 Pin | OLED Pin |
| ------------ | ------------ | -------- |
| Power (3V3)  | 3V3          | VCC      |
| Ground (GND) | GND          | GND      |
| Data (SDA)   | Pin 8        | SDA      |
| Clock (SCL)  | Pin 9        | SCL      |

> References: [SSD1306 Oled Display](https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/)

## LED (light-emitting diode)

What you need for a LED

- LED
- Resistor with 220 Ohm
- Pin for GND
- Pin to control the LED

### Example Code

```c++
const int LED_PIN = 25;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(300);
  digitalWrite(LED_PIN, LOW);
  delay(300);
}
```

### Example Design

```
Pin 25 (ESP32-S3) ────[LED]───────┬
                                  │
                                [220Ω]
                                  │
                                 GND
```

> References: [Smart Cities Dokumentation](https://studiosmartcities.nl/embedded/arduino/first-esp32-project/)

## Ultrasonic Sensor (HC-SR04)

What you need for a HC-SR04

- 5V power supply for VCC
- Pin for Trigger (TRIG)
- Pin for Echo (ECHO)
- Connection to GND
- Library: NewPing by Tim Eckel

#### How is it working

Using Sound waves with a frequencie, that cannot be heard by human ears the distance will be meassured. One of the ultrasonic transducers is a trasnmitter and the other one is the receiver that waits for a bounce back from an object.
Using the length of the signal a correct distance is calculated. The formula for each is:

- Distance = Speed x Time
- Time = Distance / Speed
- Speed = Distance / Time

Time has the type microseconds (µs). \
Speed has the general Speed of sound, which is 0.034 cm/µs. \
You also need to divide the Distance by 2, because there is the travel distance to the object and back to the receiver.

#### Example Code

```c++
const int TRIG_PIN = 2;
const int ECHO_PIN = 42;
const int THRESHOLD_CM = 3;  // Distance threshold for detection

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;  // Convert to cm
  return distance;
}

void loop() {
  long distance = measureDistance();

  if (distance < THRESHOLD_CM) {
    Serial.println("Occupied");
  } else {
    Serial.println("Free");
  }

  delay(500);
}
```

#### Example Design

| Component    | ESP32-S3 Pin | HC-SR04 Pin |
| ------------ | ------------ | ----------- |
| Power (5V)   | 5V           | VCC         |
| Ground (GND) | GND          | GND         |
| Trigger      | Pin 10       | TRIG        |
| Echo         | Pin 11       | ECHO        |

```
ESP32-S3                    HC-SR04
   5V  ──────────────────── VCC
   GND ──────────────────── GND
   Pin 10 ────────────────── TRIG
   Pin 11 ────────────────── ECHO
```

> References: [HC-SR04 Tutorial – Maker Guides](https://www.makerguides.com/hc-sr04-arduino-tutorial/), [Last Minute Engineers](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/)
