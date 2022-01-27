// phonebook.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <string.h>
#include <Windows.h>

using namespace std;

int buffer = 200;

enum Zodiac { Aquarius, Pisces, Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius, Capricorn };

struct Date {
    int day = 17;
    int month = 12;
    int year = 2020;
};

struct Person {
    int ID = 0;
    char* Second_name;
    char* First_name;
    char* Last_name;
    Date birth_day;
    Zodiac zodiac_sign;
    char* number;
};

void Print(Person** array, const int& i) {
        cout << array[i]->Second_name << " ";
        cout << array[i]->First_name << " ";
        cout << array[i]->Last_name << ", ";

        cout << array[i]->birth_day.day << ".";
        cout << array[i]->birth_day.month << ".";
        cout << array[i]->birth_day.year << ", ";

        switch (array[i]->zodiac_sign) {
        case Aquarius: 
            cout << "Водолей, ";
            break;
        case Pisces:
            cout << "Рыбы, ";
            break;
        case Aries:
            cout << "Овен, ";
            break;
        case Taurus:
            cout << "Телец, ";
            break;
        case Gemini:
            cout << "Близнецы, ";
            break;
        case Cancer:
            cout << "Рак, ";
            break;
        case Leo:
            cout << "Лев, ";
            break;
        case Virgo:
            cout << "Дева, ";
            break;
        case Libra:
            cout << "Весы, ";
            break;
        case Scorpio:
            cout << "Скорпион, ";
            break;
        case Sagittarius:
            cout << "Стрелец, ";
            break;
        case Capricorn:
            cout << "Козерог, ";
            break;
        }

        cout << array[i]->number << ";";

        cout << endl;
}

const int names_size = 20;
const char* Second_names[names_size] = {"Кощей", "Семенко", "Куликова", "Кучеров", "Скряга", "Захарова", "Дюженко", "Шумило", "Колестников",
"Шестаков", "Овчаров", "Волько", "Семенец", "Вдовенко", "Лобода", "Бомко", "Бессонова", "Бороненко", "Жиляев", "Пономаренко"};
const char* First_names[names_size] = { "Роман", "Дарья", "Кира", "Кирил", "Анна", "Светлана", "Антон", "Соня", "Дима",
"Данил", "Максим", "Афанасий", "Анастасия", "Мария", "Злата", "Алина", "Арина", "Лилия", "Ярослав", "Александр" };
const char* Last_names[names_size] = { "Витальевич", "Константинович", "Влодимирович", "Юрьевич", "Филипович", "Александрович", "Илларионович", "Иллич", "Иванович",
"Казимирович", "Максимович", "Афанасьевич", "Анатольевич", "Викторович", "Романович", "Дмитриевич", "Сергеевич", "Кирилович", "Ярославович", "Алгенибович" };

Zodiac Define_zodiac(const int& day, const int& month) {
    int zodiac_days[12] = { 21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23 };

    Zodiac sign = (Zodiac)(month - 1);

    if (day < zodiac_days[month - 1]) {
        if (month == 1) {
            sign = (Zodiac)(11);
        }
        else {
            sign = (Zodiac)(month - 2);
        }
      
    }

    return sign;
}

