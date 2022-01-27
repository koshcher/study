// functions_hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"

using namespace std;

template <typename UserType>
void Rand_array(UserType user_array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        user_array[i] = (rand() % 10000) / 100.0 - 40; // для интов будет записываться только целая часть
    }
}

template <typename UserType>
void Cout_array(UserType user_array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << user_array[i] << " ";
    }
    cout << endl;
}

// Домашнее задание 1

// Задание 1
int Is_year_leap(int year) { // int чтобы в будующем не делать проверок, а сразу добавлять 1, если высокосный
    return ((year % 4 == 0) ? (year % 100 != 0) ? 1 : (year % 400 != 0) ? 0 : 1 : 0);
}

int Day_count(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool is_date2_bigger = (year2 > year1) ? true : (month2 > month1) ? true : (day2 > day1) ? true : false;

    int days_between = 0;
    
    if (year1 == year2) {
        if (is_date2_bigger == true) {
            for (int month = month1; month < month2; month++) { 
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month - 1];
            } 
            days_between += day2;
            days_between -= day1;
        }
        else {
            for (int month = month2; month < month1; month++) {
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month - 1];
            }
            days_between += day1;
            days_between -= day2;
        }
        return days_between;
    }
    else {
        // считаем дни годов между годами
        int years_between = 0;
        if (is_date2_bigger == true) {
            years_between = year2 - year1;
        }
        else {
            years_between = year1 - year2;
        }

        if (is_date2_bigger == true) {
            for (int year = 1; year < years_between; year++) {
                days_between = days_between + 365 + Is_year_leap(year1 + year);
            }
        }
        else {
            for (int year = 1; year < years_between; year++) {
                days_between = days_between + 365 + Is_year_leap(year2 + year);
            }
        }

        // дни от первой даты
        if (is_date2_bigger == true) {
            for (int month = month1 - 1; month < 12; month++) {
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month];
            }
            days_between -= day1;
        }
        else {
            for (int month = month2 - 1; month < 12; month++) {
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month];
            }
            days_between -= day2;
        }

        // дни до второй даты
        if (is_date2_bigger == true) {
            for (int month = 0; month < month2 - 1; month++) {
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month];
            }
            days_between += day2;
        }
        else {
            for (int month = 0; month < month1 - 1; month++) {
                if (month == 1) {
                    days_between++;
                }
                days_between += days_in_month[month];
            }
            days_between += day1;
        }
        return days_between;
    }
}

// Задание 2
template <typename UserType>
double Array_average(UserType user_array[], int size) {
    UserType sum = 0;
    for (int i = 0; i < size; i++) {
        sum += user_array[i];
    }
    return sum / (double)size;
}

// Задание 3
template <typename UserType>
void Array_counts(UserType user_array[], int size, int counts_array[3]) { // counts_array - массив для записи количеств, инт так как количества всегда целые
    int positive_count = 0;
    int negative_count = 0;
    int zero_count = 0;
    for (int i = 0; i < size; i++) {
        if (user_array[i] == 0) {
            zero_count++;
        }
        else if (user_array[i] > 0) {
            positive_count++;
        }
        else {
            negative_count++;
        }
    }
    counts_array[0] = positive_count;
    counts_array[1] = negative_count;
    counts_array[2] = zero_count;
}

// Домашнее задание 2

// Задание 1
void Square_matrix_initialization(char matrix[][5], int size) { // для char особый случай
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 128;
        }
    }
}

template <typename NumType>
void Square_matrix_initialization(NumType matrix[][5], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 10000) / 100.0;
        }
    }
}

template <typename T>
void Cout_square_matrix(T matrix[][5], int size) {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Min_max_main_diagonal(T matrix[][5], int size, T min_max_array[], int min_max_size = 2) {
    int min = matrix[0][0];
    int max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }else if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }
    min_max_array[0] = min;
    min_max_array[1] = max;
}

template <typename T>
void Sort_square_matrix(T matrix[][5], int size) {
    for (int i = 0; i < size; i++) {
        int key = 0;
        for (int j = 1; j < size; j++) {
            key = matrix[i][j];
            int previos = j - 1;
            while (previos >= 0 && key < matrix[i][previos]) {
                matrix[i][previos + 1] = matrix[i][previos];
                previos--;
            }
            matrix[i][previos + 1] = key;
        }   
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Домашнее задание 1

    // Задание 1
    cout << "\tДля первой даты:" << endl;
    cout << "Введите год: ";
    int user_year1;
    cin >> user_year1;
    cout << "Введите месяц: ";
    int user_month1;
    cin >> user_month1;
    cout << "Введите день: ";
    int user_day1;
    cin >> user_day1;

    cout << "\tДля второй даты:" << endl;
    cout << "Введите год: ";
    int user_year2;
    cin >> user_year2;
    cout << "Введите месяц: ";
    int user_month2;
    cin >> user_month2;
    cout << "Введите день: ";
    int user_day2;
    cin >> user_day2;

    cout << "\xB3Количество дней между датами: " << Day_count(user_day1, user_month1, user_year1, user_day2, user_month2, user_year2);

    cout << endl << "-----------------------------------------" << endl;
    // Задание 2
    const int size_two = 10;
    float array_two[size_two];
    Rand_array(array_two, size_two);
    Cout_array(array_two, size_two);
    cout << Array_average(array_two, size_two);

    cout << endl << "-----------------------------------------" << endl;
    // Задание 3
    const int size_three = 40;
    int array_three[size_three];
    Rand_array(array_three, size_three);
    Cout_array(array_three, size_three);

    const int counts_size = 3;
    int counts_array[counts_size];
    Array_counts(array_three, size_three, counts_array);
    cout << "Кол-во положительных: " << counts_array[0] << ", отрицательных: " << counts_array[1] << ", нулей: " << counts_array[2];

    // Домашнее задание 2

    cout << endl << "-----------------------------------------" << endl;
    // Задание 1
    const int square_matrix_size = 5;
    char square_matrix[square_matrix_size][square_matrix_size]; // можно изменить тип, так как на char не очень удобно проверять
    Square_matrix_initialization(square_matrix, square_matrix_size);
    cout << "Изначальная матрица:" << endl;
    Cout_square_matrix(square_matrix, square_matrix_size);

    char min_max_array[2]; // усли поменяли тип square_matrix, надо поменять тип min_max_array на тот, который у square_matrix
    Min_max_main_diagonal(square_matrix, square_matrix_size, min_max_array);
    cout << "Минимальный элемент главной диагонали: " << min_max_array[0];
    cout << " Максимальный элемент главной диагонали: " << min_max_array[1] << endl;
    cout << "Отсортированная матрица:" << endl;
    Sort_square_matrix(square_matrix, square_matrix_size);
    Cout_square_matrix(square_matrix, square_matrix_size);

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
