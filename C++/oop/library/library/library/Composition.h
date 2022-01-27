
#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string Titles[5] = { "����� ������ �������", "��������", "� ��������� ��� ������", "����������� ����-��", "�������� ������" };
string Authors[5] = { "������", "��������", "�����", "���-��", "�����" };

class Composition
{
private: 
	string Title;
	string Author;

public:
	Composition() : Composition("", "") {}
	Composition(const string& title, const string& author) : Title{ title }, Author{ author } {}

	void SetTitle(const string& title) {
		Title = title;
	}
	void SetAuthor(const string& author) {
		Author = author;
	}

	string GetTitle() {
		return Title;
	}
	string GetAuthor() {
		return Author;
	}

	void Gen() {
		Title = Titles[rand() % 5];
		Author = Authors[rand() % 5];
	}

	void Print() {
		cout << Title << " " << Author;
	}
};

#endif