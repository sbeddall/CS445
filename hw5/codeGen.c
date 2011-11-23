#include "codeGen.h"
#include <stdlib.h>
#include "symbolTable.h"
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "enums.h"
#include "yyparse.tab.h"

extern int NUMVARIABLES;
extern int NUMLABELS;

char* newLabel(){

  char* new = (char*)malloc(sizeof(char)*10);

  new[0] = 'L';
  new[1] = '_';
  new[2] = '\0';
  
  char* integerToString = (char*)malloc(sizeof(char) * 10);
  
  itoa(NUMLABELS, integerToString);
  
  reverseString(integerToString);
  
  strcat(new,integerToString);

  NUMLABELS++;

  return new;
}

//do I want to put the actual symbolTable functionality here?
char* newVariable(symbolTable* parent){
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


void populatePlaces(node* head){
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i]!=NULL){
	populatePlaces(head->children[i]);
      }
    }
    
    //do work
    switch(head->label){
    case whileStatement:
      //make new item
      
      //makelabel
      //code
      //endlabel
      break;
    default:
      head->code = concatenateChildren(head);
      break;
	
    }
  }
}


list* concatenateChildren(node* head){
  list* first = NULL;;
  if(head != NULL){
    int n = head->nchildren;
    int i = 0;
    for(i = 0; i < n; i++){      
      if(head->children[i] != NULL && head->children[i]->code != NULL){
	//make sure we aren't concatenating null stuff
	if(first == NULL){
	  first = head->children[i]->code;
	}
	else
	  concatenateList(first, head->children[i]->code);	
      }
    }
  }
  

  return first;
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
