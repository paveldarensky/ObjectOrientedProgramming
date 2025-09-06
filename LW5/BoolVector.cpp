#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <cstring>
#include "BoolVector.h"

BoolVector::BoolVector()
{
	bv = nullptr;
	n = 0;
	m = 0;
}

BoolVector::BoolVector(int n1)
{
	n = n1;
	if (!(n % 8)) m = n / 8;
	else m = n / 8 + 1;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
	{
		bv[i] = 0b00000000;
	}
}

BoolVector::BoolVector(const char* s)
{
	n = strlen(s);
	if (!(n % 8)) m = n / 8;
	else m = n / 8 + 1;
	bv = new UC[m];
	int k = n - 1;
	int r;
	int flag = 1;
	for (int i = 0; i < m; i++)
	{
		r = 0;
		while (r != 8)
		{
			if ((s[k] == '1') && (flag))
			{
				bv[i] |= (1 << r);
			}
			else if ((s[k] == '0') && (flag))
			{
				bv[i] &= ~(1 << r);
			}
			else if (!flag)
			{
				bv[i] &= ~(1 << r);
			}
			r++;
			if (k != 0) k--;
			else flag = 0;
		}
	}
}

BoolVector::BoolVector(const char* s, int n1)
{
	if (strlen(s) < n1)
	{
		int newlen = n1 + 1;
		char* strnull = new char[newlen];
		memset(strnull, '0', n1 - strlen(s));
		strcpy(strnull + (n1 - strlen(s)), s);
		strnull[newlen] = '\0';
		s = strnull;
		n = n1;
	}
	else if (strlen(s) > n1)
	{
		int h = n1 - 1;
		char* newS = new char[n1];
		for (int i = strlen(s) - 1; i >= (strlen(s) - n1); i--)
		{
			newS[h] = s[i];
			h--;
		}
		newS[n1] = '\0';
		s = newS;
		n = n1;
	}
	else
	{
		n = n1;
	}


	delete[]bv;
	if (!(n % 8)) m = n / 8;
	else m = n / 8 + 1;
	bv = new UC[m];
	int k = n - 1;
	int r;
	int flag = 1;
	for (int i = 0; i < m; i++)
	{
		r = 0;
		while (r != 8)
		{
			if ((s[k] == '1') && (flag))
			{
				bv[i] |= (1 << r);
			}
			else if ((s[k] == '0') && (flag))
			{
				bv[i] &= ~(1 << r);
			}
			else if (!flag)
			{
				bv[i] &= ~(1 << r);
			}
			r++;
			if (k != 0) k--;
			else flag = 0;
		}
	}
}

BoolVector::BoolVector(const BoolVector& b)
{
	n = b.n;
	m = b.m;
	bv = new UC[m];
	for (int byte = 0; byte < m; byte++)
	{
		bv[byte] = b.bv[byte];
	}
}

BoolVector & BoolVector::operator=(const BoolVector& b)
{
	if (this != &b)
	{
		delete[]bv;
		bv = new UC[m = b.m];
		n = b.n;
		for (int byte = 0; byte < m; byte++)
		{
			bv[byte] = b.bv[byte];
		}
	}
	return *this;
}

void BoolVector::Scan(int kol)
{
	char* s = new char[kol];
	for (int i = 0; i < kol; i++)
	{
		std::cin >> s[i];
	}

	n = kol;
	if (!(n % 8)) m = n / 8;
	else m = n / 8 + 1;
	bv = new UC[m];
	int k = n - 1;
	int r;
	int flag = 1;
	for (int i = 0; i < m; i++)
	{
		r = 0;
		while (r != 8)
		{
			if ((s[k] == '1') && (flag))
			{
				bv[i] |= (1 << r);
			}
			else if ((s[k] == '0') && (flag))
			{
				bv[i] &= ~(1 << r);
			}
			else if (!flag)
			{
				bv[i] &= ~(1 << r);
			}
			r++;
			if (k != 0) k--;
			else flag = 0;
		}
	}
}

void BoolVector::Print()
{
	for (int byte = m - 1; byte >= 0; byte--)
	{
		for (int i = 7; i >= 0; i--) {
			std::cout << ((bv[byte] >> i) & 1);
		}
		std::cout << " ";
		//std::cout << std::endl;
	}
	std::cout << std::endl;
}

int BoolVector::Weight()
{
	int count = 0;
	UC* copyBV = new UC[m];
	for (int byte = 0; byte < m; byte++)
	{
		copyBV[byte] = bv[byte];
		while (copyBV[byte])
		{
			count += copyBV[byte] & 1;
			copyBV[byte] >>= 1;
		}
	}
	return count;
}

UC BoolVector::operator [](int x)
{
	int posByte = x / 8;
	int posBit = x % 8;
	//std::cout << ((bv[posByte] >> posBit) & 1) << std::endl;
	return ((bv[posByte] >> posBit) & 1);
}

bool BoolVector::operator ==(BoolVector& b)
{
	if (m == b.m)
	{
		int flag = 1;
		int count = 0;
		for (int byte = 0; (byte < m) && flag; byte++)
		{
			if (bv[byte] == b.bv[byte]) count++;
			else { flag = 0; };
		}
		if (count == m) return true;
	}
	return false;
}

