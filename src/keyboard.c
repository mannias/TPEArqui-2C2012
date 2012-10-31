#include "../include/keyboard.h"

char* english 		= "__1234567890-=__qwertyuiop[]__asdfghjkl;'`_\\zxcvbnm,./_*_______________789-456+1230._____";
char* englishShift 	= "__!@#$%^&*()_+__QWERTYUIOP{}__ASDFGHJKL:_~_|ZXCVBNM<>?_*_______________789-456+1230._____";

char keyboard_buffer[BUFFER_LEN];
int loc;
int shiftFlag;


void 
saveCharacter(unsigned char num){
	char aux;
	if(loc == BUFFER_LEN){
		loc = -1;	// vuelve al inicio del BUFFER circular
	}
	if(shiftFlag == 0){
		aux = english[num];
	}else{
		aux = englishShift[num];
	}
	write(num);
	if(aux == '_' && num !=12){
		if(num == 0x2A || num == 0x36){
			shiftFlag = 1;
		}
		if(num == 0xAA || num == 0xB6){
			shiftFlag = 0;
		}

	}else if(num < 96){
		keyboard_buffer[++loc] = aux;

	}
}

void
startKeyboard(){
	int i;
	loc = -1;
	shiftFlag = 0;
	for(i=0; i< BUFFER_LEN; i++){
		keyboard_buffer[i] = 0;
	}
}

char getC(){
	if(loc == -1){
		return NULL;
	}
	return keyboard_buffer[loc--];
}
