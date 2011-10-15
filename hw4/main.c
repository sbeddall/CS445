#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "symboltable.h"

int LINENO;
char* FILENAME;
token* YYTOKEN;
extern FILE* yyin;
int failed;
symbol_table* global_table;

main(int argc, char* argv[]){
  failed = 0;
  LINENO = 1;
  YYTOKEN = (token*)malloc(sizeof(token));
  global_table = makeTable(NULL);
  
  //  token_item* head = (token_item*)malloc(sizeof(token_item));
  //head->t = 0;
  //head->next = 0;
  
  //token* populizer = (token*)malloc(sizeof(token));  
  //populizer->category = -1;
  //populizer->text = "start";
  // populizer->lineno = 0;
  //populizer->ival = 0;
  //populizer->sval = "start";
  
  //  head->t = populizer; 
  //addYYTokenToList(head);
  int successful = 0;
  int total = 0;
  int i = 1;
  for(i; i < argc; i++){
    FILENAME = argv[i];
    yyin = fopen(argv[i], "r");
    if(yyin != 0){
      total++;
    //int result = 1;
    //while(result != 0){
      //result = yylex();
      //addYYTokenToList(head);
    //}
      yyparse(); 
    }
    fclose(yyin);
    LINENO = 1;
    FILENAME = argv[i];
  }

  //  double percent = ((double)(total-failed)/(double)total);
  //printf("Parsed %f of the tests successfully.\n", percent);
  //printf("Total Passed: %d, Total Failed: %d\n",total-failed, failed);
  
  //printYYList(head);
      
  
  return 0;
}
