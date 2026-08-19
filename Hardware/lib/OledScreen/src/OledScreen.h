
#pragma once
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <cstring>

class Adafruit_SSD1306;
class TwoWire;

class OledScreen
{
public:
    /**
     * @brief Constructor for OledScreen. Initializes I2C pins and display address.
     * @param sideOfStreet Side identifier (0 = left, 1 = right).
     * @param sdaPin The SDA pin number.
     * @param sclPin The SCL pin number.
     * @param displayAdress The I2C address of the display.
     * @param wirePort Optional TwoWire pointer for alternative I2C bus (defaults to Wire).
     */
    OledScreen(uint8_t sideofStreet, uint8_t sdaPin, uint8_t sclPin, uint8_t displayAdress, TwoWire *wirePort = nullptr);
    
    /**
     * @brief Initializes the OLED display.
     */
    void begin();
    
    /**
     * @brief Prints text to the OLED display at the specified position.
     * @param text The text to print.
     * @param position The position ("left", "center", "right").
     */
    void print(const char *text, const char *position);
    
    /**
     * @brief Resets the cursor to the top of the display.
     */
    void resetCursor();
    
    /**
     * @brief Skips one line on the display.
     */
    void skipLine();
    
    /**
     * @brief Clears the OLED display.
     */
    void clear();
    
    /**
     * @brief Shows a "PARKING LOT CLOSED" message on the display.
     */
    void showClosed();
    
    /**
     * @brief Displays information about free parking slots on the OLED display.
     * Mirrors display for right side (sideOfStreet = 1).
     * @param freeSlotsLeft Number of free slots on the left.
     * @param freeSlotsRight Number of free slots on the right.
     * @param maxSlots Total number of slots.
     */
    void displaySlotInformation(int freeSlotsLeft, int freeSlotsRight, int maxSlots);
    
    /**
     * @brief Gets the SDA pin number.
     * @return The SDA pin number.
     */
    uint8_t getSdaPin() const;
    
    /**
     * @brief Gets the SCL pin number.
     * @return The SCL pin number.
     */
    uint8_t getSclPin() const;
    
    /**
     * @brief Gets the screen width.
     * @return The screen width in pixels.
     */
    uint8_t getScreenWidth() const;
    
    /**
     * @brief Gets the screen height.
     * @return The screen height in pixels.
     */
    uint8_t getScreenHeight() const;

private:
    void displaySlotInformationLeft(int freeSlotsLeft, int freeSlotsRight, int maxSlots);
    void displaySlotInformationRight(int freeSlotsLeft, int freeSlotsRight, int maxSlots);
    uint8_t sdaPin;
    uint8_t sclPin;
    uint8_t displayAdress;
    uint8_t sideOfStreet = 0; // 0 = right, 1 = left from P sign perspective
    static const uint8_t screenWidth = 128;
    static const uint8_t screenHeight = 64;
    Adafruit_SSD1306 display;
    int currentLine = 0;
    TwoWire *wirePort;
};