#pragma once
#include "figure.h"

class Rectangle : public Figure
{
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;

public:
	Rectangle();
	Rectangle(Point point1, Point point2, Point point3, Point point4);
	Rectangle(const Rectangle& other);
	Rectangle(istream& is);

	virtual size_t VertexesNumber() override;
	virtual double Area() override;
	virtual void Print(ostream& os) override;
};

