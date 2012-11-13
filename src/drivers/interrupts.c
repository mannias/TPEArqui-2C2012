#include "interrupts.h"
#include "keyboard.h"

void int_08() {
	changeColor();
}

void int_09(unsigned char scancode){
	saveCharacter(scancode);
	return;
}

