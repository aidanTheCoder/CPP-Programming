//
//Aidan Rutherford
//Project: homework2
//Obtains a user defined triangle
//using structs and point
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include "point.h"
#include "triangle.h"
using namespace std;

int main()
{
  Triangle myTriangle;
  Point myTrianglesCentroid;

  myTriangle = getTriangleFromUser();
  printVertices(&myTriangle);

  myTrianglesCentroid = getCentroid(&myTriangle);
  printPoint(myTrianglesCentroid);

  cout << "The perimeter is " << getPerimeter(&myTriangle) << endl;
  return 0;
}

//
//Obtains a single set of Cartesian coordinates from the user
//

Point getPointFromUser()
{
  Point vertexCoordinates;
  double vert = 0;
  double horiz = 0;

  cout << "Enter the x and y coordinates separated by a space: ";
  cin >> horiz;
  cin >> vert;
  while(cin.fail())
  {
    cout << "Try again.\n" 
        << "Enter the x and y coordinates separated by a space: ";
    cin.clear();
    cin.ignore(999,'\n');
    cin >> horiz;
    cin >> vert;
  }

  vertexCoordinates.xCoordinate = horiz;
  vertexCoordinates.yCoordinate = vert;
  return vertexCoordinates;
}

//
//Uses the distance formula to compute the distance between
//two user defined points
//

double distanceBetweenPoints(const Point *point1,
                             const Point *point2)
{
  double distance = 0;
  double diffInX = 0;
  double diffInY = 0;

  diffInX = (point1->xCoordinate) - (point2->xCoordinate);
  diffInY = (point1->yCoordinate) - (point2->yCoordinate);
  diffInX = diffInX * diffInX;
  diffInY = diffInY * diffInY;
  distance = sqrt(diffInX + diffInY);
  return distance;
}

//
//Obtains coordinates from user 3 times,
//returns a struct with 3 vertices
//

Triangle getTriangleFromUser()
{
  Triangle userDefinedTriangle;

  userDefinedTriangle.vertex1 = getPointFromUser();
  userDefinedTriangle.vertex2 = getPointFromUser();
  userDefinedTriangle.vertex3 = getPointFromUser();
  return userDefinedTriangle;
}

//
//Calculates perimeter of a triangle
//

double getPerimeter(const Triangle *ptrThis)
{
  double perimeter = 0;
  double segment1 = 0;
  double segment2 = 0;
  double segment3 = 0;

  segment1 = distanceBetweenPoints(&(ptrThis->vertex1),
                                   &(ptrThis->vertex2));

  segment2 = distanceBetweenPoints(&(ptrThis->vertex2), 
                                   &(ptrThis->vertex3));

  segment3 = distanceBetweenPoints(&(ptrThis->vertex1), 
                                   &(ptrThis->vertex3));

  perimeter = segment1 + segment2 + segment3;
  return perimeter;
}

//
//Comoutes the centroid of the user-defined triangle
//

Point getCentroid(const Triangle *ptrThis)
{
  Point centroid;
  double sumOfX = 0;
  double sumOfY = 0;

  sumOfX = (ptrThis->vertex1.xCoordinate) \
           + (ptrThis->vertex2.xCoordinate) \
           + (ptrThis->vertex3.xCoordinate);

  sumOfY = (ptrThis->vertex1.yCoordinate) \
           + (ptrThis->vertex2.yCoordinate) \
           + (ptrThis->vertex3.yCoordinate);

  centroid.xCoordinate = sumOfX/3;
  centroid.yCoordinate = sumOfY/3;
  return centroid;
}

//
//Prints out a single set of cCartesian coordinates for the centroid
//

void printPoint(Point thePoint)
{
  cout << setprecision(2) << fixed << "The centroid is [" 
      << thePoint.xCoordinate << ", " 
      << thePoint.yCoordinate << "]" << endl;
}

//
//Prints 3 vertices as ordered pairs
//

void printVertices(const Triangle *ptrThis)
{
  cout << "The triangle vertices are " << setprecision(2) << fixed
      << "[" <<  ptrThis->vertex1.xCoordinate << ", " 
      << ptrThis->vertex1.yCoordinate << "] "
      << "[" <<  ptrThis->vertex2.xCoordinate << ", " 
      << ptrThis->vertex2.yCoordinate << "] "
      << "[" <<  ptrThis->vertex3.xCoordinate << ", " 
      << ptrThis->vertex3.yCoordinate << "] " << endl;
}
