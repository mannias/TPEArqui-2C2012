#include "../include/kc.h"
#include "../include/kasm.h"

extern DESCR_INT idt[0xA];

/***************************************************************
*k_clear_screen
*
* Borra la pantalla en modo texto color.
****************************************************************/

void k_clear_screen() 
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	};
}

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

void setup_IDT_entry (DESCR_INT *item, byte selector, dword offset, byte access,
			 byte cero) {
  item->selector = selector;
  item->offset_l = offset & 0xFFFF;
  item->offset_h = offset >> 16;
  item->access = access;
  item->cero = cero;
}

void free_IDT_entry(DESCR_INT *item){
	item->selector = NULL;
  	item->offset_l = NULL;
 	item->offset_h = NULL;
 	item->access = NULL;
  	item->cero = NULL;
}

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

void addIDT(unsigned char num){
	if(num == 0x08){
		setup_IDT_entry (&idt[0x08], 0x08, (dword)&_int_08_hand, ACS_INT, 0);
		_Cli();
		_mascaraPIC1(0xFC);
		_Sti();
	}
}

void removeIDT(unsigned char num){
	if(num == 0x08){
		free_IDT_entry(&idt[0x08]);
		_Cli();
		_mascaraPIC1(0xFD);
		_Sti();
	}else if(num == 0x09){
		free_IDT_entry(&idt[0x09]);
		_Cli();
		if(idt[0x08].selector != 0){
			_mascaraPIC1(0xFE);
		}else{
			_mascaraPIC1(0xFF);
		}
		_Sti();
	}
}

char 
read () {
	
	char aux;
	while((aux = getKeyboardChar()) == NULL)
		;
	return aux;

}
