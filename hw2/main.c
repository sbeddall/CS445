#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

extern int count;

token* YYTOKEN;

main(int argc, char* argv[]){
  YYTOKEN = (token*)malloc(sizeof(token));
  token_item* head = (token_item*)malloc(sizeof(token_item));
  head->t = 0;
  head->next = 0;
  
  token_item* head1 = (token_item*)malloc(sizeof(token_item));
  token_item* head2 = (token_item*)malloc(sizeof(token_item));
  
  token* populizer = (token*)malloc(sizeof(token));
  
  populizer->category = 0;
  head->t = populizer;
  YYTOKEN->category = 1;
  
  //addToList(head, lol);
  //addToList(head, lol1);

  //printf("%d\n", head->t->category);
  addYYTokenToList(head);


  printList(head);
  
  //int result = 1;
  /*while(result != 0){
    result = yylex();
    addYYTokenToList(head);
  }
  */
  //token_item* iterator = head;
  
  //  while(iterator->next != 0){
  // printf("%d\n", iterator->t->category);
  //  iterator = iterator->next;
  // }  

  //printList(head);

  return 0;
}
