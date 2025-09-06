#pragma once
#include <iostream>
#include "BoolVector.h"

class BoolMatrix
{
	BoolVector* BM;
	int m, n;

	int Min(char** s, int m1);

public:
	BoolMatrix();
	BoolMatrix(int m1, int n1);
	BoolMatrix(char** s, int m1);
	BoolMatrix(const BoolMatrix&B);
	~BoolMatrix() { delete[]BM; };

	void Scan(int m, int n);
	void Print();

	BoolMatrix& operator = (const BoolMatrix& B);
	BoolVector operator[] (int line);
	bool operator == (BoolMatrix& B);
	bool operator != (BoolMatrix& B);

	BoolMatrix SetUp1(int pos_m, int pos_n);
	BoolMatrix SetUp0(int pos_m, int pos_n);
	BoolMatrix Invert(int pos_m, int pos_n);

	BoolMatrix SetUp1(int kol, int pos_m, int pos_n);
	BoolMatrix SetUp0(int kol, int pos_m, int pos_n);
	BoolMatrix Invert(int kol, int pos_m, int pos_n);

	BoolMatrix operator &(BoolMatrix& B);
	BoolMatrix operator |(BoolMatrix& B);
	BoolMatrix operator ^(BoolMatrix& B);
	BoolMatrix& operator &=(BoolMatrix& B);
	BoolMatrix& operator |=(BoolMatrix& B);
	BoolMatrix& operator ^=(BoolMatrix& B);
	BoolMatrix operator ~();

	BoolMatrix ShiftRight(int pos_m, int kol);
	BoolMatrix ShiftLeft(int pos_m, int kol);

	BoolMatrix ShiftRightEq(int pos_m, int kol);
	BoolMatrix ShiftLeftEq(int pos_m, int kol);

	BoolVector Conj();
	BoolVector Disj();
	BoolVector Xor();

	friend std::ostream& operator << (std::ostream& r, BoolMatrix& B);
	friend std::istream& operator >> (std::istream& r, BoolMatrix& B);

};