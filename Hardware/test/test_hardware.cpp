#include <Arduino.h>
#include <unity.h>
#include <limits.h>

#include "UltraSonicSensor.h"

static bool _tests_serial_initialized = false;

static void ensureTestSerial()
{
  if (!_tests_serial_initialized)
  {
    Serial.begin(115200);
    delay(50);
    _tests_serial_initialized = true;
  }
}

#ifndef TEST_ULTRASONIC_TRIG_PIN
#define TEST_ULTRASONIC_TRIG_PIN 19
#endif

#ifndef TEST_ULTRASONIC_ECHO_PIN
#define TEST_ULTRASONIC_ECHO_PIN 20
#endif


bool run_ultrasonic_sensor_hardware_smoke_test()
{
  ensureTestSerial();
  UltraSonicSensor sensor(TEST_ULTRASONIC_TRIG_PIN, TEST_ULTRASONIC_ECHO_PIN);
  sensor.setup();

  long distanceCm = sensor.measureDistanceCM();
  Serial.print("[HARDWARE TEST] Ultrasonic distance: ");
  Serial.println(distanceCm);

  return distanceCm > 0;
}
