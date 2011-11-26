/*
  Author: Scott Beddall
  CS445 - Assignment 4
  To be honest, I need to tear this apart and write it from scratch;
  scrapping upwards of 40 hours of work. Function headers are not
  yet implemented, nor are imports.
  Class instantiation and variable access is g2g according to my test files.
  I've eliminated as many of the segfault situations as I can in the current timeframe,
  unfortunately I probably missed one somewhere.
  printError resides in structures.c. I'm not reprinting that as it would be
  only that one change. So, printError is prototyped right below.

void printError(char* errorText, struct node* head){
  /*
  if( head->tok != NULL) printf("%s: %s\n", errorText, head->tok->text);
  printf("\tNode label: %d\n", head->label);
  if( head->tok != NULL) printf("\tLine Number: %d\n", head->tok->lineno);
  printf("\tSymbol Table: %p\n\n", head->table); 
  */

  //status update as per assignment
  status = -3;
}

 */

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "symbolTable.h"
#include "tree.h"

int status;

int LINENO;
char* FILENAME;
token* YYTOKEN;
extern FILE* yyin;
int failed;
symbolTable* global_table;
node* head;

main(int argc, char* argv[]){
  failed = 0;
  LINENO = 1;
  YYTOKEN = (token*)malloc(sizeof(token));
  global_table = makeTable(NULL);
  status = 0;

 
  int successful = 0;
  int total = 0;
  int i = 1;
  for(i; i < argc; i++){
    FILENAME = argv[i];
    yyin = fopen(argv[i], "r");
    if(yyin != 0){
      total++;
      yyparse(); 
      //      printf("Global Symbol Table: %p\n", global_table); 
      yysemantics(head);   
      
    }
    fclose(yyin);
    LINENO = 1;
    FILENAME = argv[i];
  }

      
  
  return status;
}
