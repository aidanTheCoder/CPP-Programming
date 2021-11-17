#pragma once

struct Point
{
  double xCoordinate;
  double yCoordinate;
};

Point getPointFromUser();
double distanceBetweenPoints(const Point *point1, 
                            const Point *point2);
void printPoint(Point thePoint);

