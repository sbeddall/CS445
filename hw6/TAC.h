#ifndef THREE_ADDRESS_CODE
#define THREE_ADDRESS_CODE
#include "structures.h"


/***********TAC*************************
* int | char* | char* | char* | char   * 
* cmd | LABEL | arg1  | arg2  | arg3   *
***************************************/

typedef struct TAC {
  char** entries;
  int cmd;
  //field** places;
} TAC;

TAC* makeBlankTAC();
TAC* makeTAC(int cmd, char* arg1, char* arg2, char* arg3);
TAC* makeLabeledTAC(char* label, int cmd, char* arg1, char* arg2, char* arg3);
void labelExistingTAC(char* label, TAC* existing);
void printTAC(TAC* line);
void printTACList(list* head);
void printTACListToFile(list* head);
void printTACToFile(TAC* line, FILE* file);
char* translateOpCode(int code);

#endif 
