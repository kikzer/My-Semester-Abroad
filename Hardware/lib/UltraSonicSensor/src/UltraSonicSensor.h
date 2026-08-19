
#pragma once
#include <Arduino.h>

class UltraSonicSensor
{
private:
    uint8_t trigPin;
    uint8_t echoPin;

public:
    UltraSonicSensor(uint8_t trigPin, uint8_t echoPin);
    void setup();
    long measureDistanceCM();
    uint8_t getTrigPin() const;
    uint8_t getEchoPin() const;
};