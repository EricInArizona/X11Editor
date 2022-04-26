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

// This should have things like fill and clear() for
// the rectangle.  And Draw a visible border if it has one.
// And isInside().
// The topmost rectangles would be last in a list.
// So go backwards through the list for topmost first.

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
