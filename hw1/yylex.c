#include <stdio.h>

extern char yytext[];
extern FILE *yyin;

//discard spaces tabs and newlines
//ascii 32, 9, and 10 respectively
int yylex(){
  int x;
  
  //get first character. check for whitespace
  x = fgetc( yyin );
  
  

  printf("%d\n", x);

  yytext[0] = (char)x;
  
  
  
  return -1;
}

int parseIdentifier(){
  return -1;
}

