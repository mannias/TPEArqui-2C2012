#include "../include/video.h"

char virtualVideo[LINES_QTY][LINE_SIZE];
tCursor vcursor;
vcursor.line= FIRST_LINE;
vcursor.char= FIRST_CHAR;
char *realVideo= (char *) 0xb8000;
tCursor rcursor;
rcursor.line= FIRST_LINE;
rcursor.char= FIRST_CHAR;

void
write (char c) {
	int i;

	switch(c) {
	
		case ENTER: 
			vcursor.line++;
			vcursor.char= FIRST_CHAR;
			break;
	
		case TAB: 
			for(i=0; i<4 && (vcursor.char != (LINE_SIZE -1)) ;i++)
				virtualVideo[vcursor.line][vcursor.char+=2]= ' ';
			break;
		
		case BACKSPACE: 
			if(vcursor.char != FIRST_CHAR) {
				vcursor.char-= 2;
				write(' ');
			}
			break;
		
		case BACK_ARROW: 
			if(vcursor.char != FIRST_CHAR)
				vcursor.char-= 2;
			break;

		case FORW_ARROW: 
			if(vcursor.char != (LINE_SIZE -1))
				vcursor.char+= 2;
			break;
			
		default:
			if(vcursor.char != (LINE_SIZE -1)) {
				virtualVideo[vcursor.line][vcursor.char]= c;
				vcursor.char+= 2;
			}
	}	
}

void
refreshScreen() {
	int i, j;
	for(i=FIRST_CHAR; i<LINE_SIZE ;i++)
		for(j=FIRST_LINE; j<LINES_QTY ;j++)
			realVideo[(j*LINE_SIZE)+i]= virtualVideo[j][i];

}