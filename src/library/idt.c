#include "idt.h"

extern DESCR_INT idt[0xA];

int checkIdt(){
	char vec[9];
	int i;
	DESCR_INT *data;
	for(i=0; i<10; i++){
		data = &idt[i];
		printf("%d - ", i);
		if(data->selector != 0){
			printf("%d - ", data->selector);
			printf("%s - ", toHex(vec,data->offset_l));
			printf("%s - ", toHex(vec,data->offset_h));
			printf("%s - ", toHex(vec,data->access));
			printf("%d\n", data->cero);
		}else{
			printf("%s\n", "EMPTY");
		}
	}
}

