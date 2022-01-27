#include "Fraction.h"
#include <iostream>

using namespace std;

// Расширенный конструктоор
Fraction::Fraction(const int& Numerator, const int& Denominator) {
	if (Denominator == 0) {
		cout << "Ошибка: знаменатель не может быть равен 0" << endl;
		return;
	}
	this->Denominator = Denominator;
	this->Numerator = Numerator;
}

// Сеттеры
Fraction& Fraction::SetNumerator(int num) {
	Numerator = num;
	return *this;
}

Fraction& Fraction::SetDenominator(int num) {
	if (num == 0) {
		cout << "Ошибка: знаменатель не может быть равен 0" << endl;
	}
	else {
		Denominator = num;
	}
	return *this;
}

// Наибольший общий делитель
int Fraction::FindGCD(int A, int B) {
	if (A == 0) {
		return B;
	}
	else if (B == 0) {
		return A;
	}

	int remainder = A % B;
	int whole_part = A / B; // используем именно инт для оставления только ценой части
	return FindGCD((A - remainder) / whole_part, remainder);
}

// Сокращение
void Fraction::Reduction() {
	int max = Numerator;
	int min = Denominator;
	if (Denominator > Numerator) {
		max = Denominator;
		min = Numerator;
	}
	int gcd = FindGCD(max, min);

	Numerator /= gcd;
	Denominator /= gcd;
}

// Арифметические операции
const Fraction Fraction::Multiplication(const Fraction& sourth) {
	Fraction res;
	res.Numerator = Numerator * sourth.Numerator;
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

const Fraction Fraction::Division(const Fraction& sourth) {
	if (sourth.Numerator == 0) {
		cout << "Ошибка: числитель делителя не может быть равен 0" << endl;
		return *this; // надо что-то возвращать, как бы говоря, что деление не произошло и осталось делимое
	}
	else {
		Fraction res;
		res.Numerator = Numerator * sourth.Denominator;
		res.Denominator = Denominator * sourth.Numerator;
		res.Reduction();
		return res;
	}
}

const Fraction Fraction::Addition(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) + (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator; // можно использовать самый простой способ, перемножив знаменатели.
	res.Reduction(); // так как всё равно будет проведено сокращение
	return res;
}

const Fraction Fraction::Subtraction(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) - (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

// Арифметические операции с перегрузкой операторов
const Fraction Fraction::operator *(const Fraction& sourth) {
	Fraction res;
	res.Numerator = Numerator * sourth.Numerator;
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

const Fraction Fraction::operator /(const Fraction& sourth) {
	if (sourth.Numerator == 0) {
		cout << "Ошибка: числитель делителя не может быть равен 0" << endl;
		return *this; // надо что-то возвращать, как бы говоря, что деление не произошло и осталось делимое
	}
	else {
		Fraction res;
		res.Numerator = Numerator * sourth.Denominator;
		res.Denominator = Denominator * sourth.Numerator;
		res.Reduction();
		return res;
	}
}

const Fraction Fraction::operator +(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) + (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator; // можно использовать самый простой способ, перемножив знаменатели.
	res.Reduction(); // так как всё равно будет проведено сокращение
	return res;
}

const Fraction Fraction::operator -(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) - (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

// Вывод
Fraction& Fraction::Print() {
	cout << Numerator << " / " << Denominator;
	return *this;
}