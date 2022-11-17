#pragma once
#include <iostream>
#include "Figure.h"
#include <cmath>
#include "Functions.h"
#include "Rectangle.h"
using namespace std;
class Rhombus :public Rectangle
{
private:
	double x3 = 2 * x2 - x1, y3 = 2 * y1 - y2;
	double a = length(x1, y1, x2, y2);
	double d1 = length(x1, y1, x3, y1);
	double d2 = length(x2, y2, x2, y3);
	double p = 4 * a;
	double s = d1 * d2 / 2;
public:
	using Rectangle::Rectangle;
	void Show() override
	{
		cout << "Фигура: Ромб" << endl;
		cout << "Координаты левой точки:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Координаты верхней точки:(" << x2 << ";" << y2 << ")" << endl;
		cout << "Координаты правой точки:(" << x3 << ";" << y1 << ")" << endl;
		cout << "Координаты нижней точки:(" << x2 << ";" << y3 << ")" << endl;
		cout << "Длина стороны: " << a << endl;
		cout << "Длина первой диагонали: " << d1 << endl;
		cout << "Длина второй диагонали: " << d2 << endl;
		cout << "Радиус вписанной окружности(0, если нельзя вписать): ";
		if (IsSquare()) cout << a / 2 << endl;
		else cout << 0 << endl;
		cout << "Радиус описанной окружности(0, если нельзя описать): ";
		if (IsSquare()) cout << sqrt(2) * a / 2 << endl;
		else cout << 0 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	pair<double, double> Center() override { return pair<double, double>(x2, y1); }
	bool IsSquare() override { return (d1 == d2); }
	~Rhombus() {}
};