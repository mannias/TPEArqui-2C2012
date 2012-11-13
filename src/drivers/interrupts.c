#include "interrupts.h"
#include "keyboard.h"

/*
	Handler del Timer-Tick
*/
void int_08() {
	printf("8");
}

/*
	Handler de keyboard
*/
void int_09(unsigned char scancode){
	saveCharacter(scancode);
	return;
}

