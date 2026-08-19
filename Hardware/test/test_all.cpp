#include <Arduino.h>
#include <unity.h>
#include <Wire.h>

#include "Backend.h"
#include "HelperMethod.h"
#include "OledScreen.h"
#include "OperationEnumParkingSpace.h"
#include "OperationEnumParkingTile.h"
#include "ParkingSpace.h"
#include "ParkingTile.h"
#include "UltraSonicSensor.h"

bool run_ultrasonic_sensor_hardware_smoke_test();

void test_parking_space_enum_values()
{
  TEST_ASSERT_EQUAL_INT(0, AUTO);
  TEST_ASSERT_EQUAL_INT(1, MANUAL);
}

void test_parking_tile_enum_values()
{
  TEST_ASSERT_EQUAL_INT(0, CLOSED);
  TEST_ASSERT_EQUAL_INT(1, OPEN);
}

void test_wait_blocks_for_at_least_requested_time()
{
  unsigned long start = millis();
  wait(20);
  unsigned long elapsed = millis() - start;

  TEST_ASSERT_TRUE(elapsed >= 20);
  TEST_ASSERT_TRUE(elapsed < 200);
}

void test_ultrasonic_sensor_stores_pin_numbers()
{
  UltraSonicSensor sensor(21, 20);

  TEST_ASSERT_EQUAL_UINT8(21, sensor.getTrigPin());
  TEST_ASSERT_EQUAL_UINT8(20, sensor.getEchoPin());
}

void test_parking_space_defaults_and_state_changes()
{
  UltraSonicSensor sensor(21, 20);
  ParkingSpace space(7, sensor, 4, 5);

  TEST_ASSERT_EQUAL(7, space.getId());
  TEST_ASSERT_TRUE(space.isOccupied());
  TEST_ASSERT_EQUAL(AUTO, space.getOperationMode());

  space.setOccupied(false);
  TEST_ASSERT_FALSE(space.isOccupied());

  space.changeOperationMode(MANUAL);
  TEST_ASSERT_EQUAL(MANUAL, space.getOperationMode());
}

void test_parking_tile_accessors_and_space_lookup()
{
  UltraSonicSensor sensor1(21, 20);
  UltraSonicSensor sensor2(48, 47);

  ParkingSpace spaces[] = {
      ParkingSpace(1, sensor1, 4, 5),
      ParkingSpace(2, sensor2, 6, 7)
  };

  OledScreen screens[] = {
      OledScreen(0, 6, 7, 0x3C)
  };

  ParkingTile tile(11, spaces, 2, screens, 1);

  TEST_ASSERT_EQUAL(11, tile.getId());
  TEST_ASSERT_EQUAL(2, tile.getAmountOfParkingSpaces());
  TEST_ASSERT_EQUAL(1, tile.getAmountOfOledScreens());

  TEST_ASSERT_EQUAL_PTR(&spaces[0], tile.getParkingSpaceById(1));
  TEST_ASSERT_EQUAL_PTR(&spaces[1], tile.getParkingSpaceById(2));
  TEST_ASSERT_NULL(tile.getParkingSpaceById(99));

  tile.setParkingSpaceOccupiedById(2, true);
  TEST_ASSERT_TRUE(spaces[1].isOccupied());

  tile.setParkingSpaceOccupiedById(2, false);
  TEST_ASSERT_FALSE(spaces[1].isOccupied());
}

void test_oled_screen_stores_configuration()
{
  OledScreen screen(0, 6, 7, 0x3C);

  TEST_ASSERT_EQUAL_UINT8(6, screen.getSdaPin());
  TEST_ASSERT_EQUAL_UINT8(7, screen.getSclPin());
  TEST_ASSERT_EQUAL_UINT8(128, screen.getScreenWidth());
  TEST_ASSERT_EQUAL_UINT8(64, screen.getScreenHeight());
}

void test_backend_parking_space_override_command()
{
  UltraSonicSensor sensor1(21, 20);
  UltraSonicSensor sensor2(48, 47);

  ParkingSpace spaces[] = {
      ParkingSpace(1, sensor1, 4, 5),
      ParkingSpace(2, sensor2, 6, 7)
  };

  OledScreen screens[] = {
      OledScreen(0, 6, 7, 0x3C)
  };

  ParkingTile tile(1, spaces, 2, screens, 1);

  String json = R"({
    "command": {
      "type": "parking_override",
      "component_key": "parking_space_2",
      "mode": "manual",
      "status": "occupied"
    }
  })";

  receiveParkingTileInstructions(tile, json);

  TEST_ASSERT_EQUAL(MANUAL, spaces[1].getOperationMode());
  TEST_ASSERT_TRUE(spaces[1].isOccupied());
  TEST_ASSERT_EQUAL(AUTO, spaces[0].getOperationMode());
  TEST_ASSERT_TRUE(spaces[0].isOccupied());
}

