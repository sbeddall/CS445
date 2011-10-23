#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>
#include "symboltable.h"

typedef struct node {
  int nchildren; 
  int label;
  token* tok;
  symbol_table *parent;
  struct node** children;
} node;

//  symbol_table* parent;
//node* makeNode(char* text,symbol_table* parent, token* tok, int nchildren, ...);
node* makeNode(int label, symbol_table* parent,  token* tok, int nchildren, ...);
void yysemantics(node* head);
void buildSymbolTables(node* head, node* parent_node);
void traverseTree(node* head,node* parent_node, int level);
void verboseTraverseTree(node* head, int level);

#endif
