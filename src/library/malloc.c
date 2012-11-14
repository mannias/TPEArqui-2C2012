#include "malloc.h"

char* toHex(char* hex, char* pointer);
void mergeNext(mem_header node);
void mergeContinuous();
mem_header getHeader(char* dir);

int minsegment;
char* startsegment;
char* lastsegment;

void initMalloc(){
	long length = checkMem();
	length *= 1048576;
	minsegment = (int)((sizeof(mem_segment)*(length-(0.1*length))/(0.1*length)));
	length -= (int)(0.1*length)+1;
	startsegment = BASE_SEGMENT + (int)(0.1*length)+1;
	mem_header node = (mem_header)BASE_SEGMENT;
	node->next = NULL;
	node->length = length;
	node->used = FALSE;
	node->loc = startsegment;
	lastsegment = BASE_SEGMENT + length;
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
	firstnode = node = (mem_header)BASE_SEGMENT;
	int found = 0;
	if(length < minsegment){
		length = minsegment;
	}
	do{
		if(node->length >= length && node->used == FALSE){
			if(node->length > length){
				mem_header nextnode = (mem_header)lastsegment;
				lastsegment += sizeof(mem_segment);
				nextnode->next = node->next;
				nextnode->length = node->length - length;
				nextnode->used = FALSE;
				nextnode->loc = node->loc + length;
				node->next = nextnode;
				node->length = length;
			}
			node->used = TRUE;
			found = 1;
		}else{
			node = node->next;
		}
	}while(node != NULL && !found);
	if(found){
		return node->loc;
	}
	return NULL;

}

void* free(char* dir){
	mem_header headnode = getHeader(dir);
	if(headnode != NULL){
		headnode->used = FALSE;
		mergeContinuous();
	}
}

mem_header getHeader(char* dir){
	mem_header node = (mem_header)BASE_SEGMENT;
	while(node != NULL){
		if(node->loc == dir ){
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void mergeContinuous(){
	mem_header node = (mem_header)BASE_SEGMENT;
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
	mem_header node = (mem_header)BASE_SEGMENT;
	char pointer[9];
	do{
		printf("%s - ",toHex(pointer,node->loc));
		printf("%i - ", node->length);
		printf("%s\n", node->used ? "Used":"Free" );
		node = node->next;
	}while(node != NULL);
}	

void printMemory(){
	int i;
	char* node = BASE_SEGMENT;
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
