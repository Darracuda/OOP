#include <cmath>
#include "point.h"

using namespace std;

Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::Distance(const Point& point1, const Point& point2)
{
	double dx = point1.x - point2.y;
	double dy = point1.y - point2.y;
	double distance = sqrt(dx * dx + dy * dy);
	return distance;
}

istream& operator>>(istream& is, Point& point)
{
	is >> point.x >> point.y;
	return is;
}

ostream& operator<<(ostream& os, Point& point)
{
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}

