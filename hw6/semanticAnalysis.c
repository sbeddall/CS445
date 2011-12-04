#include "semanticAnalysis.h"
#include "yyparse.tab.h"
#include "tree.h"
#include "enums.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int status;


#if (DEBUG == 1)
#define printError(errorText, head) printErrorVerbose(errorText, head)
#define debugOutput(head) debugOutputVerbose(head)
#endif



void yysemantics(node* head){    //build the symbol tables
  buildSymbolTables(head, NULL);

  //compressTree(head);
  
  //populateSymbolTables(head, NULL);
  //checkTypes(head);


  //treePrint
  debugOutput(head);
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

void populateSymbolTables( node* head, node* parent_node ){
  if( head != NULL ){
    switch( head->label ) {
   
    case variableDeclaration:
      variableHandler( head, parent_node, NULL );
      break;  
      
    case functionDeclaration:
      functionHandlerSmall( head );
      break;
      
    case functionCall:
      break;
      
    case classStatement:
      classHandler( head, parent_node );
      break;
      
    case assignStatement:
      {
	node* new;
	if( head->children[0]->label == variableName )
	  new = getVariable( head->children[0]->table, head->children[0] );
	else
	  new = head->children[0];
	//printf("\n\n %d \n\n", new->label );
	if( new->label != IDENT ){
	  //printError("Target assigned variable does not exist. Breaking", parent_node);
	  break;
	}
	if( findIdent( new->table, new->tok->text ) ){
	  head->nodeType = strdup( getSymbolNode( new->table, new->tok->text )->nodeType );
	  assignmentHandler( new, head );
	}
	else
	  printError("Assigning to a non-existent variable", head->children[0]);
	//This needs to grab the symbol type.
	break;
      }
      
    case expression:
      
      break;   
      
      /*    case IDENT:
      if( !findIdent( head->table, head->tok->text ) ) printError( "Use of an ident without declaring", head );
      break;
      */
    default:
      {
	
	break;
      }
    }
      int n = head->nchildren;      
	int i;
	for( i = 0; i < n; i++ ){      
	  if( head->children[i] == NULL ){
	  }
	  else{
	    populateSymbolTables( head->children[i], head );
	  }
	}
  }
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

