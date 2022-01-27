// Operator_overloading_hw.cpp

#include <iostream>
#include <Windows.h>
#include "Fraction.h"
#include "Complex.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction fr1{ 3, 4 };
	Fraction fr2{ 1, 2 };
	Fraction fr3;
	cout << "Дроби: " << endl;
	fr3 = fr1 - fr2;
	fr3.Print();
	cout << endl;
	fr3 = fr1 * fr2;
	fr3.Print();
	cout << endl;
	fr3 = fr1 / fr2;
	fr3.Print();
	cout << endl;
	fr3 = fr1 + fr2;
	fr3.Print();
	cout << endl << endl;

	Complex com1{ 1, 5.5 };
	Complex com2{ 7.5, 2};
	Complex com3;
	cout << "Комплексные числа: " << endl;
	com3 = com1 - com2;
	com3.Print();
	cout << endl;
	com3 = com1 * com2;
	com3.Print();
	cout << endl;
	com3 = com1 / com2;
	com3.Print();
	cout << endl;
	com3 = com1 + com2;
	com3.Print();
}