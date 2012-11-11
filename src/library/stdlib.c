#include "stdlib.h" 

void 
strcpy(char *to, char *from) {

	while(*to && *from) {
		*to= *from;
		to++;
		from++;
	} 
	if(!(*from))
		*to= *from;
}

int
strcmp(char *str1, char *str2) {
	int flag= TRUE;
	while(*str1 && *str2 && flag) {
		if(*str1 == *str2) {
			str1++;
			str2++;
		} else
			flag= FALSE;
	}
	if(*str1 == *str2)
		return flag;
	return false;
}

