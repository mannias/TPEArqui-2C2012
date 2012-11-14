#ifndef _malloc_
#define _malloc_

#include "../../include/defs.h"

#define BASE_SEGMENT (char*) 0x200000

typedef struct mem_segment{
	struct mem_segment * next;
	char* loc;
	long length;
	int used;
}mem_segment;

typedef mem_segment * mem_header;

void initMalloc();
void* malloc(int length);
int free(char* dir);
void printSegments();
int getFreeMem();

#endif
