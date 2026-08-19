#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

#include "ParkingSpace.h"
#include "OledScreen.h"
#include "ParkingTile.h"
#include "UltraSonicSensor.h"
#include "Backend.h"
#include "HelperMethod.h"

// SENSORS
UltraSonicSensor sensor1(19, 20);
UltraSonicSensor sensor2(48, 45);
UltraSonicSensor sensor3(41, 42);
UltraSonicSensor sensor4(37, 38);

// PARKING SPACES
ParkingSpace parkingSpaces[] = {
    ParkingSpace(1, sensor1, 47, 21),
    ParkingSpace(2, sensor2, 36, 35),
    ParkingSpace(3, sensor3, 1, 2),
    ParkingSpace(4, sensor4, 40, 39)};

const int8_t sda1 = 6;
const int8_t scl1 = 7;
const int8_t sda2 = 15;
const int8_t scl2 = 16;

OledScreen oledScreens[] = {
    OledScreen(0, sda1, scl1, 0x3C, &Wire),
    OledScreen(1, sda2, scl2, 0x3C, &Wire1)};

const size_t parkingSpaceCount = sizeof(parkingSpaces) / sizeof(ParkingSpace);
const size_t oledScreenCount = sizeof(oledScreens) / sizeof(OledScreen);

// PARKING TILES
ParkingTile parkingTiles[] = {
    ParkingTile(1, parkingSpaces, parkingSpaceCount, oledScreens, oledScreenCount)};

const size_t parkingTileCount = sizeof(parkingTiles) / sizeof(ParkingTile);

unsigned long lastStatusUpdateMs = 0;
const unsigned long statusUpdateIntervalMs = 5000;

void setupParkingTiles()
{
  for (size_t i = 0; i < parkingTileCount; i++)
  {
    parkingTiles[i].setup();
  }
}

void updateParkingTiles()
{
  for (size_t i = 0; i < parkingTileCount; i++)
  {
    parkingTiles[i].updateOccupationStatus();
    wait(50);
  }
}

void sendStatusAllParkingTiles()
{
  Serial.println("[DEBUG] Sending status of all parking tiles to backend...");
  ensureWifiConnected();

  if (WiFi.status() == WL_CONNECTED)
  {
    ensureFreshToken();
    ensureMqttConnected();
  }
  else
  {
    Serial.println("[ERROR] Cannot send status, WiFi not connected");
    return;
  }

  for (size_t i = 0; i < parkingTileCount; i++)
  {
    sendParkingTileStatus(parkingTiles[i]);
  }
}

void updateParkingSpaceOperation(OperationEnumParkingSpace newMode)
{
  for (size_t i = 0; i < parkingSpaceCount; i++)
  {
    parkingSpaces[i].changeOperationMode(newMode);
  }
}

void updateParkingTileOperation(OperationEnumParkingTile newMode)
{
  for (size_t i = 0; i < parkingTileCount; i++)
  {
    parkingTiles[i].setOperationMode(newMode);
  }
}

void updateOledScreenDisplay(int freeSlotsLeft, int freeSlotsRight, int maxSlots)
{
  for (size_t i = 0; i < oledScreenCount; i++)
  {
    oledScreens[i].displaySlotInformation(freeSlotsLeft, freeSlotsRight, maxSlots);
  }
}

// Toggle occupied state for all parking spaces every 20 seconds for backend test
void testCycleParkingSpacesOccupied()
{
  static unsigned long lastToggle = 0;
  static bool toggle = false;
  unsigned long now = millis();
  if (now - lastToggle >= 20000)
  {
    lastToggle = now;
    toggle = !toggle;
    Serial.print("[TEST] Cycling parking space occupied states. Toggle: ");
    Serial.println(toggle ? "EVEN=occupied" : "ODD=occupied");
    for (size_t i = 0; i < parkingSpaceCount; i++)
    {
      bool occupied = toggle ? (i % 2 == 0) : (i % 2 == 1);
      parkingSpaces[i].setOccupied(occupied);
      parkingSpaces[i].changeOperationMode(occupied ? MANUAL : AUTO);
      Serial.print("  ParkingSpace ");
      Serial.print(i + 1);
      Serial.print(": setOccupied=");
      Serial.print(occupied ? "true" : "false");
      Serial.print(", operationMode=");
      Serial.println(occupied ? "MANUAL" : "AUTO");
    }
  }
}

void setup()
{
  Wire.begin(sda1, scl1);
  Wire1.begin(sda2, scl2);
  
  Serial.begin(115200);
  delay(100);
  Serial.println("[DEBUG] Starting setup...");

  setupParkingTiles();
  setupBackend(parkingTiles[0]);

  Serial.println("[DEBUG] Setup complete.");
}

void loop()
{
  ensureWifiConnected();
  ensureMqttConnected();
  updateParkingTiles();
  updateOledScreenDisplay(
      2 - (parkingSpaces[0].isOccupied() + parkingSpaces[1].isOccupied()),
      2 - (parkingSpaces[2].isOccupied() + parkingSpaces[3].isOccupied()),
      4);

  unsigned long now = millis();
  if (now - lastStatusUpdateMs >= statusUpdateIntervalMs)
  {
    lastStatusUpdateMs = now;
    sendStatusAllParkingTiles();
  }

  Serial.println("[DEBUG] Loop iteration complete, sleeping for 1 second...");
  Serial.println("--------------------------------------------------");
  wait(1000);
}