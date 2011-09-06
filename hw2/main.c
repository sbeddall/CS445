#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int LINENO;
char* FILENAME;
token* YYTOKEN;
extern FILE* yyin;

main(int argc, char* argv[]){

  LINENO = 0;
  YYTOKEN = (token*)malloc(sizeof(token));
  
  token_item* head = (token_item*)malloc(sizeof(token_item));
  head->t = 0;
  head->next = 0;
  
  token* populizer = (token*)malloc(sizeof(token));  
  populizer->category = -1;
  populizer->text = "start";
  populizer->lineno = 0;
  head->t = populizer; 
  //addYYTokenToList(head);

  int i = 1;
  for(i; i < argc; i++){
    FILENAME = argv[i];
    yyin = fopen(argv[i], "r");
    int result = 1;
    while(result != 0){
      result = yylex();
      addYYTokenToList(head);
    }  
    fclose(yyin);
    LINENO = 0;
    FILENAME = argv[i];
  }
  
  printYYList(head);
      
  
  return 0;
}
