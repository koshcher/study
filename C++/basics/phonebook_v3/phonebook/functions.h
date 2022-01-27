#pragma once

#include <iostream>

using namespace std;

enum Zodiac;

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

void Print(Person** array, const int& i);

Zodiac Define_zodiac(const int& day, const int& month);

void Rand_generation(Person** array, const int& i);

void New_user_person(Person** array, const int& i, const int& size);

void Add_person_to_end(Person** phonebook, int& size);

void Delete_person(Person** phonebook, int& size, const int& index);

bool Is_less_by_name(Person* person1, Person* person2);

bool Is_less_by_number(Person* person1, Person* person2);

void Sort_phonebook(Person** phonebook, int& size, bool (*Is_less)(Person* person1, Person* person2));

void Paste_into_sorted(Person** phonebook, int& size);

void Fetching_data_by_second_name(Person** phonebook, int& size, char* user_second_name);

void Fetching_data_by_zodiac(Person** phonebook, int& size, const Zodiac& user_zodiac);

void Save(Person** phonebook, int& size, const char* filename);

Person** Load(const char* filename, Person** phonebook, int& phonebook_size);