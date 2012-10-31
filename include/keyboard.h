#include "defs.h"

#ifndef _keyboard_
#define _keyboard_

#define BUFFER_LEN 200   /* tamaño del stack de teclado */

void saveCharacter(char num);
void startKeyboard();
char getC();

#endif
