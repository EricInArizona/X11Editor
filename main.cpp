// Copyright Eric Chauvin 2021 - 2022.



#include "../LinuxApi/BasicTypes.h"
#include "../LinuxApi/SetStack.h"
#include "MainApp.h"



// Int32 main( Int32 argc, char* argv[] )
Int32 main( void )
{
if( !SetStack::setit( 64L * 1024L * 1024L ))
  return 1;


MainApp mApp;

return mApp.mainLoop(); //  argc, argv );
}
