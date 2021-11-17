//
//Name: Aidan Rutherford
//File: homework1.cpp
//Purpose: Introduce data types, input and 
//output and checking for failures in input.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  int year = 0;
  int day = 0;
  double pi = 0; 
  string month = "\0";
  string name = "\0";
  
  //
  //prompt user for the year, and check for failure
  //
  cout << "Enter the year: ";
  cin >> year;
  while(cin.fail()) 
  {
    cout << "Not a valid year, try again: ";
    cin.clear();
    cin.ignore(999,'\n');
    cin >> year;
  }

  //
  //prompt user for the day, and check for failure
  //
  cout << "Enter the day of the month: ";
  cin >> day;
  while(cin.fail())
  {
    cout << "Not a valid day, try again: ";
    cin.clear();
    cin.ignore(888,'\n');
    cin >> day;
  }

  //
  //prompt user for pi, and check for failure
  //
  cout << "Enter as much of pi as you can remember: ";
  cin >> pi;
  while(cin.fail())
  {
    cout << "Not a valid input, try again: ";
    cin.clear();
    cin.ignore(999,'\n');
    cin >> pi;
  }

  //
  //prompt user for the month, and check for failure
  //
  cout << "Enter the month: ";
  cin >> month;
  cout << "Enter your full name: ";
  cin.clear();
  cin.ignore(999,'\n');
  getline(cin,name);

  //
  //print all the information entered by user, formatted nicely
  //
  cout << month << " " << day << ", " << year << endl;
  cout << setprecision(4) << pi << endl;
  cout << setprecision(4) << fixed << pi << endl;
  cout << setprecision(5) << pi << endl;
  cout << "Welcome to CS225 " << name << "!" << endl;
  return 0;
}
