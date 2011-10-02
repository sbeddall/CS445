#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

node* makeNode(char* text, token* tok, int nchildren, ...){
  node* new = (node*) malloc(sizeof( node ));
  
  if(text != NULL) new->text = strdup(text);
  new->nchildren = nchildren;
  new->tok = tok;

  new->children = 0;
  if(nchildren > 0){
    new->children = (node**)malloc(sizeof(node*) * nchildren);
    
    int i;
    va_list va;
    
    va_start(va,nchildren);
    for(i = 0; i<nchildren; i++){
      new->children[i] = va_arg(va, node*);
    }
    va_end(va);
  }
  
  return new;
}

void traverseTree(node* head, int level){
  int n = head->nchildren;
  

  int j = 0;
  for(j; j < level; j++){
    printf(" ");
  }
  if(head->text != NULL){
    printf("%s", head->text);
    printf("\n");
  }
  int i;
  for(i = 0; i < n; i++){
    
    if(head->children[i]==NULL){
      //printf("Kid's NULL. \n");
    }
    else{
      traverseTree(head->children[i], level++);
    }
  }


}




