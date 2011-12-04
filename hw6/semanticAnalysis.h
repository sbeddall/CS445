#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "structures.h"
#include "enums.h"
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void yysemantics(struct node* head);
void buildSymbolTables(struct node* head, struct node* parent_node);
void compressTree(struct node* head);
void checkTypes(struct node* head);
char* getOptionalNodeType(struct node* var);



#endif
