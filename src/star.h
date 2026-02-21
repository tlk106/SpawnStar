#pragma once
#include "random.h"
class Star {

  public:
    Star(int x = randInt(0, 4000), int y = randInt(0, 4000), int temperatureK = randInt(1500, 12000), float solarRadius = randFloat(0.3, 6), float distance = randFloat(0.5, 400));
    int getX();
    int getY();
    int getTemperature();
    float getSolarRadius();
    float getDistance();

  private:
    int sX;
    int sY;
    int sTemperatureK;
    float sSolarRadius;
    float sDistance;
};