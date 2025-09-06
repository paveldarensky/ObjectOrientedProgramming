#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "Coordinates.h"
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

class Rectangle
{
public:
	int len_a, len_b;
	Coordinates dotA;

public:
	Rectangle();
	Rectangle(Coordinates dot, double v, double u);

	void Input();	//1
	void Output();	//2

	int S();		//3
	int Perimeter();	//4
	double Radius();	//5
	bool Is_square();	//6
	Rectangle Mult(double);		//7
	bool Equality(Rectangle);	//8
	bool Likeness(Rectangle);	//9
	Coordinates Center();		//10

	bool Intersection(Rectangle);	//11
	Rectangle FindInterRec(const Rectangle, const Rectangle);

	void AllDots(Coordinates dotA, Coordinates dotB, Coordinates dotC, Coordinates dotD, double a, double b);

};
