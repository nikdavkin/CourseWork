#pragma once
#include <iostream>
#include <cmath>
#include "Functions.h"
#include"Quadrate.h"
using namespace std;
class Rectangle :public Quadrate
{
protected:
	double b = length(x2, y1, x2, y2);
	double p = 2 * a + 2 * b;
	double s = a * b;
public:
	Rectangle() : Quadrate() {}
	Rectangle(double x1, double y1, double x2, double y2) :Quadrate(x1, y1, x2, y2) {}
	void Show() override
	{
		cout << "Фигура: Прямоугольник" << endl;
		cout << "Координаты левой нижней точки:(" << x1 << ";" << y2 << ")" << endl;
		cout << "Координаты левой верхней точки:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Координаты правой верхней точки:(" << x2 << ";" << y1 << ")" << endl;
		cout << "Координаты правой нижней точки:(" << x2 << ";" << y2 << ")" << endl;
		cout << "Длина первой стороны: " << a << endl;
		cout << "Длина второй стороны: " << b << endl;
		cout << "Длина диагонали: " << d1 << endl;
		cout << "Радиус вписанной окружности(0, если нельзя вписать): ";
		if (IsSquare()) cout << a / 2 << endl;
		else cout << 0 << endl;
		cout << "Радиус описанной окружности(0, если нельзя описать): ";
		if (IsSquare()) cout << sqrt(2) * a / 2 << endl;
		else cout << 0 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	virtual bool IsSquare() { return (a == b); }
	~Rectangle() {}
};
