#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	int num;
	//printSegments();
	printMemory();
	//malloc(120);
	//if(malloc(12) == NULL){
	//	printf("lala");
	//}
	//printint(test());
	scanf("%i", &num);
	printf("%i\n", num);
}

int
parse(char *str, int *flag) {

	return TRUE;

}

