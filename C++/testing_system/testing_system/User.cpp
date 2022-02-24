// ���������� ������� ����� � ������

#include "Include.h"
using namespace std;


// User
string User::GetUsername() {
	return Username;
}


// Guest
void Guest::Write(ofstream& f) {
	string tmp_str = encryption::Encrypt(Username); // �������������
	int tmp_int = tmp_str.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(tmp_str.c_str(), sizeof(char) * tmp_int);

	tmp_str = encryption::Encrypt(Password);
	tmp_int = tmp_str.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(tmp_str.c_str(), sizeof(char) * tmp_int);

	tmp_int = Surname.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Surname.c_str(), sizeof(char) * tmp_int);

	tmp_int = Name.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Name.c_str(), sizeof(char) * tmp_int);

	tmp_int = Patronymic.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Patronymic.c_str(), sizeof(char) * tmp_int);

	tmp_int = Adress.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Adress.c_str(), sizeof(char) * tmp_int);

	tmp_int = Phone.size() + 1;
	f.write((char*)&tmp_int, sizeof(int));
	f.write(Phone.c_str(), sizeof(char) * tmp_int);

	tmp_int = tests.size();
	f.write((char*)&tmp_int, sizeof(int));

	for (auto& test : tests) {
		tmp_int = test.first->GetTitle().size() + 1;
		f.write((char*)&tmp_int, sizeof(int));
		f.write(test.first->GetTitle().c_str(), sizeof(char) * tmp_int);

		f.write((char*)&test.second.right_count, sizeof(int));
		f.write((char*)&test.second.right_percent, sizeof(double));
		f.write((char*)&test.second.grade, sizeof(int));
		f.write((char*)&test.second.last_question, sizeof(int));
	}
}

void Guest::Read(ifstream& f) {
	int tmp_int;
	char* tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Username = encryption::Decrypt(tmp_str);
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Password = encryption::Decrypt(tmp_str);
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Surname = tmp_str;
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Name = tmp_str;
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Patronymic = tmp_str;
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Adress = tmp_str;
	delete[] tmp_str;

	f.read((char*)&tmp_int, sizeof(int));
	tmp_str = new char[tmp_int] {};
	f.read(tmp_str, sizeof(char) * tmp_int);
	Phone = tmp_str;
	delete[] tmp_str;

	int tests_count;
	f.read((char*)&tests_count, sizeof(int));

	while (tests_count > 0) {
		f.read((char*)&tmp_int, sizeof(int));
		tmp_str = new char[tmp_int] {};
		f.read(tmp_str, sizeof(char) * tmp_int);
		string TmpTitle = tmp_str;
		delete[] tmp_str;

		Statistic tmp_statistic;
		f.read((char*)&tmp_statistic.right_count, sizeof(int));
		f.read((char*)&tmp_statistic.right_percent, sizeof(double));
		f.read((char*)&tmp_statistic.grade, sizeof(int));
		f.read((char*)&tmp_statistic.last_question, sizeof(int));

		for (int i = 0; i < App::All_tests.size(); i++) {
			if (App::All_tests[i].GetTitle() == TmpTitle) {
				tests.insert({ &App::All_tests[i], tmp_statistic });
			}
		}

		tests_count--;
	}
}

void Guest::Write() {
	App::Guests.insert({ this->GetUsername(), *this });
}

void Guest::Login() {
	string input_username;
	cout << "������� �����:" << endl;
	cin >> input_username;

	map<string, Guest>::iterator iter = App::Guests.find(input_username);

	while (iter == App::Guests.end()) {
		cout << "������ ������ ���, ������� ��� ���:" << endl;
		cin >> input_username;
		iter = App::Guests.find(input_username);
	}

	string input_password;
	cout << "������� ������:" << endl;
	cin >> input_password;

	while (input_password != iter->second.Password) {
		cout << "������ ��������, ������� ��� ���:" << endl;
		cin >> input_password;
	}

	Username = iter->second.Username;
	Password = iter->second.Password;
	Surname = iter->second.Surname;
	Name = iter->second.Name;
	Patronymic = iter->second.Patronymic;
	Adress = iter->second.Adress;
	Phone = iter->second.Phone;
	tests = iter->second.tests;

	App::Guests.erase(iter); // ��� ��� ������������ � ������� �� �������� ������������ ��������
}

void Guest::Register() {
	cout << "������� �����:" << endl;
	getline(cin, Username);
	while (IsUnique(Username) == false) {
		cout << "����� �����, ������� ������:" << endl;
		getline(cin, Username);
	}
	cout << "������� ������:" << endl;
	getline(cin, Password);
	cout << "������� �������:" << endl;
	getline(cin, Surname);
	cout << "������� ���:" << endl;
	getline(cin, Name);
	cout << "������� ��������:" << endl;
	getline(cin, Patronymic);
	cout << "������� ����� ����������:" << endl;
	getline(cin, Adress);
	cout << "������� ����� ��������:" << endl;
	getline(cin, Phone);
}

