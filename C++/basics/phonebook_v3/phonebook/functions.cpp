#include <iostream>
#include <string.h>
#include "functions.h"

using namespace std;

#define RAND

const int buffer = 500;

enum Zodiac { Aquarius, Pisces, Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius, Capricorn };

/*
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
};*/

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
const char* Second_names[names_size] = { "Кощей", "Семенко", "Куликова", "Кучеров", "Скряга", "Захарова", "Дюженко", "Шумило", "Колестников",
"Шестаков", "Овчаров", "Волько", "Семенец", "Вдовенко", "Лобода", "Бомко", "Бессонова", "Бороненко", "Жиляев", "Пономаренко" };
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
    else if (array[i]->birth_day.month % 2 != 0) {
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
        fgets(array[i]->number, 14, stdin);
        fgets(array[i]->number, 14, stdin);
        array[i]->number[strlen(array[i]->number) - 1] = '\0';

        if (strlen(array[i]->number) != 13) {
            cout << "Вы неправильно ввели номер телефона!" << endl;
            for (int j = 0; j < strlen(array[i]->number); j++) {
                array[i]->number[j] = '\0';
            }
        }
    } while (strlen(array[i]->number) != 13);

}

void Add_person_to_end(Person** phonebook, int& size) {
    Person** new_phonebook = new Person * [size + 1];

    for (int i = 0; i < size; i++) {
        new_phonebook[i] = new Person;
        *new_phonebook[i] = *phonebook[i];
        delete[] phonebook[i];
    }

#ifdef RAND
    Rand_generation(new_phonebook, size);
#else
    New_user_person(new_phonebook, size, size);
#endif // RAND

    delete[] phonebook;
    phonebook = new_phonebook;
    size++;
}

