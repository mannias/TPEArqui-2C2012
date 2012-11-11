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
	realVideo= (char *) 0xb8000;
	
	for(i=FIRST_CHAR; i<(LINE_SIZE/2) ;i++)
		for(j=FIRST_LINE; j<LINES_QTY ;j++) {
			virtualVideo[j][i*2]= ' ';
			virtualVideo[j][(i*2)+1]= WHITE_TXT;
		}
}

void
write (char c) {

	virtualwrite(c);
	realwrite();

}

void 
realwrite() {
	int rpos= (rcursor.line *LINE_SIZE) +rcursor.character;
	int vpos= (vcursor.line *LINE_SIZE) +vcursor.character;
	
	if(rpos<vpos)
		for(rpos; rpos< vpos ;rpos+=2)
			realVideo[rpos]= virtualVideo[rpos/LINE_SIZE][rpos%LINE_SIZE];
	else
		for(rpos; vpos< rpos ;rpos-=2)
			realVideo[rpos]= virtualVideo[rpos/LINE_SIZE][rpos%LINE_SIZE];

	rcursor.line= vcursor.line;
	rcursor.character= vcursor.character;
}


void
virtualwrite (char c) {
	int i;

	switch(c) {

		case ENTER: 
			vcursor.line++;
			vcursor.character= FIRST_CHAR;
			break;

		case TAB: 
			for(i=0; i<4 && (vcursor.character < LINE_SIZE) ;i++)
				virtualVideo[vcursor.line][vcursor.character+=2]= ' ';
			break;

		case BACKSPACE: 
			if(vcursor.character > FIRST_CHAR) {
				vcursor.character-= 2;
				write(' ');
			}
			break;

		case BACK_ARROW: 
			if(vcursor.character > FIRST_CHAR)
				vcursor.character-= 2;
			break;

		case FORW_ARROW: 
			if(vcursor.character < LINE_SIZE)
				vcursor.character+= 2;
			break;

		default:
			if(vcursor.character < LINE_SIZE) {
				virtualVideo[vcursor.line][vcursor.character]= c;
				vcursor.character+= 2;
			}
	}

}

void
refreshScreen() {
	int i, j;
	for(i=FIRST_CHAR; i<(LINE_SIZE/2) ;i++)
		for(j=FIRST_LINE; j<LINES_QTY ;j++)
			virtualVideo[j][i*2]= ' ';

}


