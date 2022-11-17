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
		cout << "������: �������������" << endl;
		cout << "���������� ����� ������ �����:(" << x1 << ";" << y2 << ")" << endl;
		cout << "���������� ����� ������� �����:(" << x1 << ";" << y1 << ")" << endl;
		cout << "���������� ������ ������� �����:(" << x2 << ";" << y1 << ")" << endl;
		cout << "���������� ������ ������ �����:(" << x2 << ";" << y2 << ")" << endl;
		cout << "����� ������ �������: " << a << endl;
		cout << "����� ������ �������: " << b << endl;
		cout << "����� ���������: " << d1 << endl;
		cout << "������ ��������� ����������(0, ���� ������ �������): ";
		if (IsSquare()) cout << a / 2 << endl;
		else cout << 0 << endl;
		cout << "������ ��������� ����������(0, ���� ������ �������): ";
		if (IsSquare()) cout << sqrt(2) * a / 2 << endl;
		else cout << 0 << endl;
	}
	double Perimeter() override { return p; }
	double Square() override { return s; }
	virtual bool IsSquare() { return (a == b); }
	~Rectangle() {}
};
