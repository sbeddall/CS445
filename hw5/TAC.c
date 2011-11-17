#include "TAC.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//it's the TAC function roundup!
TAC* makeBlankTAC(){
  TAC* new = (TAC*)malloc(sizeof(TAC));
  
  int numEntries = 4;
  
  new->entries = (char**)malloc(sizeof(char*) * numEntries);
  
  int i = 0;
  
  for(i; i < numEntries; i++){
    new->entries[i] = NULL;
  }
  
  return new;
}

//PASS THIS NUMENTRIES as the number of arguments!
TAC* makeTAC(char* arg1, char* arg2, char* arg3){
  TAC* new = makeBlankTAC();

  if(arg1 != NULL){
    new->entries[1] = strdup(arg1);
  }
  if(arg2 != NULL){
    new->entries[2] = strdup(arg2);
  }
  if(arg3 != NULL){
    new->entries[3] = strdup(arg3);    
  }
  
  return new;
}


TAC* makeLabeledTAC(char* label, char* arg1, char* arg2, char* arg3){
  TAC* new = makeTAC(arg1, arg2, arg3);
  if(label != NULL){
    new->entries[0] = strdup(label);
  }
  
  return new;
}

void printTAC(TAC* line){
  if(line != NULL){
    int i = 0;
    for(i; i < 4; i++){
      
    }
  }
}