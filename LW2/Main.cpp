#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "Array.h"
using namespace std;

#define _USE_MATH_DEFINES //все математические константы
#include <math.h>

void main()
{
	setlocale(LC_ALL, "rus");

	//1
	cout << "Task 1\n";
	Array mas1;
	int len;
	cout << "Введите длину массива: ";
	cin >> len;
	mas1.Scan(len);
	mas1.Print();

	//2
	cout << "\nTask 2\n";
	Array mas2 = mas1;
	cout << mas2;
	cout << "\n";

	//3
	cout << "\nTask 3\n";
	if (mas1 == mas2) { cout << "Массивы равны!\n"; }
	else { cout << "Массивы не равны!\n"; mas1.Print(); mas2.Print(); }

	//4
	cout << "\nTask 4\n";
	int key = 6;
	mas1 += key;
	cout << "Изменённый массив\n";
	mas1.Print();

	cout << "Сравнение mas1 и mas2\n";

	if (mas1 == mas2) { cout << "Массивы равны!\n"; }
	else { cout << "Массивы не равны!\n"; mas1.Print(); mas2.Print(); }

	//5
	cout << "\nTask 5\n";
	key = 7;
	Array mas3 = mas1 + key;
	cout << mas3 << "\n";

	//6
	cout << "\nTask 6\n";
	mas3.DelPosEq(0);
	mas3.Print();

	//7
	cout << "\nTask 7\n";
	Array mas4 = mas3.DelPosEq(-1);
	mas4.Print();

	//8
	cout << "\nTask 8\n";
	key = 1;
	//mas1 -= key;
	mas1.DelPosEq(mas1.FindKey(key));
	mas1.Print();
	if (mas1 == mas4) { cout << "Массивы равны!\n"; }
	else { cout << "Массивы не равны!\n"; mas1.Print(); mas4.Print(); }

	//9
	cout << "\nTask 9\n";
	int n;
	cout << "Введите число n: ";
	cin >> n;
	Array b(n);
	b.Randomizer();
	//b.Print();
	Array mas5(b);
	mas5.Print();

	//10
	cout << "\nTask 10\n";
	cout << "Максимальный элемент в массиве равен " << mas5[mas5.Max()] << " с индексом " << mas5.Max() << "\n";
	cout << "Минимальный элемент в массиве равен " << mas5[mas5.Min()] << " с индексом " << mas5.Min() << "\n";

	//11
	cout << "\nTask 11\n";
	mas5.Sorting();
	mas5.Print();

	//12
	cout << "\nTask 12\n";
	Array mas6 = mas1 + mas5;
	mas6.Print();

	//13
	cout << "\nTask 13\n";
	Array mas7(4);
	cin >> mas7;
	mas7.Print();

	//14
	cout << "\nTask 14\n";
	if ((mas7.FindKey(1) != -1) && (mas7.FindKey(10) != -1)) { cout << "Элементы 1 и 10 входят в массив\n"; }
	else { cout << "Один из элементов (1 или 10) не входит в массив\n"; mas7.Print(); }
	Array mas8 = mas7 - 10;
	//Array mas8 = mas7.DelPosEq(mas7.FindKey(10));
	mas8.Print();

	//15
	cout << "\nTask 15\n";
	mas4 += mas7;
	mas4.Print();
	if (mas6 == mas4) { cout << "Массивы равны!\n"; }
	else { cout << "Массивы не равны!\n"; mas6.Print(); mas4.Print(); }

	//16
	cout << "\nTask 16\n";
	cout << "Массив ДО:\n";
	mas4.Print();
	mas4 = mas6;
	cout << "Массив ПОСЛЕ:\n";
	mas4.Print();

	int flag;
	cin >> flag;
}

