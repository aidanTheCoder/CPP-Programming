#pragma once
#include "Point.h"

class Triangle {
  Point vertex1;
  Point vertex2;
  Point vertex3;

public:
  std::string print() const;
  void enter();
  double getPerimeter() const;
  Point getCentroid() const;
};

