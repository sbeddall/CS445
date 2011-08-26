#include <stdio.h>

extern char yytext[];
extern FILE *yyin;

//discard spaces tabs and newlines
//ascii 32, 9, and 10 respectively
int yylex(){

  clearText(); //make sure our array of letters is clean
  
  int x = 0;
  int whitespace = 0;
  int i = 0;

  //enter the grabby loop
  while(whitespace == 0){
    
    x = fgetc( yyin ); //grab character
    
    if((char)x == EOF){
      return -1;
    }
    
    if(checkWhite( x ) == 1){
      if(i > 0) 
	whitespace++;//don't copy to yytext
      else 
	i--;
    }

    else {
      yytext[i] = (char)x; //we do copy to yytext
    }

    i++; //iterate our counter

  }
  return 1;
}

int parseIdentifier(){
  return 1;
}

int parseName(){
  return 2;
}

int parseNumber(){
  return 3;
}

int parsePunctuation(){
  return 4;
}

int parseMixture(){
  return 5;
}

//1 == whitespace. 0 == not whitespace
int checkWhite(int x){
  return (x == 9 || x == 32 || x == 10 || x == 13 || x == 11) ? 1 : 0;
}

void clearText(){
  int i = 0;
  for(i; i < 1024; i++){
    yytext[i] = '\0';
  }
}
