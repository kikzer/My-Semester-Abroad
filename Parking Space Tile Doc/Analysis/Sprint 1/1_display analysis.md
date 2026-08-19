# Display Analysis

This document evaluates display technologies for showing the number of free parking slots **specifically in the context of the 30x30 cm Parking-Tile test environment**. The analysis focuses on the unique requirements of this compact, energy-efficient, and clearly arranged test setup. Each option is assessed for functionality, technical specifications, power consumption, practical drawbacks, and suitability for the 30x30 cm Parking Tile.

---

## 1. OLED Display (JMD0.96D-1)

### Overview (Suitability for 30x30 cm Tile)

- High contrast display using organic LEDs.
- Excellent readability in all lighting conditions.
- I2C interface uses only 2 GPIO pins (perfect for small tiles with limited space and few GPIOs).

### Technical Specifications

[Here](https://ardushop.ro/en/displays-and-leds/1842-display-oled-096-i2c-white-jmd096d-1-6427854027894.html) you can can find the technical specifications for the OLED Display.

### Pros (for the Parking Tile)

- Very low power consumption – ideal for continuous operation in a small space.
- High contrast and excellent readability – even with changing lighting conditions in the test environment.
- Supports text, numbers, and simple graphics – sufficient for displaying the number of free parking spots.
- Minimal space required and easy integration via I2C – perfect for the compact 30x30 cm tile.
- Wide library support (`Adafruit SSD1306`, `Adafruit GFX`).

### Cons

- Limited display size (max. ~4 digits) – but fully sufficient for the small tile and the simple display of free spots.
- Not suitable for large animations – but not required for the Parking Tile.

> Reference: [JMD0.96D-1 OLED Display – Product Datasheet](https://ardushop.ro/en/displays-and-leds/1842-display-oled-096-i2c-white-jmd096d-1-6427854027894.html)\
> [Datasheet Oled](https://www.datasheethub.com/ssd1306-128x64-mono-0-96-inch-i2c-oled-display/)

---

## 2. LCD Display (e.g., 16x2 Character LCD with I2C Backpack)

### Overview (Suitability for 30x30 cm Tile)

- Text-based display with backlight.
- I2C backpack available for simplified wiring.
- Limited number of characters (16 per line, 2 lines) – often oversized for the small tile and takes up more space.

### Technical Specifications

| Parameter         | Value                     |
| ----------------- | ------------------------- |
| Display Size      | 16x2 characters           |
| Interface         | I2C (with backpack)       |
| Operating Voltage | 5V DC                     |
| Power Consumption | 25–30 mA (with backlight) |
| Backlight         | LED (blue/white)          |

### Pros (for the Parking Tile)

- Very inexpensive.
- Easy to read – but usually too large for the small tile.
- I2C version requires only 2 pins.
- Good for simple status messages.

### Cons

- Relatively large for the 30x30 cm tile, takes up a lot of space.
- Backlight increases power consumption – a disadvantage for continuous operation.
- Lower contrast, harder to read in bright light (e.g., in a bright test environment).
- No graphics or symbols possible.

> Reference: [Vishay LCD016N002B – Technical Datasheet (PDF)](https://www.vishay.com/docs/37484/lcd016n002bcfhet.pdf)

---

## 3. 7-Segment Display (e.g., 4-digit with TM1637 or MAX7219)

### Overview (Suitability for 30x30 cm Tile)

- Large, easily readable numeric display with LED segments.
- Requires driver IC (TM1637 or MAX7219).
- Modules can be chained for both sides of the street.

### Technical Specifications

| Parameter         | Value                              |
| ----------------- | ---------------------------------- |
| Display Type      | 4-digit 7-segment LED              |
| Interface         | I2C (TM1637) or SPI (MAX7219)      |
| Operating Voltage | 3.3V – 5V DC                       |
| Power Consumption | 10–80 mA (depending on digits lit) |
| Digit Height      | 0.36" – 0.56"                      |

### Pros (for the Parking Tile)

- Large, clear numbers – easy to read, but may be too dominant for the small tile.
- Relatively low power consumption (with multiplexing).
- Perfect for displaying numbers only.

### Cons

- Requires additional driver IC and more complex wiring – a disadvantage with limited space.
- No text display possible, only numbers and a few symbols.
- Higher power consumption than OLED.
- Usually too large and complex for the compact 30x30 cm tile.

> References: [TM1637 – Technical Datasheet (PDF)](https://www.datasheetcafe.com/tm1637-datasheet-pdf/)  
> [TM1637 Module – Working Principle & Applications](https://www.elprocus.com/tm1637-module/)  
> [7-Segment Display – General Datasheet (PDF)](https://mil.ufl.edu/3701/docs/OOTB_Max10/sevenSegmentDatasheet.pdf)

---

## 4. LED Dot Matrix (e.g., MAX7219 8x8 or 8x8x4)

### Overview (Suitability for 30x30 cm Tile)

- LED matrix for numbers, symbols, and animations.
- Controlled via MAX7219 IC.
- Modules can be chained for larger displays, but usually too large and power-hungry for the small tile.

### Technical Specifications

| Parameter         | Value                        |
| ----------------- | ---------------------------- |
| Display Size      | 8x8 LEDs (32x8 for 4-module) |
| Interface         | SPI (CLK, DIN, CS)           |
| Operating Voltage | 5V DC                        |
| Power Consumption | 100–300 mA (all LEDs on)     |
| Driver IC         | MAX7219                      |

### Pros (for the Parking Tile)

- Very eye-catching, good for large, public displays.
- Can display numbers, symbols, and animations.

### Cons

- Very high power consumption – unsuitable for continuous operation on a small tile.
- Complex wiring and libraries required.
- Needs more GPIOs (SPI).
- Hard to read small numbers without scaling.
- Oversized and inefficient for the 30x30 cm tile.

> Reference: [MAX7219 8x8 LED Matrix Module – Datasheet (PDF)](https://components101.com/sites/default/files/component_datasheet/max7219-8x8-led-matrix-module-datasheet.pdf)

---

### Comparison Table (Focus: 30x30 cm Tile)

| Feature                | JMD0.96D-1 (OLED) | LCD | 7-Segment | LED Matrix |
| ---------------------- | ----------------- | --- | --------- | ---------- |
| Low power consumption  | ✅                | ❌  | ✅        | ❌         |
| High readability       | ✅                | ✅  | ✅        | ✅         |
| Easy integration       | ✅                | ✅  | ❌        | ❌         |
| Minimal space required | ✅                | ❌  | ❌        | ❌         |
| Cost-effective         | ✅                | ✅  | ✅        | ✅         |

---

## Conclusion

**For the 30x30 cm Parking Tile, the JMD0.96D-1 OLED display is the most practical, reliable, and cost-effective solution.**

The analysis shows that only the OLED display fully meets all requirements of the compact test environment: It is space-saving, energy-efficient, highly readable, and easy to integrate. This makes it the best choice for displaying the number of free parking spots on the 30x30 cm Parking Tile.
