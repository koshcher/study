// phonebook.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "functions.h"

using namespace std;

int BUFFER = 500;

#define FILE_IS

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int phonebook_size = 50;
    Person** phonebook = nullptr;
    
#ifdef FILE_IS
    phonebook = Load("phonebook.txt", phonebook, phonebook_size);
    cout << phonebook[0]->First_name;

#else
    phonebook = new Person * [phonebook_size];
    for (int i = 0; i < phonebook_size; i++) {
        Rand_generation(phonebook, i);
    }
#endif 


    cout << "---------------------------" << endl;

    int user_choise = 1;

    while (user_choise >= 1 && user_choise <= 8) {
        cout << phonebook_size;
        cout << "Выберете функцию:" << endl;
        cout << "[1] Добавить запись в конец справочника" << endl;
        cout << "[2] Удаление записи по индексу" << endl;
        cout << "[3] Сортировка справочника по ФИО" << endl;
        cout << "[4] Сортировка справочника по телефону" << endl;
        cout << "[5] Вставка новой записи в отсортированный по ФИО массив в нужное место (сперва стоит отсортировать массив)" << endl;
        cout << "[6] Выборка данных по фамилии" << endl;
        cout << "[7] Выборка данных по знаку зодиака" << endl;
        cout << "[8] Вывод массива на экран" << endl;
        cout << "[любая другая цифра] Завершить программу" << endl;
        cin >> user_choise;
        cout << "---------------------------" << endl;
        int user_index = 0; // ели расположить в case, то выдаёт ошибку
        char* user_second_name = new char[BUFFER];

        switch (user_choise) {
        case 1:
            Add_person_to_end(phonebook, phonebook_size);
            break;

        case 2:
            
            cout << "Введите индекс для удаления записи: ";
            cin >> user_index;
            Delete_person(phonebook, phonebook_size, user_index);
            break;

        case 3:
            Sort_phonebook(phonebook, phonebook_size, *Is_less_by_name);
            break;

        case 4:
            Sort_phonebook(phonebook, phonebook_size, *Is_less_by_number);
            break;

        case 5:
            Paste_into_sorted(phonebook, phonebook_size);
            break;

        case 6:
            fgets(user_second_name, BUFFER, stdin); // если оставить только 1, то туда каким-то образом записывается \n, из-за предидущего cin
            fgets(user_second_name, BUFFER, stdin);
            user_second_name[strlen(user_second_name) - 1] = '\0';

            Fetching_data_by_second_name(phonebook, phonebook_size, user_second_name);
            break;

        case 7:
            int user_zodiac;
            cout << "Выберете знак зодиака:" << endl;
            cout << "[1] Водолей" << endl;
            cout << "[2] Рыбы" << endl;
            cout << "[3] Овен" << endl;
            cout << "[4] Телец" << endl;
            cout << "[5] Близнецы" << endl;
            cout << "[6] Рак" << endl;
            cout << "[7] Лев" << endl;
            cout << "[8] Дева" << endl;
            cout << "[9] Весы" << endl;
            cout << "[10] Скорпион" << endl;
            cout << "[11] Стрелец" << endl;
            cout << "[12] Козерог" << endl;
            cin >> user_zodiac;

            Fetching_data_by_zodiac(phonebook, phonebook_size, (Zodiac)(user_zodiac - 1));
            break;
        case 8:
            for (int i = 0; i < phonebook_size; i++) {
                Print(phonebook, i);
            }
            break;
        }
        delete[] user_second_name;
        cout << "---------------------------" << endl;
    }

    cout << "---------------------------" << endl;

    Save(phonebook, phonebook_size, "phonebook.txt");
    delete[] phonebook;
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
