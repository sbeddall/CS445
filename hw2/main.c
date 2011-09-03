#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

extern int count;

token* yytoken;

main(int argc, char* argv[]){
  
  token_item* head = (token_item*)malloc(sizeof(token_item));

  token* list_type;  
  list_type = (token*)malloc(sizeof(token)); 
  list_type->category = 101;
  
  token* hello;
  hello = (token*)malloc(sizeof(token));
  hello->category = 100;

  head->t = list_type;
  
  addToList(head, hello);
  printList(head);
  
  int result = 1;
  while(result != 0){
    result = yylex();
  }
  return 0;
}
