// string_hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int Str_len(const char* str, const int& buffer) {
    int i = 0; 
    while (*(str + i) != '\0' && i < buffer) {
        i++;
    }
    return i;
}

int mystrcmp(const char* str1, const char* str2, const int& buffer) {
    int i = 0;
    while (*(str1 + i) != '\0' && *(str2 + i) != '\0' && i < buffer) {
        if (*(str1 + i) > * (str2 + i)) {
            return 1;
        }
        else if (*(str2 + i) > * (str1 + i)) {
            return -1;
        }
        i++;
    }
    return 0;
}

int StringToNumber(char* str, const int& buffer) {
    int degree = 1;
    int i = 1; // дабы степень была правильной
    while (*(str + i) != '\0' && i < buffer) {
        degree = degree * 10;
        i++;
    }

    int num = 0;
    i = 0;
    while (*(str + i) != '\0' && i < buffer) {
        num += ((int)*(str + i) - 48) * degree;
        degree = degree / 10;
        i++;
    }
    return num;
}

char* NumberToString(int number) {
    int num_len = 0;
    for (int tmp_num = number; tmp_num > 0; tmp_num = tmp_num / 10) {
        num_len++;
    }
    char* num_str = new char[num_len + 1];
    *(num_str + num_len) = '\0';

    for (int i = num_len; i > 0; i--) {
        *(num_str + i - 1) = (char)(number % 10 + 48);
        number = number / 10;
    }
    return num_str;
}

void Uppercase(char* str, const int& buffer) {
    int i = 0;
    while (*(str + i) != '\0' && i < buffer) {
        if (*(str + i) > 96 && *(str + i) < 123) {
            *(str + i) = *(str + i) - 32;
        }
        i++;
    }
}

void Lowercase(char* str, const int& buffer) {
    int i = 0;
    while (*(str + i) != '\0' && i < buffer) {
        if (*(str + i) > 64 && *(str + i) < 91) {
            *(str + i) = *(str + i) + 32;
        }
        i++;
    }
}

char* mystrrev(char* str, const int& buffer) {
    int str_len = Str_len(str, buffer);
    char* rev_str = new char[str_len + 1];
    *(rev_str + str_len) = '\0';
    int i = 0;
    while (i < str_len) {
        *(rev_str + i) = *(str + str_len - i - 1);
        i++;
    }
    return rev_str;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int user_buffer = 200;
    char* user_str1 = new char[user_buffer];
    fgets(user_str1, user_buffer, stdin);
    *(user_str1 + Str_len(user_str1, user_buffer) - 1) = '\0';

    char* user_str2 = new char[user_buffer];
    fgets(user_str2, user_buffer, stdin);
    *(user_str2 + Str_len(user_str2, user_buffer) - 1) = '\0';

    cout << mystrcmp(user_str1, user_str2, user_buffer) << endl;
    cout << "----------------------------------------" << endl;

    char* user_num_str = new char[user_buffer];
    fgets(user_num_str, user_buffer, stdin);
    *(user_num_str + Str_len(user_num_str, user_buffer) - 1) = '\0';

    cout << StringToNumber(user_num_str, user_buffer) << endl;
    cout << "----------------------------------------" << endl;

    int user_num;
    cin >> user_num;
    cout << NumberToString(user_num) << endl;
    cout << "----------------------------------------" << endl;

    Uppercase(user_str1, user_buffer);
    cout << user_str1 << endl;
    cout << "----------------------------------------" << endl;

    Lowercase(user_str1, user_buffer);
    cout << user_str1 << endl;
    cout << "----------------------------------------" << endl;

    char* user_rev_str = mystrrev(user_str1, user_buffer);
    cout << user_rev_str << endl;
    cout << "----------------------------------------" << endl;


    delete[] user_str1;
    delete[] user_str2;
    delete[] user_num_str;
    delete[] user_rev_str;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
