#include <iostream>
#include "BoolVector.h"
#include "BoolMatrix.h"

void main()
{
	BoolMatrix BM1(2,10);
	BM1.Scan(2,10);
	BM1.Print();
	BoolMatrix BM2 = BM1;
	BM2.Invert(4, 2, 2);
	//~BM2;
	//BM2.Print();

	//BoolMatrix C = BM1 & BM2;
	//C.Print();

	std::cout << BM2;
}