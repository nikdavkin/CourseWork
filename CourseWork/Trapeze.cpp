#include <iostream>
#include "Trapeze.h"
void Trapeze::Show()
{
	cout << "������: ��������" << endl;
	cout << "���������� ����� ������ �����:(" << x3 << ";" << y3 << ")" << endl;
	cout << "���������� ����� ������� �����:(" << x1 << ";" << y1 << ")" << endl;
	cout << "���������� ������ ������� �����:(" << x2 << ";" << y2 << ")" << endl;
	cout << "���������� ������ ������ �����:(" << x4 << ";" << y4 << ")" << endl;
	cout << "����� ����� �������: " << d << endl;
	cout << "����� ������� �������: " << a << endl;
	cout << "����� ������ �������: " << b << endl;
	cout << "����� ������ �������: " << c << endl;
	cout << "����� ������ ���������: " << d1 << endl;
	cout << "����� ������ ���������: " << d2 << endl;
	cout << "����� ������: " << h << endl;
	cout << "������ ��������� ����������(0, ���� ������ �������): ";
	if (a + c == b + d) cout << sqrt(a * c) / 2 << endl;
	else cout << 0 << endl;
	cout << "������ ��������� ����������(0, ���� ������ �������): ";
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