%{
  #include <stdio.h>
  #include <stdlib.h>
  int count = 0;
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
