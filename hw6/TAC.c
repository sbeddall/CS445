#include "TAC.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "enums.h"
extern char* FILENAME;



//it's the TAC function roundup!
TAC* makeBlankTAC(){
  TAC* new = (TAC*)malloc(sizeof(TAC));
  
  int numEntries = 4;

  new->entries = (char**)malloc(sizeof(char*) * numEntries);
  new->cmd = 0;

  int i = 0;
  
  for(i; i < numEntries; i++){
    new->entries[i] = NULL;
  }
  
  return new;
}

//PASS THIS NUMENTRIES as the number of arguments!
TAC* makeTAC(int cmd,char* arg1, char* arg2, char* arg3){
  TAC* new = makeBlankTAC();
  int i = 0;

  new->cmd = cmd;
  
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


TAC* makeLabeledTAC(char* label, int cmd, char* arg1, char* arg2, char* arg3){
  TAC* new = makeTAC(cmd, arg1, arg2, arg3);
  if(label != NULL){
    new->entries[0] = strdup(label);
  }
  
  return new;
}

void printTAC(TAC* line){
  if(line != NULL){
    int i = 1;
    printf("|");
    //label
    if(line->entries[0] != NULL){
      printf("%-9s|",line->entries[0]);
    }
    else{ 
      printf("%-10s","--");
      printf("|");
    }

    //cmd op
    printf("%-9s", translateOpCode(line->cmd));
    
    //rest of the arguments
    for(i; i < 4; i++){
      if(line->entries[i] != NULL){
	printf("%-9s|",line->entries[i]);
      }
      else{ 
	printf("%-10s","--");
	printf("|");
      }
    }
    printf("\n");
  }
  else {
    printf("Nothing Here");
  }
}


void printTACToFile(TAC* line, FILE* file){
  if(line != NULL){
    int i = 0;
    fprintf(file,"|");
    for(i; i < 5; i++){
      if(line->entries[i] != NULL){
	fprintf(file,"%-10s|",line->entries[i]);
      }
      else{ 
	fprintf(file,"%-9s","--");
	fprintf(file,"|");
      }
    }
    fprintf(file,"\n");
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

void printTACListToFile(list* head){
  char* filename = getFileName();
  FILE* file = fopen(filename, "w+");
  list* iterator = head;
   
  if(iterator != NULL){
    while(iterator->next != NULL){
      if(iterator->content != NULL){
	printTACToFile(iterator->content, file);
      }
      
      iterator = iterator->next;
    }
    printTACToFile(iterator->content, file);
  }
  
  fclose(file);

}

char* translateOpCode(int code){
  char* new = (char*)malloc(sizeof(char)*10);
  
  
  switch(code){
  case ASN:
    return strdup("ASN");
    break;
  case ADD:
    return strdup("ADD");
    break;
  case SUB:
    return strdup("SUB");
    break;
  case MUL:
    return strdup("MUL");
    break;
  case DIV:
    return strdup("DIV");
    break; 
  case MOD:
    return strdup("MOD");
    break;
  case NEG:
    return strdup("NEG");
    break;
  case ADDR:
    return strdup("ADDR");
    break;
  case LCONT:
    return strdup("LCONT");
    break;
  case SCONT:
    return strdup("SCONT");
    break;
  case GOTO:
    return strdup("GOTO");
    break;
  case BLESS:
    return strdup("BLESS");
    break;
  case BIF:
    return strdup("BIF");
    break;
  case BNIF:
    return strdup("BNIF");
    break;
  case PARM:
    return strdup("PARM");
    break;
  case CALL:
    return strdup("CALL");
    break;
  case RET:
    return strdup("RET");
    break;
  case proc:
    return strdup("PROC");
    break;
  case class:
    return strdup("CLASS");
    break;
  case package:
    return strdup("PACKAGE");
    break;
  case end:
    return strdup("END");
    break;
  case begin:
    return strdup("BEGIN");
    break;      
  default:
    strcpy(new, "wut"); //in the case of disaster
    break;

  }
  return new;
}
