#ifndef _motorcontrol_h_
#define _motorcontrol_h_

/* El motor 28BYJ-48 tiene un ángulo de paso de 5,625 grados (64 pasos por vuelta usando half-step).
 * El reductor interno tiene una relación de 1/64. Combinados, la precisión total es 64 x 64 = 4096 pasos por vuelta,
 * equivalente a un paso de 0,088°, que resulta en una precisión muy elevada. 
 * Debido a alguna razón mecánica que el fabricante no explica, 
 * no son exactamente 4096: es necesario aclarar que la cantidad verdadera de pasos para dar una vuelta 
 * completa de 360° —como verán en el programa— es de 4076. 
 */

#define SIMPLE  1   // MACRO PARA RUTINA DE PASO SIMPLE
#define DOBLE   2   // MACRO PARA RUTINA DE PASO DOBLE
#define MICRO   3   // MACRO PARA RUTINA DE MICRO PASO

class motorcontrol{
    private:    // ATRIBUTOS
        int _pin_a;
        int _pin_b;
        int _pin_c;
        int _pin_d;

        int paso_actual;
        int posicion;
        
        int paso_simple[4][4] = {   // ARRAY CON LAS SECUENCIAS DE ACTIVACION DE LAS BOBINAS PARA PASO SIMPLE
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        };
        int paso_doble[4][4] = {    // ARRAY CON LAS SECUENCIAS DE ACTIVACION DE LAS BOBINAS PARA PASO DOBLE
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 1},
            {1, 0, 0, 1},
        };
        int micro_paso[8][4] = {    // ARRAY CON LAS SECUENCIAS DE ACTIVACION DE LAS BOBINAS PARA MICRO PASO
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {1, 0, 0, 1},
        };

        int motor_off[4] = {         // ARRAY CON LAS SECUENCIAS DE APAGADO DE LAS BOBINAS
            0, 0, 0, 0};

        void print_simple(int);     //metodo para secuencia de paso simple
        void print_doble(int);      //metodo para secuencia de paso doble
        void print_micro(int);      //metodo para secuencia de micro paso
        void print_off();           //metodo para secuencia de apagado

    public:
        motorcontrol(int pin_a, int pin_b, int pin_c, int pin_d);   //constructor del objeto
        ~motorcontrol();    //destructor

        int thisPosition();     //metodo que devuelve la posicion actual del motor
        void rotateSteps(int steps, int arg);   //metodo que hace girar el motor
};
#endif