// matrices_homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // Задание 1
    const int m = 12;
    const int n = 15;

    int m_array[12];
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        m_array[i] = rand() % 100;
    }

    cout << "Матрица к заданию 1:" << endl;
    int matric_one[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matric_one[i][j] = m_array[i];
            cout << matric_one[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 2
    const int row_two = 17;
    const int col_two = 21;
    int matric_two[row_two][col_two];

    cout << "Матрица к заданию 2" << endl;
    for (int i = 0; i < row_two; i++) {
        int rand0_index = rand() % (col_two + 1);
        for (int j = 0; j < col_two; j++) {
            if (j == rand0_index) {
                matric_two[i][j] = 0;
            }
            else {
                matric_two[i][j] = (rand() % 9) + 1; // в задаче не указано, что находится в других ячейках
            }
            cout << matric_two[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 3
    const int row_three = 13;
    const int col_three = 18;
    int matric_three[row_three][col_three] = {};

    int rand_index = 0;
    int previos_rand_index = 0;
 
    for (int j = 0; j < col_three; j++) {
        for (int a = 0; a < (j + 1); a++) {
            do {
                rand_index = rand() % row_three;
            } while (previos_rand_index == rand_index);
            matric_three[rand_index][j] = 1;
            previos_rand_index = rand_index;
        }
    }

    cout << "Матрица к заданию 3" << endl;
    for (int i = 0; i < row_three; i++) {
        for (int j = 0; j < col_three; j++) {
            cout << matric_three[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 4
    int sum_four = 0;

    for (int i = 0; i < row_three; i++) {
        for (int j = 0; j < col_three; j++) {
            sum_four += matric_three[i][j];
        }
    }

    cout << "Сумма всех элементов матрицы: " << sum_four << endl << endl;

    // Задание 5
    const int row_five = 13;
    const int col_five = 18;
    int matric_five[row_five][col_five];

    for (int i = 0; i < row_five; i++) {
        for (int j = 0; j < col_five; j++) {
            matric_five[i][j] = rand() % 100 - 50;\
        }
    }

    for (int i = 0; i < row_five; i++) {
        int negative_count = 0;
        int second_negative_num_index = 0;
        for (int j = 0; j < col_five && negative_count != 2; j++) {
            if (matric_five[i][j] < 0) {
                negative_count++;
                second_negative_num_index = j;
            }
        }

        int max = matric_five[i][second_negative_num_index + 1];
        for (int a = second_negative_num_index + 1; a < col_five; a++) {
            max = matric_five[i][a];
            int index = a;
            for (int b = a + 1; b < col_five; b++) {
                if (matric_five[i][b] > max) {
                    max = matric_five[i][b];
                    index = b;
                }
            }
            int tmp = matric_five[i][a];
            matric_five[i][a] = max;
            matric_five[i][index] = tmp;
        }
    }

    cout << "Матрица к заданию 5" << endl;
    for (int i = 0; i < row_five; i++) {
        for (int j = 0; j < col_five; j++) {
            cout << matric_five[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Задание 6
    for (int i = 0; i < row_five; i++) {
        int min = matric_five[i][0];
        for (int j = 1; j < col_five; j++) {
            if (matric_five[i][j] < min) {
                min = matric_five[i][j];
            }
        }
        cout << "В стороке " << i + 1 << " наименьшее число: " << min << endl;
    }
    cout << endl;

    // Задание 7
    for (int j = 0; j < col_five; j++) {
        int tmp = matric_five[0][j];
        matric_five[0][j] = matric_five[row_five - 1][j];
        matric_five[row_five - 1][j] = tmp;
    }

    cout << "Матрица к заданию 7" << endl;
    for (int i = 0; i < row_five; i++) {
        for (int j = 0; j < col_five; j++) {
            cout << matric_five[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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
