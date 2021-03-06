// Copyright Eric Chauvin, 2021 - 2022.


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



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
const char* outFile = "/home/Eric/X11Editor/ExeOut.txt";

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


testX11();


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




void MainApp::testX11( void )
{
// I have to test that I can call the static functions
// from here.

mainIO.appendChars( "X11 test top.\n" );

if( !X11Main::init( mainIO ))
  {
  mainIO.appendChars( "X11 init returned false.\n" );
  return;
  }


mainIO.appendChars( "init() is OK.\n" );

// A window manager can override your choice of size,
// border width, and position for a top-level window.
// Your program must be prepared to use the actual size
// and position of the top window.

Int32 dWidth = X11Main::getDisplayWidth();
Int32 dHeight = X11Main::getDisplayHeight();


mainIO.appendChars( "dWidth: " );
Str showW( dWidth );
mainIO.appendStr( showW );
mainIO.appendChars( "\n" );

if( dWidth < 800 )
  dWidth = 800;

if( dHeight < 600 )
  dHeight = 600;


// Creating a window tells it what events it is interested
// in getting here.
Uint64 newWin = X11Main::createSimpleWindow(
                      1,
                      1,
                      // minus two borders - 2
                      dWidth - (2 * 5) - 2,
                      // If dHeight is too big then it will
                      // push the taskbar down so it is
                      // hidden or partially pushed down.
                      dHeight - 110,
                      5 );

X11Main::listFonts( mainIO );

// Uint64 fontID =
// X11Main::loadFont( "fixed" );

X11Main::loadFont( "-misc-fixed-medium-r-semicondensed--13-100-100-100-c-60-iso8859-1" );



for( Int32 count = 0; count < 100; count++ )
  {
  Int32 whatEvent = X11Main::checkWindowEvent( newWin );
  if( whatEvent == X11Const::EventNothing )
    {
    Threads::sleep( 100 );
    continue;
    }


  if( whatEvent == X11Const::EventExpose )
    {
    x11DrawWindow( newWin );
    }


  if( whatEvent == X11Const::EventKeyPress )
    {
    char aKey = X11Main::getKeyChar();
    if( aKey == 'q' )
      {
      mainIO.appendChars( "Got a quit.\n" );
      break;
      }

    continue;
    }

  if( whatEvent == X11Const::EventButtonPress )
    {
    // Get the x, y positions.
    // event.xbutton.x
    // event.xbutton.y
    continue;
    }


  Threads::sleep( 100 );
  }



X11Main::destroyWindow( newWin );

X11Main::closeConnect();

mainIO.appendChars( "After close.\n" );
}




void MainApp::x11DrawWindow( Uint64 window )
{
X11Main::drawRectangle( window, 100, 100, 500, 400 );

X11Main::drawString( window, 150, 150, "Test draw this." );


}
