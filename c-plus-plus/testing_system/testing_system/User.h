// Классы гостя и админа

#ifndef USER_H
#define USER_H

#include "Include.h"
using namespace std;

class User
{
protected:
	string Username;
	string Password;

public:
	string GetUsername();
	virtual void Run() = 0;
	virtual void Write() = 0;
};

class Guest : public User
{
private:
	string Surname;
	string Name;
	string Patronymic;
	string Adress;
	string Phone;

	map<Test*, Statistic> tests;

public:
	virtual void Run() override;

	virtual void Write() override; // дозапись в файл
	void Write(ofstream& f); // записи в поток
	void Read(ifstream& f);

	bool IsUnique(const string& username);

	void Login();
	void Register();

	void PassTest();
	void ShowTestRes();
	bool ShowTestRes(const string& test);
	void ShowStatistic(const Statistic& sourth);
	void ShowAllTestRes();

	void Modify();
};

class Administrator : public User
{
public:
	virtual void Run() override;
	virtual void Write() override;
	void Read();

	void Login();
	void Register();

	void AddUser();
	void DelUser();
	void ModifyUser();

	void ShowResultsAll();
	void ShowResultsTest();
	void ShowResultsUser();
	void AddTest();
	void ImportTest();
	void ExportTest();

	void AdminManagement();
	void UserManagement();
	void ViewStatistics();
	void TestManagement();
};

#endif