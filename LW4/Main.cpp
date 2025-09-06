#include <iostream>
#include <assert.h>
#include "BoolVector.h"

void main()
{
	setlocale(LC_ALL, "rus");

	//BoolVector vec1("111001101101");
	//vec1.Print();

	//BoolVector vec2("111001101101", 11);
	//vec2.Print();

	//BoolVector vec3 = vec2;
	//vec3.Print();

	//std::cout << "\nВведите длину вектора: ";
	//int len;
	//std::cin >> len;
	//BoolVector vec4;
	//vec4.Scan(len);

	//std::cout << vec4.Weight() << std::endl;

	//vec4.Print();

	//UC bit = vec4[10];

	//std::cout << "\n"  << int(vec4 != vec1) << std::endl;

	//std::cout << "\n" << int(vec4 > vec1) << std::endl << std::endl;

	//BoolVector vec5 = vec4 & vec1;
	//vec5.Print();

	//BoolVector vec6("111001100100");
	//vec6 &= vec5;
	//vec6.Print();

	//std::cout << "\n-------------\n";
	//BoolVector vec7("110001");
	//BoolVector vec8("101001101010011010100110");
	////BoolVector vec9 = vec7 | vec8;
	//vec7 |= vec8;
	//vec7.Print();

	//std::cout << "\n-------------\n";
	//BoolVector vec10("100111011111");
	//BoolVector vec11("1101");
	////BoolVector vec12 = vec10 ^ vec11;
	//vec10 ^= vec11;
	//vec10.Print();

	//std::cout << "\n****************\n";
	//BoolVector vec13("100111011111");
	//~vec13;
	//vec13.Print();

	//vec13=vec13.SetUp1(3);
	//vec13.Print();

	//vec13 = vec13.SetUp0(3);
	//vec13.Print();

	//vec13 = vec13.Invert(3);
	//vec13.Print();

	//vec13 = vec13.SetUp1(3, 6);
	//vec13.Print();

	//vec13 = vec13.SetUp0(3, 6);
	//vec13.Print();

	//vec13 = vec13.Invert(3, 6);
	//vec13.Print();

	//std::cout << "\n[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[\n";
	//std::cout << vec13;

	//BoolVector vec14;
	//vec14.n = 12;
	//std::cin >> vec14;

	//std::cout << "\n" << vec14;

	//std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	//BoolVector vec15;
	//vec15.n = 24;
	//std::cin >> vec15;

	//std::cout << "\n" << vec15;

	////vec15 = vec15 << 9;
	//vec15 <<= 9;

	//std::cout << "\nnew:\n" << vec15;

	std::cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	BoolVector vec16;
	vec16.n = 24;
	std::cin >> vec16;

	std::cout << "\n" << vec16;

	//vec16 = vec16 >> 9;
	vec16 >>= 9;

	std::cout << "\nnew:\n" << vec16;
}
