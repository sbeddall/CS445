#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>

typedef struct node {
  int nchildren; 
  char* text;
  token* tok;
  struct node** children;
} node;

node* newNode(char* text, token* tok, int nchildren, ...);
void traverseTree(node* head, int level);
void verboseTraverseTree(node* head, int level);

#endif
