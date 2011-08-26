#include <stdio.h>
#include <string.h>

char yytext[1024];
FILE *yyin;

int main(int argc, char* argv[]){
  int identifier = 0;
  int i = 1;
  
  for(i; i < argc; i++){
    yyin = fopen( argv[i], "r" );
    
 
    if(yyin == 0){
      printf("Could not open file");
      return (0);
    }
    
    while(identifier != -1){
      identifier = yylex();
      printf("%d\t%s\n", identifier, yytext);
    }
    
    fclose( yyin );
  }
  
  return 0;
}
