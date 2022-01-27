#include "Fraction.h"
#include <iostream>

using namespace std;

// ����������� ������������
Fraction::Fraction(const int& Numerator, const int& Denominator) {
	if (Denominator == 0) {
		cout << "������: ����������� �� ����� ���� ����� 0" << endl;
		return;
	}
	this->Denominator = Denominator;
	this->Numerator = Numerator;
}

// �������
Fraction& Fraction::SetNumerator(int num) {
	Numerator = num;
	return *this;
}

Fraction& Fraction::SetDenominator(int num) {
	if (num == 0) {
		cout << "������: ����������� �� ����� ���� ����� 0" << endl;
	}
	else {
		Denominator = num;
	}
	return *this;
}

// ���������� ����� ��������
int Fraction::FindGCD(int A, int B) {
	if (A == 0) {
		return B;
	}
	else if (B == 0) {
		return A;
	}

	int remainder = A % B;
	int whole_part = A / B; // ���������� ������ ��� ��� ���������� ������ ����� �����
	return FindGCD((A - remainder) / whole_part, remainder);
}

// ����������
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

// �������������� ��������
const Fraction Fraction::Multiplication(const Fraction& sourth) {
	Fraction res;
	res.Numerator = Numerator * sourth.Numerator;
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

const Fraction Fraction::Division(const Fraction& sourth) {
	if (sourth.Numerator == 0) {
		cout << "������: ��������� �������� �� ����� ���� ����� 0" << endl;
		return *this; // ���� ���-�� ����������, ��� �� ������, ��� ������� �� ��������� � �������� �������
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
	res.Denominator = Denominator * sourth.Denominator; // ����� ������������ ����� ������� ������, ���������� �����������.
	res.Reduction(); // ��� ��� �� ����� ����� ��������� ����������
	return res;
}

const Fraction Fraction::Subtraction(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) - (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

// �������������� �������� � ����������� ����������
const Fraction Fraction::operator *(const Fraction& sourth) {
	Fraction res;
	res.Numerator = Numerator * sourth.Numerator;
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

const Fraction Fraction::operator /(const Fraction& sourth) {
	if (sourth.Numerator == 0) {
		cout << "������: ��������� �������� �� ����� ���� ����� 0" << endl;
		return *this; // ���� ���-�� ����������, ��� �� ������, ��� ������� �� ��������� � �������� �������
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
	res.Denominator = Denominator * sourth.Denominator; // ����� ������������ ����� ������� ������, ���������� �����������.
	res.Reduction(); // ��� ��� �� ����� ����� ��������� ����������
	return res;
}

const Fraction Fraction::operator -(const Fraction& sourth) {
	Fraction res;
	res.Numerator = (Numerator * sourth.Denominator) - (sourth.Numerator * Denominator);
	res.Denominator = Denominator * sourth.Denominator;
	res.Reduction();
	return res;
}

// �����
Fraction& Fraction::Print() {
	cout << Numerator << " / " << Denominator;
	return *this;
}