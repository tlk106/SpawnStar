#pragma once
#include "random.hpp"
#include <string>
class Star {

  public:
    Star(int x = randInt(0, 4000), int y = randInt(0, 4000), int temperatureK = randInt(2300, 12000), double solarRadius = randFloat(0.3, 6), double distance = randFloat(0.5, 400));
    int getX();
    int getY();
    int getTemperature();
    double getSolarRadius();
    double getDistance();

    // Calculated
    double getLuminosity();
    double getAbsoluteMagnitude();
    double getApparentMagnitude();

    // Classification
    std::string getSpectralType();
    std::string getLuminosityClass();
    std::string getFinalClass();

  private:
    int sX;
    int sY;
    int sTemperatureK;
    double sSolarRadius;
    double sDistance;
};