#pragma once
#include <iostream>
#include "Figure.h"
using namespace std;
class Point :public Figure
{
protected:
	double x1, y1;
public:
	Point() :x1(0), y1(0) {};
	Point(double x, double y) :x1(x), y1(y) {};
	void Show() override
	{
		cout << "Фигура: Точка" << endl;
		cout << "Координаты:(" << x1 << ";" << y1 << ")" << endl;
	}
	double Perimeter() override { return 0; };
	double Square() override { return 0; };
	double GetX() { return x1; };
	double GetY() { return y1; };
	void SetX(double xx) { x1 = xx; };
	void SetY(double yy) { y1 = yy; };
	pair<double, double> Center() override { return pair<double, double>(x1, y1); };
	~Point() {}
};

