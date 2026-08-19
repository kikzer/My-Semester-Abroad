#include "ParkingTile.h"

/**
 * @brief Constructor for ParkingTile. Initializes parking spaces and screens.
 * @param tileId Unique identifier for the parking tile.
 * @param spaces Array of ParkingSpace objects.
 * @param spaceCount Number of parking spaces.
 * @param screens Array of OledScreen objects.
 * @param screenCount Number of OLED screens.
 */
ParkingTile::ParkingTile(int tileId, ParkingSpace *spaces, int spaceCount, OledScreen *screens, int screenCount)
        : id(tileId),
            parkingSpaces(spaces),
            oledScreen(screens),
            operationMode(OPEN),
            parkingSpaceCount(spaceCount),
            oledScreenCount(screenCount)
{
}

/**
 * @brief Initializes all parking spaces and OLED screens in the tile.
 */
void ParkingTile::setup()
{
    for (int i = 0; i < parkingSpaceCount; i++)
    {
        parkingSpaces[i].setup();
    }

    for (int i = 0; i < oledScreenCount; i++)
    {
        oledScreen[i].begin();
    }
}

/**
 * @brief Updates the occupation status of all parking spaces and screens.
 */
void ParkingTile::updateOccupationStatus()
{
    if (operationMode == CLOSED)
    {
        for (int i = 0; i < oledScreenCount; i++)
        {
            oledScreen[i].showClosed();
        }
        return;
    }

    for (int i = 0; i < parkingSpaceCount; i++)
    {
        parkingSpaces[i].checkParkingStatus();
    }
}

/**
 * @brief Returns a pointer to the ParkingSpace with the given ID.
 * @param targetId The ID of the parking space to find.
 * @return Pointer to ParkingSpace if found, nullptr otherwise.
 */
ParkingSpace *ParkingTile::getParkingSpaceById(int targetId) const
{
    for (int i = 0; i < parkingSpaceCount; i++)
    {
        if (parkingSpaces[i].getId() == targetId)
        {
            return &parkingSpaces[i];
        }
    }

    return nullptr;
}

/**
 * @brief Sets the occupied status for a parking space by ID.
 * @param targetId The ID of the parking space.
 * @param occupied True if occupied, false otherwise.
 */
void ParkingTile::setParkingSpaceOccupiedById(int targetId, bool occupied)
{
    ParkingSpace *space = getParkingSpaceById(targetId);
    if (space != nullptr)
    {
        space->setOccupied(occupied);
    }
}

/**
 * @brief Gets the unique identifier of the parking tile.
 * @return The tile ID.
 */
int ParkingTile::getId() const
{
    return id;
}

/**
 * @brief Sets the operation mode for the parking tile.
 * @param newMode The new operation mode.
 */
void ParkingTile::setOperationMode(OperationEnumParkingTile newMode)
{
    operationMode = newMode;
}

/**
 * @brief Gets the current operation mode of the parking tile.
 * @return The operation mode.
 */
OperationEnumParkingTile ParkingTile::getOperationMode() const
{
    return operationMode;
}

/**
 * @brief Gets the number of parking spaces in the tile.
 * @return Number of parking spaces.
 */
int ParkingTile::getAmountOfParkingSpaces() const
{
    return parkingSpaceCount;
}

/**
 * @brief Gets the number of OLED screens in the tile.
 * @return Number of OLED screens.
 */
int ParkingTile::getAmountOfOledScreens() const
{
    return oledScreenCount;
}