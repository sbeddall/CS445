#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include <stdarg.h>

typedef struct list {
  struct node* content;
  struct list* next;
} list;

typedef struct node {
  int nchildren; 
  int rule;
  token* tok;
  struct node** children;
} node;

node* newNode(int rule, token* tok, int nchildren, ...);

#endif
