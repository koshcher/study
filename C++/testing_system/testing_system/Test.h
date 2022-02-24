// Класс тест, вопрос и статистика

#ifndef TEST_H
#define TEST_H

#include "Include.h"
using namespace std;

struct Statistic
{
	int right_count;
	int right_percent;
	int grade;
	int last_question = 0;
};

class Question
{
private:
	string Title;
	list<string> Wrong_answers;
	string Right_answer;

public:
	Question();
	Question(const string& title);
	bool CheckAnswer(const string& answer);
	void Input();
	bool Answer();
	void Write(ofstream& f);
	void Read(ifstream& f);
	void Export(ofstream& f);
	void Import(ifstream& f);
};

class Test
{
private:
	string Title;
	string Chapter;
	vector<Question> Questions;

public:
	void Add(const Question& sourth);
	Statistic Pass(Statistic sourth);
	string GetTitle() const;
	string GetChapter() const;
	int Questions_count() const;
	void Write(ofstream& f);
	void Read(ifstream& f);
	void Input();
	void ExportTest(ofstream& f);
	void ImportTest(ifstream& f);
};

#endif