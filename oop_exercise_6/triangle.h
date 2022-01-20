#pragma once
#include "figure.h"
#include "tallocator.h"

class Triangle : public Figure
{
private:
	Point point1;
	Point point2;
	Point point3;

	static TAllocator allocator;
public:
	Triangle();
	Triangle(Point point1, Point point2, Point point3);
	Triangle(const Triangle& other);

	virtual size_t VertexesNumber() override;
	virtual double Area() override;

	friend istream& operator>>(istream& is, Triangle& triangle);
	friend ostream& operator<<(ostream& os, Triangle& triangle);

	Triangle& operator=(const Triangle& other);
	bool operator==(const Triangle& other);

	void* operator new(size_t size);
	void operator delete(void* ptr);
};

