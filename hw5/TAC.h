#ifndef THREE_ADDRESS_CODE
#define THREE_ADDRESS_CODE
#include "structures.h"


/***********TAC*************************
* char* | char* | char* | char* | char * 
* LABEL | cmd   | arg1  | arg2  | arg3 *
***************************************/


typedef struct TAC {
  char** entries;
  //field** places;
} TAC;



TAC* makeBlankTAC();
TAC* makeTAC(char* cmd, char* arg1, char* arg2, char* arg3);
TAC* makeLabeledTAC(char* label, char* cmd, char* arg1, char* arg2, char* arg3);
void printTAC(TAC* line);
void printTACList(list* head);

#endif 
