// library.cpp
//

#include <iostream>
#include <Windows.h>
#include "Library.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Library my_library;
	my_library.Gen();
	//my_library.ReadBinary();
	my_library.Print();
	my_library.WriteBinary();
}