#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	int num;
	printSegments();
	//printMemory();
	int i = 0;
	//i = checkMem();
	//printf("%i\n", i);
	//printf("asdasd");
	char* vec[7];
	//printf("algo");
	for(i = 0; i<7; i++){
		if((vec[i] = malloc(1048576))==NULL){
			printf("NADA");
		}
	}
	printSegments();
	for(i = 0; i<7; i++){
		free(vec[i]);
	}
	printSegments();
	//printint(test());
	scanf("%i", &num);
	printf("%i\n", num);
}

int
parse(char *str, int *flag) {

	return TRUE;

}

