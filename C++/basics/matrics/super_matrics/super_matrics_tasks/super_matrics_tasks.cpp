// super_matrics_tasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"
#include <algorithm> // для random shuffle

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // Магический квадрат
    const int n = 3;
    int matric_one[n][n];

    // Генерируем случайны квадрат из чисел 1, 2, ..., n2
    int matric_array[n * n];

    for (int i = 0; i < n * n; i++) {
        matric_array[i] = i + 1;
    }
    random_shuffle(begin(matric_array), end(matric_array));// случайная перестановка

    // Заполняем матрицу значениями массива
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int matric_array_index = i * n + j;
            matric_one[i][j] = matric_array[matric_array_index];
        }
    }

    // Выводим матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matric_one[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Проверяем, является ли магическим квадратом
    int main_sum = 0;
    int sum_for_checking = 0;
    bool is_sums_equal = true;

    // проверяем суммы диагоналей
    for (int i = 0; i < n; i++) {
        main_sum += matric_one[i][i]; // запишем суммы эл. из главной диагонали
        sum_for_checking += matric_one[n - 1 - i][n - 1 - i]; // запишем суммы эл. из побочной диагонали
    }
    if (sum_for_checking != main_sum) {
        is_sums_equal = false;
    }
    
    // Теперь проверяем строки и столбцы
    int col_sum = 0;
    for (int i = 0; i < n && is_sums_equal; i++) {
        main_sum = 0;
        col_sum = 0;
        for (int j = 0; j < n; j++) {
            main_sum += matric_one[i][j];
            col_sum += matric_one[j][i]; // можем сразу считать сумму столбцов, так как имеем квадратную матрицу
        }
        if ((main_sum != sum_for_checking) || (col_sum != sum_for_checking)) {
            is_sums_equal = false;
        }
        else {
            sum_for_checking = main_sum;
        }
    }
    if (is_sums_equal) {
        cout << "Данная матрица является магическим квадратом";
    }
    else {
        cout << "Данная матрица не является магическим квадратом";
    }
    cout << endl;

    // Создаём свой магический квадрат
    int magic_square[n][n];
    int magic_square_array[n * n];

    for (int i = 0; i < n * n; i++) {
        magic_square_array[i] = i + 1;
    }

    bool is_magic_sums_equal = true;
    do {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int magic_square_array_index = i * n + j;
                magic_square[i][j] = magic_square_array[magic_square_array_index];
            }
        }

        // Проверяем, является ли магическим квадратом
        int magic_sum = 0;
        int magic_checking_sum = 0;
        is_magic_sums_equal = true;

        for (int i = 0; i < n; i++) {
            magic_sum += magic_square[i][i];
            magic_checking_sum += magic_square[n - 1 - i][n - 1 - i];
        }

        if (magic_checking_sum != magic_sum) {
            is_magic_sums_equal = false;
        }

        int magic_col_sum = 0;
        for (int i = 0; i < n && is_magic_sums_equal; i++) {
            magic_sum = 0;
            magic_col_sum = 0;
            for (int j = 0; j < n; j++) {
                magic_sum += magic_square[i][j];
                magic_col_sum += magic_square[j][i]; // можем сразу считать сумму столбцов, так как имеем квадратную матрицу
            }
            if ((magic_sum != magic_checking_sum) || (magic_col_sum != magic_checking_sum)) {
                is_magic_sums_equal = false;
            }
            else {
                magic_checking_sum = magic_sum;
            }
        }

        if (is_magic_sums_equal == true) {
            cout << "Магический квадрат: " << endl; 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << magic_square[i][j] << " ";
                }
                cout << endl;
            }
            
        }
    } while (next_permutation(begin(magic_square_array), end(magic_square_array)) && !is_magic_sums_equal); // выводит только один магический квадрат (первый)
    if (is_magic_sums_equal == false) {
        cout << "Не существует магического квадрата со стороний " << n << endl;
    }

    // Task 2
    cout << "---------------------------------------------------------------" << endl;
    const int size = 9;
    int matric_two[size][size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matric_two[i][j] = rand() % 2 ;
            cout << matric_two[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int zero_count = 0;
    int checking_count = 0;

    int max_zero_straight;

    // начинаем с диагоналей
    for (int i = 0; i < size; i++) {
        if (matric_two[i][i] == 0) {
            zero_count++;
        }
        if (matric_two[i][size - 1 - i] == 0) {
            checking_count++;
        }
    }

    if (zero_count > checking_count) {
        max_zero_straight = 1;
        checking_count = zero_count;
    }
    else {
        max_zero_straight = 2;
    }
    
    // check lines
    int line_index = 0;
    for (int i = 0; i < size; i++) {
        zero_count = 0;
        for (int j = 0; j < size; j++) {
            if (matric_two[i][j] == 0) {
                zero_count++;
            }
        }
        if (zero_count > checking_count) {
            max_zero_straight = 3;
            line_index = i;
            checking_count = zero_count;
        }
    }

    // checl columns
    int column_index = 0;
    for (int j = 0; j < size; j++) {
        zero_count = 0;
        for (int i = 0; i < size; i++) {
            if (matric_two[i][j] == 0) {
                zero_count++;
            }
        }
        if (zero_count > checking_count) {
            max_zero_straight = 4;
            column_index = j;
            checking_count = zero_count;
        }
    }

    switch (max_zero_straight) {
    case 3: cout << "Больше всего нулей содержится в строке с номером " << line_index + 1;
        break;
    case 4: cout << "Больше всего нулей содержится в столбике с номером " << column_index + 1;
        break;
    case 1: cout << "Больше всего нулей содержится в главной диагонале";
        break;
    case 2: cout << "Больше всего нулей содержится в побочной диагонале";
        break;
    }
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