#include "structures.h"

extern token* YYTOKEN;

void addToList(token_item* head, token* new){
  token_item* iterator = head;
  while(iterator->next != 0){
    iterator = iterator->next;
  }
  
  token_item* new_one = (token_item*)malloc(sizeof(token_item));

  iterator->next = new_one;
  
  new_one->t = new;
  //mallocing of new object is handled inside the main
}


void addYYTokenToList(token_item* head){
  token_item* iterator = head;
  while(iterator->next != 0){
    iterator = iterator->next;
  }
  //printf("%d ", YYTOKEN->category);
  token_item* new_one = (token_item*)malloc(sizeof(token_item));
  new_one->t = YYDup();
  new_one->next = 0;
  //printf("%d", new_one->t->category);
  
  iterator->next = new_one;
}

void printList(token_item* head){
  token_item* iterator = head;
  
  printf("Entering PrintList");

  while(iterator->next != 0){
    printf("%d ", iterator->t->category);
    iterator = iterator->next;
  }
  //intf("%d\n", iterator->t->category);  
}

token* YYDup(){
  token* new = (token*)malloc(sizeof(token));
  new->category = YYTOKEN->category;
  return new;
}

void addCategoryToYYToken(int category){
  YYTOKEN->category = category;
}
