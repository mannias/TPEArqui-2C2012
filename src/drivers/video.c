#include "video.h"


char virtualVideo[LINES_QTY][LINE_SIZE];
tCursor vcursor;
char *realVideo= (char *) 0xb8000;
tCursor rcursor;

void
setUpVideo(){
	vcursor.line= FIRST_LINE;
	vcursor.character= FIRST_CHAR;
	rcursor.line= FIRST_LINE;
	rcursor.character= FIRST_CHAR;
}

void
write (char c) {
	int i;
	realVideo[20] = 'c';
	switch(c) {
	
		case ENTER: 
			vcursor.line++;
			vcursor.character= FIRST_CHAR;
			break;
	
		case TAB: 
			for(i=0; i<4 && (vcursor.character != (LINE_SIZE -1)) ;i++)
				virtualVideo[vcursor.line][vcursor.character+=2]= ' ';
			break;
		
		case BACKSPACE: 
			if(vcursor.character != FIRST_CHAR) {
				vcursor.character-= 2;
				write(' ');
			}
			break;
		
		case BACK_ARROW: 
			if(vcursor.character != FIRST_CHAR)
				vcursor.character-= 2;
			break;

		case FORW_ARROW: 
			if(vcursor.character != (LINE_SIZE -1))
				vcursor.character+= 2;
			break;
			
		default:
			if(vcursor.character != (LINE_SIZE -1)) {
				virtualVideo[vcursor.line][vcursor.character]= c;
				vcursor.character+= 2;
			}
	}	
}

void
refreshScreen() {
	int i, j;
	for(i=FIRST_CHAR; i<LINE_SIZE ;i++){
		for(j=FIRST_LINE; j<LINES_QTY ;j++){
			realVideo[(j*LINE_SIZE)+i]= virtualVideo[j][i];
		}
	}
}

char 
read () {
	
	char aux;
	while((aux = getC()) == NULL)
		;
	write(aux);
	refreshScreen();
	return aux;

}