void Rand_generation(Person** array, const int& i) {
    array[i] = new Person;
    array[i]->ID = i;
    array[i]->Second_name = new char[buffer];
    array[i]->First_name = new char[buffer];
    array[i]->Last_name = new char[buffer];

    for (int j = 0; j < buffer; j++) {
        array[i]->Second_name[j] = '\0';
        array[i]->First_name[j] = '\0';
        array[i]->Last_name[j] = '\0';
    }

    strcat_s((array[i]->Second_name), buffer, Second_names[rand() % 20]);
    strcat_s((array[i]->First_name), buffer, First_names[rand() % 20]);
    strcat_s((array[i]->Last_name), buffer, Last_names[rand() % 20]);

    array[i]->birth_day.month = rand() % 12 + 1;
    array[i]->birth_day.year = rand() % 120 + 1901;

    if (array[i]->birth_day.month == 2) {
            array[i]->birth_day.day = rand() % 28 + 1;
        }
    else if (array[i]->birth_day.month < 8) {
            if (array[i]->birth_day.month % 2 == 0) {
                array[i]->birth_day.day = rand() % 30 + 1;
            }
            else {
                array[i]->birth_day.day = rand() % 31 + 1;
            }
            
        }
    else {
            if (array[i]->birth_day.month % 2 == 0) {
                array[i]->birth_day.day = rand() % 31 + 1;
            }
            else {
                array[i]->birth_day.day = rand() % 30 + 1;
            }
        }

    array[i]->zodiac_sign = Define_zodiac(array[i]->birth_day.day, array[i]->birth_day.month);

    array[i]->number = new char[14];
    array[i]->number[13] = '\0';
    array[i]->number[0] = '+';
    array[i]->number[1] = '3';
    array[i]->number[2] = '8';
    array[i]->number[3] = '0';
    for (int j = 4; j < 13; j++) {
        array[i]->number[j] = (char)(rand() % 10 + 48);
    }
}

void New_user_person(Person** array, const int& i, const int& size) {
    array[i] = new Person;

    array[i]->ID = size;

    array[i]->Second_name = new char[buffer];
    cout << "Введите фамилию: ";
    fgets(array[i]->Second_name, buffer, stdin);// если оставить только 1, то туда каким-то образом записывается \n, из-за предидущего cin
    fgets(array[i]->Second_name, buffer, stdin);
    array[i]->Second_name[strlen(array[i]->Second_name) - 1] = '\0';

    array[i]->First_name = new char[buffer];
    cout << "Введите имя: ";
    fgets(array[i]->First_name, buffer, stdin);
    array[i]->First_name[strlen(array[i]->First_name) - 1] = '\0';

    array[i]->Last_name = new char[buffer];
    cout << "Введите отчество: ";
    fgets(array[i]->Last_name, buffer, stdin);
    array[i]->Last_name[strlen(array[i]->Last_name) - 1] = '\0';

    cout << "Введите год рождения: ";
    cin >> array[i]->birth_day.year;
    
    do {
        cout << "Введите месяц рождения: ";
        cin >> array[i]->birth_day.month;
        if (array[i]->birth_day.month > 12 || array[i]->birth_day.month < 1) {
            cout << "Вы ввели невозможный месяц!" << endl;
        }
    } while (array[i]->birth_day.month > 12 || array[i]->birth_day.month < 1);

    int days_limit = 31;

    if (array[i]->birth_day.month == 2) {
        days_limit = 28;
    }
    else if (array[i]->birth_day.month < 8 && array[i]->birth_day.month % 2 == 0) {
        days_limit = 30;
    }
    else if(array[i]->birth_day.month % 2 != 0) {
        days_limit = 30;
    }

    do {
        cout << "Введите день рождения: ";
        cin >> array[i]->birth_day.day;
        if (array[i]->birth_day.day > days_limit || array[i]->birth_day.day < 1) {
            cout << "Вы ввели невозможный день!" << endl;
        }
    } while (array[i]->birth_day.day > days_limit || array[i]->birth_day.day < 1);

    array[i]->zodiac_sign = Define_zodiac(array[i]->birth_day.day, array[i]->birth_day.month);

    array[i]->number = new char[14];
    array[i]->number[13] = '\0';
    do {
        cout << "Введите номер телефона (его надо начинать с +380): ";
        fgets(array[i]->number, buffer, stdin);
        fgets(array[i]->number, buffer, stdin);
        array[i]->number[strlen(array[i]->number) - 1] = '\0';

        if (strlen(array[i]->number) != 13) {
            cout << "Вы неправильно ввели номер телефона!" << endl;
            for (int j = 0; j < strlen(array[i]->number); j++) {
                array[i]->number[j] = '\0';
            }
        }
    } while (strlen(array[i]->number) != 13);

}

