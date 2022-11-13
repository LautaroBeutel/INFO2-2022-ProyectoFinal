#include <Arduino.h>
#include "motorcontrol.h"

motorcontrol::motorcontrol(int pin_a, int pin_b, int pin_c, int pin_d)
{
    _pin_a = pin_a;
    _pin_b = pin_b;
    _pin_c = pin_c;
    _pin_d = pin_d;
    
    pinMode(_pin_a, OUTPUT);
    pinMode(_pin_b, OUTPUT);
    pinMode(_pin_c, OUTPUT);
    pinMode(_pin_d, OUTPUT);
}

motorcontrol::~motorcontrol(){
}

void motorcontrol::print_simple(int paso){
    digitalWrite(_pin_a, paso_simple[paso][0]);
    digitalWrite(_pin_b, paso_simple[paso][1]);
    digitalWrite(_pin_c, paso_simple[paso][2]);
    digitalWrite(_pin_d, paso_simple[paso][3]);
}

void motorcontrol::print_doble(int paso){
    digitalWrite(_pin_a, paso_doble[paso][0]);
    digitalWrite(_pin_b, paso_doble[paso][1]);
    digitalWrite(_pin_c, paso_doble[paso][2]);
    digitalWrite(_pin_d, paso_doble[paso][3]);
}

void motorcontrol::print_micro(int paso){
    digitalWrite(_pin_a, micro_paso[paso][0]);
    digitalWrite(_pin_b, micro_paso[paso][1]);
    digitalWrite(_pin_c, micro_paso[paso][2]);
    digitalWrite(_pin_d, micro_paso[paso][3]);
}

int motorcontrol::thisPosition(){
    return this->posicion;
}

void motorcontrol::rotateSteps(int steps, int arg){
    int dir = steps > 0 ? 0 : 1;
    int missing_steps = abs(steps);
    
    posicion += steps;

    switch (dir)
    {
    case 0: while (missing_steps > 0)
            {
                switch (arg)
                {
                case 1:
                    print_simple(paso_actual);
                    paso_actual++;
                    if (paso_actual > 3)
                    {
                        paso_actual = 0;
                    }
                    //delay(10);
                    break;
                case 2:
                    print_doble(paso_actual);
                    paso_actual++;
                    if (paso_actual > 3)
                    {
                        paso_actual = 0;
                    }
                    //delay(10);
                    break;
                case 3:
                    print_micro(paso_actual);
                    paso_actual++;
                    if (paso_actual > 7)
                    {
                        paso_actual = 0;
                    }
                    //delay(10);
                    break;
                default:
                    break;
                }
                missing_steps--;
                delay(3);
            }
        break;
    case 1: while (missing_steps > 0)
            {
                switch (arg)
                {
                    case 1:
                        print_simple(3 - paso_actual);
                        paso_actual++;
                        if (paso_actual > 3)
                        {
                            paso_actual = 0;
                        }
                        //delay(10);
                        break;
                    case 2:
                        print_doble(3 - paso_actual);
                        paso_actual++;
                        if (paso_actual > 3)
                        {
                            paso_actual = 0;
                        }
                        //delay(10);
                        break;
                    case 3:
                        print_micro(7 - paso_actual);
                        paso_actual++;
                        if (paso_actual > 7)
                        {
                            paso_actual = 0;
                        }
                        //delay(10);
                        break;
                    default:
                        break;
                }
                missing_steps--;
                delay(3);
            }
        break;
    }
    digitalWrite(_pin_a,0);
    digitalWrite(_pin_b,0);
    digitalWrite(_pin_c,0);
    digitalWrite(_pin_d,0);


}
