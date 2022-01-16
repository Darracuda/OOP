#pragma once
#include "figure.h"

class Square : public Figure
{
private:
	Point point1;
	Point point2;
	Point point3;
	Point point4;

public:
	Square();
	Square(Point point1, Point point2, Point point3, Point point4);
	Square(const Square& other);
	Square(istream& is);

	virtual size_t VertexesNumber() override;
	virtual double Area() override;
	virtual void Print(ostream& os) override;
};

