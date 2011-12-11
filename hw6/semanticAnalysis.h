#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "structures.h"
#include "enums.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*Tree Manipulation*/
void yysemantics(struct node* head);
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


#endif
