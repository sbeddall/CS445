#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "yyparse.tab.h"


//WORKHORSE. HO!
node* makeNode(int label, symbol_table* parent, token* tok, int nchildren, ...){
  
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
  traverseTree(head,NULL,0);

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
    case _VAR:
      variableHandler(parent_node,NULL);
      break; 
      
    case _CONST:
      variableHandler(parent_node, NULL);
      break;
      
      
    default:
      break;
    }
    
    int n = head->nchildren;      
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
      }
      else{
	populateSymbolTables(head->children[i], head);
      }
    }   
  }
}



void variableHandler(node* var, node* parent_node){
  
  if(var != NULL){
    switch( var->label ){
    case IDENT:
      if(findIdentLocally(var->table, var->tok->text) == 0){
	addSymbol(var->table, var->tok->text, -1, var);
      }
      else printf("The Symbol with: \"%s\" as text is already present!", var->tok->text);
      break;
      
    default:
      break;
    }
    
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





/*
void verboseTraverseTree(node* head, int level){
  if(head != NULL){
    int i;
    int n = head->nchildren;
    if(head->text != NULL){
      printf("%s", head->text);
      printf("\n");
    }
    
    
    
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	printf("Level %d children: \n", n);
	printf("%s\n", head->children[i]->text);
	//traverseTree(head->children[i], level++);
      }
    }
    
  }
}
*/



