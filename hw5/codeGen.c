#include "codeGen.h"
#include <stdlib.h>
#include "symbolTable.h"
#include <stdio.h>
#include <string.h>

extern int NUMVARIABLES;

char* newLabel(){

  char* new = (char*)malloc(sizeof(char)*10);
  new[0] = '_';
  new[1] = '_';
  new[2] = 't';
  new[3] = '\0';
  
  char* integerToString = (char*)malloc(sizeof(char) * 10);
  
  itoa(NUMVARIABLES, integerToString);
  
  reverseString(integerToString);
  
  strcat(integerToString,"__");
  strcat(new,integerToString);

  NUMVARIABLES++;

  return new;
}

char* newVariable(symbolTable* parent){
  
  
  return NULL;
}

char* itoa(int val, char* buf){
  int new = (unsigned int)val;
  char* temp = buf;
  
  
  while(val > 0){
    
    new = val % 10;
    val /= 10;
    
    *temp++ = new + '0';
  }

  *temp++ = '\0';
  
  return NULL;
}

void reverseString(char* buf){
  char* temp1 = buf;
  char* temp2 = buf;
  
  while(*temp2 != '\0'){
    temp2++;
  }
  temp2--;
  char new;
  
  while(temp1 < temp2){
    new = *temp1;
    *temp1 = *temp2;
    *temp2 = new;
    
    temp1++;
    temp2--;
  }
}

/*
val 53
new 53%10 = 3
val 53/10 = 5
new 5%10 = 5
val 5/10 = 0
*/
