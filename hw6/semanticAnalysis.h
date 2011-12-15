#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "structures.h"
#include "enums.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*Tree Manipulation*/
void yysemantics(struct node* head);
void processImports(struct node* head);
void buildSymbolTables(struct node* head, struct node* parent_node);
void compressTree(struct node* head);
void populateSymbolTables(struct node* head, struct node* parent_node);

/*Type Stuff*/
void checkTypes(struct node* head, struct node* parent);
char* getOptionalNodeType(struct node* var);

/*HANDLERS*/
void variableHandler(struct node* head); 
void functionHandler(struct node* head);  
void classHandler(struct node* head);  
void packageHandler(struct node* head);  

/*HELPERS*/
list* functionArgumentHandler(list* front, struct node* head);
char* resolveName(struct node* head, char* str);
int compareTypes(struct node* first, struct node* second);
int compareTypeStrings(char* first, char* second);
struct node* getVariableNode( struct symbolTable* scope, struct node* head );
struct node* getVariable( struct symbolTable* scope, struct node* var );
int createArgList(struct node* head, list* front);
int getNumArgs(struct node* head, int num);
int getNumArgsFromDeclarationList(struct node* head, int num);

#endif
