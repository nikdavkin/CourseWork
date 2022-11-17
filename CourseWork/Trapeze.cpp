#include <iostream>
#include "Trapeze.h"
void Trapeze::Show()
{
	cout << "Фигура: Трапеция" << endl;
	cout << "Координаты левой нижней точки:(" << x3 << ";" << y3 << ")" << endl;
	cout << "Координаты левой верхней точки:(" << x1 << ";" << y1 << ")" << endl;
	cout << "Координаты правой верхней точки:(" << x2 << ";" << y2 << ")" << endl;
	cout << "Координаты правой нижней точки:(" << x4 << ";" << y4 << ")" << endl;
	cout << "Длина левой стороны: " << d << endl;
	cout << "Длина верхней стороны: " << a << endl;
	cout << "Длина правой стороны: " << b << endl;
	cout << "Длина нижней стороны: " << c << endl;
	cout << "Длина первой диагонали: " << d1 << endl;
	cout << "Длина второй диагонали: " << d2 << endl;
	cout << "Длина высоты: " << h << endl;
	cout << "Радиус вписанной окружности(0, если нельзя вписать): ";
	if (a + c == b + d) cout << sqrt(a * c) / 2 << endl;
	else cout << 0 << endl;
	cout << "Радиус описанной окружности(0, если нельзя описать): ";
	if (Isosceles())
	{
		double P = (b + c + d2) / 2;
		cout << c * b * d2 / (4 * sqrt(P * (P - c) * (P - b) * (P - d2))) << endl;
	}
	else cout << 0 << endl;
}
pair<double, double> Trapeze::Center()
{
	double e = length(x2, y2, x3, y3);
	double p1 = a + d + e;
	double p2 = b + c + e;
	double s1 = sqrt(p1 / 2 * (p1 / 2 - a) * (p1 / 2 - d) * (p1 / 2 - e));
	double s2 = sqrt(p2 / 2 * (p2 / 2 - b) * (p2 / 2 - c) * (p2 / 2 - e));
	double xc1 = (x1 + x2 + x3) / 3;
	double yc1 = (y1 + y2 + y3) / 3;
	double xc2 = (x4 + x2 + x3) / 3;
	double yc2 = (y4 + y2 + y3) / 3;
	return pair<double, double>((xc1 * s1 + xc2 * s2) / s, (yc1 * s1 + yc2 * s2) / s);
}
void Trapeze::GetPoints(Point Points[4])
{
	Points[0].SetX(x1);
	Points[0].SetY(y1);
	Points[1].SetX(x2);
	Points[1].SetY(y2);
	Points[2].SetX(x3);
	Points[2].SetY(y3);
	Points[3].SetX(x4);
	Points[3].SetY(y4);
}