bool Guest::IsUnique(const string& username) {
	map<string, Guest>::iterator user = App::Guests.find(username);
	if (user != App::Guests.end()) {
		return false;
	}
	return true;
}

void Guest::PassTest() {
	if (App::All_tests.size() == 0) {
		cout << "������ ���" << endl;
	}

	cout << "�������� ����:" << endl;
	int i = 0;
	for (auto test : App::All_tests) {
		cout << "[" << i << "] " << test.GetTitle() << endl;
		i++;
	}
	cin >> i;
	while (i < 0 || i >(App::All_tests.size() - 1)) {
		cout << "������, ���������� ��� ���: ";
		cin >> i;
	}

	map<Test*, Statistic>::iterator iter = tests.find(&App::All_tests[i]);
	Statistic tmp_stat;
	if (iter == tests.end()) {
		tmp_stat = App::All_tests[i].Pass({});
		tests.insert({ &App::All_tests[i], tmp_stat });
	}
	else {
		tmp_stat = App::All_tests[i].Pass(iter->second);
		iter->second = tmp_stat;
	}

	if (tmp_stat.last_question == App::All_tests[i].Questions_count()) {
		cout << "���� �������" << endl;
		cout << "���������:" << endl;
		ShowStatistic(tmp_stat);
	}
}

void Guest::ShowStatistic(const Statistic& sourth) {
	cout << "  ���-�� ���������� �������: " << sourth.right_count << endl;
	cout << "  ������� ���������� �������: " << sourth.right_percent << endl;
	cout << "  ������: " << sourth.grade << endl;
}

void Guest::ShowAllTestRes() {
	for_each(tests.begin(), tests.end(), [this](pair<Test*, Statistic> sourth) {
		cout << sourth.first->GetChapter() << " -> " << sourth.first->GetTitle() << endl;

		if (sourth.second.last_question == sourth.first->Questions_count()) {
			ShowStatistic(sourth.second);
		}
		else {
			cout << "  ���� �� �������" << endl;
		}
		cout << endl;
		});
}

bool Guest::ShowTestRes(const string& test) {
	for (int i = 0; i < App::All_tests.size(); i++) {
		if (App::All_tests[i].GetTitle() == test) {
			map<Test*, Statistic>::iterator iter = tests.find(&App::All_tests[i]);
			if (iter != tests.end()) {
				cout << iter->first->GetChapter() << " -> " << iter->first->GetTitle() << endl;

				if (iter->second.last_question == iter->first->Questions_count()) {
					ShowStatistic(iter->second);
				}
				else {
					cout << "  ���� �� �������" << endl;
				}
				cout << endl;
				return true;
			}
		}
	}
	return false;
}

void Guest::ShowTestRes() {
	cout << "������� �������� �����, ���� ����� ���� �� ����� ������, �� ��������� ������� ���������� ���� ������" << endl;
	string test;
	getline(cin, test);

	if (ShowTestRes(test)) {
		return;
	}

	ShowAllTestRes();
}

void Guest::Run() {
	string for_n;

	cout << "[0] �����" << endl;
	cout << "[1] ������������������" << endl;

	int choise;
	cin >> choise;
	while (choise < 0 || choise > 1) {
		cout << "������, ���������� ���: " << endl;
		cin >> choise;
	}
	getline(cin, for_n);

	switch (choise)
	{
	case 0:
		Login();
		break;

	default:
		Register();
		break;
	}
	
	choise = 0;
	while (choise == 0 || choise == 1) {
		cout << "[0] ����������� ���� ���������� ���������� ������������" << endl;
		cout << "[1] ����� ����� ������������" << endl;
		cout << "[������] ����� �� ����������" << endl;
		cin >> choise;
		getline(cin, for_n);

		switch (choise)
		{
		case 0:
			ShowTestRes();
			break;

		case 1:
			PassTest();
			break;

		default:
			return;
		}
	}
}

void Guest::Modify() {
	string for_n;
	int choise = 0;
	while (choise >= 0 && choise <= 4) {
		cout << "[0] �������� �������" << endl;
		cout << "[1] �������� ���" << endl;
		cout << "[2] �������� ��������" << endl;
		cout << "[3] �������� �����" << endl;
		cout << "[4] �������� ����� ��������" << endl;
		cout << "[������] ��������� �������" << endl;
		cin >> choise;
		getline(cin, for_n);

		string tmp_str;
		if (choise >= 0 && choise <= 4) {
			cout << "������� ����� ��������" << endl;
			getline(cin, tmp_str);
			while (tmp_str.empty()) {
				cout << "�� ����� ���� ������, ������� ��� ���" << endl;
				getline(cin, tmp_str);
			}
		}
		
		switch (choise) {
		case 0:
			Surname = tmp_str;
			break;

		case 1:
			Name = tmp_str;
			break;

		case 2:
			Patronymic = tmp_str;
			break;

		case 3:
			Adress = tmp_str;
			break;

		case 4:
			Phone = tmp_str;
			break;

		default:
			return;
		}
	}
}


