#include "stdio.h"

void printstring(char* string);
void printint(int data);
void write2(char data);
int getIntLength(int num);
double pow(double base, int exponent);
void putint(int data);
int checkprecision(const char* actual);
void putdouble(double num, int pres);

void printf(const char *data, ...){
        va_list args;
        int d;
        char actual;
        int comming = 0;
        int escaped = 0;
        char c, *p, *s;

        int paso = 0;
        va_start(args, data);
        while ((actual = *data++) != '\0'){
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
                	case 'd':     
                    case 'i':
                	        printint(va_arg(args, int));
                	        break;
                	case 'c':                       /* char */
                        	c = (char) va_arg(args, int);
                    	    putc(c);
                	        break;
                    case 'f':
                    case 'e':
                    case 'E':
                            putdouble(va_arg(args, double),6);
                    default:
                            break;
            	}
            	comming = 0;
        	}else{
        		putc(actual);
        	}
        }
        va_end(args);
}

void printstring(char* string){
    int i;
    for(i=0; string[i] != '\0'; i++){
        putc(string[i]);
    }
}

void putdouble(double num, int pres){
    int real = (int)num;
    int i;
    if(real<0){
        putc('-');
        real *= (-1);
    }
    printint(real);
    putc('.');
    for(i=0; i< pres; i++){
        num *= 10;
        putc(((int)num)%10 + '0');
    }

}

void putint(int data){
    if(data == 0){
        return;
    }
    printint(data/10);
    putc(data%10 + '0');
}

void printint(int data){
    if(data < 0){
        write2('-');
        data *= (-1);
    }
    putint(data);

}

void putc(char data){
    write2(data);
}

char *video= (char *) 0xb8000;
int pos = 0;

void write2(char data){
    video[pos] = data;
    pos+=2;
    if(pos >= (80*25*2)){
        pos = 0;
    }
}

char getc(){
    read();
}

void scanf(const char *data, ...){
    va_list args;
    int d;
    char actual;
    int comming = 0;
    int escaped = 0;
    char *c, *p, **s;
    int* i;
    double* d;

    int paso = 0;
    va_start(args, data);
    while ((actual = *data++) != '\0'){
        if(actual == '%' && escaped == 0){
            comming = 1;
        }else if(escaped == 1){
            escaped = 0;
        }else if(actual == '\\'){
            escaped = 1;
        }else if(comming == 1){
            switch(actual) {
                case 's':                       /* string */
                    s = va_arg(args, char**);
                    printstring(s);
                    break;
                case 'd':     
                case 'i':
                    i = va_arg(args, int*);
                    break;
                case 'c':                       /* char */
                    c = (char) va_arg(args, char*);
                    break;
                case 'f':
                case 'e':
                case 'E':
                    d  = va_arg(args, double*);
                default:
                    break;
            }
            comming = 0;
        }else{
            putc(actual);
        }
    }
    va_end(args);
}

