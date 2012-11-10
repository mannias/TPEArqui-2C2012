#include "../include/stdio.h"

void printstring(char* string);
void printint(int data);
void printchar(char data);

void printf(const char *data, ...){
        va_list args;
        int d;
        char actual;
        int comming = 0;
        int escaped = 0;
        char c, *p, *s;

        va_start(args, data);
        while (*data != '\0')
        	actual = *data++;
        	if(actual == '%' && escaped == 0){
        		comming = 1;
        	}else if(escaped == 1){
        		escaped = 0;
        	}else if(actual == '\\'){
        		escaped = 1;
        	}else if(comming == 1){
            	switch(actual) {
                	case 's':                       /* string */
                	        s = va_arg(args, char*);
                	        printstring(s);
                	        break;
                	case 'd':                       /* int */
                	        d = va_arg(args, int);
                	        printint(d);
                	        break;
                	case 'c':                       /* char */
                        	c = (char) va_arg(args, int);
                    	    printchar(c);
                	        break;
            	}
            	comming = 0;
        	}else{
        		write(actual);
        	}
        va_end(args);
}

void printstring(char* string){
    int i;
    for(i=0; string[i] != '\0'; i++){
        write(string[i]);
    }
}

void printint(int data){
    write(data);
}

void printchar(char data){
    write(data);
}
