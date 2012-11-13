#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	char *str;
	char brokestr[2][LINE_SIZE/2];
	int ints[2];
	int aux;

	getLine(str);
	aux= parsestring(str, brokestr, ints);
	printf("valido? %d, ints= %d, %d\n", aux, ints[0], ints[1]);  
	
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
