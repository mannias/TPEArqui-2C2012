#include "../include/keyboard.h"

char* english = "__1234567890-=__qwertyuiop[]__asdfghjkl;'`_\\zxcvbnm,./_*_______________789-456+1230._____";
char* english1 = "_____________`______q1___zsaw2__cxde43___vftr5__nbhgy6___mju78__,kio09__./l;p-___'_[=_____]_\\__";

void 
printCharacter(char num){
	keyboard_buffer = english[num];
}
