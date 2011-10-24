#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "yyparse.tab.h"
#include "enums.h"
#include "structures.h"

//WORKHORSE. HO!
node* makeNode(int label, symbolTable* parent, token* tok, int nchildren, ...){
  
  node* new = (node*) malloc(sizeof( node ));
  
  new->table = parent;
  new->label = label;
  new->baseType = 0;
  new->nchildren = nchildren;
  new->tok = tok;
  // new->parent = parent;
    
  new->children = 0;
  if(nchildren > 0){
    new->children = (node**)malloc(sizeof(node*) * nchildren);
    
    int i;
    va_list va;
    
    va_start(va,nchildren);
    for(i = 0; i<nchildren; i++){
      new->children[i] = va_arg(va, node*);
    }
    va_end(va);
  }
  
  return new;
}

void yysemantics(node* head){  
  //build the symbol tables
  buildSymbolTables(head, NULL);
  populateSymbolTables(head, NULL);
  
  //treePrint
  //traverseTree(head,NULL,0);

  printTable(head->table);

}


void buildSymbolTables(node* head, node* parent_node){
  if(head != NULL){
    //get the symbol tables organized
    if(head->table == NULL){
      if(parent_node != NULL)
	head->table = parent_node->table; 
    }
    else {
      if(parent_node != NULL)
	head->table->parent = parent_node->table;
    }
    
    int n = head->nchildren;      
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
      }
      else{
	buildSymbolTables(head->children[i], head);
      }
    }   
  }
}

    
  
void populateSymbolTables(node* head, node* parent_node){
  if(head != NULL){
    switch( head->label ) {
    case variableDeclaration:
      variableHandler(head,NULL);
      break;  
      
    case functionDeclaration:
      
      break;

    case IDENT:
      if(!findIdent(head->table, head->tok->text)) printError("Use of an ident: %s  without declaring!", head);
      break;

    default:
      {
	int n = head->nchildren;      
	int i;
	for(i = 0; i < n; i++){      
	  if(head->children[i]==NULL){
	  }
	  else{
	    populateSymbolTables(head->children[i], head);
	  }
	}
	break;
      }
    }
  }
}



void variableHandler(node* var, node* parent_node){  
  if(var != NULL){
    switch( var->label ){
     
    case variableInitialization:
      //this will become more complex. For now, check for just an IDENT
      //check all the way down
      //      checkIdentsInInitialization( var );
      break;
      
    case IDENT:
      
      if(findIdentLocally(var->table, var->tok->text) == 0){
	addSymbol(var->table, var->tok->text, -1, var);
      }
      else printError("Variable already present", var);
      break;
	 
    default: 
      { 
	int n = var->nchildren;      
	int i;
	for(i = 0; i < n; i++){      
	  if(var->children[i]==NULL){
	    //do nothing
	  }
	  else{
	    variableHandler(var->children[i], var);
	  } 
	}    
	break;
      }
    }
  } 
}



void traverseTree(node* head, node* parent_node, int level){
  if(head != NULL){
    int n = head->nchildren;
    // if( level > 0 && head->text == NULL) level--;
    
    //general information about the node
    printf("Label: %d -- ", head->label);
    printf("Symbol Table Pointer: %p\n", (head->table));
    
    int j = 0;
    for(j; j < level; j++){
      //printf("%d", level);
    }
    if(head->tok != NULL){
      if(head->tok->text != NULL){
	//printf("Mem:%p,%s", head, head->text);
	printf("%s ", head->tok->text);
	printf("%d", head->label);
	printf(" Symbol Table Pointer: %p", (head->table));
	printf("\n");
      }
      else{
	//printf("Null Text, Memory Location %p\n", head);
      }
    }
    
    int i;
    int k;
    /*printf("My Memory Location: %p\n", head);
    for(k = 0; k < n; k++){      
      if(head->children[k]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	printf("%d: %p, ", k,head->children[k]);
	//traverseTree(head->children[i], level++);
      }
      }*/
    //printf("\n");
    
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	//printf("Child Memory Location %p\n", head->children[i]);
	traverseTree(head->children[i], head, level++);
      }
    }
    
  }
}

void checkIdentsInInitialization(node* head){
  if( head != NULL ){
    printf("Checking IDENTS!\n");
    if(head->label = IDENT){
      if(findIdent(head->table, head->tok->text) == 0)
	printError("Use of an ident: %s  without declaring!", head);
    }
    
    int n = head->nchildren;
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL);
      else 
	checkIdentsInInitialization( head->children[i] );
    }
  }
}


//not sure this will actually work
node* miniTraverse( node* head, int label ){
  if( head != NULL ){
    if(head->label == label)
      return head;
    int n = head->nchildren;
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	//printf("Child Memory Location %p\n", head->children[i]);
	return miniTraverse( head->children[i], label );;
      }
    }
  }
  return NULL;
}







