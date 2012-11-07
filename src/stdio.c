#include "../include/kc.h"
#include "../include/stdio.h"

void printf(char* data, ...){
        va_list ap;
        int d;
        char actual;
        int comming = 0;
        int scaped = 0;
        char c, *p, *s;

        va_start(ap, fmt);
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
                	        s = va_arg(ap, char *);
                	        printstring(s);
                	        break;
                	case 'd':                       /* int */
                	        d = va_arg(ap, int);
                	        write(d);
                	        break;
                	case 'c':                       /* char */
                        	c = (char) va_arg(ap, int);
                    	    write(c);
                	        break;
            	}
            	comming = 0;
        	}else{
        		write(actual);
        	}
        va_end(ap);
}