#ifndef _string_
#define _string_

#define TRUE 1
#define FALSE 0
#define NULL 0
#define LINE_SIZE 160
#define LINES_QTY 25

#define isNumber(x) (x<='9' && x>='0')? 1:0
#define isChar(x)	((x<='Z' && x>='A') || (x<='z' && x>='a'))? 1:0

int strlen(char* cs);
char* strchr(char* cs, char* c);
char* strnchr(char* cs, char* c, int num);
void strcpy(char *to, char *from);
void strncpy(char *to, char *from, int n);
int strcmp(char *str1, char *str2);
int strncmp(char *str1, char *str2, int n);
int cutstring(char to[], char from[], char c);
int checkclear(char *str);
int parsestring(char *orig, char ret[2][LINE_SIZE/2], int ints[2]);
int parseInts(char *str, int ints[2]);
int allnumbers(char str[]);

#endif
