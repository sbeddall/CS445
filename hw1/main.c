#include <stdio.h>
#include <string.h>

char yytext[1024];
FILE *yyin;

int main(int argc, char* argv[]){
  strcpy(yytext, "damn!");
  
  yylex();
  return 0;
}
