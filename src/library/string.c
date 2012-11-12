#include "string.h"

/* apuntador a la primera ocurrencia de c en cs*/
char* strchr(char* cs, char* c){
	char* aux = cs;
	int status = 0;
	int sum = 0;
	int pos1 = 0;
	int pos2 = 0;
	int loc = 0;
	int size = strlen(c);
	while(cs[pos1] != '\0' && c[pos2] != '\0' ){
		if(status == 0){
			if(cs[pos1] == c[pos2]){
				loc = pos1;
				status = 1;
			}else{
				pos1++;
			}
		}else if(status == 1){
			if(cs[pos1++] == c[pos2++]){
				sum++;
			}else{
				if(sum == size){
					return (char*) (*cs+loc);
				}
				status = 0;
			}
		}
	}
	if(sum == size){
		return (char*) (*cs+loc);
	}
	return NULL;
}

/* apuntador a la primera ocurrencia de c en cs con n caracteres */
char* strnchr(char* cs, char* c, int num){
	char* aux = cs;
	int status = 0;
	int sum = 0;
	int pos1 = 0;
	int pos2 = 0;
	int loc = 0;
	int size = strlen(c);
	while(cs[pos1] != '\0' && c[pos2] != '\0' ){
		if(status == 0){
			if(cs[pos1] == c[pos2]){
				loc = pos1;
				status = 1;
			}else{
				pos1++;
			}
		}else if(status == 1){
			if(cs[pos1++] == c[pos2++] && sum < num){
				sum++;
			}else{
				if(sum == num){
					return (char*) (*cs+loc);
				}
				status = 0;
			}
		}
	}
	if(sum == size){
		return (char*) (*cs+loc);
	}
	return NULL;
}

/* regresa la longitud de cs */
int srtlen(char* cs){
	int i = 0;
	while(cs[i] != '\0'){
		i++;
	}
	return i-1;
}

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

int
parsestring(char *orig, char *ret[2]) {
	int i, current=0, length=0;
	for(i=0; i<(LINE_SIZE/2) ;i++) {
		if(((orig[i*2] == '(') && (current == 0)) || ((orig[i*2] == ')') && (current == 1))) {
			length++;
			current++;
		}
		else if(current > 1 && orig[i*2] != ' ')
			return FALSE;
		else if(current == 0) {
			length++;
			ret[current][i]= orig[i*2];
		}
		else if(current == 1)
			ret[current][i-length]= orig[i*2];
		else
			return FALSE;
	}
	if(current != 2)
		return FALSE;
	ret[0][length-1]= 0;
	ret[1][i-length]= 0;
	return TRUE;
}

int
parseInts(char *str, int ints[2]) {
	int i, current=0, length=0;
	char *aux;
	for(i=0; str[i] ;i++) {
		if((str[i] == ',') && (current == 0)) {
			length++;
			ints[current]= atoi(aux); 
			current++;
		}
		else if(current == 0 && isNumber(str[i]) ) {
			length++;
			aux[i]= str[i];
		}
		else if(current == 1 && isNumber(str[i]) )
			aux[i-length]= str[i];
		else
			return FALSE;
	}
	
	ints[current]= atoi(aux);
	return TRUE;
}
