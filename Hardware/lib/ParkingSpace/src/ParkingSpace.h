
#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H

#include "OperationEnumParkingSpace.h"
#include "UltraSonicSensor.h"
#include <Arduino.h>
#include "HelperMethod.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class UltraSonicSensor;

class ParkingSpace
{
    const int id;
    UltraSonicSensor sensor;
    const uint8_t ledRed;
    const uint8_t ledGreen;
    static constexpr uint8_t THRESHOLD_CM = 11;
    bool occupied = true;
    OperationEnumParkingSpace operationMode = AUTO;
    TaskHandle_t occupationTaskHandle = NULL;

    void checkOccupationDuration();
    static void checkOccupationDurationTask(void *pvParameters);

public:
    ParkingSpace(int id, UltraSonicSensor sensor, uint8_t ledRed, uint8_t ledGreen);
    void setup();
    long measureDistance();
    void debugPrintStatus(long distance);
    void checkParkingStatus();
    bool isOccupied() const;
    void setOccupied(bool occ);
    void changeOperationMode(OperationEnumParkingSpace newMode);
    int getId() const;
    OperationEnumParkingSpace getOperationMode() const;
};

#endif