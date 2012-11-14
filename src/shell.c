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
		putc('>');
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
	else if(!strcmp(name, "mymalloc") && (params[0] != -1) && (params[1] == -1) ) {
		mymalloc(params[0]);
		return TRUE;
	}
	else if(!strcmp(name, "testmalloc") && (params[0] == -1) && (params[1] == -1)) {
		testmalloc();
		return TRUE;
	}
	else if(!strcmp(name, "printmemory") && (params[0] == -1) && (params[1] == -1)) {
		printMem();
		return TRUE;
	}
	else if(!strcmp(name, "free") && (params[0] != -1) && (params[1] == -1)) {
		myfree(params[0]);
		return TRUE;
	}
	else if(!strcmp(name, "getfreemem") && (params[0] == -1) && (params[1] == -1)) {
		getMem();
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
	printf("Wimdows by Domingues Matias & Lori Tomas.\n");
}

void
commands() {
	printf("Available commands:\n");
	printf("clear() - Clears the screen.\n");
	printf("about() - Information about the O.S and authors.\n");
	printf("infoIDT() - Shows the IDT vector and status of each.\n");
	printf("addIDT(index, routine) - Allows to add a different routine for \n solving interruptions.\n");
	printf("removeIDT(index) - Allows to remove the routine called when dealing \n with a particular interruption.\n");
	printf("testIDT() - Shows how addIDT(), addIDT() and removeIDT() works\n");
	printf("testmalloc() - Generates random segments to test the malloc function\n");
	printf("mymalloc(num) - Calls malloc\n");
	printf("printmemory() - Prints the actual memory mapping\n");
	printf("getfreemem() - Prints the ammount of free memory\n");
	printf("free(num) - Free the segment by num\n");
}

void
infoIDT() {
	checkIDT();
}

void
testmalloc() {
	char* vec[5];
	int i;
	printSegments();
	printf("\n");
	for(i=4; i>=0; i--){
		vec[i] = malloc(1048576);
	}
	printSegments();
	getc();
	printf("\n");
	for(i=4; i>=0; i--){
		if(vec[i] != NULL){
			free(vec[i]);
		}
	}
	printSegments();
	getc();
	for(i=0; i<5; i++){
		vec[i] = malloc(1048576);
	}
	if(vec[3] != NULL){
		free(vec[3]);
	}
	for(i=0; i<5 ; i++){
		malloc(1024);
	}
	printSegments();

}

void
mymalloc(int num){
	char vec[17];
	char* dir;
	if((dir = malloc(num)) != NULL){
		printf("%d - reserved\n", (int)dir);
	}else{
		printf("Out of Memory\n");
	}
}



void
printMem(){
	printSegments();
}

void
myfree(int num){
	char* mem = (char*)0x000000;
	mem += num;
	if(free(mem)){
		printf("Liberado con exito\n");
	}else{
		printf("Sector incorrecto\n");
	}
};

void
getMem(){
	int num = getFreeMem();
	printf("Memoria libre: %d\n", num);
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
