/*
  Author: Scott Beddall
  CS445 - Assignment 6

  Semantic Analysis has been completley revamped.
  I'm actually happy with how it's going, but I don't have the time
  to figure it out completely. Senior Design took way more of my time 
  last week than it should have. My type system is set up and waiting, I just gotta
  get the cases implemented. 

  As for TAC I'm actually really happy. My expr and expression code is the result
  of a logical leap that I usually don't have the intellectual acumen for. With that
  being the case it's actually hard for me to be disappointed in the results. With 
  a couple more weeks in the semester this would end up being a really awesome project.

  Final code gen is, frankly, not even present. I've spent most of my energy on
  getting TAC to where I actually want it to be. 

  Cheers for an enlightening semester, 
  have a great ChristmaHanaKwanzika!

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
char* GLOBALFILENAME;

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
    GLOBALFILENAME = argv[i];
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
