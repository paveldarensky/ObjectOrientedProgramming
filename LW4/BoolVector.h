#pragma once
#include <iostream>

typedef unsigned char UC;

class BoolVector
{
public:
	UC* bv;
	int n, m;		
public:
	BoolVector();
	BoolVector(int n1);          			
	BoolVector(const char* s);
	BoolVector(const char* s, int n1);			
	BoolVector(const BoolVector&);
	BoolVector operator = (const BoolVector&);
	~BoolVector() { delete[]bv; }

	void Scan(int);
	void Print();
	int Weight();
	UC operator[] (int);

	bool operator== (BoolVector&b);
	bool operator!= (BoolVector&b);
	bool operator< (BoolVector&b);   	
	bool operator> (BoolVector&b);		 

	BoolVector operator & (const BoolVector& b);		
	BoolVector& operator &=(const BoolVector& b);		
	BoolVector operator |(BoolVector& b);			
	BoolVector& operator |=(BoolVector& b);		
	BoolVector operator ^(BoolVector& b);			
	BoolVector& operator ^=(BoolVector& b);	
	BoolVector operator ~();						

	BoolVector operator <<(int x);					
	BoolVector& operator <<=(int x);				
	BoolVector operator >>(int x);				
	BoolVector& operator >>=(int x);				

	BoolVector SetUp1(int pos);        
	BoolVector SetUp0(int pos);        	
	BoolVector Invert(int pos);           	

	BoolVector SetUp1(int kol, int pos);
	BoolVector SetUp0(int kol, int pos);
	BoolVector Invert(int kol, int pos);

	friend std::ostream& operator<< (std::ostream& r, BoolVector& V);
	friend std::istream& operator>> (std::istream& r, BoolVector& V);
};
