#include "Temperature.h"

void Temperature::setTemperatureAsCelsius(double celsius) {
	temperatureInCelsius = celsius;
}

void Temperature::setTemperatureAsFahrenheit(double fahrenheit) {
	temperatureInCelsius = (fahrenheit - 32) / 1.8;
}

void Temperature::setTemperatureAsKelvin(double kelvin) {
	temperatureInCelsius = kelvin - 273.15;
}

double Temperature::getInCelsius() const {
	return temperatureInCelsius;
}

double Temperature::getInFahrenheit() const {
	return (temperatureInCelsius * 1.8) + 32;
}

double Temperature::getInKelvin() const {
	return temperatureInCelsius + 273.15;
}
