#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include "Point.h"
#include <math.h>
#include "Functions.h"
using namespace std;
class Circle :public Point
{
private:
	double R;
	double d = R * 2;
	double p = 2 * R * M_PI;
	double s = R * R * M_PI;
public:
	Circle() :Point(), R(0) {}
	Circle(double x1, double y1, double R) : Point(x1, y1), R(R) {}
	void Show() override
	{
		cout << "Фигура: Круг" << endl;
		cout << "Координаты центра:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Радиус: " << R << endl;
		cout << "Диаметр: " << d << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	double GetR() { return R; };
	~Circle() {}
};