#include "../include/kc.h"
#include "../include/kasm.h"

extern DESCR_INT idt[0xA];
extern _empty_hand;

/***************************************************************
*setup_IDT_entry
* Inicializa un descriptor de la IDT
*
*Recibe: Puntero a elemento de la IDT
*	 Selector a cargar en el descriptor de interrupcion
*	 Puntero a rutina de atencion de interrupcion	
*	 Derechos de acceso del segmento
*	 Cero
****************************************************************/

void
setup_IDT_entry (DESCR_INT *item, byte selector, dword offset, byte access,
			 byte cero) {
  item->selector = selector;
  item->offset_l = offset & 0xFFFF;
  item->offset_h = offset >> 16;
  item->access = access;
  item->cero = cero;
}

void 
checkIDT(){
	char vec[9];
	int i;
	DESCR_INT *data;
	printf("ID - SELECTOR - OFFSET LOW - OFFSET HIGH - ACCESS - CERO\n");
	for(i=0; i<10; i++){
		data = &idt[i];
		printf("%d - ", i);
		if(((data->offset_l == ((dword) &_empty_hand & 0xFFFF)) && (data->offset_h == ((dword) &_empty_hand >> 16)))||data->selector == 0){
			printf("%s\n", "EMPTY");
		}else{
			printf("%d - ", data->selector);
			printf("%s - ", toHex(vec,data->offset_l));
			printf("%s - ", toHex(vec,data->offset_h));
			printf("%s - ", toHex(vec,data->access));
			printf("%d\n", data->cero);
		}
	}
}

void 
addIDT(unsigned char num, dword rout){
	setup_IDT_entry (&(idt[num]), 0x08, rout, ACS_INT, 0);
	_Cli();
	_mascaraPIC1(0xFC);
	_Sti();
}

void 
removeIDT(unsigned char num){
	if(num == 8){
		setup_IDT_entry (&(idt[num]), 0x00, (dword)&_empty_hand, ACS_INT, 0);
		_Cli();
		_mascaraPIC1(0xFD);
		_Sti();
	}
	if(num == 9){
		setup_IDT_entry (&(idt[num]), 0x00, (dword)&_empty_hand, ACS_INT, 0);
		_Cli();
		if((&idt[0x08])->selector != 0){
			_mascaraPIC1(0xFE);
		}else{
			_mascaraPIC1(0xFF);
		}
		_Sti();
	}
}

char 
read(int descriptor) {
	
	char aux;
	if(descriptor == 0)
		while((aux = getKeyboardChar()) == NULL)
			;
	
	return aux;
}
