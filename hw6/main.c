/*
  Author: Scott Beddall
  CS445 - Assignment 5
 */

 
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "symbolTable.h"
#include "tree.h"
#include "codeGen.h"
#include "semanticAnalysis.h"

int status;

int LINENO;
char* FILENAME;
token* YYTOKEN;
extern FILE* yyin;
int failed;
symbolTable* global_table;
node* currenthead;
int NUMVARIABLES;
int NUMLABELS;
node* globalhead;

main(int argc, char* argv[]){
  failed = 0;
  LINENO = 1;
  YYTOKEN = (token*)malloc(sizeof(token));
  global_table = makeTable(NULL);
  status = 0;
  NUMVARIABLES = 0;
  NUMLABELS = 0;
  globalhead = NULL;
  currenthead = NULL;
  
  int successful = 0;
  int total = 0;
  int i = 1;
  for(i; i < argc; i++){
    FILENAME = argv[i];
    yyin = fopen(argv[i], "r");
    if(yyin != 0){
      total++;
      yyparse();       //printf("Global Symbol Table: %p\n", global_table); 
      if(status == 0){
	yysemantics(globalhead);   
      }
      else {
	printf("Error in parser, abandoning semantic analysis\n");
      }
      if(status == 0){
	yycodegen(globalhead);
      }
      else printf("Error in parser or semantic, abandoning codeGen\n");
    }
    //fclose(yyin);
    LINENO = 1;
    yyrestart();
  }

      
  
  return status;
}
