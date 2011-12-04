#include "semanticAnalysis.h"
#include "yyparse.tab.h"
#include "tree.h"
#include "enums.h"

void yysemantics(node* head){  
  //build the symbol tables
  buildSymbolTables(head, NULL);

  
  //populateSymbolTables(head, NULL);
  //  checkTypes(head);
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

