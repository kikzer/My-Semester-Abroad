#include "OledScreen.h"

OledScreen::OledScreen(uint8_t sideOfStreet, uint8_t sdaPin, uint8_t sclPin, uint8_t displayAdress, TwoWire *wirePort)
    : sideOfStreet(sideOfStreet), sdaPin(sdaPin), sclPin(sclPin), displayAdress(displayAdress),
      wirePort(wirePort ? wirePort : &Wire),
      display(screenWidth, screenHeight, wirePort ? wirePort : &Wire, -1) {}

void OledScreen::begin()
{
  display.begin(SSD1306_SWITCHCAPVCC, displayAdress);
  display.clearDisplay();
  Serial.print("[OLED] Initialized on I2C address 0x");
  Serial.println(displayAdress, HEX);
}

void OledScreen::print(const char *text, const char *position)
{
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int y = currentLine * h;
  if (strcasecmp(position, "center") == 0)
  {
    display.setCursor((screenWidth - w) / 2, y);
  }
  else if (strcasecmp(position, "right") == 0)
  {
    display.setCursor(screenWidth - w, y);
  }
  else
  {
    display.setCursor(0, y);
  }
  display.println(text);
  currentLine++;
}

void OledScreen::resetCursor()
{
  currentLine = 0;
}

void OledScreen::skipLine()
{
  currentLine++;
}

void OledScreen::clear()
{
  display.clearDisplay();
}

void OledScreen::showClosed()
{
  clear();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  resetCursor();
  print("PARKING", "center");
  skipLine();
  print("LOT CLOSED", "center");
  display.display();
}

void OledScreen::displaySlotInformationLeft(int freeSlotsLeft, int freeSlotsRight, int maxSlots)
{
  clear();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  resetCursor();
  print("Free slots", "center");
  skipLine();

  char leftText[20];
  char rightText[20];
  sprintf(leftText, "%d <==", freeSlotsLeft);
  sprintf(rightText, "==> %d", freeSlotsRight);
  print(leftText, "left");
  print(rightText, "right");
  skipLine();

  char totalText[24];
  sprintf(totalText, "Total: %d", maxSlots);
  print(totalText, "center");
  display.display();
}

void OledScreen::displaySlotInformationRight(int freeSlotsLeft, int freeSlotsRight, int maxSlots)
{
  clear();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  resetCursor();
  print("Free slots", "center");
  skipLine();

  char leftText[20];
  char rightText[20];
  sprintf(leftText, "%d <==", freeSlotsRight);
  sprintf(rightText, "==> %d", freeSlotsLeft);
  print(leftText, "left");
  print(rightText, "right");
  skipLine();

  char totalText[24];
  sprintf(totalText, "Total: %d", maxSlots);
  print(totalText, "center");
  display.display();
}

void OledScreen::displaySlotInformation(int freeSlotsLeft, int freeSlotsRight, int maxSlots) {
  if (sideOfStreet == 0) {
    displaySlotInformationLeft(freeSlotsLeft, freeSlotsRight, maxSlots);
  } else {
    displaySlotInformationRight(freeSlotsLeft, freeSlotsRight, maxSlots);
  }
}
uint8_t OledScreen::getSdaPin() const { return sdaPin; }

uint8_t OledScreen::getSclPin() const { return sclPin; }

uint8_t OledScreen::getScreenWidth() const { return screenWidth; }

uint8_t OledScreen::getScreenHeight() const { return screenHeight; }