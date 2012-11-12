#include "video.h"
#include "../library/stdlib.h"

tVirConsole vcon;
char *realVideo;
tCursor rcursor;

void
setUpVideo(){
	int i, j;
	vcon.vcursor.line= FIRST_LINE;
	vcon.vcursor.character= FIRST_CHAR;
	vcon.commands_buffer.currentline= 0;
	rcursor.line= FIRST_LINE;
	rcursor.character= FIRST_CHAR;
	realVideo= (char *) 0xb8000;
	
	for(i=FIRST_CHAR; i<(LINE_SIZE/2) ;i++)
		for(j=FIRST_LINE; j<LINES_QTY ;j++) {
			vcon.virtualVideo[j][i*2]= ' ';
			vcon.virtualVideo[j][(i*2)+1]= WHITE_TXT;
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
	int vpos= (vcon.vcursor.line *LINE_SIZE) +vcon.vcursor.character;
	
	if(rpos<vpos)
		for(rpos; rpos< vpos ;rpos+=2)
			realVideo[rpos]= vcon.virtualVideo[rpos/LINE_SIZE][rpos%LINE_SIZE];
	else
		for(rpos; vpos< rpos ;rpos-=2)
			realVideo[rpos]= vcon.virtualVideo[rpos/LINE_SIZE][rpos%LINE_SIZE];

	rcursor.line= vcon.vcursor.line;
	rcursor.character= vcon.vcursor.character;
}


void
virtualwrite (char c) {
	int i;

	switch(c) {

		case ENTER: 
			if(vcon.vcursor.line == (LINES_QTY -1)) {
				scrollup();
				vcon.vcursor.line--;
				rcursor.line= vcon.vcursor.line;
				refreshScreen(vcon.virtualVideo);
			}
			strncpy(vcon.commands_buffer.buffer[vcon.commands_buffer.currentline], vcon.virtualVideo[vcon.vcursor.line], LINE_SIZE);
			vcon.commands_buffer.currentline++;
			vcon.vcursor.line++;
			vcon.vcursor.character= FIRST_CHAR;
			break;

		case TAB: 
			for(i=0; i<4 && (vcon.vcursor.character < LINE_SIZE) ;i++)
				vcon.virtualVideo[vcon.vcursor.line][vcon.vcursor.character+=2]= ' ';
			break;

		case BACKSPACE: 
			if(vcon.vcursor.character > FIRST_CHAR) {
				vcon.vcursor.character-= 2;
				write(' ');
			}
			break;

		case BACK_ARROW: 
			if(vcon.vcursor.character > FIRST_CHAR)
				vcon.vcursor.character-= 2;
			break;

		case FORW_ARROW: 
			if(vcon.vcursor.character < LINE_SIZE)
				vcon.vcursor.character+= 2;
			break;

		default:
			if(vcon.vcursor.character < LINE_SIZE) {
				vcon.virtualVideo[vcon.vcursor.line][vcon.vcursor.character]= c;
				vcon.vcursor.character+= 2;
			}
	}

}

void
scrollup(char mat[][]) {
	int i, j;
	
	for(i=0; i<(LINES_QTY -1) ;i++) {
		strncpy(mat[i], mat[i+1], LINE_SIZE);
	}
	for(j=0; j<(LINE_SIZE/2) ;j++) {
		mat[i][j*2]= ' ';
	}
}

void
refreshScreen() {
	int i;
	for(i=FIRST_CHAR; i<(LINE_SIZE*LINES_QTY) ;i++)
			realVideo[i]= vcon.virtualVideo[i/LINE_SIZE][i%LINE_SIZE];

}


