// Copyright Eric Chauvin 2021 - 2022.
// This copyright notice has to stay at the top.


// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


// I never use the C preprocessor except to use
// #include statements.


#include "../LinuxApi/BasicTypes.h"
#include "../LinuxApi/FileIO.h"



class MainApp
  {
  private:
  FileIO mainIO;

  public:
  inline static const char* getVersionStr( void )
    {
    return "3/30/2022";
    }

  // Int32 mainLoop( Int32 argc, char* argv[] );
  Int32 mainLoop( void );

  };
