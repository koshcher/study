// testing_system.cpp
//

#include "Include.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Testing System");

	App testing_system;
	testing_system.Run();
}