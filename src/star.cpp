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


// Classification
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
  double surfaceGraivityCentimeters = getSurfaceGravity() * 100;
  if (log10(surfaceGraivityCentimeters) >= 4.5) {
    return "VI";
  }
  else if (log10(surfaceGraivityCentimeters) >= 4) {
    return "V";
  }
  else if (log10(surfaceGraivityCentimeters) >= 3) {
    return "IV";
  }
  else if (log10(surfaceGraivityCentimeters) >= 2) {
    return "III";
  }
  else if (log10(surfaceGraivityCentimeters) >= 1.5) {
    return "II";
  }
  else if (log10(surfaceGraivityCentimeters) >= 0) {
    return "I";
  }
  else {
    return "Unknown";
  }
}

std::string Star::getFinalClass() {
  return getSpectralType() + getLuminosityClass();
}

// Rendering
std::array<int,3> Star::getRenderingColour() {
  const std::string starClass = getSpectralType();

  // M
  if (starClass == "M0") {return {255, 195, 139};}
  if (starClass == "M1") {return {255, 204, 142};}
  if (starClass == "M2") {return {255, 196, 131};}
  if (starClass == "M3") {return {255, 206, 129};}
  if (starClass == "M4") {return {255, 201, 127};}
  if (starClass == "M5") {return {255, 204, 111};}
  if (starClass == "M6") {return {255, 195, 112};}
  if (starClass == "M7") {return {255, 197, 111};}
  if (starClass == "M8") {return {255, 198, 109};}
  if (starClass == "M9") {return {255, 198, 108};}

  // K
  if (starClass == "K0") {return {255, 238, 221};}
  if (starClass == "K1") {return {255, 224, 188};}
  if (starClass == "K2") {return {255, 227, 196};}
  if (starClass == "K3") {return {255, 222, 195};}
  if (starClass == "K4") {return {255, 216, 181};}
  if (starClass == "K5") {return {255, 210, 161};}
  if (starClass == "K6") {return {255, 205, 152};}
  if (starClass == "K7") {return {255, 199, 142};}
  if (starClass == "K8") {return {255, 209, 174};}
  if (starClass == "K9") {return {255, 202, 157};}

  // G
  if (starClass == "G0") {return {255, 248, 252};}
  if (starClass == "G1") {return {255, 247, 248};}
  if (starClass == "G2") {return {255, 245, 242};}
  if (starClass == "G3") {return {255, 243, 236};}
  if (starClass == "G4") {return {255, 241, 229};}
  if (starClass == "G5") {return {255, 244, 234};}
  if (starClass == "G6") {return {255, 244, 235};}
  if (starClass == "G7") {return {255, 244, 235};}
  if (starClass == "G8") {return {255, 237, 222};}
  if (starClass == "G9") {return {255, 239, 221};}

  // F
  if (starClass == "F0") {return {224, 229, 255};}
  if (starClass == "F1") {return {230, 234, 255};}
  if (starClass == "F2") {return {236, 239, 255};}
  if (starClass == "F3") {return {230, 233, 255};}
  if (starClass == "F4") {return {224, 226, 255};}
  if (starClass == "F5") {return {248, 247, 255};}
  if (starClass == "F6") {return {244, 241, 255};}
  if (starClass == "F7") {return {246, 243, 255};}
  if (starClass == "F8") {return {255, 247, 252};}
  if (starClass == "F9") {return {255, 247, 252};}

  // A
  if (starClass == "A0") {return {175, 201, 255};}
  if (starClass == "A1") {return {171, 199, 255};}
  if (starClass == "A2") {return {177, 203, 255};}
  if (starClass == "A3") {return {181, 207, 255};}
  if (starClass == "A4") {return {187, 211, 255};}
  if (starClass == "A5") {return {192, 215, 255};}
  if (starClass == "A6") {return {189, 212, 255};}
  if (starClass == "A7") {return {190, 213, 255};}
  if (starClass == "A8") {return {203, 222, 255};}
  if (starClass == "A9") {return {209, 224, 255};}

  // B
  if (starClass == "B0") {return {136, 178, 255};}
  if (starClass == "B1") {return {140, 182, 255};}
  if (starClass == "B2") {return {140, 180, 255};}
  if (starClass == "B3") {return {145, 185, 255};}
  if (starClass == "B4") {return {144, 184, 255};}
  if (starClass == "B5") {return {150, 191, 255};}
  if (starClass == "B6") {return {152, 189, 255};}
  if (starClass == "B7") {return {153, 191, 255};}
  if (starClass == "B8") {return {157, 195, 255};}
  if (starClass == "B9") {return {161, 198, 255};}

  return {127, 0, 255};
}

int Star::getRenderingBrightness() {
  double pogsonMagnitudeFormula = pow(10, -0.4 * (getApparentMagnitude() - 1));
  int rgbAlpha = int(pogsonMagnitudeFormula * 255);
  if (rgbAlpha > 255) {
    return 255;
  }
  else {
    return rgbAlpha;
  }
}