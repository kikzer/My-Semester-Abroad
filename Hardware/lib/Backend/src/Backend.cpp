#include "Backend.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#define MQTT_MAX_PACKET_SIZE 1024
#include <PubSubClient.h>
#include <ArduinoJson.h>

// ===== CONFIG =====
const char *WIFI_SSID = "nikiWifi";
const char *WIFI_PASSWORD = "Niki1234";

const char *BACKEND_BASE_URL = "http://217.123.40.211:5000";
const char *MQTT_HOST = "217.123.40.211";
const int MQTT_PORT = 1883;

const char *MQTT_USERNAME = "smartcity";
const char *MQTT_PASSWORD = "smartcitypass";

const char *DEVICE_ID = "esp_2_parking_v3";
const char *DEVICE_SECRET = "p5lr9h38g5p6mrmfx1j7";
const char *DEVICE_TYPE = "esp";
// ==================

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

String accessToken = "";
String mqttTopic = "";
String mqttCommandTopic = "";

static ParkingTile *activeParkingTile = nullptr;

unsigned long lastWifiRetryMs = 0;
unsigned long lastMqttRetryMs = 0;
unsigned long tokenFetchedAtMs = 0;

const unsigned long tokenRefreshMs = 25UL * 60UL * 1000UL;
const unsigned long wifiRetryIntervalMs = 5000;
const unsigned long mqttRetryIntervalMs = 5000;

int sequenceNumber = 0;

/**
 * @brief Prints a divider line to the serial output for readability.
 */
static void printDivider()
{
  Serial.println("--------------------------------------------------");
}

/**
 * @brief Prints the current WiFi status and connection details to the serial output.
 */
static void printWifiStatus()
{
  Serial.print("WiFi status: ");
  Serial.println(WiFi.status());

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("WiFi IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("WiFi RSSI: ");
    Serial.println(WiFi.RSSI());
  }
}

static String toLowerCopy(String value)
{
  value.toLowerCase();
  return value;
}

static String mqttTopicForCommands()
{
  return String("smartcity/devices/") + DEVICE_ID + "/commands";
}

static void mqttCallback(char *topic, byte *payload, unsigned int length)
{
  Serial.println("[DEBUG] MQTT message received");
  Serial.print("[DEBUG] Topic: ");
  Serial.println(topic);

  if (mqttCommandTopic.length() > 0 && String(topic) != mqttCommandTopic)
  {
    Serial.println("[DEBUG] Ignoring message from non-command topic");
    return;
  }

  if (activeParkingTile == nullptr)
  {
    Serial.println("[ERROR] No active parking tile registered for backend messages");
    return;
  }

  String responseJson;
  responseJson.reserve(length + 1);
  for (unsigned int i = 0; i < length; i++)
  {
    responseJson += static_cast<char>(payload[i]);
  }

  receiveParkingTileInstructions(*activeParkingTile, responseJson);
}

/**
 * @brief Ensures the device is connected to WiFi, retrying if necessary.
 * @return True if connected, false otherwise.
 */
bool ensureWifiConnected()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    return true;
  }

  unsigned long now = millis();
  if (lastWifiRetryMs != 0 && now - lastWifiRetryMs < wifiRetryIntervalMs)
  {
    return false;
  }

  lastWifiRetryMs = now;

  Serial.println("[DEBUG] Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long startAttempt = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttempt < 15000)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("[DEBUG] WiFi connected");
    printWifiStatus();
    return true;
  }

  Serial.println("[ERROR] WiFi connection failed");
  printWifiStatus();
  return false;
}