// Admin
void Administrator::Write() {
	ofstream f("admin.bin", ios::binary);
	if (f.is_open()) {
		
		int tmp_int = 1;
		f.write((char*)& tmp_int, sizeof(int));

		string tmp_str = encryption::Encrypt(Username); // �������������
		tmp_int = tmp_str.size() + 1;
		f.write((char*)&tmp_int, sizeof(int));
		f.write(tmp_str.c_str(), sizeof(char) * tmp_int);

		tmp_str = encryption::Encrypt(Password);
		tmp_int = tmp_str.size() + 1;
		f.write((char*)&tmp_int, sizeof(int));
		f.write(tmp_str.c_str(), sizeof(char) * tmp_int);

		f.close();
	}
}

void Administrator::Read() {
	ifstream f("admin.bin", ios::binary);
	if (f.is_open()) {

		int tmp_int;
		char* tmp_str;

		f.read((char*)& tmp_int, sizeof(int));

		if (tmp_int == 1) {
			f.read((char*)& tmp_int, sizeof(int));
			tmp_str = new char[tmp_int] {};
			f.read(tmp_str, sizeof(char) * tmp_int);
			Username = encryption::Decrypt(tmp_str);
			delete[] tmp_str;

			f.read((char*)& tmp_int, sizeof(int));
			tmp_str = new char[tmp_int] {};
			f.read(tmp_str, sizeof(char) * tmp_int);
			Password = encryption::Decrypt(tmp_str);
			delete[] tmp_str;
		}

		f.close();
	}
}

void Administrator::Login() {
	cout << "����" << endl;

	string input_username;
	cout << "������� �����:" << endl;
	getline(cin, input_username);

	while (input_username != Username) {
		cout << "����� ��������, ������� ��� ���:" << endl;
		getline(cin, input_username);
	}

	string input_password;
	cout << "������� ������:" << endl;
	getline(cin, input_password);

	while (input_password != Password) {
		cout << "������ ��������, ������� ��� ���:" << endl;
		getline(cin, input_username);
	}
	  
	cout << "�� ������� �����" << endl;
}

void Administrator::Register() {
	cout << "�����������" << endl;
	cout << "������� �����:" << endl;
	getline(cin, Username);
	while (Username.empty()) {
		cout << "����� �� ����� ���� ������, ������� �����" << endl;
		getline(cin, Username);
	}

	cout << "������� ������:" << endl;
	getline(cin, Password);
	while (Password.empty()) {
		cout << "������ �� ����� ���� ������, ������� �����" << endl;
		getline(cin, Password);
	}
}

void Administrator::AdminManagement() {
	string for_n;
	int choise = 0;	
	cout << "[0] �������� �����" << endl;
	cout << "[1] �������� ������" << endl;
	cout << "[������] ��������� �������" << endl;
	cin >> choise;
	getline(cin, for_n);

	switch (choise)
	{
	case 0:
		cout << "������� ����� �����" << endl;
		getline(cin, Username);
		while (Username.empty()) {
			cout << "����� �� ����� ���� ������, ������� ������" << endl;
			getline(cin, Username);
		}
		break;

	case 1:
		cout << "������� ����� ������" << endl;
		getline(cin, Password);
		while (Password.empty()) {
			cout << "����� �� ����� ���� ������, ������� ������" << endl;
			getline(cin, Password);
		}
		break;

	default:
		return;
	}
}

void Administrator::AddUser() {
	Guest tmp_guest;
	tmp_guest.Register();
	App::Guests.insert({ tmp_guest.GetUsername(), tmp_guest });
}

void Administrator::DelUser() {
	string username;

	cout << "������� ����� ������������" << endl;
	getline(cin, username);

	map<string, Guest>::iterator iter = App::Guests.find(username);
	if (iter != App::Guests.end()) {
		App::Guests.erase(iter);
		return;
	}
	cout << "������������ �� ������, �������� ��������";
}

void Administrator::ModifyUser() {
	string username;

	cout << "������� ����� ������������" << endl;
	getline(cin, username);

	map<string, Guest>::iterator iter = App::Guests.find(username);
	if (iter != App::Guests.end()) {
		iter->second.Modify();
		return;
	}
	cout << "������������ �� ������, ��������� ��������";
}

