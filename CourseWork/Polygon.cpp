#include <iostream>
#include "Polygon.h"
void Polygon::SetSides()
{
	if (Points > 2)
	{
		Sides = new double[Points];
		for (int i = 0;i < Points - 1;i++)
		{
			Sides[i] = length(Vertexes[i].GetX(), Vertexes[i].GetY(), Vertexes[i + 1].GetX(), Vertexes[i + 1].GetY());
		}
		Sides[Points - 1] = length(Vertexes[0].GetX(), Vertexes[0].GetY(), Vertexes[Points - 1].GetX(), Vertexes[Points - 1].GetY());
	}
	else if (Points == 1) Sides = 0;
	else
	{
		Sides = new double[1];
		Sides[0] = length(Vertexes[0].GetX(), Vertexes[0].GetY(), Vertexes[1].GetX(), Vertexes[1].GetY());
	}
}
void Polygon::Show()
{
	int k = 1;
	cout << "Фигура: Многоугольник" << endl;
	for (int i = 0;i < Points;i++)
	{
		cout << "Координаты " << k << "-ой(-ей) точки:(" << Vertexes[i].GetX() << ";" << Vertexes[i].GetY() << ")" << endl;
		k++;
	}
	k = 1;
	if (Points > 2)
	{
		cout << "Количество сторон: " << Points << endl;
		for (int i = 0;i < Points;i++)
		{
			cout << "Длина " << k << "-ой(-ей) стороны: " << Sides[i] << endl;
			k++;
		}
	}
	else if (Points == 1) cout << "Сторон нет" << endl;
	else
	{
		cout << "Количество сторон: 1" << endl;
		cout << "Длина стороны: " << Sides[0] << endl;
	}
}
double Polygon::Perimeter()
{
	double sum = 0;
	if (Points == 1)return 0;
	else if (Points == 2)return Sides[0];
	else
	{
		for (int i = 0;i < Points; i++)
		{
			sum += Sides[i];
		}
		return sum;
	}
}
double Polygon::Square()
{
	if (Points < 3)return 0;
	else
	{
		double sumx = 0, sumy = 0;
		for (int i = 0;i < Points - 1; i++)
		{
			sumx += Vertexes[i].GetX() * Vertexes[i + 1].GetY();
			sumy += Vertexes[i].GetY() * Vertexes[i + 1].GetX();
		}
		sumx += Vertexes[Points - 1].GetX() * Vertexes[0].GetY();
		sumy += Vertexes[Points - 1].GetY() * Vertexes[0].GetX();
		return abs((sumx - sumy) / 2);
	}
}
pair<double, double> Polygon::Center()
{
	if (Points == 2)
	{
		return pair<double, double>((Vertexes[0].GetX() + Vertexes[1].GetX()) / 2, (Vertexes[0].GetY() + Vertexes[1].GetY()) / 2);
	}
	else if (Points == 1)
	{
		return pair<double, double>(Vertexes[0].GetX(), Vertexes[0].GetY());
	}
	else
	{
		double Square = 0;
		double X = 0, Y = 0;
		for (int i = 0;i < Points;i++)
		{
			int j = (i + 1) % Points;
			double x1 = Vertexes[i].GetX();
			double y1 = Vertexes[i].GetY();
			double x2 = Vertexes[j].GetX();
			double y2 = Vertexes[j].GetY();
			X += (x2 - x1) * (2 * x1 * y1 + x1 * y2 + x2 * y1 + 2 * x2 * y2);
			Y += (x2 - x1) * (y1 * y1 + y1 * y2 + y2 * y2);
			Square += (x2 - x1) * (y2 + y1);
		}
		return pair<double, double>(X / Square / 3, Y / Square / 3);
	}
}