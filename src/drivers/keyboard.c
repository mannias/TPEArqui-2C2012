#include "keyboard.h"

char* english 		= "__1234567890-=__qwertyuiop[]__asdfghjkl;'`_\\zxcvbnm,./_*______________________________";
char* englishShift 	= "__!@#$%^&*()_+__QWERTYUIOP{}__ASDFGHJKL:_~_|ZXCVBNM<>?_*______________________________";
char* englishMayus 	= "__1234567890-=__QWERTYUIOP[]__ASDFGHJKL;'`_\\ZXCVBNM,./_*______________________________";

char keyboard_buffer[BUFFER_LEN];
int loc;
int shiftFlag;
int mayus;

/*
	Funcion encargada de decodificar y guardar en el buffer el "scankey" pasado
	Ademas lee distintos scankeys que corresponden a comportamientos tales como
	Backspace o shift, que modifican el comportamiento interno
*/
void 
saveCharacter(unsigned char num){

	char aux;
	if(loc == BUFFER_LEN){
		loc = -1;	// vuelve al inicio del BUFFER circular
	}
	if(shiftFlag == 0){
		if(mayus == 1){
			aux = englishMayus[num];
		}else{
			aux = english[num];
		}
	}else{
		aux = englishShift[num];
	}
	if((aux == '_' && num !=12) || num >= 129 ){
		if(num == 0x2A || num == 0x36){
			shiftFlag = 1;
		}
		if(num == 0xAA || num == 0xB6){
			shiftFlag = 0;
		}
		if(num == 0x39){
			keyboard_buffer[++loc] = ' ';
			return;
		}
		if(num == 0x1C){
			keyboard_buffer[++loc] = '\n';
		}
		if(num == 0x3A){
			mayus = (mayus+1)%2;
		}
		if(num ==0x0E){
			keyboard_buffer[++loc] = BACKSPACE;
		}
		if(num == 0x48){
			keyboard_buffer[++loc] = UP_ARROW;
		}
		if(num == 0x50){
			keyboard_buffer[++loc] = DOWN_ARROW;
		}
		if(num == 0x4D){
			keyboard_buffer[++loc] = FORW_ARROW;
		}
		if(num == 0x4B){
			keyboard_buffer[++loc] = BACK_ARROW;
		}
	}else if(num < 96){
		keyboard_buffer[++loc] = aux;
	}
	return;
}

/*
	Inicializador del teclado, inicia el buffer y flags
*/
void
startKeyboard(){
	int i;
	loc = -1;
	shiftFlag = 0;
	mayus = 0;
	for(i=0; i< BUFFER_LEN; i++){
		keyboard_buffer[i] = '\0';
	}
}


/*
	Funcion que retorna el ultimo elemento que ingreso al buffer,
	si llego al final vuelve al inicio y sino vuelve al final
*/
char getKeyboardChar(){
	if(loc == -1){
		if(keyboard_buffer[BUFFER_LEN-1] == '\0'){
			return NULL;
		}
		loc = BUFFER_LEN-1;
	}
	char aux;
	aux = keyboard_buffer[loc];	//limpio el buffer
	keyboard_buffer[loc--] = '\0';
	return aux;
}
