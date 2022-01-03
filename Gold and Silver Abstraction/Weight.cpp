#include "Weight.h"

double Weight::getInGrams() {
    return weightInPounds * OZ_PER_LB * GRAMS_PER_OZ;
}