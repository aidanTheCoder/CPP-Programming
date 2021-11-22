#include <iostream>
#include <sstream>
#include <iomanip>
#include "Triangle.h"
using std::fixed;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std:: stringstream;


void Triangle::enter() {
  vertex1.enter();
  vertex2.enter();
  vertex3.enter();
}

string Triangle::print() const {
  stringstream vertices;
  vertices << vertex1.print() <<vertex2.print() << vertex3.print();
  return vertices.str();
}

double Triangle::getPerimeter() const {
  double perimeter = 0;
  double segmentOne = 0;
  double segmentTwo = 0;
  double segmentThree = 0;
  segmentOne = vertex1.distanceTo(vertex2);
  segmentTwo = vertex2.distanceTo(&vertex3);
  segmentThree = vertex3.distanceTo(vertex1);
  perimeter = segmentOne + segmentTwo + segmentThree;
  return perimeter;
}

Point Triangle::getCentroid() const {
  Point centroid;
  double sumOfX = 0;
  double sumOfY = 0;
  sumOfX = (vertex1.getX() + vertex2.getX() + vertex3.getX())/3;
  sumOfY = (vertex1.getY() + vertex2.getY() + vertex3.getY())/3;
  centroid.setX(sumOfX);
  centroid.setY(sumOfY);
  return centroid;
}
  
