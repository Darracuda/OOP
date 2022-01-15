#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure {
public:
  virtual size_t VertexesNumber() = 0; // = 0 значит, что метод определяется в наследниках, а в Figure нет
  virtual void Print(std::ostream& os) = 0;
  virtual double Area() = 0;
  virtual ~Figure() {};
};

#endif // FIGURE_H
