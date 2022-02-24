// Класс приложения

#ifndef APP_H
#define APP_H

#include "Include.h"
using namespace std;

class App
{
private:
	User* Mode;

public:
	void Run();
	static map<string, Guest> Guests;
	static vector<Test> All_tests;

private:
	void ReadGuests();
	void ReadTests();
	void Read();

	void WriteGuests();
	void WriteTests();
	void Write();
};

#endif