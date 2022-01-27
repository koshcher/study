
#ifndef HUMAN_H
#define HUMAN_H

class Human
{
private:
	const int Name_SIZE;
	char* Name;

	const int Surname_SIZE;
	char* Surname;

	const int Patronymic_SIZE;
	char* Patronymic;

	int Age;

public:
	Human();
	Human(const char* Name, const char* Surname, const char* Patronymic, const int& Age);
	Human(const Human& sourth);
	~Human();

	// Сеттеры
	Human& SetName(const char* sourth);
	Human& SetSurname(const char* sourth);
	Human& SetPatronymic(const char* sourth);
	Human& SetAge(const int& sourth);

	// Геттеры
	char* GetName() {
		return Name;
	}
	char* GetSurname() {
		return Surname;
	}
	char* GetPatronymic() {
		return Patronymic;
	}
	int GetAge() {
		return Age;
	}
	
	void Print();
};

#endif