void test_backend_tile_status_command()
{
  UltraSonicSensor sensor1(21, 20);
  UltraSonicSensor sensor2(48, 47);

  ParkingSpace spaces[] = {
      ParkingSpace(1, sensor1, 4, 5),
      ParkingSpace(2, sensor2, 6, 7)
  };

  OledScreen screens[] = {
      OledScreen(0, 6, 7, 0x3C)
  };

  ParkingTile tile(1, spaces, 2, screens, 1);

  String json = R"({
    "parkingTile": {
      "id": 1,
      "Status": "closed",
      "parkingSpaces": [
        { "id": 1, "operation": "manual", "led": "red" },
        { "id": 2, "operation": "auto" }
      ]
    }
  })";

  receiveParkingTileInstructions(tile, json);

  TEST_ASSERT_EQUAL(CLOSED, tile.getOperationMode());
  TEST_ASSERT_EQUAL(MANUAL, spaces[0].getOperationMode());
  TEST_ASSERT_TRUE(spaces[0].isOccupied());
  TEST_ASSERT_EQUAL(AUTO, spaces[1].getOperationMode());
  TEST_ASSERT_EQUAL_PTR(&spaces[1], tile.getParkingSpaceById(2));
}

void test_integration_backend_command_sequence()
{
  UltraSonicSensor sensor1(21, 20);
  UltraSonicSensor sensor2(48, 47);

  ParkingSpace spaces[] = {
      ParkingSpace(1, sensor1, 4, 5),
      ParkingSpace(2, sensor2, 6, 7)
  };

  OledScreen screens[] = {
      OledScreen(0, 6, 7, 0x3C)
  };

  ParkingTile tile(1, spaces, 2, screens, 1);

  String manualOverrideJson = R"({
    "command": {
      "type": "parking_override",
      "component_key": "parking_space_1",
      "mode": "manual",
      "status": "occupied"
    }
  })";

  String autoTileJson = R"({
    "parkingTile": {
      "id": 1,
      "Status": "open",
      "parkingSpaces": [
        { "id": 1, "operation": "auto" },
        { "id": 2, "operation": "manual", "led": "green" }
      ]
    }
  })";

  receiveParkingTileInstructions(tile, manualOverrideJson);

  TEST_ASSERT_EQUAL(MANUAL, spaces[0].getOperationMode());
  TEST_ASSERT_TRUE(spaces[0].isOccupied());

  receiveParkingTileInstructions(tile, autoTileJson);

  TEST_ASSERT_EQUAL(OPEN, tile.getOperationMode());
  TEST_ASSERT_EQUAL(AUTO, spaces[0].getOperationMode());
  TEST_ASSERT_EQUAL(MANUAL, spaces[1].getOperationMode());
  TEST_ASSERT_FALSE(spaces[1].isOccupied());
}

void test_ultrasonic_sensor_hardware_smoke_test()
{
  TEST_ASSERT_TRUE_MESSAGE(
      run_ultrasonic_sensor_hardware_smoke_test(),
      "Hardware smoke test failed. Make sure the ultrasonic sensor is wired and pointing at a valid target.");
}

void setUp() {}

void tearDown() {}

void setup()
{
  Serial.begin(115200);
  delay(50);

  UNITY_BEGIN();

  RUN_TEST(test_parking_space_enum_values);
  RUN_TEST(test_parking_tile_enum_values);
  RUN_TEST(test_wait_blocks_for_at_least_requested_time);
  RUN_TEST(test_ultrasonic_sensor_stores_pin_numbers);
  RUN_TEST(test_parking_space_defaults_and_state_changes);
  RUN_TEST(test_parking_tile_accessors_and_space_lookup);
  RUN_TEST(test_oled_screen_stores_configuration);
  RUN_TEST(test_backend_parking_space_override_command);
  RUN_TEST(test_backend_tile_status_command);
  RUN_TEST(test_integration_backend_command_sequence);
  RUN_TEST(test_ultrasonic_sensor_hardware_smoke_test);

  UNITY_END();
}

void loop()
{
}