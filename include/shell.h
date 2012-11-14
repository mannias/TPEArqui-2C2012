#ifndef _shell_
#define _shell_

#include "defs.h"

void startShell();
int parse(char *name, int params[]);
void clear();
void about();
void commands();
void infoIDT();
void testIDT();
void testmalloc();
void mymalloc(int num);
void printMem();

#endif
