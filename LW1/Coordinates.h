#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

class Coordinates
{
public:
	double x, y;

public:
	Coordinates();
	Coordinates(double a, double b);
};

