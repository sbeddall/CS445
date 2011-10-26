#include "symbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "tree.h"

symbolTable* makeTable(symbolTable* parent){
  symbolTable* new = (symbolTable*)malloc(sizeof(symbolTable));
  new->fields = (field**)malloc(sizeof(field)*50);
  new->nSymbols = 0;
  
  if(parent != NULL){
    new->parent = parent;
  }  
  return new;
}

int findIdentLocally(symbolTable* table, char* ident){
  int i = 0;
  for( i; i < table->nSymbols; i++){
    if(compareStrings(ident, table->fields[i]->name)) return 1;
  }
  
  return 0;
}

int findIdent(symbolTable* table, char* ident){
  
  symbolTable* iterator = table;
  
  while(iterator){
    if(findIdentLocally(iterator, ident) == 1) return 1;
    
    iterator = iterator->parent;
  }
  
  return 0;
}

//THIS MAY POINT TO THE RELEVANT NODE. NOT NECESSARILY THE IDENT NODE ITSELF
//Example: 
int addSymbol(symbolTable* table, char* ident, int type, struct node* token){  
  field* lol = (field*)malloc(sizeof(field));
  
  lol->name = strdup(ident);
  lol->type = type;
  lol->token = token;
  table->nSymbols++;
  int n = table->nSymbols-1;

  table->fields[n] = lol; 
}

void printTable(symbolTable* table){
  printf("Printing Table: %p\n", table);
  
  int i = 0;
  for( i; i < table->nSymbols; i++ ){
    if(table->fields[i]->name != NULL)
      printf( "Ident: %s : Type: %s\n", table->fields[i]->name, table->fields[i]->token->nodeType );
    
  }
}

void printTableHierarchy(symbolTable* table){
  symbolTable* iterator = table;

  while(iterator->parent != NULL){
    printTable(iterator);
    iterator = iterator->parent;
  }
  printTable(iterator);
}
