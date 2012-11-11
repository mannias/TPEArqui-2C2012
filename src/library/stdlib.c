#include stdlib.h

void 
strcpy(char *to, char *from) {

	while(*to && *from) {
	*to=*from;
	to++;
	from++;
	} 
	*to=*from;
}