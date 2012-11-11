#include "../include/shell.h"
#include "library/stdio.h"


void startShell(){
	char *string;
	int flag= 1;
	
	while(flag){
		putc("$");
		scanf("%s", string);
		strcpy(commands_buffer.buffer[commands_buffer.currentline], string);
		parse(string, &flag);
		}
}





