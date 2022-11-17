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
		cout << "������: ����" << endl;
		cout << "���������� ����� �����:(" << x1 << ";" << y1 << ")" << endl;
		cout << "���������� ������� �����:(" << x2 << ";" << y2 << ")" << endl;
		cout << "���������� ������ �����:(" << x3 << ";" << y1 << ")" << endl;
		cout << "���������� ������ �����:(" << x2 << ";" << y3 << ")" << endl;
		cout << "����� �������: " << a << endl;
		cout << "����� ������ ���������: " << d1 << endl;
		cout << "����� ������ ���������: " << d2 << endl;
		cout << "������ ��������� ����������(0, ���� ������ �������): ";
		if (IsSquare()) cout << a / 2 << endl;
		else cout << 0 << endl;
		cout << "������ ��������� ����������(0, ���� ������ �������): ";
		if (IsSquare()) cout << sqrt(2) * a / 2 << endl;
		else cout << 0 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	pair<double, double> Center() override { return pair<double, double>(x2, y1); }
	bool IsSquare() override { return (d1 == d2); }
	~Rhombus() {}
};