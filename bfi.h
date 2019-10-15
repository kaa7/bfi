#ifndef BFI_H
#define BFI_H

#define MAX_MEM 65536
#define MAX_STACK 65536

// Check if the string to interpret is valid or not 
int check(char *bfstr);


// Interpret the string
void interpret(char *bfstr);

#endif