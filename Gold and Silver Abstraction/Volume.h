#pragma once
class Volume {
    double volumeInGallons;
    static constexpr double LITERS_PER_GALLON = 3.785;
    static constexpr double CUBIC_CENTIMETERS_PER_LITER = 1000;
public:
    Volume() : volumeInGallons(0.0) {}
    void setInGallons(double gallons) { volumeInGallons = gallons; }
    double getInCubicCentimeters();
};

