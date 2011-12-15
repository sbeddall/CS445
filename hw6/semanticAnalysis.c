#include "semanticAnalysis.h"
#include "yyparse.tab.h"
#include "tree.h"
#include "enums.h"
#include "codeGen.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


extern int status;
extern node* currenthead;
extern FILE* yyin;
extern int LINENO;
extern char* FILENAME;

#if (DEBUG == 1)
#define printError(errorText, head) printErrorVerbose(errorText, head)
#define debugOutput(head) debugOutputVerbose(head)
#endif



void yysemantics(node* head){    

  processImports(head);
  
  buildSymbolTables(head, NULL); //build the symbol tables

  //populate symbol tables. 
  populateSymbolTables(head, NULL); //class, package, variable declarations.
  
  //checkTypes(head, NULL);
  
  /////miscellaneous checks

  //treePrint
  debugOutput(head); //won't output unless we have "debug" turned on.
}

void processImports(node* head){
  if(head != NULL){
    int n = head->nchildren;      
    int i;
    
    
    for(i = 0; i < n; i++){
      if(head->children[i] != NULL){
	if(head->children[i]->label == importStatement){
	  //yyrestart();
	  char* importedFile = resolveName(head->children[i]->children[0],NULL);
	  //printf("This is the file I am opening %s", importedFile);
	  FILENAME = importedFile;
	  LINENO = 1;
	  
	  //printf("imported file %s\n", importedFile); 
	  
	  yyin = fopen(importedFile, "r");
	  if(yyin == NULL){
	    //printf("Couldn't open file!\n");
	  }
	  else {
	    //printf("Opened file just fine\n");
	    yyparse();
	    LINENO = 1;
	    head->children[i] = currenthead;
	    //fclose(yyin); //does yyparse set it to null? I have no idea!
	  }
	  //import will always have a variable name
	  
	  //now the tree is cut. oh well.
	}
      }
    }
    
    for(i = 0; i < n; i++){      
      if(head->children[i] != NULL && head->children[i] != currenthead){
	processImports(head->children[i]);
      }
    }
    
    
  }  
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
    
    
    //do work
    switch(head->label){
    case functionCall:
      {
	if( findIdent(head->table,head->children[0]->contents ) ){
	  //  node* temp = getSymbolNode(head->table, head->children[0]->contents);
	  //printf("%d", checkArgList());
	  
	}
	else {
	  //printError("Use of an undeclared function", head);
	}
	break;
      }

    
    case forStatement:
      //make sure everything is a number, int, uint, or float.
      break;      


    case variableName:
      {
	break;
      }

    case variableBinding:
      
      break;

    case assignStatement:
      break;

    case expr:
      
      break;

    default:
      break;
    }

    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	checkTypes(head->children[i], NULL);
      }
    }

  }  
}


