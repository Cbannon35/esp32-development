#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);

  if (!Serial) {
    Serial.println("Serial port not available");
    while (true);
  }

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (touchRead(4) < 50) {
    Serial.println("Touched");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(100);
}
