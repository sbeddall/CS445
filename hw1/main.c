#include <stdio.h>
#include <string.h>

char yytext[1024];
FILE *yyin;

int main(int argc, char* argv[]){
  int identifier = 0;
  int i = 1;
  
  //grab each file in the command line
  for(i; i < argc; i++){
    identifier = 0;
    //printf("%s", argv[i]);
    yyin = fopen( argv[i], "r" );
    
    //check that it's a real file
    
    if(yyin == 0){
      printf("Could not open file");
      return (0);
    }
    
    

    //attend to each beautiful lexeme
    while(identifier != -1){
      identifier = yylex();
      printf("%d\t%s\n", identifier, yytext);
    }
    
    fclose( yyin );
  }
  
  return 0;
}
