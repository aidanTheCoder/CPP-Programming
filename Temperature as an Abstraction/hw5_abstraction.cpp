#include <iostream>
#include <string>
#include "Temperature.h"
using namespace std;

void getTemperatureFromUser(Temperature* temperatureObject);

int main() {
    Temperature theTemperature;
    cout << "The temperature is: " << theTemperature.getInCelsius() << endl;
    getTemperatureFromUser(&theTemperature);
    cout << "The temperature in Celsius is: "
        << theTemperature.getInCelsius() << endl;
    cout << "The temperature in Fahrenheit is: " 
        << theTemperature.getInFahrenheit() << endl;
    cout << "The temperature in Kelvin is: " 
        << theTemperature.getInKelvin() << endl;
    return EXIT_SUCCESS;
}

void getTemperatureFromUser(Temperature* temperatureObject) {
    double amount = 0.0;
    string units = " ";
    bool goodInput = false;

    cout << "I will asky you for a temperature and its units." << endl;
    cout << "For example, your input might be \"98.6 F\"." << endl;
    cout << "Use C for Celsius, F for Fahrenheit, and K for Kelvin."
        << endl;

    do {
        cout << "Enter a temperature followed by the units: ";
        cin >> amount >> units;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "I'm sorry. Tour input failed. Please try again"
                << endl;
            goodInput = false;
        }
        else
            goodInput = true;
        
        if (goodInput) {
            switch (units[0]) {
            case 'C':
            case 'c':
                temperatureObject->setTemperatureAsCelsius(amount);
                break;
            case 'F':
            case 'f':
                temperatureObject->setTemperatureAsFahrenheit(amount);
                break;
            case 'K':
            case 'k':
                temperatureObject->setTemperatureAsKelvin(amount);
                break;
            default:
                cout << "The type was not recognizable as C, F, or K."
                    << endl;
                goodInput = false;
            }
        }
    } while (!goodInput);
}