#include "Complex.h"
#include <iostream>

using namespace std;

// �����������
Complex::Complex(const double& Re, const double& Im) {
	this->Re = Re;
	this->Im = Im;
}

// �������
Complex& Complex::SetRe(const double& Re) {
	this->Re = Re;
	return *this;
}

Complex& Complex::SetIm(const double& Im) {
	this->Im = Im;
	return *this;
}

// �������������� ��������
const Complex Complex::Multiplication(const Complex& sourth) {
	Complex res;
	res.Re = Re * sourth.Re - Im * sourth.Im;
	res.Im = Re * sourth.Im + Im * sourth.Re;
	return res;
}

const Complex Complex::Division(const Complex& sourth) {
	if (sourth.Re != 0 && sourth.Im != 0) {
		Complex res;
		res.Re = (Re * sourth.Re - Im * sourth.Im) / (sourth.Re * sourth.Re + sourth.Im * sourth.Im);
		res.Im = (Im * sourth.Re - Re * sourth.Im) / (sourth.Re * sourth.Re + sourth.Im * sourth.Im);
		return res;
	}
	cout << "������� �� ���� ����������!";
	return *this;
}

const Complex Complex::Addition(const Complex& sourth) {
	Complex res;
	res.Re = Re + sourth.Re;
	res.Im = Im + sourth.Im;
	return res;
}

const Complex Complex::Subtraction(const Complex& sourth) {
	Complex res;
	res.Re = Re - sourth.Re;
	res.Im = Im - sourth.Im;
	return res;
}

// �������������� �������� � ����������� ����������
const Complex Complex::operator *(const Complex& sourth) {
	Complex res;
	res.Re = Re * sourth.Re - Im * sourth.Im;
	res.Im = Re * sourth.Im + Im * sourth.Re;
	return res;
}

const Complex Complex::operator /(const Complex& sourth) {
	if (sourth.Re != 0 && sourth.Im != 0) {
		Complex res;
		res.Re = (Re * sourth.Re - Im * sourth.Im) / (sourth.Re * sourth.Re + sourth.Im * sourth.Im);
		res.Im = (Im * sourth.Re - Re * sourth.Im) / (sourth.Re * sourth.Re + sourth.Im * sourth.Im);
		return res;
	}
	cout << "������� �� ���� ����������!";
	return *this;
}

const Complex Complex::operator +(const Complex& sourth) {
	Complex res;
	res.Re = Re + sourth.Re;
	res.Im = Im + sourth.Im;
	return res;
}

const Complex Complex::operator -(const Complex& sourth) {
	Complex res;
	res.Re = Re - sourth.Re;
	res.Im = Im - sourth.Im;
	return res;
}

// �����
Complex& Complex::Print() {
	cout << Re << " + " << Im << "i";
	return *this;
}