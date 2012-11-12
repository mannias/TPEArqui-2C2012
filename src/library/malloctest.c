#include <stdio.h>

#define MEM_LENGTH 8388608
#define FIRST_SEGMENT (char*) 0xF00000
#define FALSE 0
#define TRUE 1

typedef struct mem_segment{
	struct mem_segment * next;
	int length;
	int used;
}mem_segment;

typedef mem_segment * mem_header;

void initMalloc(){
	mem_header node = (mem_header)FIRST_SEGMENT;
	node->next = node;
	node->length = MEM_LENGTH;
	node->used = FALSE;
}


void* mymalloc(int length){
	mem_header node;
	char pointer[9];
	node = (mem_header)FIRST_SEGMENT;
	int found = 0;
	while(node != NULL && !found){
		if(node->length >= length && node->used == FALSE){
			mem_header nextnode = (mem_header)(node + sizeof(mem_segment) + length+1);
			nextnode->next = NULL;
			nextnode->length = node->length - ( sizeof(mem_segment) + length);
			nextnode->used = FALSE;
			node->length = length;
			node->next = nextnode;
			node->used = TRUE;
			found = 1;
		}else{
			node = node->next;
		}
	}
	if(found){
		return (void*) node+sizeof(mem_header);
	}
	return NULL;

}

void printSegments(){
	mem_header node = (mem_header)FIRST_SEGMENT;
	char pointer[9];
	char* dir = FIRST_SEGMENT;
	while(node != NULL){
		printf("%p - ", dir);
		printf("%i - ", node->length);
		printf("%s\n", node->used ? "Used":"Free" );

		dir = (char*)node->next;
		node = node->next;
	}	
}	

int main(void){
	initMalloc();
	printSegments();
	if(mymalloc(12) ==NULL){
		printf("nada");
	}
	printSegments();
}

