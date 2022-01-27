#pragma once

#include <iostream>

using namespace std;

enum Zodiac;

struct Date;

struct Person;

void Print(Person** array, const int& i);

Zodiac Define_zodiac(const int& day, const int& month);

void Rand_generation(Person** array, const int& i);

void New_user_person(Person** array, const int& i, const int& size);

void Add_person_to_end(Person**& phonebook, int& size);

void Delete_person(Person**& phonebook, int& size, const int& index);

bool Is_less_by_name(Person* person1, Person* person2);

bool Is_less_by_number(Person* person1, Person* person2);

void Sort_phonebook(Person** phonebook, int& size, bool (*Is_less)(Person* person1, Person* person2));

void Paste_into_sorted(Person**& phonebook, int& size);

void Fetching_data_by_second_name(Person**& phonebook, int& size, char* user_second_name);

void Fetching_data_by_zodiac(Person**& phonebook, int& size, const Zodiac& user_zodiac);