#include "triangle.h"

#include <iostream>
#include <cmath>

Triangle::Triangle()
    : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0) {  // можно, но длиннее p1(Point(0.0, 0.0))
  std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(Point a, Point b, Point c)
    : p1(a), p2(b), p3(c) {
  std::cout << "Triangle created by parameters" << std::endl;
}

Triangle::Triangle(std::istream &is) {
  is >> p1 >> p2 >> p3;
}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.p1, other.p2, other.p3) {
  std::cout << "Triangle copy created" << std::endl;
}

size_t Triangle::VertexesNumber() {
  return(size_t)3;
}

double Triangle::Area() {
  double p12 = p1.dist(p2);
  double p13 = p1.dist(p3);
  double p23 = p2.dist(p3);
  double p = (p12 + p23 + p13) / 2.0;
  return std::sqrt(p * (p - p12) * (p - p23) * (p - p13));
}

void Triangle::Print(std::ostream& os) {
  os << "Triangle: ";
  os << p1 << ", ";
  os << p2 << ", ";
  os << p3 << std::endl;
}

Triangle::~Triangle() {
  //std::cout << "Triangle deleted" << std::endl;
}
