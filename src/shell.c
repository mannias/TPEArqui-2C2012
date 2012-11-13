#include "../include/shell.h"
#include "library/string.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"


void startShell(){
	char *str;
	char brokestr[2][LINE_SIZE/2];
	int ints[2];
	
	
	printf("                                        ___                                    \n");   
	printf("	            .-.                    (   )                                   \n");  
	printf(" ___  ___  ___ ( __) ___ .-. .-.     .-.| |   .--.   ___  ___  ___     .--.    \n"); 
	printf("(   )(   )(   )(''')(   )   '   *   /     |  /    * (   )(   )(   )  /  _  *   \n");   
	printf(" | |  | |  | |  | |  |  .-.  .-. ; |  .-. | |  .-. ; | |  | |  | |  . .' `. ;  \n");
	printf(" | |  | |  | |  | |  | |  | |  | | | |  | | | |  | | | |  | |  | |  _*_`.(___) \n");
	printf(" | |  | |  | |  | |  | |  | |  | | | |  | | | |  | | | |  | |  | | (   ). '.   \n");
	printf(" | |  ; '  | |  | |  | |  | |  | | | '  | | | '  | | | |  ; '  | |  | |  ` | ) \n");
	printf(" ' `-'   `-' '  | |  | |  | |  | | ' `-'  / '  `-' / ' `-'   `-' '  ; '._,' '  \n");
	printf("  '.__.'.__.'  (___)(___)(___)(___) `.__,'   `.__.'   '.__.'.__.'    '.___.'   \n");
	printf("  **************************************************************************   \n");
	
	while(1) {
		ints[0]=-1;
		ints[1]=-1;
		getLine(str);
		if(!parsestring(str, brokestr, ints) || !parse(brokestr[0], ints))
			printf("Wrong command, call commands() to see a list of valid commands.\n");
	}
}

int
parse(char *name, int params[2]) {

	if(!strcmp(name, "clear") && (params[0] == -1) && (params[1] == -1))
		clear();
	else if(!strcmp(name, "about") && (params[0] == -1) && (params[1] == -1))
		about();
	else if(!strcmp(name, "commands") && (params[0] == -1) && (params[1] == -1))
		commands();
	else if(!strcmp(name, "infoIDT") && (params[0] == -1) && (params[1] == -1))
		/*infoIDT()*/;
	else if(!strcmp(name, "addIDT") && (params[0] >= 0) && (params[0] <=9) && (params[1] > 0) )
		/*addIDT(auxints[0], (int *) auxints[1])*/;
	else if(!strcmp(name, "removeIDT") && (params[0] >= 0) && (params[0] <=9) && (params[1] == -1) )
		/*removeIDT(auxints[0])*/;
	
}

void
clear() {
	clearScreen();
}

void
about() {
	printf("Wimdows by Dominguez Matias & Lori Tomas.\n");
}

void
commands() {
	printf("Available commands:\n");
	printf("clear() - Clears the screen.\n");
	printf("about() - Information about the O.S and authors.\n");
	printf("infoIDT() - Shows the IDT vector and status of each.\n");
	printf("addIDT(index, routine) - Allows to add a different routine for \n solving interruptions.\n");
	printf("removeIDT(index) - Allows to remove the routine called when dealing \n with a particular interruption.\n");
}

