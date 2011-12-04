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
  
  new->table = parent;
  new->label = label;
  // new->baseType = 0;
  new->nchildren = nchildren;
  new->tok = tok;  

  //take info from yytoken, add to the node, free the yytoken
  updateNodeWithToken(new, tok);
  printNodeDetails(new);

  //iniate to NULL
  new->place = NULL;
  new->code = NULL;
  new->args = NULL;

 
  new->nodeType = strdup("void");
  if( new->targetScope != NULL ){
    new->targetScope = NULL;
  }
  
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

node* getVariable( symbolTable* scope, node* var ){
  //base case
  if( var->label == IDENT ){
    //printf("%s\n", var->nodeType);
    if( findIdent( scope, var->tok->text ) ){
      //printf("%s\n", var->tok->text);
      return getSymbolNode( scope, var->tok->text );
    }
    else{ 
       printError( "Use of an undeclared variable.", var );
       //printTable( var->table, 0 );
    }
  }  
  else if( var->label == variableName ){
    if( var->children[0]->label == IDENT ){
      //printf("INTO TEH IF\n"); 
      
      //check the variable exists
      if( findIdent( var->children[0]->table, var->children[0]->tok->text ) ){
	//printf( "Variable Exists %s\n", var->children[0]->tok->text );
	node* tempClassNode = getSymbolNode( var->children[0]->table, var->children[0]->tok->text );
	//	printTable( tempClassNode->table, 0 );
	node* temp;
	if( findIdent( tempClassNode->table, tempClassNode->nodeType ) ){
	  node* temp = getSymbolNode( tempClassNode->table, tempClassNode->nodeType );
	  if( temp->tok == NULL ){
	    printError( "Unexpected Error", var );
	    return var;
	  }
	  
	  if( findIdent( scope, temp->tok->text ) ){
	    //printf("I found the type %s\n", temp->tok->text);
	    
	    return getVariable( temp->targetScope, var->children[2] );
	  }
	  else {
	    printError("I didn't find the class type %s\n", var->children[0]);
	  }
	}
	else {
	  printError("Accessing a variable or function as a class. Not possible.", var->children[0] );
	  return var;
	}
	
	//if(temp == NULL) printError("Class error. No such class", var->children[0]);
	//else {
	
      }
      
      printError("Class Instance does not Exist", var->children[0]);
    }
  }
  //printf("Something went terribly wrong. Var label is %d", var->label);
  return var;
}


    
  

//this only needs to handle the initiation. not the block
void functionHandler( node* var, node* parent_node ){
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


void variableHandler(node* var, node* parent_node, variableDataPack* data ){  
  if(var != NULL){
    if( data == NULL) data = initializeDataPack();
    switch( var->label ){
      
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
      
    case variableBinding:
      {
	//type information population!
	//replace this with a parseVariableName to actually delve through symbol tables
	//right now it only handles IDENTS
	
	if( var->children[0] != NULL &&  ( var->children[0]->label == IDENT || var->children[0]->label == variableName ) ){
	  //printf("Ok, my type of %s is %s\n",var->children[0]->tok->text, var->children[0]->nodeType); 
	  if( !findIdentLocally( var->children[0]->table, var->children[0]->tok->text ) ){
	    addSymbol( var->children[0]->table, var->children[0]->tok->text, 1, var->children[0], data );
	    // field* location = getField(var->children[0]->table, var->children[0]->tok->text);
	    //var->place = location;
	    //var->children[0]->place = location;
	  }
	  else printError( "Redeclaration of IDENT", var->children[0] );
	}
	
	//variable Initialization. Typecheck here is required as well.
	if( var->children[2] != NULL && var->children[2]->label == variableInitialization ){ //
	  checkIdentsInInitialization( var->children[2], var );
	}
      }
      break;
      
      /*case variableInitialization:
      //this will become more complex. For now, check for just an IDENT
      //check all the way down
      checkIdentsInInitialization( var );
      break;
      
      case IDENT:
      if(findIdentLocally(var->table, var->tok->text) == 0){
	
	addSymbol(var->table, var->tok->text, -1, var);
      }
      else printError("Redeclaration of IDENT", var);
      break;
      */      
    default: 
      { 
	int n = var->nchildren;      
	int i;
	for(i = 0; i < n; i++){      
	  if(var->children[i]==NULL){
	    //do nothing
	  }
	  else{
	    variableHandler(var->children[i], var, data);
	  } 
	}    
	break;
      }
    }
  } 
}

void evaluateExpression(node* var, node* parent_node){

}

void parseVariableName(node* var, node* parent_node){

}

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




