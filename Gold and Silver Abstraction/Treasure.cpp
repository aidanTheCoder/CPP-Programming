#include <iostream>
#include "Treasure.h"
using std::cout;

void Treasure::setVolume(double newVolume) {
    volume.setInGallons(newVolume);
}

void Treasure::setWeight(double newWeight) {
    weight.setInPounds(newWeight); 
}

/*
* Compputes the density in grams per cubic centimeters using
* member variables in the weight and volume classes. Returns 
* true if the computed density is higher the minumum bound for
* expected density and it is lower than the expected bound
*/

bool Treasure::isPure(double expectedDensity, double tolerance) {
    double actualDensity = weight.getInGrams() /
        volume.getInCubicCentimeters();
    if (actualDensity >= (expectedDensity * (1 - tolerance))
        && actualDensity <= (expectedDensity * (1 + tolerance))) {
        return true;
    } else
        return false;
}


