#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>

symbol_table* makeTable(symbol_table* parent){
  symbol_table* new = (symbol_table*)malloc(sizeof(symbol_table));
  new->nSymbols = 0;
  if(parent != NULL){
    new->parent = parent;
  }  
  return new;
}

int findIdentLocally(symbol_table* table){
  
  
  return 0;
}
