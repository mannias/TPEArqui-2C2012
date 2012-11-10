#ifndef _video_
#define _video_

#include "../../include/defs.h"


#define FIRST_LINE 0
#define FIRST_CHAR 0
#define LINES_QTY  25
#define LINE_SIZE  160

typedef struct {
	int line;
	int character;
} tCursor;

void write(char c);
void virtualwrite(char c);
void realwrite();
char read();
void refreshScreen();
void setUpVideo();

#endif
