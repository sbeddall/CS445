#include "TAC.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"




//it's the TAC function roundup!
TAC* makeBlankTAC(){
  TAC* new = (TAC*)malloc(sizeof(TAC));
  
  int numEntries = 5;
  
  new->entries = (char**)malloc(sizeof(char*) * numEntries);
  
  int i = 0;
  
  for(i; i < numEntries; i++){
    new->entries[i] = NULL;
  }
  
  return new;
}

//PASS THIS NUMENTRIES as the number of arguments!
TAC* makeTAC(char* cmd,char* arg1, char* arg2, char* arg3){
  TAC* new = makeBlankTAC();
  int i = 0;

  if(cmd != NULL){
    new->entries[1] = strdup(cmd);
  }
  if(arg1 != NULL){
    new->entries[2] = strdup(arg1);
  }
  if(arg2 != NULL){
    new->entries[3] = strdup(arg2);
  }
  if(arg3 != NULL){
    new->entries[4] = strdup(arg3);    
  }
  
  return new;
}


TAC* makeLabeledTAC(char* label, char* cmd, char* arg1, char* arg2, char* arg3){
  TAC* new = makeTAC(cmd, arg1, arg2, arg3);
  if(label != NULL){
    new->entries[0] = strdup(label);
  }
  
  return new;
}

void printTAC(TAC* line){
  if(line != NULL){
    int i = 0;
    printf("|");
    for(i; i < 5; i++){
      if(line->entries[i] != NULL){
	printf(" %s|",line->entries[i]);
      }
      else printf(" -- |");
    }
    printf("\n");
  }
  else {
    printf("Nothing Here");
  }
}


void printTACList(list* head){
  list* iterator = head;
  
  if(iterator != NULL){
    while(iterator->next != NULL){
      if(iterator->content != NULL){
	printTAC(iterator->content);
      }
      
      iterator = iterator->next;
    }
    printTAC(iterator->content);
  }
}

list* newListItem(){
  list* new = (list*)malloc(sizeof(list));
  new->content = NULL;
  new->next = NULL;
  return new;
}
