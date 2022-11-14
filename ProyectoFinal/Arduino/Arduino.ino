// Lectura de bytes de almacenamiento

#include <stdint.h>
#include "motorcontrol.h"



struct Motores {  //Definimos de la estructura para guardar los datos de los sensores
  uint16_t x;
  uint16_t y;

  uint16_t x_actual;
  uint16_t y_actual;
};

union UDato {  //Definimos una union para poder mandar los datos byte a byte
  Motores datos;
  byte a[sizeof(Motores)];
} Datos;


void Enviar_Struct() {

  for (unsigned long long k = 0; k < sizeof(Motores); k++) {  //Pasamos los datos byte a byte
    Serial.write(Datos.a[k]);
  }
}
void Recibir_Struct(){
  Serial.readBytes(Datos.a, sizeof(Motores));
}

void setup() {

  Serial.begin(9600);
}

void loop() {
  //creamos los dos objetos para cada motor
  motorcontrol a = motorcontrol(7, 6, 5, 4);
  motorcontrol b = motorcontrol(8, 9, 10, 11);

  uint8_t Identificador[1];  //Variable que se usa para identificar el tipo de movimiento en Y o X

  if (Serial.available()) {

    Serial.readBytes(Identificador, 1);
    if (Identificador[0] == 'y') {
      Recibir_Struct();
      a.rotateSteps(Datos.datos.y, 2);
    } else if (Identificador[0] == 'x') {
      Recibir_Struct();
      b.rotateSteps(Datos.datos.x, 1);
    }
  }
}
