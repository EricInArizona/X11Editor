// Copyright Eric Chauvin, 2021 - 2022.



#include "../LinuxApi/StIO.h"
#include "../LinuxApi/Str.h"
#include "../LinuxApi/SetStack.h"
#include "../LinuxApi/Casting.h"
#include "../LinuxApi/Threads.h"
#include "../LinuxApi/Signals.h"


#include "MainApp.h"
#include "../X11Api/X11Main.h"



// int MainApp::mainLoop( int argc, char* argv[] )
int MainApp::mainLoop( void )
{
Int32 delay = 200; // milliseconds.
const char* outFile = "/home/Eric/EditXA/ExeOut.txt";

try
{
StIO::putS( "See output at:" );
StIO::putS( outFile );


// See the notes in this function.
BasicTypes::thingsAreRight();


mainIO.appendChars(
            "Programming by Eric Chauvin.\n" );

mainIO.appendChars( "Version date: " );
mainIO.appendChars( getVersionStr() );
mainIO.appendChars( "\n\n" );

Int32 stackSize = SetStack::getSize();
Str showS( stackSize );

mainIO.appendChars( "Stack size: " );
mainIO.appendStr( showS );
mainIO.appendChars( "\n\n" );

Signals::setupControlCSignal();
Signals::setupFpeSignal();
Signals::setupIllegalOpSignal();
Signals::setupBadMemSignal();

X11Main x11Main;
x11Main.init( mainIO );


mainIO.appendChars( "End of main app.\n" );

//             mainIO.readAll( fileName );
mainIO.writeAll( outFile );

Threads::sleep( delay );

return 0;
}
catch( const char* in )
  {
  mainIO.appendChars( "Exception in main loop.\n" );
  mainIO.appendChars( in );
  mainIO.appendChars( "\n" );
  mainIO.writeAll( outFile );

  Threads::sleep( delay );
  return 1;
  }

catch( ... )
  {
  const char* in = "An unknown exception"
                   " happened in the main loop.\n";

  mainIO.appendChars( in );
  mainIO.writeAll( outFile );

  Threads::sleep( delay );
  return 1;
  }
}
