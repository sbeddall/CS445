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

  //enter the loop to get a lexeme
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
  
  //printf("Passing %d to parseFirst ", x);
  //parse the lexeme
  switch( parseSingle( yytext[0] ) ){
  case 1:
    return parseIdentifier();
  case 2:
    return parseName();
  case 3:
    return parseNumber();
  case 4:
    return parsePunctuation();
  case 5: 
    return parseMixture();
  default:
    return 0;
  }
}

int parseIdentifier(){
  char* iterator = yytext;
  
  while(*iterator != '\0'){
    // printf("%c\n", *iterator);
    if( parseSingle( *iterator ) != 1 ) return 5;
    iterator++;
  }
  return 1;
}

int parseName(){
  char* iterator = yytext;
  
  while(*iterator != '\0'){
    // printf("%c\n", *iterator);
    if( parseSingle( *iterator ) != 1 || parseSingle( *iterator ) != 2) return 5;
    iterator++;
  }

  return 2;
}

int parseNumber(){
  char* iterator = yytext;
  while(*iterator != '\0'){
    if( parseSingle( *iterator ) != 3 ) return 5;
    iterator++;
  }
  return 3;
}

int parsePunctuation(){
  if(yytext[1] == '\0')
    return 4;
  else return parseMixture();
}

int parseMixture(){
  return 5;
}

int parseSingle(int x){
  //identifier 97-122
  //name 65-90
  //digit 48-57 - = 45 . = 46 
  //punctuation 33-47 58-64 91-96 123-126
  //mixture
  //printf("Looking at %d", x);
  if(x >= 97 && x <= 122){
    return 1;
  }
  else if(x >= 65 && x <= 90){
    return 2;
  }
  else if((x >= 48 && x <= 57) || x == 45 || x == 46){
    return 3;
  }
  else if((x >= 33 && x <= 47) || (x >= 58 && x <= 64) || (x >= 91 && x <= 96) || (x >= 123 && x <= 126)){
    return 4;
  } 
  
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
