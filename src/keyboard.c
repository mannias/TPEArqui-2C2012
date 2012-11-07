#include "../include/keyboard.h"

char* english 		= "__1234567890-=__qwertyuiop[]__asdfghjkl;'`_\\zxcvbnm,./_*_______________789-456+1230._____";
char* englishShift 	= "__!@#$%^&*()_+__QWERTYUIOP{}__ASDFGHJKL:_~_|ZXCVBNM<>?_*_______________789-456+1230._____";
char* englishMayus 	= "__1234567890-=__QWERTYUIOP[]__ASDFGHJKL;'`_\\ZXCVBNM,./_*_______________789-456+1230._____";

char keyboard_buffer[BUFFER_LEN];
int loc;
int shiftFlag;
int mayus;

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
	if(aux == '_' && num !=12){
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
	}else if(num < 96){
		keyboard_buffer[++loc] = aux;
	}
	return;
}

void
startKeyboard(){
	int i;
	loc = -1;
	shiftFlag = 0;
	mayus = 0;
	for(i=0; i< BUFFER_LEN; i++){
		keyboard_buffer[i] = 0;
	}
}

char getC(){
	if(loc == -1){
		if(keyboard_buffer[BUFFER_LEN-1] == NULL){
			return NULL;
		}
		loc = BUFFER_LEN-1;
	}
	char aux;
	aux = keyboard_buffer[loc];	//limpio el buffer
	keyboard_buffer[loc--] = 0;
	return aux;
}
