#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "Array.h"
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

Array::Array()
{
	//a = NULL; //nullptr
	//n = 0;

	n = 1;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = 0;
	}
}

Array::Array(int m)
{
	n = m;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = 0;
	}
}

Array::Array(int* b, int m)
{
	a = b;		//
	n = m;
}

Array::Array(const Array& x)
{
	n = x.n;
	a = new int[n];
	for (int i = 0; i < n;i++)
	{
		a[i] = x.a[i];
	}
}

Array& Array :: operator = (const Array& x)
{
	n = x.n;
	delete[] a;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = x.a[i];
	}
	return *this;
}

Array::~Array()
{
	delete[]a;
}

void Array::Scan(int m)
{
	cout << "Введите данные массива: \n";
	n = m;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
}

void Array::Print()
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

int& Array:: operator [] (int i)
{
	if ((i < 0) || (i >= n)) { cout << "\nИндекс за пределами!\n"; exit(0); }
	return	a[i];
}

int Array::FindKey(int key)
{
	//if (find(0, n - 1, key) != (n - 1)) { cout << "Элемент не найден!"; }
	//else { return find(0, n - 1, key); }

	int ind = -1;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == key) ind = i;
	}
	return ind;
}

Array& Array:: operator +=(int key)
{
	int* v;
	v = a;
	n++;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = v[i];
	}
	a[n - 1] = key;
	return *this;
}

Array Array:: operator +(int key)
{
	Array b;
	b.n = n + 1;
	b.a = new int[b.n];
	for (int i = 0;i < b.n;i++)			//+=
	{
		b.a[i] = a[i];
	}
	b.a[b.n - 1] = key;
	return b;
}

Array& Array:: operator +=(Array u)
{
	int* MasNew = new int[n + u.n];
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

Array Array:: operator +(Array u)
{
	Array res;
	res.n = n + u.n;
	res.a = new int[res.n];
	for (int i = 0;i < n;i++)
	{
		res.a[i] = a[i];					//+=
	}
	for (int i = n;i < n + u.n;i++)
	{
		res.a[i] = u.a[i - n];
	}
	return res;
}

Array& Array:: operator -=(int key)
{
	Array newMas = *this;
	delete[] a;
	n = newMas.n - 1;
	a = new int[n];
	for (int i = 0;i < n;i++)
	{
		if (newMas[i + 1] != key) a[i] = newMas[i + 1];
	}
	return *this;
}

Array Array:: operator -(int key)
{
	Array b;
	b.n = n - 1;
	b.a = new int[b.n];
	for (int i = 0;i < b.n;i++)
	{
		if (a[i + 1] != key) b.a[i] = a[i + 1];
	}
	return b;
}

Array& Array::DelPosEq(int pos)
{
	Array newMas = *this;			//1 copy
	delete[] a;
	n--;
	a = new int[n];
	int j = 0;
	for (int i = 0;i < newMas.n;i++)
	{
		if (i != pos) { a[j] = newMas[i];j++; }
	}
	return *this;
}

Array Array::DelPosNew(int pos)
{
	Array res;
	res.n = n - 1;
	res.a = new int[res.n];
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		if (i != pos) { res.a[j] = a[i];j++; }
	}
	return res;
}

bool Array::operator ==(Array b)
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

bool Array::operator !=(Array b)
{
	int count = 0;
	if (n != b.n) return true;
	if (n == b.n)
	{
		for (int i = 0;i < n;i++)
		{
			if (a[i] != b.a[i]) return true;
		}
	}
}

int Array::Max()
{
	int M = -1000, j = -1;
	for (int i = 0;i < n;i++)
	{
		if (M <= a[i]) { M = a[i]; j = i; }
	}
	return j;
}

int Array::Min()
{
	int M = 1000, j = -1;
	for (int i = 0;i < n;i++)
	{
		if (a[i] <= M) { M = a[i]; j = i; }
	}
	return j;
}

void Array::Sorting()
{
	int p, k;
	for (int j = 0;j < n - 1;j++)
	{
		k = j;
		while ((k >(-1)) && (a[k] > a[k + 1]))
		{
			p = a[k];
			a[k] = a[k + 1];
			a[k + 1] = p;
			k--;
		}
	}
}

ostream& operator << (ostream& r, Array& x)
{
	//r << "Данные массива: ";
	for (int i = 0;i < x.n;i++)
	{
		r << x.a[i] << " ";
	}
	return r;
}

istream& operator >> (istream& r, Array& x)
{
	//cout << "\nВведите значение элемента массива: ";
	for (int i = 0;i < x.n;i++)
	{
		r >> x.a[i];
	}
	return r;
}

void Array::ShiftLeft(int pos) {
	for (int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
}

void Array::Randomizer()
{
	for (int i = 0;i < n;i++)
	{
		a[i] = -10 + rand() % (10 - (-10) + 1);			//srand
	}
}
