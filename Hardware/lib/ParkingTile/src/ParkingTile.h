#pragma once

#include "OperationEnumParkingTile.h"
#include "ParkingSpace.h"
#include "OledScreen.h"

class ParkingTile
{
private:
    int id;
    ParkingSpace *parkingSpaces;
    OledScreen *oledScreen;
    OperationEnumParkingTile operationMode;
    int parkingSpaceCount;
    int oledScreenCount;

public:
    ParkingTile(int tileId, ParkingSpace *spaces, int spaceCount, OledScreen *screens, int screenCount);
    void setup();
    void updateOccupationStatus();
    ParkingSpace *getParkingSpaceById(int id) const;
    void setParkingSpaceOccupiedById(int id, bool occupied);
    int getId() const;
    void setOperationMode(OperationEnumParkingTile newMode);
    OperationEnumParkingTile getOperationMode() const;
    int getAmountOfParkingSpaces() const;
    int getAmountOfOledScreens() const;
};