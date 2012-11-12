#include "stdlib.h" 

void 
strcpy(char to[], char from[]) {
	int i;
	for(i=0; from[i-1] ;i++)
		to[i]= from[i];

}

void
strncpy(char to[], char from[], int n) {
	int i, flag= TRUE;
	for(i=0; i<n ;i++) {
		if(!flag)
			to[i]=flag;
		else {
			if(from[i] == FALSE)
				flag= from[i];
			to[i]= from[i];
		}
	}
}

int
strcmp(char str1[], char str2[]) {
	int i, aux=0;
	for(i=0; str1[i] && str2[i] && !aux ;i++)
		aux= str1[i] -str2[i];

	return aux;
}

int
strncmp(char str1[], char str2[], int n) {
	int i, aux=0;
	for(i=0; str1[i] && str2[i] && !aux && i<n ;i++)
		aux= str1[i] -str2[i];

	return aux;
	
}

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

