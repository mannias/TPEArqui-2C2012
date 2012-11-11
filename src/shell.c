#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"


void startShell(){
	char *string;
	int flag= TRUE;
	
	while(flag){
		putc('$');
		scanf("%s", string);
		parse(string, &flag);

		}
}

int
parse(char *str, int *flag) {

	return TRUE;

}

