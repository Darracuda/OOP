#include "triangle.h"

using namespace std;

Triangle::Triangle()
{
    this->point1 = Point();
    this->point2 = Point();
    this->point3 = Point();
}

Triangle::Triangle(Point point1, Point point2, Point point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}

Triangle::Triangle(const Triangle& other)
{
    this->point1 = other.point1;
    this->point2 = other.point2;
    this->point3 = other.point3;
}

size_t Triangle::VertexesNumber()
{
    return 3;
}

double Triangle::Area()
{
    double length12 = Point::Distance(point1, point2);
    double length23 = Point::Distance(point2, point3);
    double length31 = Point::Distance(point3, point1);
    double semiPerimeter = (length12 + length23 + length31) / 2.0;
    return sqrt(semiPerimeter * (semiPerimeter - length12) * (semiPerimeter - length23) * (semiPerimeter - length31));
}

istream& operator>>(istream& is, Triangle& triangle)
{
    is >> triangle.point1 >> triangle.point2 >> triangle.point3;
    return is;
}

ostream& operator<<(ostream& os, Triangle& triangle)
{
    os << "Triangle: " << triangle.point1 << ", " << triangle.point2 << ", " << triangle.point3;
    return os;
}

Triangle& Triangle::operator=(const Triangle& other)
{
    this->point1 = other.point1;
    this->point2 = other.point2;
    this->point3 = other.point3;
    return *this;
}

bool Triangle::operator==(const Triangle& other)
{
    return (this->point1 == other.point1)
        && (this->point2 == other.point2)
        && (this->point3 == other.point3);
}

void* Triangle::operator new(size_t size)
{
    return allocator.allocate(size);
}

void Triangle::operator delete(void* pObject)
{
    allocator.unallocate(pObject);
}

TAllocator Triangle::allocator(sizeof(Triangle), 10);