bool BoolVector::operator !=(BoolVector& b)
{
	//if (this == &b) return false;
	//else return true;
	return !(*this == b);
}

bool BoolVector::operator <(BoolVector& b)
{
	if (m == b.m)
	{
		int flag = 1;
		int count = 0;
		for (int byte = 0; (byte < m) && flag; byte++)
		{
			if (bv[byte] <= b.bv[byte]) count++;
			else { flag = 0; };
		}
		if (count == m) return true;
	}
	return false;
}

bool BoolVector::operator >(BoolVector& b)
{
	if (m == b.m)
	{
		int flag = 1;
		int count = 0;
		for (int byte = 0; (byte < m) && flag; byte++)
		{
			if (bv[byte] >= b.bv[byte]) count++;
			else { flag = 0; };
		}
		if (count == m) return true;
	}
	return false;
}

BoolVector BoolVector::operator &(const BoolVector& b)
{
	BoolVector res;
	res.n = std::min(n, b.n);
	res.m = std::min(m, b.m);
	res.bv = new UC[res.m];

	for (int byte = 0; byte < res.m; byte++)
	{
		res.bv[byte] = (bv[byte] & b.bv[byte]);
	}

	return res;
}

BoolVector& BoolVector::operator &=(const BoolVector& b)
{
	UC* save = new UC[m];
	for (int byte = 0; byte < m; byte++)
	{
		save[byte] = bv[byte];
	}
	delete[] bv;
	m = std::min(m, b.m);
	n = std::min(n, b.n);

	for (int byte = 0; byte < m; byte++)
	{
		save[byte] &= b.bv[byte];
	}
	bv = save;

	//*this = *this & b;
	return *this;
}

BoolVector BoolVector::operator |(BoolVector& b)
{
	BoolVector res;
	if (m > b.m)
	{
		res.bv = new UC[m];
		for (int byte = 0; byte < m; byte++)
		{
			res.bv[byte] = bv[byte];
		}
	}
	else
	{
		res.bv = new UC[b.m];
		for (int byte = 0; byte < b.m; byte++)
		{
			res.bv[byte] = b.bv[byte];
		}
	}
	res.n = std::max(n, b.n);
	res.m = std::max(m, b.m);

	for (int byte = 0; byte < (std::min(m, b.m)); byte++)
	{
		res.bv[byte] = (bv[byte] | b.bv[byte]);
	}

	return res;
}

BoolVector& BoolVector::operator |=(BoolVector& b)
{
	UC* save;
	if (m > b.m)
	{
		save = new UC[m];
		for (int byte = 0; byte < m; byte++)
		{
			save[byte] = bv[byte];
		}

		for (int byte = 0; byte < (std::min(m, b.m)); byte++)
		{
			save[byte] |= b.bv[byte];
		}
	}
	else
	{
		save = new UC[b.m];
		for (int byte = 0; byte < b.m; byte++)
		{
			save[byte] = b.bv[byte];
		}

		for (int byte = 0; byte < (std::min(m, b.m)); byte++)
		{
			save[byte] |= bv[byte];
		}
	}

	n = std::max(n, b.n);
	m = std::max(m, b.m);
	bv = save;

	//*this = *this | b;
	return *this;
}

BoolVector BoolVector::operator ^(BoolVector& b)
{
	BoolVector res;
	if (m > b.m)
	{
		res.bv = new UC[m];
		for (int byte = 0; byte < m; byte++)
		{
			res.bv[byte] = bv[byte];
		}
	}
	else
	{
		res.bv = new UC[b.m];
		for (int byte = 0; byte < b.m; byte++)
		{
			res.bv[byte] = b.bv[byte];
		}
	}
	res.n = std::max(n, b.n);
	res.m = std::max(m, b.m);

	for (int byte = 0; byte < (std::min(m, b.m)); byte++)
	{
		res.bv[byte] = (bv[byte] ^ b.bv[byte]);
	}

	return res;
}

BoolVector& BoolVector::operator ^=(BoolVector& b)
{
	UC* save;
	if (m > b.m)
	{
		save = new UC[m];
		for (int byte = 0; byte < m; byte++)
		{
			save[byte] = bv[byte];
		}

		for (int byte = 0; byte < (std::min(m, b.m)); byte++)
		{
			save[byte] ^= b.bv[byte];
		}
	}
	else
	{
		save = new UC[b.m];
		for (int byte = 0; byte < b.m; byte++)
		{
			save[byte] = b.bv[byte];
		}

		for (int byte = 0; byte < (std::min(m, b.m)); byte++)
		{
			save[byte] ^= bv[byte];
		}
	}

	n = std::max(n, b.n);
	m = std::max(m, b.m);
	bv = save;

	//*this = *this ^ b;
	return *this;
}

BoolVector BoolVector::operator ~()
{
	for (int i = 0; i < n; i++)
	{
		int posByte = i / 8;
		int posBit = i % 8;
		if ((bv[posByte] & (1 << posBit)) == 0) { bv[posByte] |= (1 << posBit); }
		else { bv[posByte] &= ~(1 << posBit); }
	}
	return *this;
}

