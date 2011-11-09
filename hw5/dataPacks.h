#ifndef DATAPACKS
#define DATAPACKS

typedef struct variableDataPack {
  int publicFlag;
  int constFlag; 
  int varFlag;
  int privateFlag;
  int protectedFlag; 
  int overrideFlag;
  int nativeFlag;
} variableDataPack;

typedef struct functionDataPack {
  int publicFlag, 
    constFlag, 
    varFlag, 
    privateFlag, 
    protectedFlag, 
    overrideFlag, 
    nativeFlag, 
    numArguments;
} functionDataPack;

variableDataPack* initializeDataPack();


#endif
