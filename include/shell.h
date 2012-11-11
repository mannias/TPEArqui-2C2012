#ifndef _shell_
#define _shell_

#include "defs.h"

typedef struct{
	char buffer[LINES_QTY][LINE_SIZE];
	int currentline;
} tCommandsBuffer

void startShell();

#endif
