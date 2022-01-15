#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include "figure.h"

class Square : public Figure {

//friend std::istream& operator>>(std::istream& is, Square& t);
//friend std::ostream& operator<<(std::ostream& os, Square& t);

public:
  Square();
  Square(Point a, Point b, Point c, Point d);
  Square(std::istream &is);
  Square(const Square& other);

  size_t VertexesNumber();
  double Area();
  void Print(std::ostream& os);

  virtual ~Square();

private:
  Point p1;
  Point p2;
  Point p3;
  Point p4;
};

#endif // SQUARE_H