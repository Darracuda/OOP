#include "square.h"

Square::Square()
{
    this->point1 = Point();
    this->point2 = Point();
    this->point3 = Point();
    this->point4 = Point();
}

Square::Square(Point point1, Point point2, Point point3, Point point4)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->point4 = point4;
}

Square::Square(const Square& other)
{
    this->point1 = other.point1;
    this->point2 = other.point2;
    this->point3 = other.point3;
    this->point4 = other.point4;
}

Square::Square(istream& is)
{
    is >> point1 >> point2 >> point3 >> point4;
}

size_t Square::VertexesNumber()
{
    return 4;
}

double Square::Area()
{
    double size = Point::Distance(point1, point2);
    return size * size;
}

void Square::Print(ostream& os)
{
    os << "Square: " << point1 << ", " << point2 << ", " << point3 << ", " << point4 << endl;
}
