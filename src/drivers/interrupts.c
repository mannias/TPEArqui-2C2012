#include "interrupts.h"
#include "keyboard.h"

void int_08() {
	printf("8");
}

void int_09(unsigned char scancode){
	saveCharacter(scancode);
	return;
}

