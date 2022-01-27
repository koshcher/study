// files_hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

const int BUFFER_SIZE = 1000;

void Null_str(char* str, const int& size) {
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
}

void Delete_last_line(const char* filename, const char* new_filename) {
    FILE* f;
    FILE* new_f;
    if (!fopen_s(&f, filename, "r")) {
        fopen_s(&new_f, new_filename, "w");
        char* buffer = new char[BUFFER_SIZE];
        Null_str(buffer, BUFFER_SIZE);

        fgets(buffer, BUFFER_SIZE, f);

        while (!feof(f)) {
            fputs(buffer, new_f);
            fgets(buffer, BUFFER_SIZE, f);
        }

        delete[] buffer;
    }
}

int Bigest_line_lenth(const char* filename) {
    int len = 0;
    FILE* f;

    if (!fopen_s(&f, filename, "r")) {
        char* buffer = new char[BUFFER_SIZE];
        Null_str(buffer, BUFFER_SIZE);

        while (!feof(f)) {
            fgets(buffer, BUFFER_SIZE, f);
            int buffer_len = strlen(buffer);

            if (buffer[buffer_len - 1] == '\n') {
                buffer[buffer_len - 1] = '\0';
                buffer_len--;
            }

            if (buffer_len > len) {
                len = buffer_len;
            }
        }

        delete[] buffer;
    }

    return len;
}

int Word_count(const char* filename) {
    int count = 0;
    FILE* f;

    char* user_word = new char[BUFFER_SIZE];
    Null_str(user_word, BUFFER_SIZE);
    cout << "Введите слово для поиска количества:" << endl;
    fgets(user_word, BUFFER_SIZE, stdin);
    user_word[strlen(user_word) - 1] = '\0';

    if (!fopen_s(&f, filename, "r")) {
        char* buffer = new char[BUFFER_SIZE];
        Null_str(buffer, BUFFER_SIZE);
        
        while (!feof(f)) {
            fgets(buffer, BUFFER_SIZE, f);
            char* word = strstr(buffer, user_word);
            while (word != nullptr) {
                count++;
                word = strstr(word + 1, user_word);
            }
        }
        delete[] buffer;
    }

    delete[] user_word;
    return count;
}

void Replace_word(const char* filename, const char* new_filename) {
    FILE* f;
    FILE* new_f;
    
    if (!fopen_s(&f, filename, "r") && !fopen_s(&new_f, new_filename, "w")) {
        char* word_to_replace = new char[BUFFER_SIZE];
        Null_str(word_to_replace, BUFFER_SIZE);
        cout << "Введите слово для замены:" << endl;
        fgets(word_to_replace, BUFFER_SIZE, stdin);
        fgets(word_to_replace, BUFFER_SIZE, stdin);
        int word_to_replace_len = strlen(word_to_replace);
        word_to_replace[word_to_replace_len - 1] = '\0';

        char* new_word = new char[BUFFER_SIZE];
        Null_str(new_word, BUFFER_SIZE);
        cout << "Введите новое слово:" << endl;
        fgets(new_word, BUFFER_SIZE, stdin);
        int new_word_len = strlen(new_word);
        new_word[new_word_len - 1] = '\0';

        char* buffer = new char[BUFFER_SIZE];
        Null_str(buffer, BUFFER_SIZE);
        
        while (!feof(f)) {
            fgets(buffer, BUFFER_SIZE, f);

            char* in_buffer = strstr(buffer, word_to_replace);
            while (in_buffer != nullptr) {
                char* new_buffer = new char[BUFFER_SIZE - word_to_replace_len + new_word_len];
                Null_str(new_buffer, (BUFFER_SIZE - word_to_replace_len + new_word_len));

                *in_buffer = '\0'; // так мы сможем скопировать лишь часть до найденого слова
                strcat_s(new_buffer, BUFFER_SIZE, buffer);
                strcat_s(new_buffer, BUFFER_SIZE, new_word);
                strcat_s(new_buffer, BUFFER_SIZE, (in_buffer + word_to_replace_len - 1));

                in_buffer = strstr(in_buffer + 1, word_to_replace);

                delete[] buffer;
                buffer = new_buffer;
            }
            fputs(buffer, new_f);
        }

        fclose(f);
        fclose(new_f);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int user_choise = 0;

    do {
        cout << "[1] Удалить из файла последнюю строку. Результат записать в другой файл" << endl;
        cout << "[2] Найти длину самой длинной строки" << endl;
        cout << "[3] Посчитать сколько раз в файле встречается заданное слово" << endl;
        cout << "[4]  Найти и заменить в файле заданное слово" << endl;
        cout << "Ваш выбор: ";
        cin >> user_choise;

        switch (user_choise) {
        case 1:
            Delete_last_line("text.txt", "one_line_less.txt");
            break;
        case 2:
            cout << "Результат: " << Bigest_line_lenth("text.txt") << endl;
            break;
        case 3:
            cout << "Результат: " << Word_count("text.txt") << endl;
            break;
        case 4:
            Replace_word("text.txt", "changed_text.txt");
            break;
        default:
            cout << "Программа окончена!";
            break;
        }

    } while (user_choise < 1 && user_choise > 4);
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
