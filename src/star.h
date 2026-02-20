#pragma once
#include <random.h>
class Star {

  public:
    Star(int x = Random::random(5, 5), int y = 0);
    int getX();
    int getY();

  private:
    int sX;
    int sY;
    
};