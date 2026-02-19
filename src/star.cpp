#include <cstdlib>
#include "star.h"

Star::Star(int x = std::rand() % 101, int y = std::rand() % 101) {
  sX = x;
  sY = y;
}

int Star::getX(){
	return sX;
}

int Star::getY(){
	return sY;
}