BoolVector BoolVector::operator <<(int x)
{
	BoolVector res(n);				//res.method (this->method) ((*this).method) (method) this->m  m
	for (int posBit = 0; posBit < (m * 8 - x); posBit++)
	{
		if ((bv[posBit / 8] & (1 << posBit % 8)) == 0) { res.bv[(posBit + x) / 8] &= ~(1 << (posBit + x) % 8); }
		else { res.bv[(posBit + x) / 8] |= (1 << (posBit + x) % 8); }
	}
	return res;
}

BoolVector& BoolVector::operator <<=(int x)
{
	UC* copy = new UC[m];

	for (int posBit = 0; posBit < (0 + x); posBit++)
	{
		copy[posBit / 8] &= ~(1 << posBit % 8);
	}

	for (int posBit = 0; posBit < (m * 8 - x); posBit++)
	{
		if ((bv[posBit / 8] & (1 << posBit % 8)) == 0) { copy[(posBit + x) / 8] &= ~(1 << (posBit + x) % 8); }
		else { copy[(posBit + x) / 8] |= (1 << (posBit + x) % 8); }
	}
	bv = copy;
	return *this;
}

BoolVector BoolVector::operator >>(int x)
{
	BoolVector res(n);
	for (int posBit = ((m * 8) - 1); posBit >= x; posBit--)
	{
		if ((bv[posBit / 8] & (1 << posBit % 8)) == 0) { res.bv[(posBit - x) / 8] &= ~(1 << (posBit - x) % 8); }
		else { res.bv[(posBit - x) / 8] |= (1 << (posBit - x) % 8); }
	}
	return res;
}

BoolVector& BoolVector::operator >>=(int x)
{
	UC* copy = new UC[m];

	for (int posBit = (m * 8 - 1); posBit >= (m * 8 - x); posBit--)
	{
		copy[posBit / 8] &= ~(1 << posBit % 8);
	}

	for (int posBit = ((m * 8) - 1); posBit >= x; posBit--)
	{
		if ((bv[posBit / 8] & (1 << posBit % 8)) == 0) { copy[(posBit - x) / 8] &= ~(1 << (posBit - x) % 8); }
		else { copy[(posBit - x) / 8] |= (1 << (posBit - x) % 8); }
	}
	bv = copy;
	return *this;
}

BoolVector BoolVector::SetUp1(int pos)
{
	bv[pos / 8] |= (1 << pos % 8);
	return *this;
}

BoolVector BoolVector::SetUp0(int pos)
{
	bv[pos / 8] &= ~(1 << pos % 8);
	return *this;
}

BoolVector BoolVector::Invert(int pos)
{
	int posByte = pos / 8;
	int posBit = pos % 8;
	if ((bv[posByte] & (1 << posBit)) == 0) { bv[posByte] |= (1 << posBit); }
	else { bv[posByte] &= ~(1 << posBit); }
	return *this;
}

BoolVector BoolVector::SetUp1(int kol, int pos)
{
	for (int posBit = pos; posBit < (pos + kol); posBit++)
	{
		bv[posBit / 8] |= (1 << posBit % 8);
	}
	return *this;
}


BoolVector BoolVector::SetUp0(int kol, int pos)
{
	for (int posBit = pos; posBit < (pos + kol); posBit++)
	{
		bv[posBit / 8] &= ~(1 << posBit % 8);
	}
	return *this;
}

BoolVector BoolVector::Invert(int kol, int pos)
{
	for (int posBit = pos; posBit < (pos + kol); posBit++)
	{
		if ((bv[posBit / 8] & (1 << posBit % 8)) == 0) { bv[posBit / 8] |= (1 << posBit % 8); }
		else { bv[posBit / 8] &= ~(1 << posBit % 8); }
	}
	return *this;
}

std::ostream& operator<< (std::ostream& r, BoolVector& V)
{
	for (int byte = V.m - 1; byte >= 0; byte--)
	{
		for (int i = 7; i >= 0; i--) {
			r << ((V.bv[byte] >> i) & 1);
		}
		//r << std::endl;
		r << " ";
	}
	r << std::endl;
	return r;
}

std::istream& operator>> (std::istream& r, BoolVector& V)
{
	char* s = new char[V.n];
	for (int i = 0; i < V.n; i++)
	{
		r >> s[i];
	}

	if (!(V.n % 8)) V.m = V.n / 8;
	else V.m = V.n / 8 + 1;
	V.bv = new UC[V.m];
	int k = V.n - 1;
	int p;
	int flag = 1;
	for (int i = 0; i < V.m; i++)
	{
		p = 0;
		while (p != 8)
		{
			if ((s[k] == '1') && (flag))
			{
				V.bv[i] |= (1 << p);
			}
			else if ((s[k] == '0') && (flag))
			{
				V.bv[i] &= ~(1 << p);
			}
			else if (!flag)
			{
				V.bv[i] &= ~(1 << p);
			}
			p++;
			if (k != 0) k--;
			else flag = 0;
		}
	}
	return r;
}