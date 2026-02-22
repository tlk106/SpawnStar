double wattsToSolarLuminosity(double watts) {
  return watts/3.827e26;
}
double solarLuminosityToWatts(double solarLuminosity) {
  return solarLuminosity*3.827e26;
}

double metersToLightYears(double meters) {
  return meters/9.461e15;
}
double lightYearsToMeters(double lightYears) {
  return lightYears*9.461e15;
}

double metersToSolarRadius(double meters) {
  return meters/6.957e8;
}
double solarRadiusToMeters(double solarRadius) {
  return solarRadius*6.957e8;
}

double parsecsToLightYears(double parsecs) {
	return parsecs*3.262;
}
double lightYearsToParsecs(double lightyear) {
	return lightyear/3.262;
}