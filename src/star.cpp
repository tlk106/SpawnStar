#include "star.hpp"

Star::Star(int x, int y, int temperatureK, float solarRadius, float distance) {
  sX = x;
  sY = y;
  sTemperatureK = temperatureK;
  sSolarRadius = solarRadius;
  sDistance = distance;
}

int Star::getX(){
	return sX;
}

int Star::getY(){
	return sY;
}

int Star::getTemperature(){
  return sTemperatureK;
}

float Star::getSolarRadius() {
  return sSolarRadius;
}

float Star::getDistance() {
  return sDistance;
}