// matrics_hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // Задание 1
    const int row_one = 10;
    const int col_one = 10;
    int array_one[row_one][col_one];

    srand(time(NULL));
    cout << "Изначальный массив к заданию 1: " << endl;
    for (int i = 0; i < row_one; i++) {
        for (int j = 0; j < col_one; j++) {
            array_one[i][j] = rand() % 100;
            cout << array_one[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int min = array_one[0][0];
    int tmp = 0;
    int index = 0;
    for (int j = 0; j < col_one; j++) {
        min = array_one[0][j];
        index = j;

        for (int i = j + 1; i < col_one; i++) {
            if (array_one[0][i] < min) {
                min = array_one[0][i];
                index = i;
            }
        }
        for (int row = 0; row < row_one; row++) {
            tmp = array_one[row][j];
            array_one[row][j] = array_one[row][index];
            array_one[row][index] = tmp;
        }
    }

    cout << "Конечный массив к заданию 1: " << endl;
    for (int i = 0; i < row_one; i++) {
        for (int j = 0; j < col_one; j++) {
            cout << array_one[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;

    // Задание 2
    const int row_two = 10;
    const int col_two = 10;
    int array_two[row_two][col_two];

    cout << "Изначальный массив к заданию 2: " << endl;
    for (int i = 0; i < row_two; i++) {
        for (int j = 0; j < col_two; j++) {
            array_two[i][j] = rand() % 100;
            cout << array_two[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int max_in_rows[row_two];
    int max = array_two[0][0];

    for (int i = 0; i < row_two; i++) {
        max = array_two[i][0];
        for (int j = 1; j < col_two; j++) {
            if (array_two[i][j] > max) {
                max = array_two[i][j];
            }
        }
        max_in_rows[i] = max;
    }

    int min_from_max = max_in_rows[0];
    int del_row_index = 0;
    for (int i = 1; i < row_two; i++) {
        if (max_in_rows[i] < min_from_max) {
            min_from_max = max_in_rows[i];
            del_row_index = i;
        }
    }

    int new_array_two[row_two - 1][col_two];
    int count = 0;

    for (int i = 0; i < row_two; i++) {
        if (i != del_row_index) {
            for (int j = 0; j < col_two; j++) {
                new_array_two[count][j] = array_two[i][j];
            }
            count++;
        }
    }

    cout << "Конечный массив к заданию 2: " << endl;
    for (int i = 0; i < row_two - 1; i++) {
        for (int j = 0; j < col_two; j++) {
            cout << new_array_two[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;

    // Задание 3
    const int total_three = 4;
    const int row_3_1 = 3;
    const int col_3_2 = 5;
    int matric_3_1[row_3_1][total_three];
    int matric_3_2[total_three][col_3_2];

    cout << "Данные матрицы: " << endl;
    for (int i = 0; i < row_3_1; i++) {
        for (int j = 0; j < total_three; j++) {
            matric_3_1[i][j] = rand() % 100;
            cout << matric_3_1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < total_three; i++) {
        for (int j = 0; j < col_3_2; j++) {
            matric_3_2[i][j] = rand() % 100;
            cout << matric_3_2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Перемноженная матрица: " << endl;
    int multiplied_matric[row_3_1][col_3_2] = {};
    for (int i = 0; i < row_3_1; i++) {
        for (int j = 0; j < col_3_2; j++) {

            for (int position = 0; position < total_three; position++) {
                multiplied_matric[i][j] += matric_3_1[i][position] * matric_3_2[position][j];
            }
            
            cout << multiplied_matric[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;

    // Задание 4
    const int m = 9;
    const int n = 4;
    int matric_four[m][n] = {};

    count = 1;
    for (int i = 0; i < m / 2 +1; i++) {
        if (matric_four[i][i] == 0) {
            for (int j = i; j < (n - i); j++) {
                matric_four[i][j] = count;
                count++;
            }
        }

        if (matric_four[i + 1][n - i - 1] == 0) {
            for (int j = i + 1; j <= (m - i - 1); j++) {
                matric_four[j][n - i - 1] = count;   
                count++;
            }
        }
        
        if (matric_four[m - i - 1][n - i - 2] == 0) {
            for (int j = n - i - 2; j >= i; j--) {  
                matric_four[m - i - 1][j] = count;   
                count++;
            }
        }
        
        if (matric_four[m - i - 2][i] == 0) {
            for (int j = m - i - 2; j > i; j--) {
                matric_four[j][i] = count;
                count++;
            }
        }
    }

     cout << "матрица: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)  {
            cout << matric_four[i][j] << "\t";
        }
        cout << endl;
    }
    

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;
    
    // Задание 5
    const int cube_size = 5;
    int cube[cube_size][cube_size][cube_size];

    int rand_num = 0;
    for (int x = 0; x < cube_size; x++) {
        for (int y = 0; y < cube_size; y++) {
            for (int z = 0; z < cube_size; z++) {
                rand_num = rand() % 4;
                if (rand_num == 1) {
                    cube[x][y][z] = 1;
                }
                else {
                    cube[x][y][z] = 0;
                }
                
            }
        }
    }

    int filled_unit_num = 0;
    // Первое измерение

    for (int x = 0; x < cube_size; x++) {
        for (int y = 0; y < cube_size; y++) {
            filled_unit_num = 0;
            for (int z = 0; z < cube_size; z++) {
                if (cube[x][y][z] == 1) {
                    filled_unit_num++;
                }
            }
            if (filled_unit_num == 0) {
                cout << "Просвет x= " << x << "; y= " << y << endl;
            }
        }
    }
    // Второе измерение
    for (int y = 0; y < cube_size; y++) {
        for (int z = 0; z < cube_size; z++) {
            filled_unit_num = 0;
            for (int x = 0; x < cube_size; x++) {
                if (cube[x][y][z] == 1) {
                    filled_unit_num++;
                }
            }
            if (filled_unit_num == 0) {
                cout << "Просвет y= " << y << "; z= " << z << endl;
            }
        }
    }
    // Третье измерение
    for (int z = 0; z < cube_size; z++) {
        for (int x = 0; x < cube_size; x++) {
            filled_unit_num = 0;
            for (int y = 0; y < cube_size; y++) {
                if (cube[x][y][z] == 1) {
                    filled_unit_num++;
                }
            }
            if (filled_unit_num == 0) {
                cout << "Просвет z= " << z << "; x= " << x << endl;
            }
        }
    }

    cout << endl << "--------------------------------------------------------------------------" << endl << endl;

    // Дополнительное задание: сглаживания матрицы 
    const int add_row = 3;
    const int add_col = 5;
    long long add_array[add_row][add_col];  // при int выдаёт кучу предупреждений

    cout << "Изначальный матрица к дополнительному заданию: " << endl;
    for (int i = 0; i < add_row; i++) {
        for (int j = 0; j < add_col; j++) {
            add_array[i][j] = rand() % 100;
            cout << add_array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    double smoothed_matric[add_row][add_col]; // float так как среднее значение не всегда целое
    for (int i = 0; i < add_row; i++) {
        for (int j = 0; j < add_col; j++) {
            if (i == 0) {
                if (j == 0) { // самая верхняя строка
                    smoothed_matric[i][j] = (add_array[0][1] + add_array[1][0]) / 2.0;
                }
                else if (j == add_col - 1) {
                    smoothed_matric[i][j] = (add_array[0][add_col - 2] + add_array[1][add_col - 1]) / 2.0;
                }
                else {
                    smoothed_matric[i][j] = (add_array[0][j - 1] + add_array[0][j + 1] + add_array[1][j]) / 3.0;
                }
            } 
            else if (i == add_row - 1) { // самая нижняя строка
                if (j == 0) {
                    smoothed_matric[i][j] = (add_array[add_row - 2][0] + add_array[add_row - 1][1]) / 2.0;
                }
                else if (j == add_col - 1) {
                    smoothed_matric[i][j] = (add_array[add_row - 1][add_col - 2] + add_array[add_row - 2][add_col - 1]) / 2.0;
                }
                else {
                    smoothed_matric[i][j] = (add_array[add_row - 1][j - 1] + add_array[add_row - 1][j + 1] + add_array[add_row - 2][j]) / 3.0;
                }
            }
            else if (j == 0) { // самая правая строка
                smoothed_matric[i][j] = (add_array[i - 1][0] + add_array[i + 1][0] + add_array[i][1]) / 3.0;
            }
            else if (j == add_col - 1) { // самая правая строка
                smoothed_matric[i][j] = (add_array[i - 1][add_col - 1] + add_array[i + 1][add_col - 1] + add_array[i][add_col - 2]) / 3.0;
            }
            else {
                smoothed_matric[i][j] = (add_array[i - 1][j] + add_array[i + 1][j] + add_array[i][j - 1] + add_array[i][j + 1]) / 4.0;
            }
        }
    }

    cout << "Сглаженная матрица к дополнительному заданию: " << endl;
    for (int i = 0; i < add_row; i++) {
        for (int j = 0; j < add_col; j++) {
            cout << smoothed_matric[i][j] << "\t";
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
