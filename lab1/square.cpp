#include "square.h"

#include <iostream>
#include <cmath>

Square::Square()
    : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), p4(0.0, 0.0) {  // можно, но длиннее p1(Point(0.0, 0.0))
  std::cout << "Default square created" << std::endl;
}

Square::Square(Point a, Point b, Point c, Point d)
    : p1(a), p2(b), p3(c), p4(d) {
  std::cout << "Square created by parameters" << std::endl;
}

Square::Square(std::istream &is) {
  is >> p1 >> p2 >> p3 >> p4;
}

Square::Square(const Square& other)
    : Square(other.p1, other.p2, other.p3, other.p4) {
  std::cout << "Square copy created" << std::endl;
}

size_t Square::VertexesNumber() {
  return(size_t)4;
}

double Square::Area() {
  double p12 = p1.dist(p2);
  double p = p12 * p12;
  return p;
}

void Square::Print(std::ostream& os) {
  os << "Square: ";
  os << p1 << ", ";
  os << p2 << ", ";
  os << p3 << ", ";
  os << p4 << std::endl;
}

Square::~Square() {
  //std::cout << "Square deleted" << std::endl;
}
