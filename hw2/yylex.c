%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "structures.h"
  int count = 0;
  
  extern token* yytoken;
%}
%option noyywrap

line .*\n

%%
{line} { 
  count++; 
  printf("%d\n", count);
  return 1;
}

%%
