#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>
#include "symbolTable.h"


typedef struct node {
  int nchildren; 
  int label;
  int baseType;
  token* tok;
  symbolTable* table;
  struct node** children;
} node;

//  symbolTable* parent;
//node* makeNode(char* text,symbolTable* parent, token* tok, int nchildren, ...);
node* makeNode(int label, symbolTable* parent,  token* tok, int nchildren, ...);
void yysemantics(node* head);
void populateSymbolTables(node* head, node* parent_node);
void buildSymbolTables(node* head, node* parent_node);
void variableHandler(node* var, node* parent_node);
void traverseTree(node* head,node* parent_node, int level);
void checkIdentsInInitialization(node* head);
node* miniTraverse( node* head, int label );

#endif
