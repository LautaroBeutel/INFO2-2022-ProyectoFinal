#include <Arduino.h>
#include "motorcontrol.h"

motorcontrol m1(D1, D2, D3, D4);

/* int paso_simple[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1},
}; */

void setup() {
  Serial.begin(9600);
  /* pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT); */
  m1.rotateSteps(-4096, MICRO);
}
/* 
void print_simple(int paso_actual); */

void loop() {
  /* int paso_actual = 0;
  for (int i = 0; i < 10; i++)
  {
      print_simple(paso_actual);
      Serial.println(paso_actual);
      delay(1000);
      paso_actual++;
      if (paso_actual > 3)
      {
          paso_actual = 0;
      }
  } */
}
/* 
void print_simple(int paso){
    digitalWrite(D1, paso_simple[paso][0]);
    digitalWrite(D2, paso_simple[paso][1]);
    digitalWrite(D3, paso_simple[paso][2]);
    digitalWrite(D4, paso_simple[paso][3]);
} */