void Add_person_to_end(Person**& phonebook, int& size) {
    Person** new_phonebook = new Person * [size + 1];

    for (int i = 0; i < size; i++) {
        new_phonebook[i] = phonebook[i];
    }

    Rand_generation(new_phonebook, size);
    delete[] phonebook;
    phonebook = new_phonebook;
    size++;
}

void Delete_person(Person**& phonebook, int& size, const int& index) {
    Person** new_phonebook = new Person* [size - 1];
    for (int i = 0; i < index; i++) {
        new_phonebook[i] = phonebook[i];
    }

    for (int i = index + 1; i < size; i++) {
        new_phonebook[i - 1] = phonebook[i];
    }

    delete[] phonebook;
    phonebook = new_phonebook;
    size--;
}

bool Is_less_by_name(Person* person1, Person* person2) {
    int second_namecmp = strcmp(person1->Second_name, person2->Second_name);

    if (second_namecmp > 0) {
        return 0;
    }
    else if (second_namecmp < 0) {
        return 1;
    }
    else {
        int first_namecmp = strcmp(person1->First_name, person2->First_name);

        if (first_namecmp > 0) {
            return 0;
        }
        else if (first_namecmp < 0) {
            return 1;
        }
        else {
            int last_namecmp = strcmp(person1->Last_name, person2->Last_name);

            if (last_namecmp < 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

bool Is_less_by_number(Person* person1, Person* person2) {
    if (strcmp(person1->number,  person2->number) < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void Sort_phonebook(Person** phonebook, int& size, bool (*Is_less)(Person* person1, Person* person2)) {
    Person* key = nullptr;
    for (int j = 1; j < size; j++) {
        key = phonebook[j];
        int i = j - 1;
        while (i >= 0 && Is_less(key, phonebook[i])) {
            phonebook[i + 1] = phonebook[i];
            i--;
        }
        phonebook[i + 1] = key;
    }
}

void Paste_into_sorted(Person**& phonebook, int& size) {
    Person** new_phonebook = new Person* [size + 1];

    New_user_person(new_phonebook, 0, size);

    int index = 0;
    while (index < size - 1 && Is_less_by_name(new_phonebook[0], phonebook[index]) == false) {
        index++;
    }

    if (index != 0) {
        new_phonebook[index] = new_phonebook[0];
        new_phonebook[0] = nullptr;
    }

    for (int i = 0; i < index; i++) {
        new_phonebook[i] = phonebook[i];
    }

    for (int i = index; i < size; i++) {
        new_phonebook[i + 1] = phonebook[i];
    }

    delete[] phonebook;
    phonebook = new_phonebook;
    size++;
}

void Fetching_data_by_second_name(Person**& phonebook, int& size, char* user_second_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phonebook[i]->Second_name, user_second_name) == 0) {
            Print(phonebook, i);
        }
    }
}

void Fetching_data_by_zodiac(Person**& phonebook, int& size, const Zodiac& user_zodiac) {
    for (int i = 0; i < size; i++) {
        if (phonebook[i]->zodiac_sign == user_zodiac) {
            Print(phonebook, i);
        }
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int phonebook_size = 100;
    Person** phonebook = new Person* [phonebook_size];
    for (int i = 0; i < phonebook_size; i++) {
        Rand_generation(phonebook, i);
    }
    
    cout << "---------------------------" << endl;

    int user_choise = 1;

    while (user_choise >= 1 && user_choise <= 8) {
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
        char* user_second_name = new char[buffer];

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
            fgets(user_second_name, buffer, stdin); // если оставить только 1, то туда каким-то образом записывается \n, из-за предидущего cin
            fgets(user_second_name, buffer, stdin);
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
