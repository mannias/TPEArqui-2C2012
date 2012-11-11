#include "../include/shell.h"
#include "library/stdio.h"
#include "library/stdlib.h"


void startShell(){
	char *string;
	int flag= 1;
	
	while(flag){
		putc('$');
		scanf("%s", string);
<<<<<<< HEAD
=======
//		parse(string, &flag);
>>>>>>> scrollup patch v2.1
		}
}

