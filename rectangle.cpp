#include "rectangle.h"

Rectangle::Rectangle()
{
    this->point1 = Point();
    this->point2 = Point();
    this->point3 = Point();
    this->point4 = Point();
}

Rectangle::Rectangle(Point point1, Point point2, Point point3, Point point4)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->point4 = point4;
}

Rectangle::Rectangle(const Rectangle& other)
{
    this->point1 = other.point1;
    this->point2 = other.point2;
    this->point3 = other.point3;
    this->point4 = other.point4;
}

Rectangle::Rectangle(istream& is)
{
    is >> point1 >> point2 >> point3 >> point4;
}

size_t Rectangle::VertexesNumber()
{
    return 4;
}

double Rectangle::Area()
{
    double width = Point::Distance(point1, point2);
    double height = Point::Distance(point2, point3);
    return width * height;
}

void Rectangle::Print(ostream& os)
{
    os << "Rectangle: " << point1 << ", " << point2 << ", " << point3 << ", " << point4 << endl;
}
