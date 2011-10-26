#include "dataPacks.h"
#include <stdlib.h>

variableDataPack* initializeDataPack(){
  variableDataPack* data = ( variableDataPack* )malloc( sizeof( variableDataPack ) );
  data->publicFlag = 0;
  data->constFlag = 0;
  data->varFlag = 0;
  data->privateFlag = 0;
  data->protectedFlag = 0;
  data->overrideFlag = 0;
  data-> nativeFlag = 0;
}

