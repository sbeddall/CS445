#ifndef SYMBOLTABLE
#define SYMBOLTABLE
#include "dataPacks.h"

/*struct c_type {
  int base_type;    // 1 = int, 2=float, ... 
  union {
    struct array {
      int size;
      struct c_type *elemtype;
    } a;
    struct ctype *p;
    struct struc {
      char *label;
      struct field **f;
    } s;
  } u;
}
*/ 



typedef struct field {
  char *name;
  struct node* token;
  int* flags; 
  int baseType; //1 = var. 2 = function. 3 = class
  /*
    
    0 var 
    1 const
    2 public 
    3 private 
    4 protected 
    5 override
    6 dynamic 
    7 final 
    8 native 
    9 static
  
  */
  
  //struct ctype *elemtype;
} field;
  
typedef struct symbolTable { 
  struct symbolTable* parent;
  int nSymbols;
  field** fields;
} symbolTable;

symbolTable* makeTable(symbolTable* parent);

int findIdentLocally(symbolTable* table, char* ident); //no recursion up
int findIdent(symbolTable* table, char* ident); //searches up
int addSymbol( symbolTable* table, char* ident, int baseType, struct node* token, struct variableDataPack* flags );
int* updateFlagsFromData( variableDataPack* data );
struct node* getSymbolNode( symbolTable* table, char* ident);

void printTable(symbolTable* table);

#endif
