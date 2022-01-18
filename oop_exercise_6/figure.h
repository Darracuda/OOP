#pragma once
#include "point.h"

class Figure
{
public:
	virtual size_t VertexesNumber() = 0;
	virtual double Area() = 0;
};