void Delete_person(Person** phonebook, int& size, const int& index) {
    Person** new_phonebook = new Person * [size - 1];
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
    if (strcmp(person1->number, person2->number) < 0) {
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

void Paste_into_sorted(Person** phonebook, int& size) {
    Person** new_phonebook = new Person * [size + 1];

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

void Fetching_data_by_second_name(Person** phonebook, int& size, char* user_second_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(phonebook[i]->Second_name, user_second_name) == 0) {
            Print(phonebook, i);
        }
    }
}

void Fetching_data_by_zodiac(Person** phonebook, int& size, const Zodiac& user_zodiac) {
    for (int i = 0; i < size; i++) {
        if (phonebook[i]->zodiac_sign == user_zodiac) {
            Print(phonebook, i);
        }
    }
}

void Save(Person** phonebook, int& size, const char* filename) {
    FILE* save_file;
    if (!fopen_s(&save_file, filename, "w")) {
        char* str_size = new char[10];
        _itoa_s(size, str_size, 10, 10);
        strcat_s(str_size, 10, "\n");

        fputs(str_size, save_file);

        delete[] str_size;

        for (int i = 0; i < size; i++) {
            char* tmp_str = new char[buffer];
            char* num = new char[10]; // 10 символов точно хватит для года 

            _itoa_s(phonebook[i]->ID, tmp_str, buffer, 10);
            strcat_s(tmp_str, buffer, "|");
            strcat_s(tmp_str, buffer, phonebook[i]->Second_name);
            strcat_s(tmp_str, buffer, "|");
            strcat_s(tmp_str, buffer, phonebook[i]->First_name);
            strcat_s(tmp_str, buffer, "|");
            strcat_s(tmp_str, buffer, phonebook[i]->Last_name);
            strcat_s(tmp_str, buffer, "|");

            _itoa_s(phonebook[i]->birth_day.day, num, 10, 10);
            strcat_s(tmp_str, buffer, num);
            strcat_s(tmp_str, buffer, "|");

            _itoa_s(phonebook[i]->birth_day.month, num, 10, 10);
            strcat_s(tmp_str, buffer, num);
            strcat_s(tmp_str, buffer, "|");

            _itoa_s(phonebook[i]->birth_day.year, num, 10, 10);
            strcat_s(tmp_str, buffer, num);

            switch (phonebook[i]->zodiac_sign) {
            case Aquarius:
                strcat_s(tmp_str, buffer, "|Водолей|");
                break;
            case Pisces:
                strcat_s(tmp_str, buffer, "|Рыбы|");
                break;
            case Aries:
                strcat_s(tmp_str, buffer, "|Овен|");
                break;
            case Taurus:
                strcat_s(tmp_str, buffer, "|Телец|");
                break;
            case Gemini:
                strcat_s(tmp_str, buffer, "|Близнецы|");
                break;
            case Cancer:
                strcat_s(tmp_str, buffer, "|Рак|");
                break;
            case Leo:
                strcat_s(tmp_str, buffer, "|Лев|");
                break;
            case Virgo:
                strcat_s(tmp_str, buffer, "|Дева|");
                break;
            case Libra:
                strcat_s(tmp_str, buffer, "|Весы|");
                break;
            case Scorpio:
                strcat_s(tmp_str, buffer, "|Скорпион|");
                break;
            case Sagittarius:
                strcat_s(tmp_str, buffer, "|Стрелец|");
                break;
            case Capricorn:
                strcat_s(tmp_str, buffer, "|Козерог|");
                break;
            }

            strcat_s(tmp_str, buffer, phonebook[i]->number);
            strcat_s(tmp_str, buffer, "\n\0");

            fputs(tmp_str, save_file);

            delete[] tmp_str;
        }

        fclose(save_file);
    }
}

void Null_array(char* array, const int& size) {
    for (int i = 0; i < size; i++) {
        array[i] = '\0';
    }
}

Person** Load(const char* filename, Person** phonebook, int& phonebook_size) {
    FILE* load_file;
    phonebook_size = 0;
    if (!fopen_s(&load_file, filename, "r")) {
        char* str_size = new char[10];
        Null_array(str_size, 10);
        fgets(str_size, 10, load_file);

        str_size[strlen(str_size) - 1] = '\0';
        phonebook_size = atoi(str_size);
        Person** phonebook = new Person* [phonebook_size];

        int i = 0;
        while (!feof(load_file)) {
            char* person_str = new char[buffer];
            fgets(person_str, buffer, load_file);

            char** info = new char* [9];
            for (int j = 0; j < 9; j++) {
                info[j] = new char[buffer];
                Null_array(info[j], buffer);
            }
            
            char* index = person_str;
            for (int j = 0; j < 9; j++) {
                int char_j = 0;
                while (*index != '|' && *index != '\n' && *index != '\0') {
                    info[j][char_j] = *index;
                    char_j++;
                    index++;
                }
                index++;
                info[j][char_j] = '\0';
            }

            phonebook[i] = new Person;

            phonebook[i]->ID = atoi(info[0]);
            phonebook[i]->Second_name = new char[buffer];
            Null_array((phonebook[i]->Second_name), buffer);
            strcat_s((phonebook[i]->Second_name), buffer, info[1]);
            cout << (phonebook[i]->Second_name) << endl;

            phonebook[i]->First_name = new char[buffer];
            Null_array((phonebook[i]->First_name), buffer);
            strcat_s((phonebook[i]->First_name), buffer, info[2]);

            phonebook[i]->Last_name = new char[buffer];
            Null_array((phonebook[i]->Last_name), buffer);
            strcat_s((phonebook[i]->Last_name), buffer, info[3]);
            phonebook[i]->birth_day.day = atoi(info[4]);
            phonebook[i]->birth_day.month = atoi(info[5]);
            phonebook[i]->birth_day.year = atoi(info[6]);

            if (strcmp(info[7], "Водолей") == 0) {
                phonebook[i]->zodiac_sign = Aquarius;
            }
            else if (strcmp(info[7], "Рыбы") == 0) {
                phonebook[i]->zodiac_sign = Pisces;
            }
            else if (strcmp(info[7], "Овен") == 0) {
                phonebook[i]->zodiac_sign = Aries;
            }
            else if (strcmp(info[7], "Телец") == 0) {
                phonebook[i]->zodiac_sign = Taurus;
            }
            else if (strcmp(info[7], "Близнецы") == 0) {
                phonebook[i]->zodiac_sign = Gemini;
            }
            else if (strcmp(info[7], "Рак") == 0) {
                phonebook[i]->zodiac_sign = Cancer;
            }
            else if (strcmp(info[7], "Лев") == 0) {
                phonebook[i]->zodiac_sign = Leo;
            }
            else if (strcmp(info[7], "Дева") == 0) {
                phonebook[i]->zodiac_sign = Virgo;
            }
            else if (strcmp(info[7], "Весы") == 0) {
                phonebook[i]->zodiac_sign = Libra;
            }
            else if (strcmp(info[7], "Скорпион") == 0) {
                phonebook[i]->zodiac_sign = Scorpio;
            }
            else if (strcmp(info[7], "Стрелец") == 0) {
                phonebook[i]->zodiac_sign = Sagittarius;
            }
            else {
                phonebook[i]->zodiac_sign = Capricorn;
            }

            phonebook[i]->number = new char[14];
            Null_array((phonebook[i]->number), 14);
            strcat_s((phonebook[i]->number), 14, info[8]);

            i++;

            for (int j = 0; j < 9; j++) {
                delete[] info[j];
            }
            delete[] info;
            delete[] person_str;
        }
        delete[] str_size;

        fclose(load_file);

        return phonebook;
    }
    
    return nullptr;
}