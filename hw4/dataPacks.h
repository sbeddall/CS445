#ifndef DATAPACKS
#define DATAPACKS

typedef struct variableDataPack {
  int publicFlag, 
    constFlag, 
    varFlag, 
    publicFlag, 
    privateFlag, 
    protectedFlag, 
    overrideFlag,
    nativeFlag, 
} variableDataPack;

typdef struct functionDataPack {
  int publicFlag, 
    constFlag, 
    varFlag, 
    publicFlag, 
    privateFlag, 
    protectedFlag, 
    overrideFlag, 
    nativeFlag, 
    numArguments;
} functionDataPack;


#endif
