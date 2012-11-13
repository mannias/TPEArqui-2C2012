#include "string.h"
#include "../../include/defs.h"


/* regresa la longitud de cs */
int strlen(char* cs){
	int i = 0;
	while(cs[i] != '\0'){
		i++;
	}
	return i-1;
}

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
cutstring(char to[], char from[], char c) {
	int i;
	printf("cutstring con %s ", from);
	for(i=0; (from[i] != c) && from[i] ;i++)
		to[i]= from[i];
	//printf("%d %d \n", i, from[i]);
	to[i]= 0;
	if(!from[i])
		return -1;
	return i+1;
}	

int
checkclear(char str[]) {
	int i;
	if(str[0])
		for(i=0; str[i] ;i++) 
			if(str[i] != ' ')
				return FALSE;
	return TRUE;
}

int
parsestring(char orig[], char ret[2][LINE_SIZE/2], int ints[2]) {
	int aux, aux2;
	aux= cutstring(ret[0], orig, '('); 
	printf("%s\n", ret[0]);
	if(aux == -1)
		return FALSE;
	aux2= cutstring(ret[1], &(orig[aux]), ')');
	if(aux2 == -1)
		return FALSE;
	if(!checkclear(&(orig[aux+aux2])))
		return FALSE;
		
	return parseInts(ret[1], ints);
}

int
parseInts(char *str, int ints[2]) {
	int aux;
	char *s1;
	char *s2;
	printf("parseInts con %s\n", str);
	aux= cutstring(s1, str, ',');
	printf("retorne");
	if(!allnumbers(s1))
		return FALSE;
	if(aux != -1) {
		cutstring(s2, &(str[aux]), '\0');
		if(!allnumbers(s2))
			return FALSE;
		ints[1]= atoi(s2);
	}
	ints[0]= atoi(s1);
	return TRUE;
}

int
allnumbers(char str[]) {
	int i;
	printf("allnumbers\n");
	for(i=0; str[i] ;i++)
		if((str[i] < '0') || (str[i] > '9'))
			return FALSE;
	return TRUE;
}
