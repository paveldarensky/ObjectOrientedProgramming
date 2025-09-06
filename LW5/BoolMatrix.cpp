#include <iostream>
#include "BoolVector.h"
#include "BoolMatrix.h"
#include <cstring>

int BoolMatrix::Min(char** s, int m1)
{
	int min_line = strlen(s[0]);
	for (int line = 1; line < m1; line++)
	{
		min_line = std::min(min_line, int(strlen(s[line])));
	}
	return min_line;
}

BoolMatrix::BoolMatrix()
{
	BM = nullptr;
	m = 0;	n = 0;
}

BoolMatrix::BoolMatrix(int m1, int n1)
{
	m = m1; n = n1;
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
	{
		BM[i] = BoolVector(n);
	}
}

BoolMatrix::BoolMatrix(char **s,int m1)
{
	m = m1;
	n = Min(s, m);
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
	{
		BM[i] = BoolVector(s[i]);
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix &B)
{
	m = B.m; n = B.n;
	//delete[] BM;
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
	{
		BM[i] = B.BM[i];
	}
}

void BoolMatrix::Scan(int m1, int n1)
{
	m = m1; n = n1;
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
	{
		BM[i].Scan(n);
	}
}

void BoolMatrix::Print()
{
	for (int i = 0; i < m; i++)
	{
		BM[i].Print();
	}
}

BoolMatrix& BoolMatrix::operator = (const BoolMatrix& B)
{
	if (this != &B)
	{
		delete[]BM;
		BM = new BoolVector[m = B.m];
		n = B.n;
		for (int i = 0; i < m; i++)
		{
			BM[i] = B.BM[i];
		}
	}
	return *this;
}

BoolVector BoolMatrix::operator [] (int line)
{
	return BM[line];
}

bool BoolMatrix::operator == (BoolMatrix& B)
{
	bool F = 1; int line = 0;
	while (F)
	{
		F &= (BM[line] == B.BM[line]);
	}
	return F;
}

bool BoolMatrix::operator != (BoolMatrix& B)
{
	return !(*this == B);
}

BoolMatrix BoolMatrix::SetUp1(int pos_m, int pos_n)
{
	BM[pos_m - 1].SetUp1(pos_n);
	return *this;
}

BoolMatrix BoolMatrix::SetUp0(int pos_m, int pos_n)
{
	BM[pos_m - 1].SetUp0(pos_n);
	return *this;
}

BoolMatrix BoolMatrix::Invert(int pos_m, int pos_n)
{
	BM[pos_m - 1].Invert(pos_n);
	return *this;
}

BoolMatrix BoolMatrix::SetUp1(int kol, int pos_m, int pos_n)
{
	BM[pos_m - 1].SetUp1(kol, pos_n);
	return *this;
}

BoolMatrix BoolMatrix::SetUp0(int kol, int pos_m, int pos_n)
{
	BM[pos_m - 1].SetUp0(kol, pos_n);
	return *this;
}

BoolMatrix BoolMatrix::Invert(int kol, int pos_m, int pos_n)
{
	BM[pos_m - 1].Invert(kol, pos_n);
	return *this;
}

BoolMatrix BoolMatrix::operator &(BoolMatrix &B)
{
	BoolMatrix res;
	if (m == B.m)
	{
		res.m = m; res.n = std::min(n, B.n);
		for (int line = 0; line < res.m; line++)
		{
			res.BM[line] = BM[line] & B.BM[line];
		}
	}
	return res;
}

BoolMatrix BoolMatrix::operator |(BoolMatrix& B)
{
	BoolMatrix res;
	if (m == B.m)
	{
		res.m = m; res.n = std::max(n, B.n);
		for (int line = 0; line < res.m; line++)
		{
			res.BM[line] = BM[line] | B.BM[line];
		}
	}
	return res;
}

BoolMatrix BoolMatrix::operator ^(BoolMatrix& B)
{
	BoolMatrix res;
	if (m == B.m)
	{
		res.m = m; res.n = std::max(n, B.n);
		for (int line = 0; line < res.m; line++)
		{
			res.BM[line] = BM[line] ^ B.BM[line];
		}
	}
	return res;
}

BoolMatrix & BoolMatrix::operator &=(BoolMatrix& B)
{
	if (m == B.m)
	{
		n = std::min(n, B.n);
		for (int line = 0; line < m; line++)
		{
			BM[line] &= B.BM[line];
		}
	}
	return *this;
}

BoolMatrix& BoolMatrix::operator |=(BoolMatrix& B)
{
	if (m == B.m)
	{
		n = std::max(n, B.n);
		for (int line = 0; line < m; line++)
		{
			BM[line] |= B.BM[line];
		}
	}
	return *this;
}

BoolMatrix& BoolMatrix::operator ^=(BoolMatrix& B)
{
	if (m == B.m)
	{
		n = std::max(n, B.n);
		for (int line = 0; line < m; line++)
		{
			BM[line] ^= B.BM[line];
		}
	}
	return *this;
}

BoolMatrix BoolMatrix::operator ~()
{
	for (int line = 0; line < m; line++)
	{
		~BM[line];
	}
	return *this;
}

BoolMatrix BoolMatrix::ShiftLeft(int pos_m, int kol)
{
	BoolMatrix res(m, n);
	for (int line = 0; line < m; line++)
	{
		res.BM[line] = BM[line];
	}
	res.BM[pos_m - 1] << kol;
	return res;
}

BoolMatrix BoolMatrix::ShiftRight(int pos_m, int kol)
{
	BoolMatrix res(m, n);
	for (int line = 0; line < m; line++)
	{
		res.BM[line] = BM[line];
	}
	res.BM[pos_m - 1] >> kol;
	return res;
}

BoolMatrix BoolMatrix::ShiftLeftEq(int pos_m, int kol)
{
	BM[pos_m - 1] <<= kol;
	return *this;
}

BoolMatrix BoolMatrix::ShiftRightEq(int pos_m, int kol)
{
	BM[pos_m - 1] >>= kol;
	return *this;
}

BoolVector BoolMatrix::Conj()
{
	BoolVector res(n);
	for (int line = 0; line < m; line++)
	{
		res &= BM[line];
	}
	return res;
}

BoolVector BoolMatrix::Disj()
{
	BoolVector res(n);
	for (int line = 0; line < m; line++)
	{
		res |= BM[line];
	}
	return res;
}

BoolVector BoolMatrix::Xor()
{
	BoolVector res(n);
	for (int line = 0; line < m; line++)
	{
		res ^= BM[line];
	}
	return res;
}

std::ostream& operator << (std::ostream& r, BoolMatrix& B)
{
	for (int line = 0; line < B.m; line++)
	{
		r << B.BM[line];
	}
	return r;
}

std::istream& operator >> (std::istream& r, BoolMatrix& B)
{
	for (int line = 0; line < B.m; line++)
	{
		r >> B.BM[line];
	}
	return r;
}