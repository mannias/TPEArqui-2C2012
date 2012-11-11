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

int
test() {
	int i;
	char str1[3]= "asd";
	char str2[3]= "zxc";
	strcpy(str1, str2);
	while(*str1 == *str2) {
		if(i==3)
			return TRUE;
		str1++;
		str2++;
		i++;
	}
	return FALSE;
}

