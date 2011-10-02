#include "tree.h"

node* makeNode(int label, token* tok, int nchildren, ...){
  node* new = (node*) malloc(sizeof( node ));
  
  new->rule = label;
  new->nchildren = nchildren;
  new->tok = tok;

  new->children = (node**)malloc(sizeof(node*) * nchildren);
  
  return new;
}




