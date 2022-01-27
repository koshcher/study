// ���������� ������ ����, ������ � ����������

#include "Include.h"
using namespace std;


// Question
Question::Question() {}

Question::Question(const string& title) : Title{ title } {}

bool Question::CheckAnswer(const string& answer) {
	if (answer == Right_answer) {
		return true;
	}
	return false;
}

void Question::Input() {
	cout << "������� ������" << endl;
	getline(cin, Title);
	while (Title.empty()) {
		cout << "������ �� ����� ���� ������, ������� ������" << endl;
		getline(cin, Title);
	}

	cout << "������� ���������� �����" << endl;
	getline(cin, Right_answer);
	while (Right_answer.empty()) {
		cout << "����� �� ����� ���� ������, ������� ������" << endl;
		getline(cin, Right_answer);
	}
	
	string for_n;
	int count;
	cout << "������� ���-�� ������������ �������: ";
	cin >> count;
	getline(cin, for_n);

	while (count) {
		cout << "������� ������������ �����" << endl;
		string TmpStr;
		getline(cin, TmpStr);
		Wrong_answers.push_back(TmpStr);
		count--;
	}
}

bool Question::Answer() {
	cout << Title << endl;

	vector<string> All_answers;
	for (auto answer : Wrong_answers) {
		All_answers.push_back(answer);
	}
	All_answers.push_back(Right_answer);

	random_shuffle(All_answers.begin(), All_answers.end());

	for (int i = 0; i < All_answers.size(); i++) {
		cout << "[" << i << "] " << All_answers[i] << endl;
	}

	int choise;
	cout << "������� �����: ";
	cin >> choise;
	while (choise < 0 || choise >(All_answers.size() - 1)) {
		cout << "������ ��� ���� ������ ���!" << endl;
		cout << "������� �����: ";
		cin >> choise;
	}

	return CheckAnswer(All_answers[choise]);
}

void Question::Write(ofstream& f) {
	int tmp_int = Title.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Title.c_str(), sizeof(char) * tmp_int);

	tmp_int = Wrong_answers.size();
	f.write((char*)&tmp_int, sizeof(int));

	for (auto answer : Wrong_answers) {
		tmp_int = answer.size() + 1;
		f.write((char*)&tmp_int, sizeof(int));
		f.write(answer.c_str(), sizeof(char) * tmp_int);
	}

	tmp_int = Right_answer.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Right_answer.c_str(), sizeof(char)* tmp_int);
}

void Question::Read(ifstream& f) {
	int tmp_int;
	char* tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Title = tmp_str;
	delete[] tmp_str;

	int wrong_answers_count;
	f.read((char*)&wrong_answers_count, sizeof(int));

	while (wrong_answers_count > 0) {

		f.read((char*)&tmp_int, sizeof(int));
		tmp_str = new char[tmp_int] {};
		f.read(tmp_str, sizeof(char) * tmp_int);
		Wrong_answers.push_back(tmp_str);
		delete[] tmp_str;

		wrong_answers_count--;
	}

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Right_answer = tmp_str;
	delete[] tmp_str;
}

void Question::Export(ofstream& f) {
	Question copy = *this;
	f << copy.Title << endl;
	f << copy.Right_answer << endl;
	f << copy.Wrong_answers.size() << endl;
	for (auto& answer : copy.Wrong_answers) {
		f << answer << endl;
	}
}

void Question::Import(ifstream& f) {
	f >> Title;
	f >> Right_answer;
	int count;
	f >> count;
	while (count > 0) {
		string tmp_answer;
		f >> tmp_answer;
		Wrong_answers.push_back(tmp_answer);
		count--;
	}

}


// Test
void Test::Add(const Question& sourth) {
	Questions.push_back(sourth);
}

string Test::GetTitle() const {
	return Title;
}

string Test::GetChapter() const {
	return Chapter;
}

Statistic Test::Pass(Statistic sourth) {
	cout << Chapter << " -> " << Title << endl;

	int i = 0;
	if (sourth.last_question > 0 && sourth.last_question < Questions.size() - 1) {
		i = sourth.last_question;
	}
	else if (sourth.last_question == Questions.size()) {
		sourth.grade = 0;
		sourth.last_question = 0;
		sourth.right_count = 0;
		sourth.right_percent = 0;
	}

	int choise;
	while (i < Questions.size()) {
		sourth.last_question++;
		if (Questions[i].Answer()) {
			sourth.right_count++;
		}
		cout << "[0] �������� ������������" << endl;
		cout << "[������ �����] ��������� ������" << endl;
		cin >> choise;
		if (choise == 0) {
			return sourth;
		}
		i++;
	}

	sourth.right_percent = 1.0 * sourth.right_count / Questions.size() * 100.0;
	sourth.grade = ceil(12.0 / Questions.size() * sourth.right_count);

	return sourth;
}

int Test::Questions_count() const {
	return Questions.size();
}

void Test::Write(ofstream& f) {
	int tmp_int = Title.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Title.c_str(), sizeof(char) * tmp_int);

	tmp_int = Chapter.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Chapter.c_str(), sizeof(char) * tmp_int);

	tmp_int = Questions.size();
	f.write((char*)&tmp_int, sizeof(int));

	for (auto question : Questions) {
		question.Write(f);
	}
}

void Test::Read(ifstream& f) {
	int tmp_int;
	char* tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Title = tmp_str;
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Chapter = tmp_str;
	delete[] tmp_str;

	int questionss_count;
	f.read((char*)&questionss_count, sizeof(int));

	while (questionss_count > 0) {
		Question tmp_question;
		tmp_question.Read(f);
		Questions.push_back(tmp_question);
		questionss_count--;
	}
}

void Test::Input() {
	cout << "������� �������� �����" << endl;
	getline(cin, Title);
	while (Title.empty()) {
		cout << "�������� ����� �� ����� ���� ������, ������� ������" << endl;
		getline(cin, Title);
	}

	cout << "������� ������" << endl;
	getline(cin, Chapter);
	while (Chapter.empty()) {
		cout << "������ �� ����� ���� ������, ������� ������" << endl;
		getline(cin, Chapter);
	}

	string for_n;
	int questions_count;
	cout << "������� ���-�� ��������: ";
	cin >> questions_count;
	getline(cin, for_n);

	while(questions_count > 0) {
		Question tmp_question;
		tmp_question.Input();
		Questions.push_back(tmp_question);
		questions_count--;
	}
}

void Test::ExportTest(ofstream& f) {
	Test copy = *this;
	f << copy.Title << endl;
	f << copy.Chapter << endl;
	f << copy.Questions.size() << endl;
	for (auto& question : copy.Questions) {
		question.Export(f);
	}
}

void Test::ImportTest(ifstream& f) {
	f >> Title;
	f >> Chapter;
	int count;
	f >> count;
	while (count > 0) {
		Question tmp_question;
		tmp_question.Import(f);
		Questions.push_back(tmp_question);
		count--;
	}
}