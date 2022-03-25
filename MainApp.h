// Copyright Eric Chauvin 2021 - 2022.



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
    return "3/25/2022";
    }

  // Int32 mainLoop( Int32 argc, char* argv[] );
  Int32 mainLoop( void );
  // void checkSignals( void );

  };
