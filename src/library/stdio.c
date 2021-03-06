#include "stdio.h"
#include "ctype.h"

void printstring(char* string);
void printint(int data);
void write2(char data);
int getIntLength(int num);
double pow(double base, int exponent);
void putint(int data);
int checkprecision(const char* actual);
void putdouble(double num, int pres);
char* getUpstream(char *vec);
void cleanBuffer();
void getChar(char* dir, int* pos, char* text);
void getString(char* dir, int* pos, char* text);
void getInt(int* dir, int* pos, char* text);

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
                	        printstring(va_arg(args, char*));
                	        break;
                	case 'd':     
                    case 'i':
                	        printint(va_arg(args, int));
                	        break;
                	case 'c':                       /* char */
                        	putc((char) va_arg(args, int));
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
    putint(data/10);
    putc(data%10 + '0');
}

void printint(int data){
    if(data < 0){
        putc('-');
        data *= (-1);
    }
    if(data == 0){
        putc('0');
    }
    putint(data);

}

void putc(char data){
    write(data, 1);
}

char getc(){
    read(0);
}

void scanf(const char *data, ...){
    va_list args;
    int comming = 0;
    int escaped = 0;
    char actual;
    char* text;
    int pos =0;
    text = getUpstream(text);
    va_start(args, data);
    while((actual = *data++)!='\0'){
        if(actual == '\\'){
            escaped = 1;
        }else if(actual == '%' && escaped == 0){
            comming = 1;
        }else if(comming == 1){
            switch(actual){
                case 'c':
                    getChar(va_arg(args,char*), &pos, text);
                    break;
                case 's':
                    getString(va_arg(args,char*), &pos, text);
                    break;
                case 'i':
                    getInt(va_arg(args,int*), &pos, text);
                    break;
            }
            comming = 0; 
        }else if(actual == text[pos++]){
            escaped = 0;
        }else{
            printf("rompe");
            return;
        }

    }
    va_end(args);
}

void getChar(char* dir, int* pos, char* text){
    *dir = text[(*pos)++];
}

void getString(char* dir, int* pos, char* text){
    int loc = 0;
    while(text[*pos] != '\0' && text[*pos] != ' '){
        dir[loc++] = text[(*pos)++];  
    }
    dir[loc] = '\0';
}

void getInt(int* dir, int* pos, char* text){
    char vec[20];
    int loc = 0;

    while(isdigit(text[*pos])){
        vec[loc++] = text[(*pos)++]; 
    }
    vec[loc] = '\0';
    if(loc == 0){
        (*dir) = 0;
    }
    (*dir) = atoi(vec);
}


char* getUpstream(char *vec){
    char upstream;
    int pos = 0;
    for(pos = 0; pos < 80 ; pos++){
        vec[pos] = '\0';
    }
    pos = 0;
    while((upstream = getc()) != '\n'){
        if(upstream == BACKSPACE){
            if(pos > 0){
                pos -=1;
                vec[pos] = 0;
            }
        }else{
            vec[pos++] = upstream;
        }
        putc(upstream);
    }
    putc('\n');
    vec[pos] = '\n';
    return vec;
}

void cleanBuffer(){
    while(getc()!= '\n');
}

void
getLine(char str[LINE_SIZE/2]) {
	int i, flag= FALSE;
	for(i=0; i<(LINE_SIZE/2) ;i++) {
		if(!flag) {
			str[i]= getc();
			putc(str[i]);
			if(str[i] == '\n') {
				flag= TRUE;
				str[i]= '\0';
			}
		}
		else
			str[i]= '\0';
	}
}

void wait(){
    long i;
    long w;
    for(i=0; i< 1000000000; i++){
        w=(i/23214)*24234234+234235/3123;
    }
}
