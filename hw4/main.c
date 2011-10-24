#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "symbolTable.h"
#include "tree.h"

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
  

 
  int successful = 0;
  int total = 0;
  int i = 1;
  for(i; i < argc; i++){
    FILENAME = argv[i];
    yyin = fopen(argv[i], "r");
    if(yyin != 0){
      total++;
      yyparse(); 
      printf("Global Symbol Table: %p\n", global_table); 
      yysemantics(head);   
    }
    fclose(yyin);
    LINENO = 1;
    FILENAME = argv[i];
  }

      
  
  return 0;
}
