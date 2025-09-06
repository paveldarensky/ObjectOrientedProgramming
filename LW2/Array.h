#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define _USE_MATH_DEFINES //��� �������������� ���������
#include <math.h>

class Array
{
private:
	int* a, n;
public:
	Array();		//����������� �� ���������
	Array(int m);	//����������� � ����� ���������� (m � ����� ��������� � �������)

	Array(int* b, int m);	//����������� � ����������, m � ����� ��������� � ������� b

	Array(const Array& x);		//����������� �����������
	Array& operator=(const Array& x);	//�������� ����������
	~Array();	//����������

	void Scan(int m);	//���� ������� �� m �����
	void Print();		//����� �������
	int& operator [](int i);	//���������� �������� �� �������
	int FindKey(int key);		//����� �������� key � ������� (���������� ������ key ��� -1)

	Array& operator += (int key);	//��������� key � ����� ������� a
	Array operator + (int key);		//��������� ������ b = a + key (key ����������� � �����)

	Array& operator += (Array);		//���������� ������� � ����� ������� a
	Array operator + (Array);		//��������� ������ y=a+x

	Array& operator -=(int key);	//�������� �������� key
	Array operator -(int key);		//��������� ����� ������ b = a - key

	Array& DelPosEq(int pos);		//�������� �������� � ������� pos
	Array DelPosNew(int pos);		//��������� ����� ������ b, � ������� ������ ������� � ������� pos

	bool operator == (Array);		//�������� ��������� ��������
	bool operator != (Array);		//�������� ����������� ��������

	int Max();						//���������� ��������� � �������, ���������� ������ ������������� ��������
	int Min();						// ���������� �������� � �������

	void Sorting();					//���������� �������

	friend ostream& operator << (ostream& r, Array& x);
	friend istream& operator >> (istream& r, Array& x);

private:
	void ShiftLeft(int pos);		 //����� �����, ������� � ������� pos+1

public:
	void Randomizer();		//generate random array
};