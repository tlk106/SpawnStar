#include <cstdlib>
#include "star.h"

Star::Star(int x, int y, int red, int blue, int green, int brightness) {
  sX = x;
  sY = y;
  sRed = red;
  sGreen = green;
  sBlue = blue;
  sBrightness = brightness;
}

int Star::getX(){
	return sX;
}

int Star::getY(){
	return sY;
}

int Star::getRed(){
	return sRed;
}

int Star::getGreen(){
	return sGreen;
}

int Star::getBlue(){
	return sBlue;
}

int Star::getBrightness(){
	return sBrightness;
}