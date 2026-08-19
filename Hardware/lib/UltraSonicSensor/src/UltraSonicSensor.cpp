#include "UltraSonicSensor.h"

/**
 * @brief Constructor for UltraSonicSensor. Initializes trigger and echo pins.
 * @param trigPin The trigger pin number.
 * @param echoPin The echo pin number.
 */
UltraSonicSensor::UltraSonicSensor(uint8_t trigPin, uint8_t echoPin)
    : trigPin(trigPin), echoPin(echoPin) {}

/**
 * @brief Initializes the trigger and echo pins for the ultrasonic sensor.
 */
void UltraSonicSensor::setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
 * @brief Measures the distance in centimeters using the ultrasonic sensor.
 * @return The measured distance in centimeters.
 */
long UltraSonicSensor::measureDistanceCM() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}

uint8_t UltraSonicSensor::getTrigPin() const
{
    return trigPin;
}

uint8_t UltraSonicSensor::getEchoPin() const
{
    return echoPin;
}