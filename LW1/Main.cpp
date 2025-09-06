#include "iostream"
#include "Rectangle.h"
#include "Coordinates.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	Rectangle rec1, rec2;
	
	//1
	rec1.Input();
	cout << endl;

	//2
	rec1.Output();
	cout << endl;

	//3
	cout << "Площадь прямоугольника равна: " << rec1.S() << endl;

	//4
	cout << "Периметр прямоугольника равен: " << rec1.Perimeter() << endl;

	//5
	cout << "Радиус описанной окружности около прямоугольника равен: " << rec1.Radius() << endl;

	//6
	if (rec1.Is_square()) cout << "Является квадратом" << endl;
	else cout << "Не является квадратом" << endl;

	//7
	cout << "Введите число: ";
	double number;
	cin >> number;
	cout << endl;
	cout << "Получившийся новый прямоугольник:" << endl;
	rec1.Mult(number).Output();
	cout << endl;

	//8
	cout << "Введите данные для второго прямоугольника: " << endl;

	rec2.Input();
	cout << endl;

	if (rec1.Equality(rec2)) cout << "Прямоугольники равны" << endl;
	else cout << "Прямоугольники не равны" << endl;

	//9
	if (rec1.Likeness(rec2)) cout << "Прямоугольники подобны" << endl;
	else cout << "Прямоугольники не подобны" << endl;

	//10
	Coordinates O;
	O = rec1.Center();
	cout << "Центр описанной окружности около прямоугольника: O(" << O.x << ";" << O.y << ")" << endl;
	cout << endl;

	//11
	if (rec1.Intersection(rec2)) { cout << "Прямоугольники пересекаются!"; }
	else { cout << "Прямоугольники не пересекаются!"; }

	//12*
	if (rec1.Intersection(rec2)) 
	{
		cout << "Прямоугольник пересечения:\n";
		(rec1.FindInterRec(rec1, rec2)).Output();
	}
	else { cout << "Прямоугольники не пересекаются!"; }

	cout << "\n";
	int flag;
	cin >> flag;
}


