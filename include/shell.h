#ifndef _shell_
#define _shell_

#include "defs.h"

void startShell();
int parse(char *name, char *params);
void clear();
void about();
void commands();

#endif
