#ifndef _SERIALGIMBAL_H_
#define _SERIALGIMBAL_H_

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "rs232.h"

int check_port();
void send_char(char letter);
void send_struct();
void receive_struct();

#endif
