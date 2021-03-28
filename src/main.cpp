#include <M5Core2.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "credential.h"

void initWifi()
{
  WiFi.begin(SSID, PSW);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

String httpGETRequest()
{
  DynamicJsonDocument jsonResponse(2048);
  HTTPClient http;

  http.useHTTP10(true);

  String serverPath = (String)BASE_URL + "/api/printer";

  http.begin(serverPath.c_str());
  http.addHeader("X-Api-Key", "4B9383736CD24ABEB0B31715DDF6E1BE");

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode == HTTP_CODE_OK)
  {
    payload = http.getString();
    // Serial.println(payload);
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
  return payload;
}

void setup()
{
  M5.begin(true);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Remote printer controller");
  Serial.begin(115200);
  initWifi();
}

void loop()
{
  M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);
  if (WiFi.status() == WL_CONNECTED)
  {
    String payloadResponde;

    DynamicJsonDocument jsonResponse(1024);

    payloadResponde = httpGETRequest();

    deserializeJson(jsonResponse, payloadResponde);

    JsonObject current = jsonResponse["temperature"];
    JsonObject state = jsonResponse["state"];

    String actualToolTemp = current["tool0"]["actual"];
    String actualBedTemp = current["bed"]["actual"];
    String statusPrinter = state["text"];

    Serial.println(actualBedTemp);

    if (!current["tool0"]["actual"].isNull() && !current["bed"]["actual"].isNull())
    {
      M5.Lcd.setCursor(10, 40);
      M5.Lcd.setTextSize(2);
      M5.Lcd.print("Status Printer:\n " + statusPrinter);
      M5.Lcd.setCursor(10, 80);
      M5.Lcd.setTextSize(2);
      M5.Lcd.print("Bed Temp.: " + actualBedTemp + " C");
      M5.Lcd.setCursor(10, 100);
      M5.Lcd.print("Tools Temp: " + actualToolTemp + " C");
    }
  }
}