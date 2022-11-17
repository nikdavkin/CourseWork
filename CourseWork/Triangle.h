#pragma once
#include <iostream>
#include "Figure.h"
#include <cmath>
#include "Functions.h"
using namespace std;
class Triangle :public Figure
{
private:
	double x1, x2, x3, y1, y2, y3;
	double a = length(x1, y1, x2, y2);
	double b = length(x2, y2, x3, y3);
	double c = length(x3, y3, x1, y1);
	double p = a + b + c;
	double s = sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
public:
	Triangle() :x1(0), x2(0), x3(0), y1(0), y2(0), y3(0) {}
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :x1(x1), x2(x2), x3(x3), y1(y1), y2(y2), y3(y3) {}
	void Show() override
	{
		cout << "Фигура: Треугольник" << endl;
		cout << "Координаты первой точки:(" << x1 << ";" << y1 << ")" << endl;
		cout << "Координаты второй точки:(" << x2 << ";" << y2 << ")" << endl;
		cout << "Координаты третьей точки:(" << x3 << ";" << y3 << ")" << endl;
		cout << "Длина первой стороны: " << a << endl;
		cout << "Длина второй стороны: " << b << endl;
		cout << "Длина третьей стороны: " << c << endl;
		cout << "Длина первой медианы: " << sqrt(2 * a * a + 2 * b * b - c * c) / 2 << endl;
		cout << "Длина второй медианы: " << sqrt(2 * a * a + 2 * c * c - b * b) / 2 << endl;
		cout << "Длина третьей медианы: " << sqrt(2 * b * b + 2 * c * c - a * a) / 2 << endl;
		cout << "Длина первой биссектрисы: " << 2 * sqrt(a * b * p / 2 * (p / 2 - c)) / (a + b) << endl;
		cout << "Длина второй биссектрисы: " << 2 * sqrt(a * c * p / 2 * (p / 2 - b)) / (a + c) << endl;
		cout << "Длина третьей биссектрисы: " << 2 * sqrt(b * c * p / 2 * (p / 2 - a)) / (b + c) << endl;
		cout << "Длина первой высоты: " << s * 2 / a << endl;
		cout << "Длина второй высоты: " << s * 2 / b << endl;
		cout << "Длина третьей высоты: " << s * 2 / c << endl;
		cout << "Радиус вписанной окружности:" << sqrt((p / 2 - a) * (p / 2 - b) * (p / 2 - c) / (p / 2)) << endl;
		cout << "Радиус описанной окружности:" << a * b * c / (4 * sqrt((p / 2) * (p / 2 - a) * (p / 2 - b) * (p / 2 - c))) << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	pair<double, double> Center() override { return pair<double, double>((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3); }
	bool Isosceles() { return(a == b || a == c || b == c); }
	bool equilateral() { return(a == b && b == c); }
	bool Rectangular() { return(abs(a * a - b * b - c * c) < 0, 001 || abs(b * b - a * a - c * c) < 0, 001 || abs(c * c - a * a - b * b) < 0, 001); }
	void GetPoints(Point Points[3])
	{
		Points[0].SetX(x1);
		Points[0].SetY(y1);
		Points[1].SetX(x2);
		Points[1].SetY(y2);
		Points[2].SetX(x3);
		Points[2].SetY(y3);
	}
	~Triangle() {}
};
