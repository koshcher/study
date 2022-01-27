
#ifndef DATE_H
#define DATE_H

#include <time.h>

class Date
{
private:
	int Day;
	int Month;
	int Year;

public:
	Date() : Date(1, 1, 0) {}
	Date(const int& day, const int& month, const int& year) : Day{ day }, Month{ month }, Year{ year } {}

	void Print() {
		cout << Day << "." << Month << "." << Year;
	}

	void Gen() {
		Day = rand() % 28 + 1;
		Month = rand() % 12 + 1;
		Year = rand() % 50 + 1972;
	}
};

#endif