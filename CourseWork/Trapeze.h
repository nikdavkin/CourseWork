#pragma once
#include <iostream>
#include "Point.h"
#include <cmath>
#include "Functions.h"
using namespace std;
class Trapeze :public Figure
{
private:
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double a = length(x1, y1, x2, y2);
	double b = length(x2, y2, x4, y4);
	double c = length(x4, y4, x3, y3);
	double d = length(x3, y3, x1, y1);
	double d1 = length(x1, y1, x4, y4);
	double d2 = length(x2, y2, x3, y3);
	double p = a + b + c + d;
	double h = length(x1, y1, x1, y3);
	double s = (a + c) / 2 * h;
public:
	Trapeze() :x1(0), x2(0), x3(0), x4(0), y1(0), y2(0), y3(0), y4(0) {}
	Trapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) :x1(x1), x2(x2), x3(x3), x4(x4), y1(y1), y2(y2), y3(y3), y4(y4) {}
	void Show() override;
	double Perimeter() override { return p; }
	double Square() override { return s; }
	pair<double, double> Center() override;
	bool Isosceles() { return (b == d); }
	bool Rectangular() { return((x1 == x2 && y2 == y4) || (x2 == x4 && y4 == y3) || (x4 == x3 && y3 == y1) || (x3 == x1 && y1 == y2)); }
	void GetPoints(Point Points[4]);
	~Trapeze() {}
};