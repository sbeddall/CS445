#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

extern int count;

token* YYTOKEN;

main(int argc, char* argv[]){
  YYTOKEN = (token*)malloc(sizeof(token));
  token_item* head = (token_item*)malloc(sizeof(token_item));

  int result = 1;
  while(result != 0){
    result = yylex();
    YYTOKEN->category = result;
    addYYTokenToList(head);
  }

  token_item* iterator = head;
  
  printList(head);

  return 0;
}
