#include <stdio.h>

extern char yytext[];
extern FILE *yyin;

yylex(){
  yytext[0] = 'a'; 
  printf("%s\n", yytext);
}
