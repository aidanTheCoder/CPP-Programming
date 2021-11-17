#pragma once
#include "point.h"

struct Triangle
{
  Point vertex1;
  Point vertex2;
  Point vertex3;
};

double getPerimeter(const Triangle *ptrThis);
void printVertices(const Triangle *ptrThis);
Triangle getTriangleFromUser();
Point getCentroid(const Triangle *ptrThis);
