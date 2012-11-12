
mem_header mem_struct;

void initStruct(){
	mem_header node = FIRST_SEGMENT;
	node->next = NULL;
	node->length = MEM_LENGTH;
	node->used = FALSE;
}


void* malloc(int length){
	mem_header node;
	node = FIRST_SEGMENT;
	int found = 0;
	while(node->next != NULL && !found){
		if(node->length >= length && node->used = FALSE){
			mem_header nextnode = (mem_header)(node+sizeof(mem_header)+length);
			if(node->next != NULL){
				nextnode->next = node->next;
			}else{
				nextnode->next = NULL;
			}
			nextnode->length = node->length - sizeof(mem_header) - length;
			nextnode->used = FALSE;
			node->length = sizeof(mem_header) + length;
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

void* free(char* dir){
	mem_header headnode = (mem_header) dir-sizeof(mem_header);
	headnode->used = FALSE;
	while(headnode->next != NULL && headnode->next->used == FALSE){
		headnode->length = headnode->length + headnode->next->length;
		headnode->next = headnode->next->next;

	}
}


int getUsed()