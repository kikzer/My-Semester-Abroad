#pragma once

#include <Arduino.h>
#include "ParkingTile.h"

void receiveParkingTileInstructions(ParkingTile &tile, const String &responseJson);
bool sendParkingTileStatus(const ParkingTile &tile);
bool testBackendConnection(const ParkingTile &tile);

void setupBackend(ParkingTile &tile);
bool ensureWifiConnected();
bool fetchDeviceToken();
bool ensureFreshToken();
void configureMqtt();
bool connectMqtt();
bool ensureMqttConnected();
void buildTelemetryPayload(String &payload);