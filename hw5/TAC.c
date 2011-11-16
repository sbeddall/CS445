#include "TAC.h"

TAC* makeBlankTAC(){
  TAC* new = (TAC*)malloc(sizeof(TAC));
  
  int numEntries = NUMENTRIES;
  
  new->entries = (char**)malloc(sizeof(char*) * numEntries);
  
  return new;
}
