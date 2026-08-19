#include "ParkingSpace.h"


ParkingSpace::ParkingSpace(int id, UltraSonicSensor sensor, uint8_t ledRed, uint8_t ledGreen)
    : id(id), sensor(sensor), ledRed(ledRed), ledGreen(ledGreen) {}


void ParkingSpace::setup()
{
    sensor.setup();
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    setOccupied(occupied);
}

long ParkingSpace::measureDistance()
{
    return sensor.measureDistanceCM();
}


void ParkingSpace::debugPrintStatus(long distance)
{
    Serial.print("ParkingSpace ID: ");
    Serial.print(id);
    Serial.print(" - Distance: ");
    Serial.print(distance);
    Serial.print(" cm - Mode: ");

    switch (operationMode)
    {
    case AUTO:
        Serial.print("AUTO");
        break;
    case MANUAL:
        Serial.print("MANUAL");
        break;
    }

    Serial.print(" - Status: ");
    Serial.println(isOccupied() ? "Occupied" : "Free");
}


void ParkingSpace::checkParkingStatus()
{
    if (operationMode == AUTO)
    {
        long distance = measureDistance();
        debugPrintStatus(distance);

        if (distance < THRESHOLD_CM)
        {
            if (occupationTaskHandle == NULL)
            {
                xTaskCreate(
                    ParkingSpace::checkOccupationDurationTask,
                    "occTask",
                    4096,
                    this,
                    1,
                    &occupationTaskHandle);
            }
        }
        else
        {
            if (occupationTaskHandle != NULL)
            {
                vTaskDelete(occupationTaskHandle);
                occupationTaskHandle = NULL;
            }

            setOccupied(false);
        }
    }
    else if (operationMode == MANUAL)
    {
        debugPrintStatus(-1);
    }
}

void ParkingSpace::checkOccupationDuration()
{
    unsigned long start = millis();

    while (millis() - start < 5000UL)
    {
        long distance = measureDistance();
        if (distance >= THRESHOLD_CM)
        {
            return;
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }

    setOccupied(true);
}

void ParkingSpace::checkOccupationDurationTask(void *pvParameters)
{
    ParkingSpace *self = static_cast<ParkingSpace *>(pvParameters);
    if (self == nullptr)
    {
        vTaskDelete(NULL);
    }

    self->checkOccupationDuration();
    self->occupationTaskHandle = NULL;
    vTaskDelete(NULL);
}

bool ParkingSpace::isOccupied() const
{
    return occupied;
}

void ParkingSpace::changeOperationMode(OperationEnumParkingSpace newMode)
{
    operationMode = newMode;
}
OperationEnumParkingSpace ParkingSpace::getOperationMode() const
{
    return operationMode;
}


int ParkingSpace::getId() const
{
    return id;
}
void ParkingSpace::setOccupied(bool occ)
{
    occupied = occ;

    digitalWrite(ledRed, occupied ? HIGH : LOW);
    digitalWrite(ledGreen, occupied ? LOW : HIGH);
}
