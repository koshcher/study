
#ifndef LITERATURE_H
#define LITERATURE_H

#include <iostream>
#include <string>

#include "Composition.h"
#include "Date.h"

using namespace std;

string Literature_Titles[5] = { "О жизни", "О праздниках", "Боевые исскуства", "Огород", "Политика" };
string Editions[5] = { "Киев", "Москва", "Где-то", "Не у нас", "Нигде" };

class Literature
{
protected:
	string Title;

public:
	Literature() : Literature("") {}
	Literature(const string& title) : Title{ title } {}
	virtual void Print() = 0;
	virtual void Gen() = 0; 
	virtual int TypeNum() = 0;
};


class Newspaper : public Literature 
{
private:
	int Num;
	Date Issue_date;

public:
	Newspaper() : Newspaper("", Date{1, 1, 0}, 0) {}
	Newspaper(const string& title, const Date& date, const int& num) : Literature(title), Num{ num }, Issue_date{ date } {}

	virtual void Print() override {
		cout << Title << " ";
		Issue_date.Print();
		cout << " " << Num;
	}

	virtual void Gen() override {
		Title = Literature_Titles[rand() % 5];
		Num = rand() % 100 + 1;
		Issue_date.Gen();
	}

	int TypeNum() {
		return 1;
	}
};

class Almanac : public Literature
{
private:
	int Num;
	Date Issue_date;
	string Edition;
	int List_size;
	Composition* Works_list;

public:
	Almanac() : Almanac("", Date{ 1, 1, 0 }, 0, "") {}
	Almanac(const string& title, const Date& date, const int& num, const string& edition) : Literature(title), Issue_date{ date }, Num{ num }, Edition{ edition }, List_size{ 0 }, Works_list{ nullptr } {}
	Almanac(const string& title, const Date& date, const int& num, const string& edition, const int& list_size, Composition* works_list);
	~Almanac() {
		if (Works_list != nullptr) {
			delete[] Works_list;
		}
	}

	virtual void Print() override {
		cout << Title << " ";
		Issue_date.Print();
		cout << " " << Num << " " << Edition << ":" << endl;
		for (int i = 0; i < List_size; i++) {
			cout << "    ";
			Works_list[i].Print();
			cout << endl;
		}
	}

	virtual void Gen() override;

	int TypeNum() {
		return 2;
	}

	void AddComposition(const string& title, const string& author) {
		Composition* tmp = new Composition[List_size + 1];
		for (int i = 0; i < List_size; i++) {
			tmp[i].SetAuthor(Works_list[i].GetAuthor());
			tmp[i].SetTitle(Works_list[i].GetTitle());
		}
		tmp[List_size].SetAuthor(author);
		tmp[List_size].SetTitle(title);

		if (Works_list != nullptr) {
			delete[] Works_list;
		}

		List_size++;
		Works_list = tmp;
		tmp = nullptr;
	}
};

Almanac::Almanac(const string& title, const Date& date, const int& num, const string& edition, const int& list_size, Composition* works_list) :
	Literature(title), Issue_date{ date }, Num{ num }, Edition{ edition }, List_size{ list_size }, Works_list{ new Composition[List_size] }
{
	for (int i = 0; i < List_size; i++) {
		Works_list[i].SetAuthor(works_list[i].GetAuthor());
		Works_list[i].SetTitle(works_list[i].GetTitle());
	}
}

void Almanac::Gen() {
	Title = Literature_Titles[rand() % 5];
	Num = rand() % 100 + 1;
	Issue_date.Gen();
	Edition = Editions[rand() % 5];

	if (Works_list != nullptr) {
		delete[] Works_list;
	}
	List_size = rand() % 5 + 1;
	Works_list = new Composition[List_size];
	for (int i = 0; i < List_size; i++) {
		Works_list[i].Gen();
	}
}

class Book : public Literature
{
private:
	int Year;
	string Author;
	string Edition;
	int Pages;

public:
	Book() : Book("", 0, "", "", 0) {}
	Book(const string& title, const int& year, const string& author, const string& edition, const int& pages) :
		Literature(title), Year{ year }, Author{ author }, Edition{ edition }, Pages{ pages } {}

	virtual void Print() override {
		cout << Title << " " << Year << " " << Author << " " << Edition << " " << Pages;
	}

	virtual void Gen() override {
		Title = Literature_Titles[rand() % 5];
		Year = rand() % 50 + 1972;
		Author = Authors[rand() % 5];
		Edition = Editions[rand() % 5];
		Pages = rand() % 300 + 100;
	}

	int TypeNum() {
		return 3;
	}
};

#endif