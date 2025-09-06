#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

class Array
{
private:
	int* a, n;
public:
	Array();		//конструктор по умолчанию
	Array(int m);	//конструктор с целым аргументом (m – число элементов в массиве)

	Array(int* b, int m);	//конструктор с аргументом, m – число элементов в массиве b

	Array(const Array& x);		//конструктор копирования
	Array& operator=(const Array& x);	//операция присвоения
	~Array();	//деструктор

	void Scan(int m);	//ввод массива из m чисел
	void Print();		//вывод массива
	int& operator [](int i);	//считывание элемента по позиции
	int FindKey(int key);		//поиск элемента key в массиве (возвращает индекс key или -1)

	Array& operator += (int key);	//добавляет key в конец массива a
	Array operator + (int key);		//формирует массив b = a + key (key добавляется в конец)

	Array& operator += (Array);		//добавление массива в конец массива a
	Array operator + (Array);		//формирует массив y=a+x

	Array& operator -=(int key);	//удаление элемента key
	Array operator -(int key);		//формирует новый массив b = a - key

	Array& DelPosEq(int pos);		//удаление элемента с позиции pos
	Array DelPosNew(int pos);		//формирует новый массив b, в котором удален элемент с позиции pos

	bool operator == (Array);		//проверка равенства массивов
	bool operator != (Array);		//проверка неравенства массивов

	int Max();						//нахождение максимума в массиве, возвращает индекс максимального элемента
	int Min();						// нахождение минимума в массиве

	void Sorting();					//сортировка массива

	friend ostream& operator << (ostream& r, Array& x);
	friend istream& operator >> (istream& r, Array& x);

private:
	void ShiftLeft(int pos);		 //сдвиг влево, начиная с позиции pos+1

public:
	void Randomizer();		//generate random array
};