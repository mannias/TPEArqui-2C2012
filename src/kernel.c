#include "../include/kasm.h"
#include "../include/defs.h"

DESCR_INT idt[0xA];			/* IDT de 10 entradas*/
IDTR idtr;				/* IDTR */


void int_08() {

	write('+');

}


char keyboard_flags[4];
char keyboard_buffer;

void int_09() {

	char aux= /* aca llamo a la rutina q levanta de i/o 060h y retorna el valor */;
	
	/* chequeo la matriz etc etc y pongo el valor final en el keyboard_buffer */
	
	
}

	
/**********************************************
kmain() 
Punto de entrada de código C.
*************************************************/

kmain() 
{

        int i,num;

/* Borra la pantalla. */ 

	k_clear_screen();


/* CARGA DE IDT CON LA RUTINA DE ATENCION DE IRQ0    */

        setup_IDT_entry (&idt[0x08], 0x08, (dword)&_int_08_hand, ACS_INT, 0);
	
/* Carga de IDTR    */

	idtr.base = 0;  
	idtr.base +=(dword) &idt;
	idtr.limit = sizeof(idt)-1;
	
	_lidt (&idtr);	

	_Cli();
/* Habilito interrupcion de timer tick*/

        _mascaraPIC1(0xFE);
        _mascaraPIC2(0xFF);
        
	_Sti();

        while(1)
        {
        }
	
}

