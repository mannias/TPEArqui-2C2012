#include "../include/shell.h"
#include "library/string.h"
#include "library/stdio.h"
#include "library/stdlib.h"
#include "library/string.h"
#include "library/malloc.h"

extern _int_08_hand;

void startShell(){
	char *str;
	char brokestr[2][LINE_SIZE/2];
	int ints[2];
	int aux[2];
	
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
		if(!(aux[0]=parsestring(str, brokestr, ints)) || !(aux[1]=parse(brokestr[0], ints)))
			printf("Wrong command, call commands() to see a list of valid commands.\n");
	}
}

int
parse(char *name, int params[2]) {

	if(!strcmp(name, "clear") && (params[0] == -1) && (params[1] == -1)) {
		clear();
		return TRUE;
	}
	else if(!strcmp(name, "about") && (params[0] == -1) && (params[1] == -1)) {
		about();
		return TRUE;
	}
	else if(!strcmp(name, "commands") && (params[0] == -1) && (params[1] == -1)) {
		commands();
		return TRUE;
	}
	else if(!strcmp(name, "infoIDT") && (params[0] == -1) && (params[1] == -1)) {
		infoIDT();
		return TRUE;
	}
	else if(!strcmp(name, "addIDT") && (params[0] >= 0) && (params[0] <=9) && (params[1] > 0) ) {
		addIDT(params[0], (dword) params[1]);
		return TRUE;
	}
	else if(!strcmp(name, "removeIDT") && (params[0] >= 0) && (params[0] <=9) && (params[1] == -1) ) {
		removeIDT(params[0]);
		return TRUE;
	}
	else if(!strcmp(name, "testIDT") && (params[0] == -1) && (params[1] == -1)) {
		testIDT();
		return TRUE;
	}
	else if(!strcmp(name, "testmalloc") && (params[0] != -1) && (params[1] == -1) ) {
		testmalloc(params[0]);
		return TRUE;
	}
	return FALSE;
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

void
infoIDT() {
	checkIDT();
}

void
testmalloc(int size) {

}

void
testIDT() {
	checkIDT();
	printf("*********************************************************************************\n");
	getc();
	addIDT(8, &_int_08_hand);
	checkIDT();
	printf("*********************************************************************************\n");
	getc();
	removeIDT(8);
	checkIDT();
	printf("*********************************************************************************\n");
}
