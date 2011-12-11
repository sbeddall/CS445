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
int addSymbol(symbolTable* table, char* ident, int baseType, struct node* token, variableDataPack* flags){  
  field* lol = (field*)malloc(sizeof(field));
  
  lol->name = strdup(ident);
  lol->baseType = baseType;
  lol->token = token;
  
  if(flags != NULL) lol->flags = updateFlagsFromData( flags );

  table->nSymbols++;
  int n = table->nSymbols-1;
  table->fields[n] = lol; 
}


void printTable( symbolTable* table, int level ){
  int z = 0;
  for(z; z < level; z++)printf(" ");
  printf("Printing Table: %p\n", table);
  int i = 0;
  for( i; i < table->nSymbols; i++ ){
    if(table->fields[i]->name != NULL){
      z = 0;
      for(z; z < level; z++)printf(" ");
      printf( "Ident: %s : Base Type: %d\n", table->fields[i]->name, table->fields[i]->baseType );
      if( table->fields[i]->baseType == 3){
	printTable(table->fields[i]->token->targetScope, level+1);
      }
      if( table->fields[i]->baseType == 2){
	printTable(table->fields[i]->token->targetScope, level+1);
      }
      if( table->fields[i]->baseType == 4){
	printTable(table->fields[i]->token->targetScope, level+1);
      }
      //, table->fields[i]->token->nodeType, 
      /*if(table->fields[i]->flags != NULL){
	int j = 0;
	printf("\tFlags active\n");
	for(j; j < 7; j++){
	  printf("\t\t%d\n", table->fields[i]->flags[j]);
	}
	}*/
    }
  }
  //  printf("End of Table\n");
}


void printTableHierarchy(symbolTable* table){
  symbolTable* iterator = table;

  while(iterator->parent != NULL){
    printTable(iterator, 0);
    iterator = iterator->parent;
  }
  printTable(iterator, 0);
}

int* updateFlagsFromData( variableDataPack* data ){
    /*
    
      0 var 
      1 const 
      2 public 
      3 private 
      4 protected 
      5 override
      6 native 
      
    */
  int* flags = (int*)malloc(sizeof(int) * 7);
  int i = 0;
  for( i; i< 7; i++){
    flags[i] = 0;
  }
  
  if( data->varFlag == 1 ) flags[0] = 1;
  if( data->constFlag == 1 ) flags[1] = 1;
  if( data->publicFlag == 1 ) flags[2] = 1;
  if( data->privateFlag == 1 ) flags[3] = 1;
  if( data->protectedFlag == 1 ) flags[4] = 1;
  if( data->overrideFlag == 1 ) flags[4] = 1;
  
  if( data->nativeFlag == 1 ) flags[6] = 1;
      
  
  return flags;  
}

field* getField( symbolTable* table, char* ident ){
int i = 0;
 for( i; i < table->nSymbols; i++){
   if(compareStrings(ident, table->fields[i]->name)) return table->fields[i];
 }
 return getField( table->parent, ident );  
}



struct node* getSymbolNode( symbolTable* table, char* ident ){
  int i = 0;
  for( i; i < table->nSymbols; i++){
    if(compareStrings(ident, table->fields[i]->name)) return table->fields[i]->token;
  }
  return getSymbolNode( table->parent, ident );
}
