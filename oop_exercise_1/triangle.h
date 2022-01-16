#pragma once
#include "figure.h"

class Triangle : public Figure
{
private:
	Point point1;
	Point point2;
	Point point3;

public:
	Triangle();
	Triangle(Point point1, Point point2, Point point3);
	Triangle(const Triangle& other);
	Triangle(istream& is);

	virtual size_t VertexesNumber() override;
	virtual double Area() override;
	virtual void Print(ostream& os) override;
};

