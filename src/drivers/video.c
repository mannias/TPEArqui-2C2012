#include "video.h"


char virtualVideo[LINES_QTY][LINE_SIZE];
tCursor vcursor;
char *realVideo;
tCursor rcursor;

void
setUpVideo(){
	int i, j;
	vcursor.line= FIRST_LINE;
	vcursor.character= FIRST_CHAR;
	rcursor.line= FIRST_LINE;
	rcursor.character= FIRST_CHAR;
	*realVideo= (char *) 0xb8000;
	
	for(i=0; i<LINE_SIZE ;i++)
		for(j=0; j<LINES_QTY ;j++)
			virtualVideo[j][i]= ' ';
	
	virtualwrite('A');
}

void
write (char c) {

//	virtualwrite(c);
	realwrite();

}

void 
realwrite() {
	int i;
	
	for(i= ((rcursor.line *LINE_SIZE) +rcursor.character); i< ((vcursor.line *LINE_SIZE) +vcursor.character) ;i+=2)
		realVideo[i]= virtualVideo[i/16][i%16];

}


void
virtualwrite (char c) {
	int i;
	
/*	switch(c) {
	
		case ENTER: 
			vcursor.line++;
			vcursor.character= FIRST_CHAR;
			break;
	
		case TAB: 
			for(i=0; i<4 && (vcursor.character != (LINE_SIZE -2)) ;i++)
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
			if(vcursor.character != (LINE_SIZE -2))
				vcursor.character+= 2;
			break;
			
		default:
			if(vcursor.character != (LINE_SIZE -2)) {
				virtualVideo[vcursor.line][vcursor.character]= c;
				
				vcursor.character+= 2;
			}
	}	*/
	
	for(i=0; i<25*80 ;i++)
		**(virtualVideo +(i*2))= c;
	vcursor.character= LINE_SIZE -1;
	vcursor.line= LINES_QTY -1;
	
}

void
refreshScreen() {
	int i, j;
	for(i=FIRST_CHAR; i<LINE_SIZE ;i++)
		for(j=FIRST_LINE; j<LINES_QTY ;j++)
			realVideo[(j*LINE_SIZE)+i]= virtualVideo[j][i];
		
}

char 
read () {
	
	char aux;
	while((aux = getC()) == NULL)
		;

		
	return aux;

}
