
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



void yysemantics(node* head){    
  buildSymbolTables(head, NULL); //build the symbol tables

  //compressTree(head);
  
  //populate symbol tables. 
  populateSymbolTables(head, NULL); //class, package, variable declarations.

  checkTypes(head, NULL);
  
  /////miscellaneous checks

  //treePrint
  debugOutput(head); //won't output unless we have "debug" turned on.
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
  //don't use this I think
}

void populateSymbolTables( node* head, node* parent_node ){
  if( head != NULL ){
    switch( head->label ) {
   
    case variableDeclaration:
      {
	variableHandler(head);
	break;  
      }
      
    case functionDeclaration:
      {
	functionHandler(head);
	break;
      }
      
    case classStatement:
      {
	printf("I'm in a classStatement!\n");
	classHandler(head);
	break;
      }
      
    case packageStatement:
      {
	packageHandler(head);
	break;
      }

    default:
      {
	//nothing
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




void checkTypes(node* head, struct node* parent){
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	checkTypes(head->children[i], NULL);
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


/*HANDLERS*/
void variableHandler( node* var ){  
  if(var != NULL){
    /*
    if( data == NULL) data = initializeDataPack();
    */
    switch( var->label ){
      /*  
    case _VAR:
      data->varFlag = 1;
      break;

    case _CONST:
      data->constFlag = 1;
      break;
      
    case _PUBLIC:
      data->publicFlag = 1;
      break;
      
    case _PRIVATE:
      data->privateFlag = 1;
      break;

    case _PROTECTED:
      data->protectedFlag = 1;
      break;
      
    case _OVERRIDE:
      data->overrideFlag = 1;
      break;

    case _NATIVE:
      data->nativeFlag = 1;
      break;
      */
    case variableBinding:
      {
	
      }
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
	    variableHandler(var->children[i]);
	  } 
	}    
	break;
      }
    }
  } 
}

void functionHandler(struct node* head){

}

void classHandler(struct node* head){
  if( head != NULL ){
    int n = head->nchildren;
    int i = 0;
    for( i; i < n; i++ ){
      if(head->children[i]->label == IDENT){
	if( !findIdentLocally( head->children[i]->table, head->children[i]->contents ) )
	  {
	    //update the place here as well
	    printf("Adding symbol to Table: %s\n", head->children[i]->contents);
	    addSymbol( head->children[i]->table, head->children[i]->contents, 3, head->children[i], NULL );
	    break;
	  }
	else 
	  printError( "Redeclaration of Class definition", head->children[i] );	
      }
    }
  }
}

void packageHandler(struct node* head){

}

