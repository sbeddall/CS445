#include <stdio.h>
#include <stdlib.h>

extern int count;

main(int argc, char* argv[]){
  int result = 1;
  while(result != 0){
    result = yylex();
  }
  return 0;
}
