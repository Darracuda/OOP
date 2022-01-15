#include <iostream>
#include <vector>

#include "triangle.h"
#include "rectangle.h"
#include "square.h"


int main() {
  std::vector<Figure*> figures;
  
  std::cout << "Enter triangle vertices' coordinates: "; // -4 2 2 0 0 -2
  Triangle t1(std::cin);
  std::cout << "Number of vertices: " << t1.VertexesNumber() << std::endl;
  t1.Print(std::cout);
  std::cout << "Area:" << t1.Area() << std::endl;
  figures.push_back(&t1);

  std::cout << "Enter rectangle vertices' coordinates: "; // 0 0 5 0 5 -2 0 -2
  Rectangle r1(std::cin);
  std::cout << "Number of vertices: " << r1.VertexesNumber() << std::endl;
  r1.Print(std::cout);
  std::cout << "Area:" << r1.Area() << std::endl;
  figures.push_back(&r1);

  std::cout << "Enter square vertices' coordinates: "; // -1 1 1 1 1 -1 -1 -1
  Square s1(std::cin);
  std::cout << "Number of vertices: " << s1.VertexesNumber() << std::endl;
  s1.Print(std::cout);
  std::cout << "Area:" << s1.Area() << std::endl;
  figures.push_back(&s1);

  std::cout << "Enter rectangle vertices' coordinates: "; // -2.5 3 2.5 3 2.5 -3 0 -3
  Rectangle r2(std::cin);
  std::cout << "Number of vertices: " << r2.VertexesNumber() << std::endl;
  r2.Print(std::cout);
  std::cout << "Area:" << r2.Area() << std::endl;
  figures.push_back(&r2);

  std::cout << "\nFigures in container:" << std::endl;
  for (int i = 0; i < figures.size(); i++)
  {
    figures[i]->Print(std::cout);
  }


  return 0;
}
