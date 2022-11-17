#include <SFML/Graphics.hpp>
#include<iostream>
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include"Rhombus.h"
#include"Trapeze.h"
#include"Functions.h"
#include <vector>
#include <conio.h>
#include "Polygon.h"
using namespace std;
using namespace sf;
int main()
{
	setlocale(LC_ALL, "ru-RU");
	char symbol;
	string quantity;
	while (true)
	{
		cout << "Введите количество фигур, которое планируете добавлять: ";
		cin >> quantity;
		if (!has_only_digits(quantity)) cout << "Ошибка! Введено некорректное значение!" << endl;
		else if (stod(quantity) <= 0) cout << "Ошибка! Количество должно быть больше 0!" << endl;
		else if (floor(stod(quantity)) != stod(quantity)) cout << "Ошибка! Количество должно быть целым!" << endl;
		else break;
	}
	vector<Figure*>Figures(stoi(quantity) - 1);
	Figures.clear();
	system("cls");
	while (true)
	{

		cout << "Что вы хотите сделать?" << endl;
		cout << "0 - Добавить фигуру" << endl;
		cout << "1 - Вывести данные" << endl;
		cout << "2 - Удалить фигуру" << endl;
		cout << "3 - Посмотреть свойства фигуры" << endl;
		cout << "4 - Изобразить фигуру" << endl;
		cout << "5 - Количество фигур" << endl;
		cout << "6 - Расстояние между центрами фигур" << endl;
		cout << "7 - Выход" << endl;
		cout << "Выберите необходимую цифру: ";
		symbol = _getch();
		cout << endl;
		switch (symbol)
		{
		case'0':
		{
			system("cls");
			cout << "Какую фигуру вы хотите добавить?" << endl;
			cout << "0 - Точка" << endl;
			cout << "1 - Отрезок" << endl;
			cout << "2 - Треугольник" << endl;
			cout << "3 - Квадрат" << endl;
			cout << "4 - Прямоугольник" << endl;
			cout << "5 - Ромб" << endl;
			cout << "6 - Круг" << endl;
			cout << "7 - Трапеция" << endl;
			cout << "8 - Многоугольник" << endl;
			cout << "Выберите необходимую цифру: ";
			symbol = _getch();
			switch (symbol)
			{
			case '0':
			{
				system("cls");
				string x, y;
				while (true)
				{
					cout << "Введите x: ";
					cin >> x;
					cout << "Введите y: ";
					cin >> y;
					if (has_only_digits(x) && has_only_digits(y))
					{
						Figures.push_back(new Point(stod(x), stod(y)));
						cout << "Элемент добавлен!" << endl;
						_getch();
						system("cls");
						break;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '1':
			{
				system("cls");
				string xs1, ys1, xs2, ys2;
				while (true)
				{
					cout << "Введите x1: ";
					cin >> xs1;
					cout << "Введите y1: ";
					cin >> ys1;
					cout << "Введите x2: ";
					cin >> xs2;
					cout << "Введите y2: ";
					cin >> ys2;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2);
						if (x1 != x2 || y1 != y2)
						{
							Figures.push_back(new Section(x1, y1, x2, y2));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Введены 2 одинаковые точки!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '2':
			{
				system("cls");
				string xs1, ys1, xs2, ys2, xs3, ys3;
				while (true)
				{
					cout << "Введите x1: ";
					cin >> xs1;
					cout << "Введите y1: ";
					cin >> ys1;
					cout << "Введите x2: ";
					cin >> xs2;
					cout << "Введите y2: ";
					cin >> ys2;
					cout << "Введите x3: ";
					cin >> xs3;
					cout << "Введите y3: ";
					cin >> ys3;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2) && has_only_digits(xs3) && has_only_digits(ys3))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2); double x3 = stod(xs3); double y3 = stod(ys3);
						if (!inLine(x1, y1, x2, y2, x3, y3))
						{
							Figures.push_back(new Triangle(stod(xs1), stod(ys1), stod(xs2), stod(ys2), stod(xs3), stod(ys3)));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! 3 точки лежат на одной прямой или какие-то точки совпадают!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			default:
			{
				system("cls");
				break;
			}
			case '3':
			{
				system("cls");
				string xs1, ys1, xs2, ys2;
				while (true)
				{
					cout << "Введите x левой верхней точки: ";
					cin >> xs1;
					cout << "Введите y левой верхней точки: ";
					cin >> ys1;
					cout << "Введите x правой нижней точки: ";
					cin >> xs2;
					cout << "Введите y правой нижней точки: ";
					cin >> ys2;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2);
						if (!(x1 == x2 && y1 == y2) && x2 - x1 == y1 - y2)
						{
							Figures.push_back(new Quadrate(x1, y1, x2, y2));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Точки лежат на одной прямой либо не образуют квадрат!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '4':
			{
				system("cls");
				string xs1, ys1, xs2, ys2;
				while (true)
				{
					cout << "Введите x левой верхней точки: ";
					cin >> xs1;
					cout << "Введите y левой верхней точки: ";
					cin >> ys1;
					cout << "Введите x правой нижней точки: ";
					cin >> xs2;
					cout << "Введите y правой нижней точки: ";
					cin >> ys2;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2);
						if (x1<x2 && y1>y2)
						{
							Figures.push_back(new Rectangle(x1, y1, x2, y2));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Точки лежат на одной прямой либо неправильно заданы координаты!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '5':
			{
				system("cls");
				string xs1, ys1, xs2, ys2;
				while (true)
				{
					cout << "Введите x левой точки: ";
					cin >> xs1;
					cout << "Введите y левой точки: ";
					cin >> ys1;
					cout << "Введите x верхней точки: ";
					cin >> xs2;
					cout << "Введите y верхней точки: ";
					cin >> ys2;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2);
						if (x1 < x2 && y1 < y2)
						{
							Figures.push_back(new Rhombus(x1, y1, x2, y2));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Точки лежат на одной прямой либо неправильно заданы координаты!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '6':
			{
				system("cls");
				string xs, ys, Rs;
				while (true)
				{
					cout << "Введите x центра окружности: ";
					cin >> xs;
					cout << "Введите y центра окружности: ";
					cin >> ys;
					cout << "Введите радиус: ";
					cin >> Rs;
					if (has_only_digits(xs) && has_only_digits(ys) && has_only_digits(Rs))
					{
						double x = stod(xs); double y = stod(ys); double R = stod(Rs);
						if (R > 0)
						{
							Figures.push_back(new Circle(x, y, R));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Радиус должен быть больше 0!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '7':
			{
				system("cls");
				string xs1, ys1, xs2, ys2, xs3, ys3, xs4, ys4;
				while (true)
				{
					cout << "Введите x левой нижней точки: ";
					cin >> xs3;
					cout << "Введите y левой нижней точки: ";
					cin >> ys3;
					cout << "Введите x левой верхней точки: ";
					cin >> xs1;
					cout << "Введите y левой  верхней точки: ";
					cin >> ys1;
					cout << "Введите x правой верхней точки: ";
					cin >> xs2;
					cout << "Введите y правой верхней точки: ";
					cin >> ys2;
					cout << "Введите x правой нижней точки: ";
					cin >> xs4;
					cout << "Введите y правой нижней точки: ";
					cin >> ys4;
					if (has_only_digits(xs1) && has_only_digits(ys1) && has_only_digits(xs2) && has_only_digits(ys2) && has_only_digits(xs3) && has_only_digits(ys3) && has_only_digits(xs4) && has_only_digits(ys4))
					{
						double x1 = stod(xs1); double y1 = stod(ys1); double x2 = stod(xs2); double y2 = stod(ys2); double x3 = stod(xs3); double y3 = stod(ys3); double x4 = stod(xs4); double y4 = stod(ys4);
						if ((x2 >= x1 && x4 >= x3 && y1 >= y3 && y2 >= y4) && (length(x1, y1, x2, y2) != length(x3, y3, x4, y4) || length(x1, y1, x3, y3) != length(x2, y2, x4, y4)) && !inLine(x1, y1, x2, y2, x3, y3) && (((x1 - x2) * (y3 - y4) == (y1 - y2) * (x3 - x4)) || ((x1 - x3) * (y2 - y4) == (y1 - y3) * (x2 - x4))))
						{
							Figures.push_back(new Trapeze(x1, y1, x2, y2, x3, y3, x4, y4));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Точки лежат на одной прямой либо неправильно заданы координаты!" << endl;
					}
					else cout << "Ошибка! Введены некорректные значения! Попробуйте ещё раз" << endl;
				}
				break;
			}
			case '8':
			{
				system("cls");
				string x, y;
				int k;
				bool t = true;
				while (true)
				{

					string sn;
					k = 1;
					while (true)
					{
						cout << "Введите количество вершин многоугольника: ";
						cin >> sn;
						if (has_only_digits(sn) && stod(sn) > 0 && floor(stod(sn)) == stod(sn))break;
						else cout << "Некорректно введено значение!" << endl;
					}
					int n = stoi(sn);
					Point* Points = new Point[n];
					for (int i = 0;i < n;i++)
					{

						while (true)
						{
							t = true;
							cout << "Введите x" << k << ": ";
							cin >> x;
							if (has_only_digits(x))Points[i].SetX(stod(x));
							else t = false;
							cout << "Введите y" << k << ": ";
							cin >> y;
							if (has_only_digits(y))Points[i].SetY(stod(y));
							else t = false;
							if (t == true)
							{
								k++;
								break;
							}
							else cout << "Введены некорректные данные!" << endl;
						}
					}
					if (n < 3)
					{
						Figures.push_back(new Polygon(n, Points));
						cout << "Элемент добавлен!" << endl;
						_getch();
						system("cls");
						break;
					}
					else
					{
						t = true;
						for (int i = 0;i < n - 2;i++)
						{
							if (inLine(Points[i].GetX(), Points[i].GetY(), Points[i + 1].GetX(), Points[i + 1].GetY(), Points[i + 2].GetX(), Points[i + 2].GetY()))t = false;
						}
						if (n > 3 && inLine(Points[n - 2].GetX(), Points[n - 2].GetY(), Points[n - 1].GetX(), Points[n - 1].GetY(), Points[0].GetX(), Points[0].GetY()))t = false;
						if (n > 3 && inLine(Points[0].GetX(), Points[0].GetY(), Points[1].GetX(), Points[1].GetY(), Points[n - 1].GetX(), Points[n - 1].GetY()))t = false;
						if (t == true)
						{
							Figures.push_back(new Polygon(n, Points));
							cout << "Элемент добавлен!" << endl;
							_getch();
							system("cls");
							break;
						}
						else cout << "Ошибка! Точки лежат на одной прямой!" << endl;
					}
				}
				break;
			}
			}
			break;
		}
		case '1':
		{
			if (Figures.size() == 0)
			{
				cout << "Ошибка! Вектор пуст!" << endl;
				_getch();
				system("cls");
				break;
			}
			system("cls");
			cout << "Хотите вывести все элементы или определенный элемент?(0 - определенный, 1 - все)" << endl;
			symbol = _getch();
			switch (symbol)
			{
			case '0':
			{
				cout << "Введите номер элемента(начиная с 0): ";
				string n;
				cin >> n;
				if (!has_only_digits(n)) cout << "Ошибка! Введено некорректное значение!" << endl;
				else if (stod(n) < 0) cout << "Ошибка! Номер должен быть неотрицательным!" << endl;
				else if (floor(stod(n)) != stod(n)) cout << "Ошибка! Номер должен быть целым!" << endl;
				else if (Figures.size() > stoi(n))Figures[stoi(n)]->Show();
				else cout << "Ошибка! Слишком большое значение! На данный момент в векторе " << Figures.size() << " элемент(-а/-ов)" << endl;
				_getch();
				system("cls");
				break;
			}
			case '1':
			{
				int k = 1;
				for (int i = 0;i < Figures.size();i++, k++)
				{
					cout << "Элемент " << k << endl;
					Figures[i]->Show();
				}
				_getch();
				system("cls");
				break;
			}
			default:
			{
				system("cls");
				break;
			}
			}
			break;
		}
		case '2':
		{
			if (Figures.size() == 0)
			{
				cout << "Ошибка! Вектор пуст!" << endl;
				_getch();
				system("cls");
				break;
			}
			system("cls");
			cout << "Хотите удалить все элементы или определенный элемент?(0 - определенный, 1 - все)" << endl;
			symbol = _getch();
			if (symbol == '0')
			{
				cout << "Введите номер элемента(начиная с 0): ";
				string n;
				cin >> n;
				if (!has_only_digits(n)) cout << "Ошибка! Введено некорректное значение!" << endl;
				else if (stod(n) < 0) cout << "Ошибка! Номер должен быть неотрицательным!" << endl;
				else if (floor(stod(n)) != stod(n)) cout << "Ошибка! Номер должен быть целым!" << endl;
				else if (Figures.size() > stoi(n))
				{
					delete Figures[stoi(n)];
					Figures.erase(Figures.begin() + stoi(n));
					cout << "Элемент удалён!" << endl;
				}
				else cout << "Ошибка! Слишком большое значение! На данный момент в векторе " << Figures.size() << " элемент(-а/-ов)" << endl;
				_getch();
				system("cls");
				break;
			}
			else if (symbol == '1')
			{
				for (int i = 0;i < Figures.size();i++) delete Figures[i];
				Figures.clear();
				cout << "Вектор очищен!" << endl;
				_getch();
				system("cls");
				break;
			}
			else
			{
				system("cls");
				break;
			}
		}
		case '3':
		{
			if (Figures.size() == 0)
			{
				cout << "Ошибка! Вектор пуст!" << endl;
				_getch();
				system("cls");
				break;
			}
			system("cls");
			string sn;
			cout << "Введите номер элемента, свойства которого хотите посмотреть: ";
			cin >> sn;
			if (!has_only_digits(sn)) cout << "Ошибка! Введено некорректное значение!" << endl;
			else if (stod(sn) < 0) cout << "Ошибка! Номер должен быть неотрицательным!" << endl;
			else if (floor(stod(sn)) != stod(sn)) cout << "Ошибка! Номер должен быть целым!" << endl;
			else if (Figures.size() > stoi(sn))
			{
				int n = stoi(sn);
				cout << typeid(*Figures[n]).name() << endl;
				cout << "Периметр:" << Figures[n]->Perimeter() << endl;
				cout << "Площадь:" << Figures[n]->Square() << endl;
				cout << "Координаты центра:(" << Figures[n]->Center().first << ";" << Figures[n]->Center().second << ")" << endl;
				if (typeid(*Figures[n]) == typeid(Triangle))
				{
					cout << "Является прямоугольным? ";
					if (dynamic_cast<Triangle*>(Figures[n])->Rectangular()) cout << "Да" << endl;
					else cout << "Нет" << endl;
					cout << "Является равнобедренным? ";
					if (dynamic_cast<Triangle*>(Figures[n])->Isosceles()) cout << "Да" << endl;
					else cout << "Нет" << endl;
					cout << "Является равносторонним? ";
					if (dynamic_cast<Triangle*>(Figures[n])->equilateral()) cout << "Да" << endl;
					else cout << "Нет" << endl;
				}
				else if (typeid(*Figures[n]) == typeid(Rectangle))
				{
					cout << "Является квадратом? ";
					if (dynamic_cast<Rectangle*>(Figures[n])->IsSquare()) cout << "Да" << endl;
					else cout << "Нет" << endl;
				}
				else if (typeid(*Figures[n]) == typeid(Rhombus))
				{
					cout << "Является квадратом? ";
					if (dynamic_cast<Rhombus*>(Figures[n])->IsSquare()) cout << "Да" << endl;
					else cout << "Нет" << endl;
				}
				else if (typeid(*Figures[n]) == typeid(Trapeze))
				{
					cout << "Является прямоугольной? ";
					if (dynamic_cast<Trapeze*>(Figures[n])->Rectangular()) cout << "Да" << endl;
					else cout << "Нет" << endl;
					cout << "Является равнобедренной? ";
					if (dynamic_cast<Trapeze*>(Figures[n])->Isosceles()) cout << "Да" << endl;
					else cout << "Нет" << endl;
				}
			}
			else cout << "Ошибка! Слишком большое значение! На данный момент в векторе " << Figures.size() << " элемент(-а/-ов)" << endl;
			_getch();
			system("cls");
			break;
		}
		case '4':
		{
			if (Figures.size() == 0)
			{
				cout << "Ошибка! Вектор пуст!" << endl;
				_getch();
				system("cls");
				break;
			}
			system("cls");
			string sn;
			cout << "Введите номер элемента, который хотите изобразить: ";
			cin >> sn;
			if (!has_only_digits(sn)) cout << "Ошибка! Введено некорректное значение!" << endl;
			else if (stod(sn) < 0) cout << "Ошибка! Номер должен быть неотрицательным!" << endl;
			else if (floor(stod(sn)) != stod(sn)) cout << "Ошибка! Номер должен быть целым!" << endl;
			else if (Figures.size() > stoi(sn))
			{
				int n = stoi(sn);
				ContextSettings settings;
				settings.antialiasingLevel = 8;
				RenderWindow window(VideoMode(500, 500), "CourseWork", Style::Default, settings);
				while (window.isOpen())
				{
					Event event;
					while (window.pollEvent(event))
					{
						if (event.type == Event::Closed)
							window.close();
					}
					window.clear(Color(250, 220, 100, 0));
					if (typeid(*Figures[n]) == typeid(Quadrate) || typeid(*Figures[n]) == typeid(Rectangle) || typeid(*Figures[n]) == typeid(Rhombus))
					{
						ConvexShape rectangle;
						Point Points[2];
						dynamic_cast<Section*>(Figures[n])->GetPoints(Points);
						rectangle.setPointCount(4);
						double x1 = Points[0].GetX();
						double y1 = Points[0].GetY();
						double x2 = Points[1].GetX();
						double y2 = Points[1].GetY();
						rectangle.setPoint(0, Vector2f(250 + x1, 250 - y1));
						if (typeid(*Figures[n]) == typeid(Rhombus))
						{
							rectangle.setPoint(1, Vector2f(250 + x2, 250 - y2));
							rectangle.setPoint(2, Vector2f(250 + (2 * x2 - x1), 250 - y1));
							rectangle.setPoint(3, Vector2f(250 + x2, 250 - (2 * y1 - y2)));
						}
						else
						{
							rectangle.setPoint(1, Vector2f(250 + x2, 250 - y1));
							rectangle.setPoint(2, Vector2f(250 + x2, 250 - y2));
							rectangle.setPoint(3, Vector2f(250 + x1, 250 - y2));
						}
						rectangle.setFillColor(Color::Black);
						window.draw(rectangle);
					}
					else if (typeid(*Figures[n]) == typeid(Circle) || typeid(*Figures[n]) == typeid(Point))
					{
						double R;
						if (typeid(*Figures[n]) == typeid(Circle)) R = dynamic_cast<Circle*>(Figures[n])->GetR();
						else R = 10;
						CircleShape circle(R);
						double x1 = dynamic_cast<Point*>(Figures[n])->GetX();
						double y1 = dynamic_cast<Point*>(Figures[n])->GetY();
						circle.move(250 - R + x1, 250 - R - y1);
						circle.setFillColor(Color::Black);
						window.draw(circle);
					}
					else if (typeid(*Figures[n]) == typeid(Triangle))
					{
						ConvexShape triangle;
						Point Points[3];
						dynamic_cast<Triangle*>(Figures[n])->GetPoints(Points);
						triangle.setPointCount(3);
						double x1 = Points[0].GetX();
						double y1 = Points[0].GetY();
						double x2 = Points[1].GetX();
						double y2 = Points[1].GetY();
						double x3 = Points[2].GetX();
						double y3 = Points[2].GetY();
						triangle.setPoint(0, Vector2f(250 + x1, 250 - y1));
						triangle.setPoint(1, Vector2f(250 + x2, 250 - y2));
						triangle.setPoint(2, Vector2f(250 + x3, 250 - y3));
						triangle.setFillColor(Color::Black);
						window.draw(triangle);
					}
					else if (typeid(*Figures[n]) == typeid(Section))
					{
						Point Points[2];
						dynamic_cast<Section*>(Figures[n])->GetPoints(Points);
						double x1 = Points[0].GetX();
						double y1 = Points[0].GetY();
						double x2 = Points[1].GetX();
						double y2 = Points[1].GetY();
						Vertex section[] =
						{
							Vertex(Vector2f(250 + x1,250 - y1)),
							Vertex(Vector2f(250 + x2,250 - y2))
						};
						section->color = Color::Black;
						window.draw(section, 2, Lines);
					}
					else if (typeid(*Figures[n]) == typeid(Trapeze))
					{
						ConvexShape trapeze;
						Point Points[4];
						dynamic_cast<Trapeze*>(Figures[n])->GetPoints(Points);
						trapeze.setPointCount(4);
						double x1 = Points[0].GetX();
						double y1 = Points[0].GetY();
						double x2 = Points[1].GetX();
						double y2 = Points[1].GetY();
						double x3 = Points[2].GetX();
						double y3 = Points[2].GetY();
						double x4 = Points[3].GetX();
						double y4 = Points[3].GetY();
						trapeze.setPoint(0, Vector2f(250 + x3, 250 - y3));
						trapeze.setPoint(1, Vector2f(250 + x1, 250 - y1));
						trapeze.setPoint(2, Vector2f(250 + x2, 250 - y2));
						trapeze.setPoint(3, Vector2f(250 + x4, 250 - y4));
						trapeze.setFillColor(Color::Black);
						window.draw(trapeze);
					}
					else if (typeid(*Figures[n]) == typeid(Polygon))
					{
						int count = dynamic_cast<Polygon*>(Figures[n])->GetN();
						Point* Points = dynamic_cast<Polygon*>(Figures[n])->GetPoints();
						if (count == 1)
						{
							CircleShape polygon(10);
							polygon.move(240 + Points[0].GetX(), 240 - Points[0].GetY());
							polygon.setFillColor(Color::Black);
							window.draw(polygon);
						}
						else if (count == 2)
						{
							Vertex polygon[] =
							{
								Vertex(Vector2f(250 + Points[0].GetX(),250 - Points[0].GetY())),
								Vertex(Vector2f(250 + Points[1].GetX(),250 - Points[1].GetY()))
							};
							polygon->color = Color::Black;
							window.draw(polygon, 2, Lines);
						}
						else
						{
							ConvexShape polygon;
							polygon.setPointCount(count);
							for (int i = 0;i < count;i++)
							{
								polygon.setPoint(i, Vector2f(250 + Points[i].GetX(), 250 - Points[i].GetY()));
							}
							polygon.setFillColor(Color::Black);
							window.draw(polygon);
						}
					}
					window.display();
				}
			}
			else cout << "Ошибка! Слишком большое значение! На данный момент в векторе " << Figures.size() << " элемент(а/ов)" << endl;
			_getch();
			system("cls");
			break;
		}
		case '5':
		{
			cout << "На данный момент в векторе " << Figures.size() << " фигур(-а/-ы)" << endl;
			_getch();
			system("cls");
			break;
		}
		case '6':
		{
			if (Figures.size() == 0)
			{
				cout << "Ошибка! Вектор пуст!" << endl;
				_getch();
				system("cls");
				break;
			}
			system("cls");
			cout << "Введите номер 1 элемента(начиная с 0): ";
			string sn1, sn2;
			cin >> sn1;
			cout << "Введите номер 2 элемента(начиная с 0): ";
			cin >> sn2;
			if (!has_only_digits(sn1) || !has_only_digits(sn2)) cout << "Ошибка! Введено некорректное значение!" << endl;
			else if (stod(sn1) < 0 || stod(sn2) < 0) cout << "Ошибка! Номер должен быть неотрицательным!" << endl;
			else if (floor(stod(sn1)) != stod(sn1) || floor(stod(sn2)) != stod(sn2)) cout << "Ошибка! Номер должен быть целым!" << endl;
			else if (Figures.size() > stoi(sn1) && Figures.size() > stoi(sn2))
			{
				int n1 = stoi(sn1), n2 = stoi(sn2);
				double x1 = Figures[n1]->Center().first;
				double y1 = Figures[n1]->Center().second;
				double x2 = Figures[n1]->Center().first;
				double y2 = Figures[n2]->Center().second;
				cout << "Координаты центра первой фигуры:(" << x1 << ";" << y1 << ")" << endl;
				cout << "Координаты центра второй фигуры:(" << x2 << ";" << y2 << ")" << endl;
				cout << "Расстояние между центрами фигур: " << length(x1, y1, x2, y2) << endl;
			}
			else cout << "Ошибка! Слишком большое значение! На данный момент в векторе " << Figures.size() << " элемент(-а/-ов)" << endl;
			_getch();
			system("cls");
			break;
		}
		case '7':
		{
			return 0;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}