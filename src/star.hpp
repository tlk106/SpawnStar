#pragma once
#include "random.hpp"
#include <string>
#include <array>

class Star {

  public:
    Star(int x = randInt(0, 4000), int y = randInt(0, 4000), int temperatureK = randInt(2300, 12000), double solarRadius = randFloat(0.3, 12), double distance = randFloat(0.5, 400));
    int getX();
    int getY();
    int getTemperature();
    double getSolarRadius();
    double getDistance();

    // Calculated
    double getLuminosity();
    double getAbsoluteMagnitude();
    double getApparentMagnitude();
    double calculateMass();
    double getMass();
    double getSurfaceGravity();

    // Classification
    std::string getSpectralType();
    std::string getLuminosityClass();
    std::string getFinalClass();

    // Rendering
    std::array<int,3> getRenderingColour();
    int getRenderingBrightness();

  private:
    int sX;
    int sY;
    int sTemperatureK;
    double sSolarRadius;
    double sDistance;
    double sMass;
};