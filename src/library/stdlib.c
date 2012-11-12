#include "stdlib.h" 

int atoi(const char *s){
	int i =0;
	int sig = 1;
	int final = 0;
	while(s[i] != '\0'){
		if(s[i] == '-'){
			sig = -1;
		}
		final = final*10 + (s[i++] - '0');
	}
	return final;
}
