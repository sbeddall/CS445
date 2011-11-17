#include <stdio.h>
#include <stdlib.h>
//#include "structures.h"
//#include "symboltable.h"
//#include "tree.h"
#include "codeGen.h"

//int LINENO;
//token* YYTOKEN;
//FILE* FILENAME;

int NUMVARIABLES;

int main(){
  NUMVARIABLES = 0;
  /*  list* head = (list*)malloc(sizeof(list));
  int* lol = (int*)malloc(sizeof(int));
  lol[0] = 2;
  head->content = lol;
  genericAdd(head, lol);
  genericAdd(head, lol);
  genericPrint(head);
  printf("Now inserting\n");
  int result = genericInsert(head, lol, 0);
  genericPrint(head);
  
  char* first = "hello";
  char* second = "hello";

  

  printf("%d\n", compareStrings(first, second));
  
  symbol_table* global = makeTable(NULL);
  
  int goddamnit = addSymbol(global, "hello", 0, NULL);
  
  */
  
  //  printTable(global);

  int i = 0;
  char* lol;
  
  for(i; i < 300; i++){
    lol = newLabel();
    printf("%s\n", lol);
  }
  
  

  return 0;
}