char* getOptionalNodeType( node* var ){
  if( var != NULL){
    if( var->label == optionalVariableType ){
      if( var->children[0]->label == IDENT )
	return strdup( var->children[0]->contents );
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
    int z;
    int j;
    for( i; i < n; i++ ){
      if(head->children[i] != NULL){
	
	
	if(head->children[i]->label == IDENT){
	  if( !findIdentLocally( head->children[i]->table, head->children[i]->contents ) )
	    {
	      addSymbol( head->children[i]->table, 
			 head->children[i]->contents, 2, head->children[i], NULL );
	      //set up the target scope
	      j = i + 1;
	      head->children[i]->targetScope = head->children[j]->targetScope;
	      
	      z = i;
	      break;
	    }
	  else 
	    printError( "Redeclaration of function definition", head->children[i] );	
	}
      }
    }
    
    //we need to grab the functionHeader!
    node* iterator = head->children[j];
    
    
    //now step through the functionHeader node and find the arg list
    for( i=0; i < head->children[j]->nchildren; i++ ){
      //printf("\n\nLabel %d \n\n", head->children[i]->label);      
      if(iterator->children[i] != NULL){
	if(iterator->children[i]->label == variableDeclarationList ||
	   iterator->children[i]->label == variableBinding){
	  head->children[z]->args = functionArgumentHandler(NULL, iterator->children[i]);
	  head->children[z]->numArgs = getNumArgsFromDeclarationList(iterator->children[i],0);
	  printf("%d\n",head->children[z]->numArgs);
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

/* HELPERS */
list* functionArgumentHandler(list* front, struct node* head){
  switch(head->label){
  case variableDeclarationList:
    {
      //non-base case. attach the child and recurse
      if(front == NULL){//uh oh! we need to make a new list!
	list* lst = newListItem();
	lst->content = strdup(head->children[0]->nodeType);
	return functionArgumentHandler(lst, head->children[1]);
      }
      else {
	genericAdd(front, strdup(head->children[0]->nodeType));
	return functionArgumentHandler(front, head->children[1]);
      }
    }
    break;

  case variableBinding:
    {
      //base case. attach myself and return
      if(front == NULL){ //uh oh! we need to make a new list!
	list* lst = newListItem();
	lst->content = strdup(head->nodeType);
	return lst;
      }
      else {
	genericAdd(front, strdup(head->nodeType));
	return front;
      }
    }
    break;
    
  default:
    //here in case of panic
    return front;
    break;
  }
  
}

char* resolveName(node* head, char* str){
  switch(head->label){
  case variableName:
    {
      //concat an recurse
      if(str == NULL){
	str = (char*)malloc(100*sizeof(char));
	strcpy(str,head->children[0]->contents);
	strcat(str, "/");
      }
      else {
	char* current = (char*)malloc(100*sizeof(char));
	current = strcpy(current,str);
	current = strcat(current, head->children[0]->contents);
	current = strcat(current, "/");
	free(str);
	str = current;
      }
      
      return resolveName(head->children[1], str);
      break;
    }
    
  case IDENT:
    {
      //concat and return
      if(str == NULL){
	str = (char*)malloc(100*sizeof(char));
	strcpy(str,head->contents);
	strcat(str, ".as");
	printf("%s\n", str);
	//str = strdup(head->contents);
      }
      else {
	char* current = (char*)malloc(100*sizeof(char));
	current = strcpy(current,str);
	strcat(current, head->contents);
	strcat(current, ".as");
	free(str);
	str = current;
      }
      
      return str;
      break;
    }
    
  default: 
    break;
  }
  //absolute failure 
  return NULL;
}

int compareTypes(node* first, node* second){
  if( first != NULL && second != NULL ){
    
    if( compareStrings( first->nodeType, "void"))
      return 1;
    
    if( compareStrings( first->nodeType, "number" ) ||
	compareStrings( first->nodeType, "uint" ) ||
	compareStrings( first->nodeType, "int" ) ){
      if( compareStrings( second->nodeType, "number" ) ||
	  compareStrings( second->nodeType, "uint" ) ||
	  compareStrings( second->nodeType, "int" ) ){
	return 1;
      }
      return 0;
    }
    
    if( !compareStrings( first->nodeType, second->nodeType ) ){
      return 0;
    }
    
    return 1;
  }
  printError("Ident doesn't exist.", first);
  
  return 0;
}

int compareTypeStrings(char* first, char* second){
  
  if( first != NULL && second != NULL ){
    
    if( compareStrings( first, "void"))
      return 1;
    
    if( compareStrings( first, "number" ) ||
	compareStrings( first, "uint" ) ||
	compareStrings( first, "int" ) ){
      if( compareStrings( second, "number" ) ||
	  compareStrings( second, "uint" ) ||
	  compareStrings( second, "int" ) ){
	return 1;
      }
      return 0;
    }
    
    if( !compareStrings( first, second ) ){
      return 0;
    }
    
    return 1;
  }  
  return 0;
}

/*
node* getVariableNode(node* head,char* symbol){
  if(head != NULL){
    switch(head->label){
      
      

      
    }
  }
  }*/

node* getVariableNode( symbolTable* scope, node* head ){
  printf("In getVariableNode\n");
  
  if(scope != NULL && head != NULL){
    printf("scope != NULL and head != NULL\n");
    printf("%d\n", head->label);
    switch(head->label){
    case IDENT:
      {
	printf("What the hell?\n");
	printf("In IDENT\n");
	if( findIdent(scope, head->contents) ){
	  printf("Getting ready to return!\n");
	  node* tempNodeForReturning = getSymbolNode( scope, head->contents);
	  return tempNodeForReturning;
	}
	else {
	  printf("God damnit!\n");
	  printError("Use of an undeclared variable.", head);
	  break;
	}
      }
    case variableName:
      {
	printf("Go in here somehow\n");
	if(head->children[0]->label == IDENT){
	  //if I can find the class or package
	  if( findIdent( head->children[0]->table, head->children[0]->contents ) ){
	    
	    //then we need to get that class or package's scope.
	    //with the correct scope, we can then recursively call this function
	    //make a temporary node. use this temp node to grab the scope.
	    node* tempNodeForScoping = getSymbolNode( head->table, head->children[0]->contents );
	    
	    //with the new scope, go ahead and recursively call
	    printf("I'm looking at %s. Recursively calling.\n", head->children[0]->contents);
	    return getVariableNode(tempNodeForScoping->table, head->children[1]);
	  }
	  printError("Class or Package Instance does not Exist", head->children[0]);
	}
      }

    default:
      //just in case everything is broken
      return NULL;
      break;
    }
  }
  printf("Table or Head = NULL!\n");
  return NULL;
}
  
  
node* getVariable( symbolTable* scope, node* var ){
  if( var->label == IDENT ){
    //printf("%s\n", var->nodeType);
    if( findIdent( scope, var->contents ) ){
      //printf("%s\n", var->contents);
      return getSymbolNode( scope, var->contents );
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
      if( findIdent( var->children[0]->table, var->children[0]->contents ) ){
	//printf( "Variable Exists %s\n", var->children[0]->contents );
	node* tempClassNode = getSymbolNode( var->children[0]->table, var->children[0]->contents );
	//	printTable( tempClassNode->table, 0 );
	node* temp;
	if( findIdent( tempClassNode->table, tempClassNode->nodeType ) ){
	  node* temp = getSymbolNode( tempClassNode->table, tempClassNode->nodeType );
	  if( temp->tok == NULL ){
	    printError( "Unexpected Error", var );
	    return var;
	  }
	  
	  if( findIdent( scope, temp->contents ) ){
	    //printf("I found the type %s\n", temp->contents);
	    
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
  

int checkArgList(node* head, list* front){
  switch(head->label){
  case valueList:
    {
      if( !compareTypeStrings(head->children[0]->nodeType, front->content) )
	printError("Type mismatch in argument list", head->children[0]);
      if(front->next != NULL){
	return checkArgList(head->children[1], front->next);
      }
      printError("Too many arguments\n",head->children[1]);
      break;
    }
    
  default:
    //here in case of panic
    //check type
    {
      printf("%d", head->label);
      if( !compareTypeStrings(head->nodeType, front->content) )
	printError("Type mismatch in argument list", head);
      
    
      return 1;
      break;
    }
  }
}

int getNumArgs(node* head, int num){
  switch(head->label){
  case valueList:
    {
      num++;
      return getNumArgs(head->children[1],num);
    }
    break;
  default:
    {
      num++;
      return num;
    }
  }
}


int getNumArgsFromDeclarationList(node* head, int num){
  switch(head->label){
  case variableDeclarationList:
    {
      num++;
      return getNumArgsFromDeclarationList(head->children[1],num);
    }
    break;
  default:
    {
      num++;
      return num;
    }
  }
}
