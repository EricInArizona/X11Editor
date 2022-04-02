// Copyright Eric Chauvin 2022




#pragma once




#include "../LinuxApi/BasicTypes.h"
#include "../LinuxApi/FileIO.h"



class RectBase
  {
  private:
  Int32 testForCopy = 123;

  public:
  // RectBase( void );
  // RectBase( const RectBase& in );
  // ~RectBase( void );

  virtual void draw( FileIO& mainIO );


/*
class Derived : RectBase
  {
    void draw() override
    {
    // Draw something.

    }
  };
*/


  };
