#ifndef _malloc_
#define _malloc_

#define MEM_LENGTH 8388608
#define FIRST_SEGMENT (char*) 0x20000

typedef struct mem_segment{
	struct *mem_segment * next
	int length;
	int used;
}mem_segment;

typeof mem_segment * mem_header;

#endif
