#include "../include/kasm.h"
#include "../include/defs.h"
#include "drivers/keyboard.h"

extern _empty_hand;

DESCR_INT idt[0xA];			/* IDT de 10 entradas*/
IDTR idtr;				/* IDTR */
	
/**********************************************
kmain() 
Punto de entrada de código C.
*************************************************/

kmain() 
{

    int i,num;

/* Limpieza registros bios */
    i=1-1;

/* Carga el teclado */
	startKeyboard();

/* Inicia el video */
	setUpVideo();

/* Inicia el malloc */
	initMalloc();
/* CARGA DE IDT CON LA RUTINA DE ATENCION DE IRQ0    */

        setup_IDT_entry (&idt[0x08], 0x08, (dword)&_empty_hand, ACS_INT, 0);
        setup_IDT_entry (&idt[0x09], 0x08, (dword)&_int_09_hand, ACS_INT, 0);
	
/* Carga de IDTR    */

	idtr.base = 0;  
	idtr.base +=(dword) &idt;
	idtr.limit = sizeof(idt)-1;
	
	_lidt (&idtr);	

	_Cli();
	
/* Habilito interrupcion de timer tick*/

        _mascaraPIC1(0xFC);
        _mascaraPIC2(0xFF);
        
	_Sti();
        while(1)
        {
        	startShell();
        }
	
}


