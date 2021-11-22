
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Point.h"
using std::cout;
using std::cin;
using std::endl;
using std:: setprecision;
using std:: fixed;
using std::stringstream;
using std::string;

void  Point::enter() { 
  cout << "Enter the x and y coordinates separated by a space: ";
  cin >> xCoordinate >> yCoordinate;
  while(cin.fail()) {
    cout << "Try again. \n"
        << "Enter the x and y coordinates separated by a space: ";
    cin.clear();
    cin.ignore(999,'\n');
    cin >> xCoordinate >> yCoordinate;
  }
}

double Point::distanceTo(Point that) const {
  double distance = 0;
  double diffInX = 0;
  double diffInY = 0;
  diffInX = xCoordinate - that.xCoordinate;
  diffInY = yCoordinate - that.yCoordinate;
  diffInX = diffInX * diffInX;
  diffInY = diffInY * diffInY;
  distance = sqrt(diffInX + diffInY);
  return distance;
}

double Point::distanceTo(const Point *that) const {
  double distance = 0;
  double diffInX = 0;
  double diffInY = 0;
  diffInX = xCoordinate - that->xCoordinate;
  diffInY = yCoordinate - that->yCoordinate;
  diffInX = diffInX * diffInX;
  diffInY = diffInY * diffInY;
  distance = sqrt(diffInX + diffInY);
  return distance;
}

string Point::print() const {
  stringstream printableString;
  printableString << setprecision(2) << fixed
                 << "[" << xCoordinate << ", " << yCoordinate << "] ";
  return printableString.str();
}
