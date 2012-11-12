#include "malloc.h"

char* toHex(char* hex, char* pointer);

void initMalloc(){
	mem_header node = (mem_header)FIRST_SEGMENT;
	node->next = node;
	node->length = MEM_LENGTH;
	node->used = FALSE;
	int i;
	char* point = FIRST_SEGMENT;
	for(i=0; i< 2000; i++){
		point[i] = 'a';
	}
}


void* malloc(int length){
	mem_header node, firstnode;
	char pointer[9];
	firstnode = node = (mem_header)FIRST_SEGMENT;
	int found = 0;
	do{
		if(node->length >= length && node->used == FALSE){
			mem_header nextnode = (mem_header)(node + sizeof(mem_segment) + length);
			nextnode->next = node->next;
			nextnode->length = node->length - ( sizeof(mem_segment) + length);
			nextnode->used = FALSE;
			node->length = length;
			node->next = nextnode;
			node->used = TRUE;
			found = 1;
			printf("node: %s\n",toHex(pointer,(char*)node));
			printf("node next: %s\n",toHex(pointer,(char*)node->next));
			printf("next node: %s\n",toHex(pointer,(char*)nextnode));
			printf("next node next: %s\n",toHex(pointer,(char*)nextnode->next));
		}else{
			printf("node: %s\n",toHex(pointer,(char*)node));
			printf("nodenext: %s\n",toHex(pointer,(char*)node->next));
			node = node->next;
		}
	}while(node != firstnode && !found);
	if(found){
		return (void*) node+sizeof(mem_header);
	}
	return NULL;

}

void* free(char* dir){
	mem_header headnode = (mem_header) (dir - sizeof(mem_segment));
	headnode->used = FALSE;
	while(headnode->next != NULL && headnode->next->used == FALSE){
		headnode->length = headnode->length + headnode->next->length;
		headnode->next = headnode->next->next;

	}
}

void printSegments(){
	mem_header node, firstnode;
	node = firstnode = (mem_header)FIRST_SEGMENT;
	char pointer[9];
	char* dir = FIRST_SEGMENT;
	do{
		printf("%s - ",toHex(pointer,dir));
		printf("%i - ", node->length);
		printf("%s\n", node->used ? "Used":"Free" );

		dir = (char*)node->next;
		node = node->next;
	}while(node != firstnode);
}	

void printMemory(){
	int i;
	char* node = FIRST_SEGMENT;
	for(i=0; i< 2000; i++){
		putc(node+i);
	}
}

char* toHex(char* hex, char* pointer){
	int i;
	int w;
	int num = (int)pointer;
	hex[0] = '0';
	hex[1] = 'x';
	for(i=7; i>1; i--){
		w=num%16;
		if(w<10){
			hex[i] = w+'0';
		}else{
			hex[i] = w-10+'a';
		}
		num/=16;
	}
	hex[8] = '\0';
	return hex;
}
