#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point();
	Point(double x, double y);

	static double Distance (const Point& point1, const Point& point2);

	friend istream& operator>>(istream& is, Point& point);
	friend ostream& operator<<(ostream& os, Point& point);

	bool operator==(const Point& other);
};

