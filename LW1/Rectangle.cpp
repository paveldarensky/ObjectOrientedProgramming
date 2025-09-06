#include "iostream"
#include "Rectangle.h"
#include "Coordinates.h"
using namespace std;

Rectangle::Rectangle()
{
	Coordinates();
	len_a = 1;
	len_b = 1;
}

Rectangle::Rectangle(Coordinates dot, double a, double b)
{
	dotA.x = dot.x;
	dotA.y = dot.y;
	len_a = a;
	len_b = b;
}

void Rectangle::Input()
{
	cout << "Введите координаты точки А: ";
	cin >> dotA.x;
	cin >> dotA.y;

	cout << "Введите длину стороны a: ";
	cin >> len_a;
	cout << "Введите длину стороны b: ";
	cin >> len_b;

	cout << endl;
}

void Rectangle::Output()
{
	cout << "Координаты точки А : " << dotA.x << " " << dotA.y << endl;
	cout << "Длины сторон a и b : " << len_a << " " << len_b << endl;
}

int Rectangle::S()
{
	return (len_a * len_b);
}

int Rectangle::Perimeter()
{
	return (len_a * 2 + len_b * 2);
}

double Rectangle::Radius()
{
	return ((sqrt(len_a * len_a + len_b * len_b) / 2));
}

bool Rectangle::Is_square()
{
	//if (len_a == len_b) return true;
	//else return false;
	return (len_a == len_b);
}

Rectangle Rectangle::Mult(double num)
{
	Rectangle res;
	res.dotA = dotA;
	res.len_a = num * len_a;
	res.len_b = num * len_b;

	return res;

	//len_a *= num;
	//len_b *= num;
}

bool Rectangle::Equality(Rectangle rec2)
{
	if ((len_a == rec2.len_a) && (len_b == rec2.len_b)) return true;
	else return false;
}

bool Rectangle::Likeness(Rectangle rec2)
{
	if ((len_a / rec2.len_a) == (len_b / rec2.len_b)) return true;
	else return false;
}

Coordinates Rectangle::Center()
{
	Coordinates res;
	int x1, y1;
	x1 = dotA.x + len_a;
	y1 = dotA.y - len_b;

	res.x = (dotA.x + x1) / 2;
	res.y = (dotA.y + y1) / 2;

	return res;

	//dotA.x += len_a / 2;
	//dotA.y -= len_b / 2;
}

void Rectangle::AllDots(Coordinates dotA, Coordinates dotB, Coordinates dotC, Coordinates dotD, double a, double b)
{
	dotB.x = dotA.x + a;
	dotB.y = dotA.y;

	dotC.x = dotB.x;
	dotC.y = dotB.y - b;

	dotD.x = dotA.x;
	dotD.y = dotA.y - b;
}

bool Rectangle::Intersection(Rectangle R2)
{
	bool Ox, Oy, var1, var2;
	Ox = (dotA.x <= (R2.dotA.x + R2.len_a)) && ((dotA.x + len_a) >= R2.dotA.x);
	Oy= (dotA.y >= (R2.dotA.y - R2.len_b)) && ((dotA.y - len_b) <= R2.dotA.y);
	var1 = Ox && Oy;
	Ox = (R2.dotA.x <= (dotA.x + len_a)) && ((R2.dotA.x + R2.len_a) >= dotA.x);
	Oy = (R2.dotA.y >= (dotA.y - len_b)) && ((R2.dotA.y - R2.len_b) <= dotA.y);
	var2 = Ox && Oy;
	return (var1 || var2);
}

Rectangle Rectangle::FindInterRec(const Rectangle R1, const Rectangle R2)
{
	Rectangle res;
	res.dotA.x = max(R1.dotA.x, R2.dotA.x);
	res.dotA.y = min(R1.dotA.y, R2.dotA.y);

	res.len_a = abs(min(R1.dotA.x + R1.len_a, R2.dotA.x + R2.len_a) - res.dotA.x);
	res.len_b = abs(max(R1.dotA.y - R1.len_b, R2.dotA.y - R2.len_b) - res.dotA.y);

	return res;
}
