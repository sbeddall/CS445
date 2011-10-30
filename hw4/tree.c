#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "yyparse.tab.h"
#include "enums.h"
#include "dataPacks.h"
#include "structures.h"
#include <string.h>

//WORKHORSE. HO!
node* makeNode(int label, symbolTable* parent, token* tok, int nchildren, ...){
  
  node* new = (node*) malloc(sizeof( node ));
  
  new->table = parent;
  new->label = label;
  // new->baseType = 0;
  new->nchildren = nchildren;
  new->tok = tok;
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

node* getVariable(symbolTable* scope, node* var){

}

void yysemantics(node* head){  
  //build the symbol tables
  buildSymbolTables(head, NULL);
  populateSymbolTables(head, NULL);
  
  //treePrint
  //  traverseTree(head,NULL,0);

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

    
  
void populateSymbolTables( node* head, node* parent_node ){
  if( head != NULL ){
    switch( head->label ) {
   
    case variableDeclaration:
      variableHandler( head, parent_node, NULL );
      break;  
      
    case functionDeclaration:
      functionHandler( head, parent_node );

      break;
      
    case functionCall:
      break;
      
    case classStatement:
      classHandler( head, parent_node );
      break;
      
    case assignStatement:
      {
	if( findIdent( head->table, head->children[0]->tok->text ) ){
	  head->nodeType = strdup( getSymbolNode( head->children[0]->table, head->children[0]->tok->text )->nodeType );
	  assignmentHandler( head, head );
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

//this only needs to handle the initiation. not the block
void functionHandler( node* var, node* parent_node ){
  if( var != NULL ){
    switch( var->label ){
    case IDENT:
      if( !findIdentLocally( var->table, var->tok->text ) ) 
	addSymbol( var->table, var->tok->text, 2 , parent_node, NULL );
      else 
	printError( "Redeclaration of IDENT", var );
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
	if( var->children[0] != NULL && var->children[0]->label == IDENT ){
	  //printf("Ok, my type of %s is %s\n",var->children[0]->tok->text, var->children[0]->nodeType); 
	  
	  if( !findIdentLocally( var->children[0]->table, var->children[0]->tok->text ) )
	    addSymbol( var->children[0]->table, var->children[0]->tok->text, 1, var->children[0], data );
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
    case NUMBERLIT:
      if( !compareTypes( head, root ) ){
	printError("Mismatching Types, I am a Number", head);
      }
      break;
      
    case STRINGLIT:
      if( !compareTypes( head, root ) )
	printError("Mismatching Types, I am a String", head);
      break;
	  
    }
    int n = head->nchildren;
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL);
      else 
	checkIdentsInInitialization( head->children[i] , root );
    }
  }
}


void assignmentHandler( node* var, node* root){
  if( var != NULL ){
    switch( var->label ){
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
      
    }
    int n = var->nchildren;
    int i;
    for(i = 0; i < n; i++){      
      if(var->children[i]==NULL);
      else 
	assignmentHandler( var->children[i] , root );
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

char* getOptionalNodeType( node* var ){
  if( var != NULL){
    if( var->label == optionalVariableType ){
      if( var->children[1]->label == IDENT )
	return strdup( var->children[1]->tok->text );
    }
    else return strdup("void");
  }
  return strdup("void");
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






