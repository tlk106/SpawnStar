#include "star.hpp"
#include "convert.hpp"
#include <cmath>

const double pi = 3.14159265359;
const double stefanBoltzmanConstant = 5.6704e-8;
const double zeroPointLuminosity = 3.0128e28;

Star::Star(int x, int y, int temperatureK, double solarRadius, double distance) {
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