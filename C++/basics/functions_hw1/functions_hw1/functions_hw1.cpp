// functions_hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Time.h"
#include <math.h> 

using namespace std;

// Домашнее задание 1

// Задание 1
int Num_degree(int base, int exponent) {
    int num_degree = base;
    if (exponent == 0) {
        return 1;
    }
    for (int i = 1; i < exponent; i++) {
        num_degree = num_degree * base;
    }
    return num_degree;
}

// Задание 2
int Range_between_sum(int operand1, int operand2) {
    int bigger_border = (operand1 > operand2) ? operand1 : operand2;
    int smaller_border = (operand1 < operand2) ? operand1 : operand2;

    int sum = 0;
    for (int i = smaller_border + 1; i < bigger_border; i++) {
        sum += i;
    }
    return sum;
}

// Задание 3
void Perfect_number(int operand1, int operand2) {
    int bigger_border = (operand1 > operand2) ? operand1 : operand2;
    int smaller_border = (operand1 < operand2) ? operand1 : operand2;

    for (int i = smaller_border + 1; i < bigger_border; i++) {
        int divisor_sum = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                divisor_sum++;
            }
        }
        if (divisor_sum == i) {
            cout << i << " ";
        }
    }
}

// Задание 4
void Print_card(int suit, int value) {
    setlocale(LC_ALL, "C");
    cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
    switch (value) {
    case 11:
        setlocale(LC_ALL, "C");
        cout << "\xB3";
        setlocale(LC_ALL, "ru");
        cout << "ВАЛЕТ";
        setlocale(LC_ALL, "C");
        cout << " \xB3" << endl; 
        break;
    case 12:
        setlocale(LC_ALL, "C");
        cout << "\xB3";
        setlocale(LC_ALL, "ru");
        cout << "ДАМА";
        setlocale(LC_ALL, "C");
        cout << "  \xB3" << endl;
        break;
    case 13:
        setlocale(LC_ALL, "C");
        cout << "\xB3";
        setlocale(LC_ALL, "ru");
        cout << "КОРОЛЬ";
        setlocale(LC_ALL, "C");
        cout << "\xB3" << endl;
        break;
    case 14:
        setlocale(LC_ALL, "C");
        cout << "\xB3";
        setlocale(LC_ALL, "ru");
        cout << "ТУЗ";
        setlocale(LC_ALL, "C");
        cout << "   \xB3" << endl;
        break;
    case 10: 
        setlocale(LC_ALL, "C");
        cout << "\xB3" << "10" << "    \xB3" << endl;
        break;
    default: 
        setlocale(LC_ALL, "C");
        cout << "\xB3" << value << "     \xB3" << endl;
        break;
    }

    cout << "\xB3      \xB3" << endl;

    switch (suit) {
    case 1: 
        setlocale(LC_ALL, "C");
        cout << "\xB3" << " /\\/\\ " << "\xB3" << endl; // Червы
        cout << "\xB3" << " \\  / " << "\xB3" << endl;
        cout << "\xB3" << "  \\/  " << "\xB3" << endl;
        cout << "\xB3" << "      " << "\xB3" << endl;
        break;
    case 2:
        setlocale(LC_ALL, "C");
        cout << "\xB3" << "  /\\  " << "\xB3" << endl;  // Бубны
        cout << "\xB3" << " /  \\ " << "\xB3" << endl;
        cout << "\xB3" << " \\  / " << "\xB3" << endl;
        cout << "\xB3" << "  \\/  " << "\xB3" << endl;
        break;
    case 3: 
        setlocale(LC_ALL, "C");
        cout << "\xB3" << "  /\\  " << "\xB3" << endl; // Трефы
        cout << "\xB3" << " _\\/_ " << "\xB3" << endl;
        cout << "\xB3" << " \\/\\/ " << "\xB3" << endl;
        cout << "\xB3" << "  /\\  " << "\xB3" << endl;
        break;
    case 4: 
        setlocale(LC_ALL, "C");
        cout << "\xB3" << "  /\\  " << "\xB3" << endl; // Пики
        cout << "\xB3" << " /  \\ " << "\xB3" << endl;
        cout << "\xB3" << " \\/\\/ " << "\xB3" << endl;
        cout << "\xB3" << "  /\\  " << "\xB3" << endl; 
        break;
    }

    cout << "\xB3      \xB3" << endl;

    switch (value) {
    case 11:
        setlocale(LC_ALL, "C");
        cout << "\xB3 ";
        setlocale(LC_ALL, "ru");
        cout << "ВАЛЕТ";
        setlocale(LC_ALL, "C");
        cout << "\xB3" << endl;
        break;
    case 12:
        setlocale(LC_ALL, "C");
        cout << "\xB3  ";
        setlocale(LC_ALL, "ru");
        cout << "ДАМА";
        setlocale(LC_ALL, "C");
        cout << "\xB3" << endl;
        break;
    case 13:
        setlocale(LC_ALL, "C");
        cout << "\xB3";
        setlocale(LC_ALL, "ru");
        cout << "КОРОЛЬ";
        setlocale(LC_ALL, "C");
        cout << "\xB3" << endl;
        break;
    case 14:
        setlocale(LC_ALL, "C");
        cout << "\xB3   ";
        setlocale(LC_ALL, "ru");
        cout << "ТУЗ";
        setlocale(LC_ALL, "C");
        cout << "\xB3" << endl;
        break;
    case 10:
        setlocale(LC_ALL, "C");
        cout << "\xB3    " << "10" << "\xB3" << endl;
        break;
    default:
        setlocale(LC_ALL, "C");
        cout << "\xB3     " << value << "\xB3" << endl;
        break;
    }
    cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
}

