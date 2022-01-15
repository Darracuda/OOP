#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "figure.h"

class Triangle : public Figure {

public:
  Triangle();
  Triangle(Point a, Point b, Point c);
  Triangle(std::istream &is);
  Triangle(const Triangle& other);

  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Triangle();

private:
  Point p1;
  Point p2;
  Point p3;
};

#endif // TRIANGLE_H