bool fetchDeviceToken()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("[ERROR] Cannot fetch token, WiFi not connected");
    return false;
  }

  HTTPClient http;
  String url = String(BACKEND_BASE_URL) + "/api/device-auth/token";

  if (!http.begin(url))
  {
    Serial.println("[ERROR] HTTP begin failed");
    return false;
  }

  http.setTimeout(10000);
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<256> requestDoc;
  requestDoc["device_id"] = DEVICE_ID;
  requestDoc["device_secret"] = DEVICE_SECRET;

  String requestBody;
  serializeJson(requestDoc, requestBody);

  int httpCode = http.POST(requestBody);
  String response = http.getString();
  http.end();

  Serial.print("[DEBUG] Token HTTP code: ");
  Serial.println(httpCode);
  Serial.print("[DEBUG] Token response: ");
  Serial.println(response);

  if (httpCode != 200)
  {
    Serial.println("[ERROR] Token request failed");
    return false;
  }

  StaticJsonDocument<1024> responseDoc;
  DeserializationError error = deserializeJson(responseDoc, response);
  if (error)
  {
    Serial.print("[ERROR] Failed to parse token response: ");
    Serial.println(error.c_str());
    return false;
  }

  if (!responseDoc["access_token"].is<const char *>())
  {
    Serial.println("[ERROR] Token response missing access_token");
    return false;
  }

  if (!responseDoc["mqtt"]["topic"].is<const char *>())
  {
    Serial.println("[ERROR] Token response missing mqtt.topic");
    return false;
  }

  accessToken = responseDoc["access_token"].as<String>();
  mqttTopic = responseDoc["mqtt"]["topic"].as<String>();
  if (responseDoc["mqtt"]["command_topic"].is<const char *>())
  {
    mqttCommandTopic = responseDoc["mqtt"]["command_topic"].as<String>();
  }
  else
  {
    mqttCommandTopic = mqttTopicForCommands();
  }
  tokenFetchedAtMs = millis();

  Serial.println("[DEBUG] Device token received");
  Serial.print("[DEBUG] MQTT topic: ");
  Serial.println(mqttTopic);
  Serial.print("[DEBUG] MQTT command topic: ");
  Serial.println(mqttCommandTopic);

  return accessToken.length() > 0 && mqttTopic.length() > 0 && mqttCommandTopic.length() > 0;
}

bool ensureFreshToken()
{
  if (accessToken.length() == 0 || mqttTopic.length() == 0)
  {
    return fetchDeviceToken();
  }

  if (millis() - tokenFetchedAtMs > tokenRefreshMs)
  {
    return fetchDeviceToken();
  }

  return true;
}

void configureMqtt()
{
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
  mqttClient.setBufferSize(1024);
  mqttClient.setKeepAlive(30);
  mqttClient.setSocketTimeout(10);
}

static bool subscribeToCommandTopic()
{
  if (!mqttClient.connected() || mqttCommandTopic.length() == 0)
  {
    return false;
  }

  bool ok = mqttClient.subscribe(mqttCommandTopic.c_str());
  Serial.print("[DEBUG] MQTT subscribe command topic: ");
  Serial.println(ok ? "success" : "failed");
  return ok;
}

bool connectMqtt()
{
  configureMqtt();

  Serial.print("[DEBUG] Connecting to MQTT as client id: ");
  Serial.println(DEVICE_ID);

  bool ok = mqttClient.connect(DEVICE_ID, MQTT_USERNAME, MQTT_PASSWORD);

  if (ok)
  {
    Serial.println("[DEBUG] MQTT connected");
    subscribeToCommandTopic();
    return true;
  }

  Serial.print("[ERROR] MQTT connect failed, state = ");
  Serial.println(mqttClient.state());
  return false;
}

bool ensureMqttConnected()
{
  if (mqttClient.connected())
  {
    mqttClient.loop();
    return true;
  }

  unsigned long now = millis();
  if (lastMqttRetryMs != 0 && now - lastMqttRetryMs < mqttRetryIntervalMs)
  {
    return false;
  }

  lastMqttRetryMs = now;
  return connectMqtt();
}

void setupBackend(ParkingTile &tile)
{
  Serial.println("[DEBUG] setupBackend()");
  randomSeed(micros());
  activeParkingTile = &tile;

  printDivider();
  Serial.println("ESP32 Smart City device starting");
  printDivider();

  WiFi.mode(WIFI_STA);
  configureMqtt();

  ensureWifiConnected();

  if (WiFi.status() == WL_CONNECTED)
  {
    ensureFreshToken();
    ensureMqttConnected();
  }

  printDivider();
}

