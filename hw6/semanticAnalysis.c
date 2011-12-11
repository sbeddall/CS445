
#include "semanticAnalysis.h"
#include "yyparse.tab.h"
#include "tree.h"
#include "enums.h"
#include "codeGen.h"
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
void variableHandler( node* head ){  
  if(head != NULL){
    /*
    if( data == NULL) data = initializeDataPack();
    */
    switch( head->label ){
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
	if(head->children[0]->label == IDENT){
	  if( !findIdentLocally( head->children[0]->table, head->children[0]->contents ) )
	    {
	      addSymbol( head->children[0]->table, head->children[0]->contents, 1, head->children[0], NULL );
	      break;
	    }
	  else 
	    printError( "Redeclaration of variable", head->children[0] );	
	}
	if(head->children[0]->label == variableName){
	  printError("Incorrect usage of variable inheritance. Try declaring inside the correct scope.", head->children[0]);
	}
      }
      break;
      
      
    default: 
      { 
	int n = head->nchildren;      
	int i;
	for(i = 0; i < n; i++){      
	  if(head->children[i]==NULL){
	    //do nothing
	  }
	  else{
	    variableHandler(head->children[i]);
	  } 
	}    
	break;
      }
    }
  } 
}

void functionHandler(struct node* head){
  if( head != NULL ){
    int n = head->nchildren;
    int i = 0;
    for( i; i < n; i++ ){
      if(head->children[i] != NULL){
	if(head->children[i]->label == IDENT){
	  if( !findIdentLocally( head->children[i]->table, head->children[i]->contents ) )
	    {
	      addSymbol( head->children[i]->table, head->children[i]->contents, 2, head->children[i], NULL );
	      //set up the target scope
	      int j = i + 1;
	      head->children[i]->targetScope = head->children[j]->targetScope;
	      printf("There is a god damn targetscope here! %p\n", head->targetScope);
	      break;
	    }
	  else 
	    printError( "Redeclaration of function definition", head->children[i] );	
	}
      }
    }
  }  
}

void classHandler(struct node* head){
  if( head != NULL ){
    int n = head->nchildren;
    int i = 0;
    for( i; i < n; i++ ){
      if(head->children[i] != NULL){
	if(head->children[i]->label == IDENT){
	  if( !findIdentLocally( head->children[i]->table, head->children[i]->contents ) )
	    {
	      addSymbol( head->children[i]->table, head->children[i]->contents, 3, head->children[i], NULL );
	      break;
	    }
	  else 
	    printError( "Redeclaration of class definition", head->children[i] );	
	}
      }
    }
  }
}

void packageHandler(struct node* head){
  if( head != NULL ){
    if(head->children[0]->label == IDENT){
      if( !findIdentLocally( head->children[0]->table, head->children[0]->contents ) )
	{
	  addSymbol( head->children[0]->table, head->children[0]->contents, 4, head->children[0], NULL );
	}
      else 
	  printError( "Redeclaration of package definition", head->children[0] );	
    }
  }
}

