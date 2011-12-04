#include "semanticAnalysis.h"
#include "yyparse.tab.h"
#include "tree.h"
#include "enums.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void yysemantics(node* head){    //build the symbol tables
  buildSymbolTables(head, NULL);

  //compressTree(head);
  
  //populateSymbolTables(head, NULL);
  //checkTypes(head);


  //treePrint
  traverseTree(head,NULL,0);
  //printTable(head->table, 0);
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

void compressTree(node* head){
  
  
}


void checkTypes(node* head){
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	checkTypes(head->children[i]);
      }
    }
    
    //do work
    switch(head->label){
    }
    
  }  
}



char* getOptionalNodeType( node* var ){
  if( var != NULL){
    if( var->label == optionalVariableType ){
      if( var->children[0]->label == IDENT )
	return strdup( var->children[0]->tok->text );
    }
    else return strdup("void");
  }
  return strdup("void");
}