// Задание 5
bool Is_num_lucky(int num) {  //Счастли́вое число́ — натуральное число из множества, генерируемого «решетом», аналогичным решету Эратосфена, которое генерирует простые числа.
    if (num > 999999 || num < 100000) {
        cout << "Переданное число не является шестизначным" << endl;
        return 0;
    }
    if (num % 2 == 0) {
        return 0;
    }
    else if (num % 3 == 2) {
        return 0;
    }
    else if (num % 7 == 5) {
        return 0;
    }
    else {
        return 1;
    }
}

// Домашнее задание 2

// Задание 1
int Linear_search_key(int key, int searching_array[], int size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (searching_array[i] == key) {
            return index;
        }
        cout << "В массиве нет заданого ключа" << endl;
        return -1;
    }
}

// Задание 2
int Binary_search_key(int key, int searching_array[], int size) { // только в отсортированном массиве
    int mid = size / 2;
    int max_operation_count = log2((double)size);  // можем записывать в инт, так как работаем с целыми числами
    for (int i = 0; i < max_operation_count; i++) {
        if (searching_array[mid] == key) {
            return mid;
        }
        else if (searching_array[mid] > key) {
            mid = (size - mid) / 2;
        }
        else {
            mid = (size - mid) / 2 + mid;
        }
    }
    cout << "В массиве нет заданого ключа" << endl;
    return -1;
}

// Задание 3
int Binary_to_decimal(int num) {
    int decimal_num = 0;

    for (int i = 1; num > 0; i = i * 2) {
        if (num % 10 == 1) {
            decimal_num += i;
        }
        num = num / 10;
    }

    return decimal_num;
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Домашнее задание 1

    // Задание 1
    int user_base;
    cout << "Введите основание степени: ";
    cin >> user_base;
    int user_exponent;
    cout << "Введите показатель степени: ";
    cin >> user_exponent;
    cout << "Степень числа: " << Num_degree(user_base, user_exponent) << endl;

    cout << "------------------------------------------" << endl;
    // Задание 2
    int user_border1;
    cout << "Введите первую границу диапозона: ";
    cin >> user_border1;
    int user_border2;
    cout << "Введите вторую границу диапозона: ";
    cin >> user_border2;
    cout << "Сумма чисел из диапазона: " << Range_between_sum(user_border1, user_border2) << endl;
    
    cout << "------------------------------------------" << endl;
    // Задание 3
    int user_limit1;
    cout << "Введите первую границу диапозона: ";
    cin >> user_limit1;
    int user_limit2;
    cout << "Введите вторую границу диапозона: ";
    cin >> user_limit2;
    cout << "Совершенные числа в диапозоне: ";
    Perfect_number(user_limit1, user_limit2);
    cout << endl;

    cout << "------------------------------------------" << endl;
    // Задание 4
    cout << "Введите масть: " << endl;
    cout << "[1] Червы" << endl;
    cout << "[2] Бубны" << endl;
    cout << "[3] Трефы" << endl;
    cout << "[4] Пики" << endl;
    int user_suit;
    cin >> user_suit;

    cout << "Введите карту: " << endl;
    cout << "[11] Валет" << endl;
    cout << "[12] Дама" << endl;
    cout << "[13] Король" << endl;
    cout << "[14] Туз" << endl;
    cout << "Для остальных просто введите цифру" << endl;
    int user_value;
    cin >> user_value;
    Print_card(user_suit, user_value);

    cout << "------------------------------------------" << endl;
    // Задание 5
    setlocale(LC_ALL, "ru");
    int six_digit_num;
    cout << "Введите шестизначное число: ";
    cin >> six_digit_num;
    if (Is_num_lucky(six_digit_num) == 1) {
        cout << "Введённое шестизначное число является счастливым!" << endl;
    }
    else {
        cout << "Введённое шестизначное число НЕ является счастливым!" << endl;
    }

    // Домашнее задание 2

    cout << "------------------------------------------" << endl;
    // Задание 1
    const int size_one = 10;
    int array_one[size_one];
    srand(time(NULL));
    cout << "Изначальный массив: ";
    for (int i = 0; i < size_one; i++) {
        array_one[i] = rand() % 10;
        cout << array_one[i] << " ";
    }
    cout << endl;

    int user_key1;
    cout << "Введите ключ: ";
    cin >> user_key1;
    int key_index1 = Linear_search_key(user_key1, array_one, size_one);
    if (key_index1 != -1) {
        cout << "Индекс ключа: " << key_index1 << endl;
    }
    cout << "------------------------------------------" << endl;
    // Задание 2
    const int size_two = 10;
    int array_two[size_two];

    for (int i = 0; i < size_two; i++) {
        array_two[i] = rand() % 10;
    }
   
    // Сортировка, так как бинарный поиск работает только с отсортированными массивами
    int tmp = 0;
    for (int i = 1; i < size_two; i++) {
        for (int j = 0; j < i; j++) {
            if (array_two[i] < array_two[j]) {
                tmp = array_two[j];
                array_two[j] = array_two[i];
                array_two[i] = tmp;
            }
        }
    }

    cout << "Изначальный массив: " << endl;
    for (int i = 0; i < size_two; i++) {
        cout << array_two[i] << " ";
    }
    cout << endl;
    
    int user_key2;
    cout << "Введите ключ: ";
    cin >> user_key2;
    int key_index2 = Binary_search_key(user_key2, array_two, size_two);
    if (key_index2 != -1) {
        cout << "Индекс ключа: " << key_index2 << endl;
    }

    cout << "------------------------------------------" << endl;
    // Задание 3
    int binary_num;
    cout << "Введите число в двоичном виде: ";
    cin >> binary_num;
    cout << "Число в десятичном виде: " << Binary_to_decimal(binary_num) << endl;;

    system("pause");
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
