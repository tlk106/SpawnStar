#include <cstdlib>
#include "star.h"

Star::Star(int x, int y) {
  sX = x;
  sY = y;
}

int Star::getX(){
	return sX;
}

int Star::getY(){
	return sY;
}