bool sendParkingTileStatus(const ParkingTile &tile)
{
  if (!ensureWifiConnected())
  {
    Serial.println("[ERROR] No WiFi connection");
    return false;
  }

  if (!ensureFreshToken())
  {
    Serial.println("[ERROR] No valid token");
    return false;
  }

  if (!ensureMqttConnected())
  {
    Serial.println("[ERROR] MQTT not connected");
    return false;
  }

  StaticJsonDocument<1536> doc;

  doc["device_id"] = DEVICE_ID;
  doc["token"] = accessToken;
  doc["sequence"] = sequenceNumber++;

  JsonObject metrics = doc.createNestedObject("metrics");
  metrics["device_type"] = DEVICE_TYPE;

  JsonObject tileObj = metrics.createNestedObject("parkingTile");

  for (int i = 0; i < tile.getAmountOfParkingSpaces(); i++)
  {
    ParkingSpace *ps = tile.getParkingSpaceById(i + 1);

    if (ps != nullptr)
    {
      String key = "parking_space_" + String(ps->getId());
      JsonObject space = tileObj.createNestedObject(key);
      space["operationMode"] = ps->getOperationMode() == AUTO ? "AUTO" : "MANUAL";
      space["led"] = ps->isOccupied() ? "red" : "green";
      space["sensor"] = ps->isOccupied() ? "occupied" : "free";
    }
  }

  String json;
  serializeJson(doc, json);

  Serial.println("[DEBUG] Publishing payload:");
  Serial.println(json);

  bool ok = mqttClient.publish(mqttTopic.c_str(), json.c_str());
  mqttClient.loop();

  Serial.print("[DEBUG] MQTT publish parking tile status: ");
  Serial.println(ok ? "success" : "failed");

  return ok;
}

bool testBackendConnection(const ParkingTile &tile)
{
  return sendParkingTileStatus(tile);
}

void receiveParkingTileInstructions(ParkingTile &tile, const String &responseJson)
{
  StaticJsonDocument<2048> doc;
  DeserializationError err = deserializeJson(doc, responseJson);
  if (err)
  {
    Serial.println("[ERROR] Invalid instruction JSON");
    return;
  }

  if (doc["command"].is<JsonObject>())
  {
    JsonObject commandObj = doc["command"].as<JsonObject>();
    String commandType = commandObj["type"] | "";
    commandType = toLowerCopy(commandType);

    if (commandType != "parking_override")
    {
      Serial.println("[DEBUG] Unsupported command type");
      return;
    }

    String componentKey = commandObj["component_key"] | "";
    String mode = toLowerCopy(commandObj["mode"] | "");
    String status = toLowerCopy(commandObj["status"] | "");

    if (!componentKey.startsWith("parking_space_"))
    {
      Serial.println("[DEBUG] Unsupported component key");
      return;
    }

    int id = componentKey.substring(String("parking_space_").length()).toInt();
    ParkingSpace *ps = tile.getParkingSpaceById(id);
    if (ps == nullptr)
    {
      Serial.println("[DEBUG] Parking space not found");
      return;
    }

    if (mode == "manual")
    {
      ps->changeOperationMode(MANUAL);
      if (status == "occupied")
      {
        ps->setOccupied(true);
      }
      else if (status == "free")
      {
        ps->setOccupied(false);
      }
    }
    else
    {
      ps->changeOperationMode(AUTO);
    }

    Serial.print("[DEBUG] Applied backend command to parking space ");
    Serial.println(id);
    return;
  }

  JsonObject tileObj = doc["parkingTile"];
  if (!tileObj.containsKey("id"))
  {
    return;
  }

  int targetId = tileObj["id"];
  if (tile.getId() != targetId)
  {
    return;
  }

  String status = toLowerCopy(tileObj["Status"] | "open");
  tile.setOperationMode(status == "closed" ? CLOSED : OPEN);

  JsonArray spaces = tileObj["parkingSpaces"];
  for (JsonObject space : spaces)
  {
    int id = space["id"];
    String op = toLowerCopy(space["operation"] | "auto");

    ParkingSpace *ps = tile.getParkingSpaceById(id);
    if (ps != nullptr)
    {
      ps->changeOperationMode(op == "auto" ? AUTO : MANUAL);

      if (op == "manual")
      {
        String led = toLowerCopy(space["led"] | "green");
        ps->setOccupied(led != "green");
      }
    }
  }
}