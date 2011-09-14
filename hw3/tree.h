#ifndef TREE_H
#define TREE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct easylist {
  struct treenode* content;
  struct easylist* next;
} list;

typedef struct treenode {
  short nchildren; 
  short label;
  struct easylist* children;
} tree;

tree* makeNode(short label);

#endif
