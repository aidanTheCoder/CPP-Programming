#pragma once

class Temperature {
    double temperatureInCelsius;
    static constexpr double FAHRENHEIT_TO_CELSIUS = 1.8;
    static constexpr double KELVIN_TO_CELSIUS = 273;
public:
    Temperature() : temperatureInCelsius(0.0) {}
    void setTemperatureAsCelsius(double newTemperature);
    void setTemperatureAsFahrenheit(double newTemperature);
    void setTemperatureAsKelvin(double newTemperature);
    double getInCelsius() const;
    double getInFahrenheit() const;
    double getInKelvin() const;
};