#include <stdio.h>
#include "bfi.h"


// TODO: implement check
int check(char *bfstr) {
    return 1;
}

void interpret(char *bfstr) {
    if(bfstr == NULL) {
        printf("Null brainfuck command string!\n");
        return;
    }

    if(!check(bfstr)) {
        printf("Brainfuck program not valid!\n");
        return;
    }

    // Data memory
    char data[MAX_MEM] = {0};

    // Stack memory
    char *stack[MAX_STACK];

    // Stack top pointer
    int sp;

    // Code pointer
    char *cp = bfstr;

    // Data pointer
    char *dp = data + MAX_MEM / 2;

    // TODO: Jump table
    

    int k = 0;
    
    while(*cp != '\0') {
        //printf("%c\n", *cp);
        switch(*cp) {
            case '>':
                ++dp;
                break;
            case '<':
                --dp;
                break;
            case '+':
                ++(*dp);
                break;
            case '-':
                --(*dp);
                break;
            case '.':
                putchar(*dp);
                break;
            case ',':
                *dp = getchar();
                break;
            case '[':
                if(*dp == 0) {
                    k = 1;
                    while(k) {
                        ++cp;
                        if(*cp == ']') {
                            --k;
                        } else {
                            if(*cp == '[') {
                                ++k;
                            }
                        }
                    }
                }

                stack[++sp] = cp;
                break;

            case ']':
                cp = stack[sp--];
                continue;
        }
        ++cp;
    }
    
}