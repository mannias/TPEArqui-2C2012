#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	int num;
	char *strtoparse[2];
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
parse(char *name, char *params) {
	int auxints[2]= {-1,-1};
	
	if(!strcmp(name, "clear") && !params)
		/*clear()*/;
	else if(!strcmp(name, "about") && !params)
		/*about()*/;
	else if(!strcmp(name, "commands") && !params)
		/*commands()*/;
	else if(!strcmp(name, "infoIDT") && !params)
		/*infoIDT()*/;
	else if(!strcmp(name, "addIDT") && parseInts(params, auxints) && (auxints[0]>=0) && (auxints[0]<10))
		/*addIDT(auxints[0], (int *) auxints[1])*/;
	else if(!strcmp(name, "removeIDT") && parseInts(params, auxints) && (auxints[1] == -1) && (auxints[0]>=0) && (auxints[0]<10))
		/*removeIDT(auxints[0])*/;
	
}
