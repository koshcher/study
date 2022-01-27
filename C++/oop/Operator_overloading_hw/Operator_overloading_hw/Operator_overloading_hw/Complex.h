
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double Re;
	double Im;

public:
	Complex() = default;
	Complex(const double& Re, const double& Im);
	~Complex() = default;

	Complex& SetRe(const double& Re);
	Complex& SetIm(const double& Im);

	double GetRe() {
		return Re;
	}
	double GetIm() {
		return Im;
	}

	const Complex Multiplication(const Complex& sourth);
	const Complex Division(const Complex& sourth);
	const Complex Addition(const Complex& sourth);
	const Complex Subtraction(const Complex& sourth);

	const Complex operator *(const Complex& sourth);
	const Complex operator /(const Complex& sourth);
	const Complex operator +(const Complex& sourth);
	const Complex operator -(const Complex& sourth);

	Complex& Print();
};

#endif