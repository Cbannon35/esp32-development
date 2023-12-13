#include <Arduino.h>
#include <WiFi.h>

#define WIFI_NETWORK "Berkeley-Visitor"
#define WIFI_PASSWORD ""
#define WIFI_TIMEOUT 20000

void connectToWiFi();

void setup() {
  Serial.begin(9600);
  if (!Serial) {
    Serial.println("Serial port not available");
    while (true);
  }
  connectToWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(WIFI_NETWORK);

  WiFi.mode(WIFI_STA);

  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < WIFI_TIMEOUT) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect");
    // while (true);
  } else {
    Serial.println("Connected!");
    Serial.println(WiFi.localIP());
  }
}