void Administrator::UserManagement() {
	string for_n;
	int choise = 0;
	while (choise >= 0 || choise <= 2) {
		cout << "[0] ������� ������������" << endl;
		cout << "[1] ������� ������������" << endl;
		cout << "[2] ����������� ������������" << endl;
		cout << "[������] ��������� �������" << endl;
		cin >> choise;
		getline(cin, for_n);

		if (choise == 0) {
			AddUser();
		}
		else if (choise == 1) {
			DelUser();
		}
		else if (choise == 2) {
			ModifyUser();
		}
		else {
			return;
		}
	}
}

void Administrator::ShowResultsAll() {
	for (auto guest : App::Guests) {
		cout << "-> " << guest.first << endl;
		guest.second.ShowAllTestRes();
		cout << endl;
	}
}

void Administrator::ShowResultsTest() {
	string test_name;
	cout << "������� �������� �����" << endl;
	getline(cin, test_name);

	for (auto guest : App::Guests) {
		guest.second.ShowTestRes(test_name);
	}
}

void Administrator::ShowResultsUser() {
	string username;
	cout << "������� ����� ������������" << endl;
	getline(cin, username);

	map<string, Guest>::iterator iter = App::Guests.find(username);

	if (iter != App::Guests.end()) {
		iter->second.ShowAllTestRes();
		return;
	} 
	cout << "������������ �� ������" << endl;
}

void Administrator::ViewStatistics() {
	string for_n;
	int choise = 0;
	while (choise >= 0 || choise <= 2) {
		cout << "[0] �������� ����������� ���� ������������" << endl;
		cout << "[1] �������� ����������� ����������� �����" << endl;
		cout << "[2] �������� ����������� ������������ ����������� ������������" << endl;
		cout << "[������] ��������� �������" << endl;
		cin >> choise;
		getline(cin, for_n);

		switch (choise) {
		case 0:
			ShowResultsAll();
			break;

		case 1:
			ShowResultsTest();
			break;

		case 2:
			ShowResultsUser();
			break;

		default:
			return;
		}
	}
}

void Administrator::AddTest() {
	Test tmp_test;
	tmp_test.Input();
	App::All_tests.push_back(tmp_test);
}

void Administrator::ExportTest() {
	string test_name;
	cout << "������� �������� �����" << endl;
	getline(cin, test_name);
	while (test_name.empty()) {
		cout << "�������� ����� �� ����� ���� ������, ������� ������" << endl;
		getline(cin, test_name);
	}

	Test* tmp_test = nullptr;
	for (int i = 0; i < App::All_tests.size(); i++) {
		if (App::All_tests[i].GetTitle() == test_name) {
			tmp_test = &App::All_tests[i];
			break;
		}
	}
	if (tmp_test == nullptr) {
		cout << "���� �� ������, ������� ������" << endl;
	}
	string file_name;
	cout << "������� ��� txt �����" << endl;
	getline(cin, file_name);
	while (file_name.empty()) {
		cout << "��� �� ����� ���� ������, ������� ������" << endl;
		getline(cin, file_name);
	}

	ofstream f(file_name);
	if (f.is_open()) {
		tmp_test->ExportTest(f);
		f.close();
	}
}

void Administrator::ImportTest() {
	string file_name;
	cout << "������� ��� txt �����" << endl;
	getline(cin, file_name);
	while (file_name.empty()) {
		cout << "��� �� ����� ���� ������, ������� ������" << endl;
		getline(cin, file_name);
	}

	ifstream f(file_name);
	if (f.is_open()) {
		Test tmp_test;
		tmp_test.ImportTest(f);
		App::All_tests.push_back(tmp_test);
		f.close();
	}
}

void Administrator::TestManagement() {
	string for_n;
	int choise = 0;
	while (choise >= 0 || choise <= 2) {
		cout << "[0] �������� ����" << endl;
		cout << "[1] �������������� ����" << endl;
		cout << "[2] ������������� ����" << endl;
		cout << "[������] ��������� �������" << endl;
		cin >> choise;
		getline(cin, for_n);

		switch (choise) {
		case 0:
			AddTest();
			break;

		case 1:
			ExportTest();
			break;

		case 2:
			ImportTest();
			break;

		default:
			return;
		}
	}
}

void Administrator::Run() {
	Read();

	if (Username.empty()) {
		Register();
	}
	else {
		Login();
	}

	string for_n;
	int choise = 0;
	while (choise >= 0 || choise <= 3) {
		cout << "[0] ���������� �������" << endl;
		cout << "[1] ���������� ��������������" << endl;
		cout << "[2] �������� ����������" << endl;
		cout << "[3] ���������� �������������" << endl;
		cout << "[������] ����� �� ����������" << endl;
		cin >> choise;
		getline(cin, for_n);

		switch (choise)
		{
		case 0:
			AdminManagement();
			break;

		case 1:
			UserManagement();
			break;

		case 2:
			ViewStatistics();
			break;

		case 3:
			TestManagement();
			break;

		default:
			return;
		}
	}
}