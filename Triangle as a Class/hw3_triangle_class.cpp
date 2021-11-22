#include <iostream>
#include <iomanip>
#include "Triangle.h"
#include "Point.h"
using namespace std;

int main() { 
  Triangle myTriangle;
  Point myTrianglesCentroid;
  double myTrianglesPerimeter = 0;

  myTriangle.enter();
  myTrianglesCentroid = myTriangle.getCentroid();
  myTrianglesPerimeter = myTriangle.getPerimeter();

  cout << "The triangles vertices are: " << myTriangle.print() << endl;
  cout << "The centroid is: " << myTrianglesCentroid.print() << endl;
  cout << setprecision(2) << fixed
     << "The perimeter of the triangle is: "
     << myTrianglesPerimeter << endl;

  return 0;
}
