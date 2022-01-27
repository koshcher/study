// Реализация класса приложения

#include "Include.h"
using namespace std;


map<string, Guest> App::Guests;
vector<Test> App::All_tests;

// Read
void App::ReadGuests() {
	ifstream f("guests.bin", ios::binary);
	if (f.is_open()) {

		int count;
		f.read((char*)&count, sizeof(int));

		while (f && count > 0)
		{
			Guest tmp_guest;
			tmp_guest.Read(f);
			Guests.insert({ tmp_guest.GetUsername(), tmp_guest });
			count--;
		}

		f.close();
	}
}
void App::ReadTests() {
	ifstream f("tests.bin", ios::binary);
	if (f.is_open()) {

		int count;
		f.read((char*)&count, sizeof(int));

		while (f && count > 0)
		{
			Test tmp_test;
			tmp_test.Read(f);
			All_tests.push_back(tmp_test);
			count--;
		}

		f.close();
	}
}

void App::Read() {
	ReadTests();
	ReadGuests();
}

// Write
void App::WriteGuests() {
	ofstream f("guests.bin", ios::binary);
	if (f.is_open()) {

		int tmp_int = Guests.size();
		f.write((char*)&tmp_int, sizeof(int));

		for (auto guest : Guests) {
			guest.second.Write(f);
		}

		f.close();
	}
}

void App::WriteTests() {
	ofstream f("tests.bin", ios::binary);
	if (f.is_open()) {

		int tmp_int = All_tests.size();
		f.write((char*)&tmp_int, sizeof(int));

		for (auto test : All_tests) {
			test.Write(f);
		}

		f.close();
	}
}

void App::Write() {
	Mode->Write();
	WriteTests();
	WriteGuests();
}

// Run
void App::Run() {
	Read();
	string for_n;

	cout << "Выберете режим:" << endl;
	cout << "[0] Администратор" << endl;
	cout << "[1] Тестируемый" << endl;
	int mode_int;
	cin >> mode_int;
	while (mode_int < 0 || mode_int > 1) {
		cout << "Ошибка, попроюуйте ещё: ";
		cin >> mode_int;
	}
	getline(cin, for_n);

	switch (mode_int) {
	case 0:
		Mode = new Administrator;
		break;
	case 1:
		Mode = new Guest;
		break;
	default:
		return;
	}

	Mode->Run();

	Write();
}