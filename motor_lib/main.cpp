#include <Arduino.h>
#include "motorcontrol.h"

motorcontrol m1(D1, D2, D3, D4);

void setup() {
  Serial.begin(9600);

  m1.rotateSteps(4096, MICRO);
  Serial.println(m1.thisPosition());
  m1.rotateSteps(-4096, MICRO);
  Serial.println(m1.thisPosition());
}


void loop() {
}
