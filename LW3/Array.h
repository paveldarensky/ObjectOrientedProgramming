#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

template <class T> class Array
{
private:
	T* a; int n;
public:
	Array(int m = 0);	//конструктор по умолчанию или с целым аргументом (m – число элементов в массиве)

	Array(pair<T* , int > p);	//конструктор с аргументом, m – число элементов в массиве b

	Array(const Array <T>& x);		//конструктор копирования
	Array& operator=(const Array <T>& x);	//операция присвоения
	~Array();	//деструктор

	void Scan(int m);	//ввод массива из m чисел
	void Print();		//вывод массива
	T& operator [](int i);	//считывание элемента по позиции
	int FindKey(T key);		//поиск элемента key в массиве (возвращает индекс key или -1)

	Array <T>& operator += (T key);	//добавляет key в конец массива a
	Array <T> operator + (T key);		//формирует массив b = a + key (key добавляется в конец)

	Array <T>& operator += (Array <T>);		//добавление массива в конец массива a
	Array <T> operator + (Array <T>);		//формирует массив y=a+x

	Array <T>& operator -=(T key);	//удаление элемента key
	Array <T> operator -(T key);		//формирует новый массив b = a - key

	Array <T>& DelPosEq(int pos);		//удаление элемента с позиции pos
	Array <T> DelPosNew(int pos);		//формирует новый массив b, в котором удален элемент с позиции pos

	bool operator == (Array <T>);		//проверка равенства массивов
	bool operator != (Array <T>);		//проверка неравенства массивов

	int Max();						//нахождение максимума в массиве, возвращает индекс максимального элемента
	int Min();						// нахождение минимума в массиве

	void Sorting();					//сортировка массива

	template <class T> friend ostream& operator << (ostream& r, Array <T>& x);
	template <class T> friend istream& operator >> (istream& r, Array <T>& x);

private:
	void ShiftLeft(int pos);		 //сдвиг влево, начиная с позиции pos+1

public:
	void Randomizer();		//generate random array
};

template <class T> Array <T>::Array(int m)
{
	n = max(0, m);
	a = new T[n];
	fill(a, a + n, 0);
}

template <class T> Array <T>::Array(pair<T*, int > p)
{
	n = max(0, p.second);
	a = new T[n];
	copy(p.first, p.first + n, a);
}

template <class T> Array <T>::Array(const Array <T>& x)
	: Array(make_pair(x.a, x.n))
{
}

template <class T> Array <T> & Array <T>:: operator = (const Array <T>& x)
{
	n = x.n;
	delete []a;
	a = new T[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = x.a[i];
	}
	return *this;
}

template <class T> Array <T>::~Array()
{
	delete[]a;
}

template <class T> void Array<T>::Scan(int m)
{
	if (m > 0)
	{
		cout << "Введите данные массива: \n";
		n = m;
		delete[] a;
		a = new T[n];
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
	}
	else { cout << "Массив нечем заполнять, длина равна 0!\n"; }
}

template <class T> void Array<T>::Print()
{
	if (n > 0)
	{
		cout << "Данные массива: \n";
		cout << "Длина массива = " << n << "\n";
		cout << "Элементы массива: ";
		for (int i = 0;i < n;i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	else { cout << "Массив пуст!\n"; }
}

template <class T> T& Array <T>:: operator [] (int i)
{
	if ((i < 0) || (i >= n)) { cout << "\nИндекс за пределами!\n"; exit(0); }
	return	a[i];
}

template <class T> int Array<T>::FindKey(T key)
{
	int ind = -1;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == key) ind = i;
	}
	return ind;
}

template <class T> Array <T>& Array <T>:: operator +=(T key)
{
	T* v;
	v = a;
	n++;
	a = new T[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = v[i];
	}
	delete[] v;
	a[n - 1] = key;
	return *this;
}

template <class T> Array <T> Array <T>:: operator +(T key)
{
	Array<T> b(*this);
	b += key;
	return b;
}

template <class T> Array <T>& Array <T>:: operator +=(Array<T> u)
{
	T* MasNew = new T[n + u.n];
	int k = 0;
	for (int i = 0;i < n;i++)
	{
		MasNew[k] = a[i];
		k++;
	}
	for (int i = 0;i < u.n;i++)
	{
		MasNew[k] = u.a[i];
		k++;
	}
	delete[]a;
	a = MasNew;
	n += u.n;
	return *this;
}

template <class T> Array <T> Array <T>:: operator +(Array<T> u)
{
	Array<T> res(*this);
	res += u;
	return res;
}

template <class T> Array <T>& Array <T>:: operator -=(T key)
{
	Array<T> newMas = *this;
	delete[] a;
	n = newMas.n - 1;
	a = new T[n];
	for (int i = 0;i < n;i++)
	{
		if (newMas[i + 1] != key) a[i] = newMas[i + 1];
	}
	return *this;
}

template <class T> Array <T> Array <T>:: operator -(T key)
{
	Array<T> b(*this);
	b -= key;
	return b;
}

template <class T> Array <T>& Array <T>::DelPosEq(int pos)
{
	T* masiv = new T[n - 1];
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		if (i != pos) { masiv[j] = a[i];j++; }
	}
	n--;
	delete[] a;
	a = masiv;
	return *this;
}

template <class T> Array <T> Array <T>::DelPosNew(int pos)
{
	Array<T> res(*this);
	res.DelPosEq(pos);
	return res;
}

template <class T> bool Array<T>::operator ==(Array<T> b)
{
	int count = 0;
	if (n == b.n)
	{
		for (int i = 0;i < n;i++)
		{
			if (a[i] == b.a[i]) count++;
		}
		if (n == count) return true;
	}
}

template <class T> bool Array<T>::operator !=(Array<T> b)
{
	if (*this == b) { return false; }
	else return true;
}

template <class T> int Array<T>::Max()
{
	if (n <= 0)
	{
		return -1;
	}

	T M = a[0];
	int j = 0;
	for (int i = 1;i < n;i++)
	{
		if (M <= a[i]) { M = a[i]; j = i; }
	}
	return j;
}

template <class T> int Array<T>::Min()
{
	if (n > 0)
	{
		T M = a[0], j = -1;
		for (int i = 0;i < n;i++)
		{
			if (a[i] <= M) { M = a[i]; j = i; }
		}
		return j;
	}
	else return -1;
}

template <class T> void Array<T>::Sorting()
{
	T p;
	int k;
	for (int j = 0;j < n - 1;j++)
	{
		k = j;
		while ((k > (-1)) && (a[k] > a[k + 1]))
		{
			p = a[k];
			a[k] = a[k + 1];
			a[k + 1] = p;
			k--;
		}
	}
}

template <class T> ostream& operator << (ostream& r, Array<T>& x)
{
	for (int i = 0;i < x.n;i++)
	{
		r << x.a[i] << " ";
	}
	return r;
}

template <class T> istream& operator >> (istream& r, Array<T>& x)
{
	for (int i = 0;i < x.n;i++)
	{
		r >> x.a[i];
	}
	return r;
}

template <class T> void Array<T>::ShiftLeft(int pos) {
	for (int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
}

template <class T> void Array<T>::Randomizer()
{
	srand(time(0));
	for (int i = 0;i < n;i++)
	{
		a[i] = -10 + rand() % (10 - (-10) + 1);
	}
}