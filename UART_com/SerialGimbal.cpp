#include "SerialGimbal.h"
using namespace std;

typedef struct Motores{
  uint16_t x;
  uint16_t y;

  uint16_t x_actual;
  uint16_t y_actual;
}Motores;

union UDato{
  Motores datos;
  unsigned char  a[sizeof(Motores)];
} Datos, Hola;


int cport_nr=24,
    bdrate=9600;

char mode[]={'8', 'N', '1', 0};

int check_port(){
	return RS232_OpenComport(cport_nr, bdrate, mode, 0) ? 1 : 0;
}

void send_char(char letter){
	RS232_SendByte(cport_nr, letter);
}

void send_struct(){
	int cantidadBytes = RS232_SendBuf(cport_nr, Datos.a, sizeof(Motores));
	cout << "Los bytes enviados fueron:" << cantidadBytes << endl;
}

void receive_struct(){
	int cantidadBytes= RS232_PollComport(cport_nr, Hola.a, sizeof(Motores));

	cout << "Los bytes recibidos fueron:" << cantidadBytes<<endl;

	if(cantidadBytes > 0)
	{
		cout<<"x_actual: "<<Hola.datos.x_actual<<endl;
		cout<<"y_actual: "<<Hola.datos.y_actual<<endl;
		cout<<"X: "<<Hola.datos.x<<endl;
		cout<<"y: "<<Hola.datos.y<<endl;
	}
}
