// Lectura de bytes de almacenamiento

#include <stdint.h>
#include "motorcontrol.h"

bool RL = 1;         //variable que pasamos a las funciones para definir el sentido
int movimiento = 1;  //variable para elegir el tipo de funcionamiento
int aux = 1;

uint32_t T;  //Variables usadas para la lectura y transformacion

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

int espera = 200, time = 0;  //Variables usadas en el antirebote y el delay

void Actual() {

  for (unsigned long long k = 0; k < sizeof(Motores); k++) {  //Pasamos los datos byte a byte
    Serial.write(Datos.a[k]);
  }
}
void Recibir_Struct() {
  Serial.readBytes(Datos.a, sizeof(Motores));
}

void setup() {

  Serial.begin(9600);
}

void loop() {
  motorcontrol a = motorcontrol(7, 6, 5, 4);
  motorcontrol b = motorcontrol(8, 9, 10, 11);

  uint8_t Identificador[1];  //Variable que se usa para identificar el tipo de sensor elegido
  size_t n;                  //Utilizamos esta variable para verificar si se leyeron datos
  //b.rotateSteps(200,1);
  //delay(200);
  //b.rotateSteps(200,2);


  if (Serial.available()) {

    n = Serial.readBytes(Identificador, 1);
    if(Identificador[0] == 'y') {
      Recibir_Struct();
      b.rotateSteps(Datos.datos.y,2);      
    }else if(Identificador[0] == 'x'){
      Recibir_Struct();
      a.rotateSteps(Datos.datos.x,1);
    }
    
  }
}