#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "yyparse.tab.h"
#include "enums.h"
#include "dataPacks.h"
#include "structures.h"
#include <string.h>
#include "codeGen.h"
#include "semanticAnalysis.h"

#if (DEBUG == 1)
#define printError(errorText, head) printErrorVerbose(errorText, head)
#define printNodeDetails(head) printNodeDetailsVerbose(head)
#endif


//WORKHORSE. HO!
node* makeNode(int label, symbolTable* parent, token* tok, int nchildren, ...){
  
  node* new = (node*) malloc(sizeof( node ));
  
  //$2->table = $4->table;
  ///$2->table = $6->table;

  new->table = parent;
  new->label = label;
  // new->baseType = 0;
  new->nchildren = nchildren;
  new->tok = tok;  
  new->usage = 0;
  
  //take info from yytoken, add to the node, free the yytoken
  updateNodeWithToken(new, tok);
  //  printNodeDetails(new);

  //iniate to NULL
  new->place = NULL;
  new->code = NULL;
  new->args = NULL;
  new->numArgs = 0;
 
  new->nodeType = strdup("void");
  if( new->targetScope != NULL ){
    new->targetScope = NULL;
  }
      
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

//no more yytokens in my nodes! readily available information is the way to go!
void updateNodeWithToken(node* head, token* tok){
  
  if(head != NULL){
    if(tok != NULL){
      
      if(tok->text != NULL){
	head->contents = strdup(tok->text);
      }
      
      if(tok->filename != NULL){
	head->filename = strdup(tok->text);
      }
      
      head->lineno = tok->lineno;
    }
    
    freeToken(tok);  
  }
}



    
  

//this only needs to handle the initiation. not the block
/*void functionHandler( node* var, node* parent_node ){
  if( var != NULL ){
    switch( var->label ){
    case IDENT:
      {
	if( !findIdentLocally( var->table, var->tok->text ) ){ 
	  list* lst = newListItem();
	  int* size = malloc(sizeof(int));
	  *size = 0;
	  lst->content = size;
	  
	  addSymbol( var->table, var->tok->text, 2 , parent_node, NULL );
	  if(parent_node->nchildren == 5){
	    var->args = buildArgList(parent_node->children[4], lst);
	  }
	  else if(parent_node->nchildren == 4){
	    var->args = buildArgList(parent_node->children[3], lst);
	  }
	}
	else 
	  printError( "Redeclaration of IDENT", var );
      }
      break;
      
    default: 
      { 
	int n = var->nchildren;      
	int i;
	for( i = 0; i < n; i++ ){      
	  if( var->children[i] == NULL ){
	    //do nothing
	  }
	  else{
	    functionHandler( var->children[i], var );
	  } 
	}    
	break;
      }
    }
  }
}
*/
void functionHandlerSmall( node* var ){
  if( var != NULL ){
    switch( var->label ){
    case functionDeclaration:
      {
	list* lst = newListItem();
	int* size = malloc(sizeof(int));
	*size = 0;
	lst->content = size;
	if(var->nchildren == 5){
	  if( !findIdentLocally( var->table, var->children[3]->tok->text ) ){ 
	    addSymbol( var->table, var->children[3]->tok->text, 2 , var->children[3], NULL );
	  }
	  else 
	    printError( "Redeclaration of IDENT", var );
	  var->args = buildArgList(var->children[4], lst);
	}
	else if(var->nchildren == 4){
	  if( !findIdentLocally( var->table, var->children[2]->tok->text ) ){ 
	    addSymbol( var->table, var->children[2]->tok->text, 2 , var->children[3], NULL );
	  }
	  else 
	    printError( "Redeclaration of IDENT", var );
	  var->args = buildArgList(var->children[3], lst);
	  
	}
      }
      break;
      
    default: 
      { 
	int n = var->nchildren;      
	int i;
	for( i = 0; i < n; i++ ){      
	  if( var->children[i] == NULL ){
	    //do nothing
	  }
	  else{
	    functionHandlerSmall( var->children[i]);
	  } 
	}    
	break;
      }
    }
  }
}

list* buildArgList(node* head, list* lst){
  if( head != NULL ){
    if(head->label != block ){
      switch( head->label ){
      case variableBinding:
	{
	  int* lol = lst->content;
	  lol[0]++;
	}
      break;
      
      default:
	//do nothing
	break;
      }
      
      
      int n = head->nchildren;      
      int i;
      for( i = 0; i < n; i++ ){      
	if( head->children[i] == NULL ){
	  //do nothing
      }
	else{
	  buildArgList( head->children[i], lst );
	} 
      }   
    }
  }
  

  
  return lst;
}


void evaluateExpression(node* var, node* parent_node){

}

void parseVariableName(node* var, node* parent_node){

}
/*
void checkIdentsInInitialization(node* head, node* root){
  if( head != NULL ){
    switch( head->label ){
    case IDENT:
      { 
	if(head->tok->text != NULL){
	  if( !findIdent(head->table, head->tok->text) )
	    printError("Use of an ident without declaring", head);
	  else {
	    //check type information
   	    if( !compareTypes( getSymbolNode( head->table, head->tok->text ) , root ) ){
	      printError("Mismatching Types of the two Idents", head);
	    }
	  }
	}
      } 
      break;
    case variableName:
      {
	node* new = getVariable( head->table, head );
	if( new->label != IDENT ) break;
	if(new->tok->text != NULL){
	  if( !findIdent(new->table, new->tok->text) )
	    printError("Use of an ident without declaring", new);
	  else {
	    //check type information
   	    if( !compareTypes( getSymbolNode( new->table, new->tok->text ) , root ) ){
	      printError("Mismatching Types of the two Idents", new);
	    }
	  }
	} 
      }
      break;
    case NUMBERLIT:
      if( !compareTypes( head, root ) ){
	printError("Mismatching Types, I am a Number", head);
      }
      break;
      
    case STRINGLIT:
      if( !compareTypes( head, root ) )
	printError("Mismatching Types, I am a String", head);
      break;

    default:
      {
          int n = head->nchildren;
	  int i;
	  for(i = 0; i < n; i++){      
	    if(head->children[i]==NULL);
	    else 
	      checkIdentsInInitialization( head->children[i] , root );
	  }
      }
    }
  }
}
*/

void assignmentHandler( node* var, node* root){
  if( var != NULL ){
    switch( var->label ){
      
    case variableName:
      {
	
      }
      break; 
      
    case IDENT:
      { 
	if(var->tok->text != NULL){
	  if( !findIdent(var->table, var->tok->text) )
	    printError("Use of an ident without declaring", var);
	  else {
	    //check type information
   	    if( !compareTypes( getSymbolNode( var->table, var->tok->text ) , root ) ){
	      printError("Mismatching Types of the two Idents", var);
	    }
	  }
	}
      } 
      break;

    case NUMBERLIT:
      if( !compareTypes( var, root ) ){
	printError("Mismatching Types, I am a Number", var);
      }
      break;
      
    case STRINGLIT:
      if( !compareTypes( var, root ) )
	printError("Mismatching Types, I am a String", var);
      break;

    default:
      {
      int n = var->nchildren;
      int i;
      for(i = 0; i < n; i++){      
	if(var->children[i]==NULL);
	else 
	  assignmentHandler( var->children[i] , root );
      }   
      }
    }
  }
}

/*
void classHandler( node* var, node* parent_node ){
if( var != NULL ){
int n = var->nchildren;
    int i = 0;
    for( i; i < n; i++ ){
      if(var->children[i]->label == IDENT){
	if( !findIdentLocally( var->children[i]->table, var->children[i]->tok->text ) )
	  addSymbol( var->children[i]->table, var->children[i]->tok->text, 3, var->children[i], NULL );
	else 
	  printError( "Redeclaration of Class definition", var->children[i] );	
      }
    }
  }
}
*/
/* 
int compareTypes( node* var, node* parent_node ){
  if( var != NULL && parent_node != NULL ){
    if( compareStrings( parent_node->nodeType, "void"))
      return 1;
    if( !compareStrings( parent_node->nodeType, var->nodeType ) ) {
      return 0;
    }
    return 1;
  }
  printError("Ident doesn't exist.", var);
  return 0; 
}
*/

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


void traverseTree(node* head, node* parent_node, int level){
  if(head != NULL){
    int n = head->nchildren;
    // if( level > 0 && head->text == NULL) level--;
    
    //general information about the node
   
    int j = 0;
    for(j; j < level; j++){
      printf("%s", " ");
    }
    if(head->label <= 400){
      if(head->contents != NULL){
	//printf("Mem:%p,%s", head, head->text);
	printf("%s ", head->contents);
	printf("%d", head->label);
	printf(" Symbol Table Pointer: %p", (head->table));
	printf("\n");
      }
    }
    else{
      printf("Label: %d -- ", head->label);
      printf("Symbol Table Pointer: %p\n", (head->table));
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




