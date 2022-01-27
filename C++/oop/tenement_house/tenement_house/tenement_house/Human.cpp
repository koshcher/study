#include "Human.h"
#include <string.h>
#include <iostream>

using namespace std;

// ������������
Human::Human() : Human("", "", "", 0)
{
}

Human::Human(const char* Name, const char* Surname, const char* Patronymic, const int& Age) : Name_SIZE{ strlen(Name) + 1 }, Surname_SIZE{ strlen(Surname) + 1 }, Patronymic_SIZE{ strlen(Patronymic) + 1 }
{
	this->Name = new char[Name_SIZE];
	this->Surname = new char[Surname_SIZE];
	this->Patronymic = new char[Patronymic_SIZE];

	strcpy_s(this->Name, Name_SIZE, Name);
	strcpy_s(this->Surname, Surname_SIZE, Surname);
	strcpy_s(this->Patronymic, Patronymic_SIZE, Patronymic);
	this->Age = Age;
}

// ����������� �����������
/*
Human::Human(const Human& sourth) : SIZE{ sourth.SIZE }, Name{ new char[sourth.SIZE] {} }, Surname{ new char[sourth.SIZE] {} }, Patronymic{ new char[sourth.SIZE] {} }
{
	strcpy_s(Name, SIZE, sourth.Name);
	strcpy_s(Surname, SIZE, sourth.Surname);
	strcpy_s(Patronymic, SIZE, sourth.Patronymic);
	Age = sourth.Age;
}
*/

// ����������
Human::~Human()
{
	delete[] Name;
	delete[] Surname;
	delete[] Patronymic;
}

// �������
Human& Human::SetName(const char* Name) {
	strcpy_s(this->Name, SIZE, Name);
	return *this;
}

Human& Human::SetSurname(const char* Surname) {
	strcpy_s(this->Surname, SIZE, Surname);
	return *this;
}

Human& Human::SetPatronymic(const char* Patronymic) {
	strcpy_s(this->Patronymic, SIZE, Patronymic);
	return *this;
}

Human& Human::SetAge(const int& Age) {
	this->Age = Age;
	return *this;
}

// �����
void Human::Print() {
	cout << Surname << " " << Name << " " << Patronymic << " | �������: " << Age;
 }