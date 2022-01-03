#include "Volume.h"

double Volume::getInCubicCentimeters() {
    return volumeInGallons * LITERS_PER_GALLON 
        * CUBIC_CENTIMETERS_PER_LITER;
}
