#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	int num;
	//printSegments();
	//printMemory();

	if(malloc(1048576) == NULL){
		printf("lala");
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

