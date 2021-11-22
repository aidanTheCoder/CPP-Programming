#pragma once
#include <string>

class Point {
  double xCoordinate;
  double yCoordinate;

public:
  void enter();
  double distanceTo(Point that) const;
  double distanceTo(const Point *that) const;
  double getY() const { return yCoordinate; }
  double getX() const { return xCoordinate; }
  void setX(double newX) { xCoordinate = newX; }
  void setY(double newY) { yCoordinate = newY; }
  std::string print() const;
};
