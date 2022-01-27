
#ifndef FRACTION_H
#define FRACTION_H

class Fraction 
{
private:
	int Numerator;
	int Denominator;

public:
	Fraction() = default;
	Fraction(const int& Numerator, const int& Denominator);
	~Fraction() = default;

	Fraction& SetNumerator(int num);
	Fraction& SetDenominator(int num);

	int GetNumerator() const {
		return Numerator;
	}
	int GetDenominator() const {
		return Denominator;
	}

	const Fraction Multiplication(const Fraction& sourth);
	const Fraction Division(const Fraction& sourth);
	const Fraction Addition(const Fraction& sourth);
	const Fraction Subtraction(const Fraction& sourth);

	const Fraction operator *(const Fraction& sourth);
	const Fraction operator /(const Fraction& sourth);
	const Fraction operator +(const Fraction& sourth);
	const Fraction operator -(const Fraction& sourth);

	Fraction& Print();

private:
	void Reduction();
	int FindGCD(int A, int B);
};
#endif 