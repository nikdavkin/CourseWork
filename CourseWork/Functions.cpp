#include <iostream>
#include <cmath>
#include "Functions.h"
using namespace std;
double length(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
bool has_only_digits(const string s)
{
	return (s.find_first_not_of("-,0123456789") == string::npos);
}
bool inLine(double x1, double y1, double x2, double y2, double x3, double y3)
{
	if ((x1 == x2) && (x2 == x3) || (y1 == y2) && (y2 == y3))return true;
	return((y3 - y1) / (y2 - y1) == ((x3 - x1) / (x2 - x1)));
}
