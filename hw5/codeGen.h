#ifndef CODE_GEN
#define CODE_GEN
#include "symbolTable.h"


int count = 0;

char* newLabel();
char* newVariable(symbolTable* parent);

int my_itoa(int val, char* buf);



#endif
