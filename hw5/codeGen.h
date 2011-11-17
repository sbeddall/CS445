#ifndef CODE_GEN
#define CODE_GEN
#include "symbolTable.h"


char* newLabel();
char* newVariable(symbolTable* parent);

char* itoa(int val, char* buf);
int my_itoa(int val, char* buf);
void reverseString(char* buf);


#endif
