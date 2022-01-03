#include <iostream>
#include "Weight.h"
#include "Volume.h"
#include "Treasure.h"
using namespace std;

bool testTreasure();
bool checkForTreasure(double weight, double volume);

int main() {
    if (testTreasure())
        cout << "You have treasure" << endl;
    else 
        cout << "you have nothing" << endl;
    return EXIT_SUCCESS;
}

/*
* testTreasure() prompts the user for a weight and volume
* the weight is in pounds and the volume is in gallons
* returns a Bool to see if the treasure is real
*/

bool testTreasure() {
    Weight weight;
    Volume volume;
    double weightInPounds = 0;
    double volumeInGallons = 0;
    cout << "Enter the weight of the substance in pounds: ";
    cin >> weightInPounds;
    while (cin.fail()) {
        cout << "Invalid entry. "
            << "Enter the weight of the substance in pounds: ";
        cin.clear();
        cin.ignore(999, '\n');
        cin >> weightInPounds;
    }
    cout << "Enter the volume of the substance in gallons: ";
    cin >> volumeInGallons;
    while (cin.fail()) {
        cout << "Invalid entry. "
            << "Enter the volume of the substance in gallons: ";
        cin.clear();
        cin.ignore(999, '\n');
        cin >> volumeInGallons;
    }
    return checkForTreasure(weightInPounds, volumeInGallons);
}

/*
* checkForTreasure sets a weight and volume into a 
* treasure object. It is evaluated with the isPure()
* method and returns a Bool regardless of the type
* of treasure whether it is gold or silver
*/

bool checkForTreasure(double weight, double volume) {
    Treasure treasure;
    treasure.setWeight(weight);
    treasure.setVolume(volume);
    if (treasure.isPure(treasure.GOLD, treasure.ONE_PERCENT)) 
        return true;
    else if(treasure.isPure(treasure.SILVER, treasure.ONE_PERCENT))
        return true;
    else 
        return false;
}
