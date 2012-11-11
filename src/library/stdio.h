#ifndef _stdio_
#define _stdio_

#include "../../include/defs.h"

#define BUFFER_LEN 200   /* tamaño del stack de teclado */

#define va_start(v,l) __builtin_va_start(v,l)
#define va_arg(v,l)   __builtin_va_arg(v,l)
#define va_end(v)     __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)

typedef __builtin_va_list va_list;

void printf(const char *data, ...);
void putc(char data);
char getc();
void scanf(const char *data, ...)

#endif
