
/* apuntador a la primera ocurrencia de c en cs*/
char* strchr(char* cs, char* c){
	char* aux = cs;
	int status = 0;
	int sum = 0;
	int pos1 = 0;
	int pos2 = 0;
	int loc = 0;
	int size = strlen(c);
	while(cs[pos1] != '\0' && c[pos2] != '\0' ){
		if(status == 0){
			if(cs[pos1] == c[pos2]){
				loc = pos1;
				status = 1;
			}else{
				pos1++;
			}
		}else if(status == 1){
			if(cs[pos1++] == c[pos2++]){
				sum++;
			}else{
				if(sum == size){
					return *cs+loc;
				}
				status = 0;
			}
		}
	}
	if(sum == size{
		return *cs+loc;
	}
	return NULL;
}
/* regresa la longitud de cs */
size_t srtlen(char* cs){
	int i = 0;
	while(cs[i] != '\0'){
		i++
	}
	return i-1;
}