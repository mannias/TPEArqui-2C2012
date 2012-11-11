#ifndef _video_
#define _video_

#include "../../include/defs.h"

#define FIRST_LINE 0
#define FIRST_CHAR 0
#define LINES_QTY  25
#define LINE_SIZE  160

#define WHITE_TXT 0x07

typedef struct {
	int line;
	int character;
} tCursor;

typedef struct {
	char buffer[LINES_QTY][LINE_SIZE];
	int currentline;
} tCommandsBuffer;

typedef struct {
	char virtualVideo[LINES_QTY][LINE_SIZE];
	tCursor vcursor;
	tCommandsBuffer commands_buffer;
} tVirConsole;
	

void write(char c);
void virtualwrite(char c);
void realwrite();
char read();
void refreshScreen();
void setUpVideo();
void scrollup();

#endif
