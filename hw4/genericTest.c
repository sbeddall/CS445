#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int LINENO;
token* YYTOKEN;
FILE* FILENAME;

int main(){
  list* head = (list*)malloc(sizeof(list));
  int* lol = (int*)malloc(sizeof(int));
  lol[0] = 2;
  
  head->content = lol;
  
  genericAdd(head, lol);
  genericAdd(head, lol);
  
  

  genericPrint(head);
  
  printf("Now inserting\n");

  int result = genericInsert(head, lol, 0);

  genericPrint(head);
  
  return 0;
}
