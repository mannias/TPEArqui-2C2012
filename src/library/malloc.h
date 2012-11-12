#ifndef _malloc_
#define _malloc_

#include "../../include/defs.h"

#define MEM_LENGTH 8388608
#define FIRST_SEGMENT (char*) 0x200000

typedef struct mem_segment{
	struct mem_segment * next;
	int length;
	int used;
}mem_segment;

typedef mem_segment * mem_header;

void initMalloc();
void* malloc(int length);
void* free(char* dir);
void printSegments();

#endif
