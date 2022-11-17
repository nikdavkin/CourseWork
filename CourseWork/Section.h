#pragma once
#include <iostream>
#include "Point.h"
#include "Functions.h"
using namespace std;
class Section :public Point
{
protected:
	double x2, y2;
	double Length = length(x1, y1, x2, y2);
public:
	Section() :Point(), x2(0), y2(0) {}
	Section(double x1, double y1, double x2, double y2) :Point(x1, y1), x2(x2), y2(y2) {}
	void Show() override
	{
		cout << "Фигура: Отрезок" << endl;
		cout << "Координаты начала:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Координаты конца:(" << x2 << ";" << y2 << ")" << endl;
		cout << "Длина: " << Length << endl;
	}
	double Perimeter() override { return Length; };
	pair<double, double> Center() override { return pair<double, double>((x1 + x2) / 2, (y1 + y2) / 2); }
	void GetPoints(Point Points[2])
	{
		Points[0].SetX(x1);
		Points[0].SetY(y1);
		Points[1].SetX(x2);
		Points[1].SetY(y2);
	}
	~Section() {}
};
