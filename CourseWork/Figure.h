#pragma once
#include <iostream>
using namespace std;
class Figure
{
public:
	virtual void Show() = 0;
	virtual double Perimeter() = 0;
	virtual double Square() = 0;
	virtual pair<double, double>Center() = 0;
};
