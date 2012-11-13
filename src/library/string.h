#ifndef _string_
#define _string_

#include "../../include/defs.h"

#define isNumber(x) (x<='9' && x>='0')? 1:0

int srtlen(char* cs);
char* strchr(char* cs, char* c);
char* strnchr(char* cs, char* c, int num);
void strcpy(char *to, char *from);
void strncpy(char *to, char *from, int n);
int strcmp(char *str1, char *str2);
int strncmp(char *str1, char *str2, int n);
int parsestring(char *orig, char *ret[2]);
int parseInts(char *str, int ints[2]);

#endif
