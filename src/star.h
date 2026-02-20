#pragma once
#include "random.h"
class Star {

  public:
    Star(int x = randInt(0, 4000), int y = randInt(0, 4000));
    int getX();
    int getY();

  private:
    int sX;
    int sY;
    
};