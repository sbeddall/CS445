#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>
#include "symboltable.h"

typedef struct node {
  int nchildren; 
  char* text;
  token* tok;
  symbol_table* parent;
  struct node** children;
} node;

node* makeNode(char* text,symbol_table* parent, token* tok, int nchildren, ...);
void traverseTree(node* head, node* parent, int level);
void verboseTraverseTree(node* head, int level);

#endif
