#include "../include/keyboard.h"

char* english = "__1234567890-=__qwertyuiop[]__asdfghjkl;'`_\\zxcvbnm,./_*_______________789-456+1230._____";
char* english1 = "_____________`______q1___zsaw2__cxde43___vftr5__nbhgy6___mju78__,kio09__./l;p-___'_[=_____]_\\__";

char keyboard_buffer[BUFFER_LEN];
int loc;

void 
saveCharacter(char num){
	if(loc == BUFFER_LEN){
		loc = -1;	// vuelve al inicio del BUFFER circular
	}
	char aux = english[num];
	if(aux == '_' && num !=12){

	}else{
		keyboard_buffer[++loc] = aux;
	}
}

void
startKeyboard(){
	int i;
	loc = -1;
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
