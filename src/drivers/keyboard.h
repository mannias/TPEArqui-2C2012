
#ifndef _keyboard_
#define _keyboard_

#include "../../include/defs.h"

#define BUFFER_LEN 200   /* tamaño del stack de teclado */

void saveCharacter(unsigned char num);
void startKeyboard();
char getC();

#endif
