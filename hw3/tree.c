#include "tree.h"

tree* makeNode(short label){
  tree* new = (tree*) malloc(sizeof( tree ));
  
  new->label = label;
  new->nchildren = 0;
  
  new->children = NULL;
  
  return new;
}


