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
	cout << "������� �������������� �����: " << rec1.S() << endl;

	//4
	cout << "�������� �������������� �����: " << rec1.Perimeter() << endl;

	//5
	cout << "������ ��������� ���������� ����� �������������� �����: " << rec1.Radius() << endl;

	//6
	if (rec1.Is_square()) cout << "�������� ���������" << endl;
	else cout << "�� �������� ���������" << endl;

	//7
	cout << "������� �����: ";
	double number;
	cin >> number;
	cout << endl;
	cout << "������������ ����� �������������:" << endl;
	rec1.Mult(number).Output();
	cout << endl;

	//8
	cout << "������� ������ ��� ������� ��������������: " << endl;

	rec2.Input();
	cout << endl;

	if (rec1.Equality(rec2)) cout << "�������������� �����" << endl;
	else cout << "�������������� �� �����" << endl;

	//9
	if (rec1.Likeness(rec2)) cout << "�������������� �������" << endl;
	else cout << "�������������� �� �������" << endl;

	//10
	Coordinates O;
	O = rec1.Center();
	cout << "����� ��������� ���������� ����� ��������������: O(" << O.x << ";" << O.y << ")" << endl;
	cout << endl;

	//11
	if (rec1.Intersection(rec2)) { cout << "�������������� ������������!"; }
	else { cout << "�������������� �� ������������!"; }

	//12*
	if (rec1.Intersection(rec2)) 
	{
		cout << "������������� �����������:\n";
		(rec1.FindInterRec(rec1, rec2)).Output();
	}
	else { cout << "�������������� �� ������������!"; }

	cout << "\n";
	int flag;
	cin >> flag;
}


