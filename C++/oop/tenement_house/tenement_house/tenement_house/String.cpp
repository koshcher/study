#include "String.h"
#include <string.h>
#include <iostream>

using namespace std;

String::String() : String("", 10)
{
}

String::String(int size) : String("", size)
{
}

String::String(const char* sourth) : String(sourth, (strlen(sourth) + 1))
{
}

String::String(const char* sourth, int size) : SIZE{ size }, str{ new char[SIZE] {} }
{
	if (SIZE >= (strlen(sourth) + 1)) {
		strcpy_s(str, SIZE, sourth);
	}
	else {
		cout << "Error";
	}
}

String::~String()
{
	delete[] str;
}

String& String::SetString(const char* sourth) {
	delete[] str;
	SIZE = strlen(sourth) + 1; // я оставляю 1 символ под \0 для безопастности
	str = new char[SIZE] {};
	strcpy_s(str, SIZE, sourth); 
	return *this;
}

String& String::Print()
{
	cout << str;
}