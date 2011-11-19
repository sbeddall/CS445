#ifndef CODE_GEN
#define CODE_GEN
#include "symbolTable.h"
#include "structures.h"
#include "tree.h"

char* newLabel();
char* newVariable(symbolTable* parent);


//string functions for labels and variables
char* itoa(int val, char* buf);
int my_itoa(int val, char* buf);
void reverseString(char* buf);

void populatePlaces(node* head);
list* concatenateChildren(node* head);

#endif
