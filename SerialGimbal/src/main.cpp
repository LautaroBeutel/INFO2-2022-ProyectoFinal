#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

char abc[] = "abc";

void loop() {
  for (int i = 0; i < 3; i++)
  {
    Serial.write(abc[i]);
    delay(500);
  }
}