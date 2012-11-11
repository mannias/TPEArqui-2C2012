#include "stdlib.h" 

void 
strcpy(char to[], char from[]) {
	int i;
	for(i=0; to[i] && from[i]; i++)
		to[i]= from[i];

	if(!(from[i]))
		to[i]= from[i];
}

int
strcmp(char str1[], char str2[]) {
	int i, flag= TRUE;
	for(i=0; str1[i] && str2[i] && flag ;i++)
		if(str1[i] != str2[i])
			flag= FALSE;
	if(str1[i] == str2[i])
		return flag;
	return FALSE;
}

