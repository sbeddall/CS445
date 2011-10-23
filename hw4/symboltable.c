#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>


symbol_table* makeTable(symbol_table* parent){
  symbol_table* new = (symbol_table*)malloc(sizeof(symbol_table));
  new->fields = (field**)malloc(sizeof(field)*50);
  new->nSymbols = 0;
  
  if(parent != NULL){
    new->parent = parent;
  }  
  return new;
}

int findIdentLocally(symbol_table* table, char* ident){
  int i = 0;
  for( i; i < table->nSymbols; i++){
    if(compareStrings(ident, table->fields[i]->name)) return 1;
  }
  
  return 0;
}

int findIdent(symbol_table* table, char* ident){
  symbol_table* iterator = table;
  
  while(iterator){
    if(findIdentLocally(iterator, ident) == 1) return 1;
    
    iterator = iterator->parent;
  }
  
  return 0;
}

int addSymbol(symbol_table* table, char* ident, int type, struct node* token){  
  field* lol = (field*)malloc(sizeof(field));
  
  lol->name = strdup(ident);
  lol->type = type;
  lol->token = token;
  table->nSymbols++;
  int n = table->nSymbols-1;

  table->fields[n] = lol; 
}

void printTable(symbol_table* table){
  printf("Printing Table: %p\n", table);
  
  int i = 0;
  for( i; i < table->nSymbols; i++ ){
    printf("Ident: %s\n", table->fields[i]->name);
  }
}

void printTableHierarchy(symbol_table* table){
  symbol_table* iterator = table;

  while(iterator->parent != NULL){
    printTable(iterator);
    iterator = iterator->parent;
  }
  printTable(iterator);
}
