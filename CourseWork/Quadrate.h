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
		cout << "������: �������" << endl;
		cout << "���������� ����� ������: (" << x1 << ";" << y2 << ")" << endl;
		cout << "���������� ����� ������� �����:(" << x1 << ";" << y1 << ")" << endl;
		cout << "���������� ������ �������: (" << x2 << ";" << y1 << ")" << endl;
		cout << "���������� ������ ������: (" << x2 << ";" << y2 << ")" << endl;
		cout << "����� ������: " << a << endl;
		cout << "����� ����������: " << d1 << endl;
		cout << "������ ���������� �����: " << a / 2 << endl;
		cout << "������ ���������� �����: " << sqrt(2) * a / 2 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	~Quadrate() {}
};