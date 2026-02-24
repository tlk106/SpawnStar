#include "star.hpp"
#include "convert.hpp"
#include "random.hpp"
#include <cmath>

const double pi = 3.14159265359;
const double stefanBoltzmanConstant = 5.6704e-8;
const double zeroPointLuminosity = 3.0128e28;
const double gravitationalConstant = 6.6743e-11;

Star::Star(int x, int y, int temperatureK, double solarRadius, double distance) {
  sX = x;
  sY = y;
  sTemperatureK = temperatureK;
  sSolarRadius = solarRadius;
  sDistance = distance;
  sMass = Star::calculateMass();
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

double Star::getSolarRadius() {
  return sSolarRadius;
}

double Star::getDistance() {
  return sDistance;
}

double Star::getLuminosity() {
  return (4 * pi * pow(solarRadiusToMeters(sSolarRadius), 2) * stefanBoltzmanConstant * pow(sTemperatureK, 4)); // This is in watts btw 
}

double Star::getAbsoluteMagnitude() {
  return (-2.5 * log10(getLuminosity() / zeroPointLuminosity));
}

double Star::getApparentMagnitude() {
  return (getAbsoluteMagnitude() - 5 + (5 * log10(lightYearsToParsecs(sDistance))));
}

double Star::getMass() {
  return sMass;
}

double Star::calculateMass() {
  if (sSolarRadius >= 12) {
    return randFloat(10, 20);
  }
  else if (sSolarRadius >= 5) {
    return randFloat(2, 10);
  }
  else if (sSolarRadius >= 1.5) {
    return randFloat(0.7, 2);
  }
  else if (sSolarRadius >= 0.7) {
    return randFloat(0.08, 0.7);
  }
  else {
    return randFloat(0.08, 0.4);
  }
}

double Star::getSurfaceGravity() {
  return (gravitationalConstant * solarMassToKilograms(getMass())) / pow(solarRadiusToMeters(getSolarRadius()), 2);
}

std::string Star::getSpectralType() {
  int subClass;
  if (sTemperatureK >= 10000) {
    subClass = 9 - int((double(sTemperatureK - 10000) / (33000 - 10000)) * 10.0);
    std::string result = "B" + std::to_string(subClass);
    return result;
  }
  else if (sTemperatureK >= 7300) {
    subClass = 9 - int((double(sTemperatureK - 7300) / (10000 - 7300)) * 10.0);
    std::string result = "A" + std::to_string(subClass);
    return result;
  }
  else if (sTemperatureK >= 6000) {
    subClass = 9 - int((double(sTemperatureK - 6000) / (7300 - 6000)) * 10.0);
    std::string result = "F" + std::to_string(subClass);
    return result;
  }
  else if (sTemperatureK >= 5300) {
    subClass = 9 - int((double(sTemperatureK - 5300) / (6000 - 5300)) * 10.0);
    std::string result = "G" + std::to_string(subClass);
    return result;
  }
  else if (sTemperatureK >= 3900) {
    subClass = 9 - int((double(sTemperatureK - 3900) / (5300 - 3900)) * 10.0);
    std::string result = "K" + std::to_string(subClass);
    return result;
  }
  else if (sTemperatureK >= 2300) {
     subClass = 9 - int((double(sTemperatureK - 2300) / (3900 - 2300)) * 10.0);
    std::string result = "M" + std::to_string(subClass);
    return result;
  }
  else {
    return "Unknown";
  }
}

std::string Star::getLuminosityClass() {
  return 0;
}