#include "../include/kc.h"

char tickpos=0;


void
write (char c) {
/*
	char * pantalla = (char *) 0xb8000;
	
	switch(c) {
	
		case ENTER: 
			
		
			break;
	
		case TAB: 
			
		
			break;
		
		case BACKSPACE: 
			if( !tick_is_at_line_start()) {
				tickpos-=2;
				write(' ');
			}
			break;
		
		case BACK_ARROW: 
			if( !tick_is_at_line_start())
				tickpos-=2;
			break;

		case FORW_ARROW: 
			if( !tick_is_at_line_end())
				tickpos+=2;
			break;
			
		case default:
			pantalla[tickpos] = c;
			tickpos+=2;
	}
*/	
}

int
tick_is_at_line_start () {
	return (tickpos% 10/* tamaño de linea */) == 0;
}

int
tick_is_at_line_end () {
	return ( (tickpos +1) % 10/* tamaño de linea */) == 0;
}

char 
read () {
	
	char aux;
	/*while(!keyboard_buffer)
		;

	aux = keyboard_buffer;	

	keyboard_buffer = 0;
	return aux;
*/
}


/***************************************************************
*k_clear_screen
*
* Borra la pantalla en modo texto color.
****************************************************************/

void k_clear_screen() 
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]='7';
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	};
}

/***************************************************************
*setup_IDT_entry
* Inicializa un descriptor de la IDT
*
*Recibe: Puntero a elemento de la IDT
*	 Selector a cargar en el descriptor de interrupcion
*	 Puntero a rutina de atencion de interrupcion	
*	 Derechos de acceso del segmento
*	 Cero
****************************************************************/

void setup_IDT_entry (DESCR_INT *item, byte selector, dword offset, byte access,
			 byte cero) {
  item->selector = selector;
  item->offset_l = offset & 0xFFFF;
  item->offset_h = offset >> 16;
  item->access = access;
  item->cero = cero;
}
