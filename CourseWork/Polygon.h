#pragma once
#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Functions.h"
using namespace std;
class Polygon :public Figure
{
private:
	int Points;
	Point* Vertexes;
	double* Sides;
	void SetSides();
public:
	Polygon() :Points(0), Vertexes(nullptr) { Sides = 0; }
	Polygon(int Points, Point* Vertexes) : Points(Points), Vertexes(Vertexes) { SetSides(); }
	void Show() override;
	double Perimeter() override;
	double Square() override;
	pair<double, double> Center() override;
	Point* GetPoints()
	{
		return Vertexes;
	}
	int GetN()
	{
		return Points;
	}
	~Polygon() { delete[]Vertexes; delete[]Sides; }
};
