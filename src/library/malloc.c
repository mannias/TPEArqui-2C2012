#include "malloc.h"

char* toHex(char* hex, char* pointer);
void mergeNext(mem_header node);
void mergeContinuous();

void initMalloc(){
	long length = checkMem();
	length *= 1048576;
	mem_header node = (mem_header)FIRST_SEGMENT;
	node->next = NULL;
	node->length = length;
	node->used = FALSE;
}

int checkMem(){
	char* mem = (char*)0x200000;
	int space = 1048576;
	int i=0;
	char vec[9];
	int error = 0;
	while(!error){
		*mem = 0;
		if(*mem == 0){
			*mem = 1;
			if(*mem != 1){
				error = 1;
			}
		}else{
			error = 1;
		}
		mem = mem + space;
		if(!error){
			i++;
		}
	}
	return i;
}


void* malloc(int length){
	mem_header node, firstnode;
	char pointer[9];
	firstnode = node = (mem_header)FIRST_SEGMENT;
	int found = 0;
	do{
		if(node->length + sizeof(mem_segment) >= length && node->used == FALSE){
			mem_header nextnode = (mem_header)((char*)node + sizeof(mem_segment) + length);
			nextnode->next = node->next;
			nextnode->length = node->length - ( sizeof(mem_segment) + length);
			nextnode->used = FALSE;
			node->length = length + sizeof(mem_segment);
			node->next = nextnode;
			node->used = TRUE;
			found = 1;
		}else{
			node = node->next;
		}
	}while(node != NULL && !found);
	if(found){
		return (void*) node + sizeof(mem_segment);
	}
	return NULL;

}

void* free(char* dir){
	char vec[9];
	mem_header headnode = (mem_header) ((char*)dir - sizeof(mem_segment));
	headnode->used = FALSE;

	mergeContinuous();
}

void mergeContinuous(){
	mem_header node = (mem_header)FIRST_SEGMENT;
	while(node != NULL){
		if(node->used == FALSE){
			mergeNext(node);
		}
		node = node->next;
	}
}

void mergeNext(mem_header node){
	while(node->next != NULL && node->next->used == FALSE){
		node->length = node->length + node->next->length;
		node->next = node->next->next;
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
	}while(node != NULL);
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
