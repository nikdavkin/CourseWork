#pragma once
#include <iostream>
#include "Section.h"
#include <cmath>
#include "Functions.h"
using namespace std;
class Quadrate :public Section
{
protected:
	double a = length(x1, y1, x2, y1);
	double d1 = length(x1, y1, x2, y2);
	double p = 4 * a;
	double s = a * a;
public:
	Quadrate() :Section() {}
	Quadrate(double x1, double y1, double x2, double y2) :Section(x1, y1, x2, y2) {}
	void Show() override
	{
		cout << "Фигура: Квадрат" << endl;
		cout << "Координаты левой нижней: (" << x1 << ";" << y2 << ")" << endl;
		cout << "Координаты левой верхней точки:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Координаты правой верхней: (" << x2 << ";" << y1 << ")" << endl;
		cout << "Координаты правой нижней: (" << x2 << ";" << y2 << ")" << endl;
		cout << "Длина сторон: " << a << endl;
		cout << "Длина диагоналей: " << d1 << endl;
		cout << "Радиус вписанного круга: " << a / 2 << endl;
		cout << "Радиус описанного круга: " << sqrt(2) * a / 2 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	~Quadrate() {}
};