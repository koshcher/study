// dinamic_array_hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
void Matrix_print(T** matrix, const int& rows, const int& cols) { // выделение памяти под столбцы и заполнение случайными значениями
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

template <typename T>
void Matrix_making(T** matrix, const int& rows, const int& cols) { // выделение памяти под столбцы и заполнение случайными значениями
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 256;
        }
    }
} 

template <typename T>
void Add_column(T**& array, const int& rows, int& cols, const int& index) {
    srand(time(NULL));
    T** new_array = new T* [rows];
    cols++;

    for (int i = 0; i < rows; i++) {
        new_array[i] = new T[cols];
        for (int j = 0; j < index; j++) {
            new_array[i][j] = array[i][j];
        }
        new_array[i][index] = rand() % 256; // подойдёт и для char
        for (int j = index + 1; j < cols; j++) {
            new_array[i][j] = array[i][j - 1];
        }
    }

    delete[] array;
    array = new_array;
}

template <typename T>
void Delete_column(T**& array, const int& rows, int& cols, const int& index) {
    srand(time(NULL));
    T** new_array = new T * [rows];
    cols--;

    for (int i = 0; i < rows; i++) {
        new_array[i] = new T[cols];

        for (int j = 0; j < index; j++) {
            new_array[i][j] = array[i][j];
        }

        for (int j = index; j < cols; j++) {
            new_array[i][j] = array[i][j + 1];
        }
    }

    delete[] array;
    array = new_array;
}

template <typename T>
void Cyclic_shift(T**& array, const int& rows, int& cols, const bool& shift_rows, const bool& shift_cols, const int& count, const bool& go_forward) {
    
    if (shift_rows == true) {
        T** new_array = new T * [rows];
        if (go_forward == true) {
            for (int i = 0; i < rows - count; i++) {
                new_array[i + count] = array[i];
            }
            for (int i = rows - count; i < rows; i++) {
                new_array[i + count - rows] = array[i];
            }
        }
        else {
            for (int i = count; i < rows; i++) {
                new_array[i - count] = array[i];
            }
            for (int i = 0; i < count; i++) {
                new_array[i + rows - count] = array[i];
            }
        }
        delete[] array;
        array = new_array;
        new_array = nullptr;
    }
    
    if (shift_cols == true) {
        T** new_array = new T * [rows];
        if (go_forward == true) {
            for (int i = 0; i < rows; i++) {
                new_array[i] = new T[cols];
                for (int j = 0; j < cols - count; j++) {
                    new_array[i][j + count] = array[i][j];
                }

                for (int j = cols - count; j < cols; j++) {
                    new_array[i][j - cols + count] = array[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < rows; i++) {
                new_array[i] = new T[cols];

                for (int j = count; j < cols; j++) {
                    new_array[i][j - count] = array[i][j];
                }

                for (int j = cols - count; j < cols; j++) {
                    new_array[i][j] = array[i][j - cols + count];
                }

                delete[] array[i];
            }
        }
        delete[] array;
        array = new_array;
        new_array = nullptr;
    }
}

template <typename T>
void Matrix_transpose(T** array, const int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            T tmp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = tmp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    int rows_size = 5;
    int cols_size = 5;
    int** user_array = new int* [rows_size];
    Matrix_making(user_array, rows_size, cols_size);
    Matrix_print(user_array, rows_size, cols_size);

    cout << "--------------------------------" << endl;

    int user_index;
    cout << "Введите индекс для добовления столбца: ";
    cin >> user_index;
    Add_column(user_array, rows_size, cols_size, user_index);
    Matrix_print(user_array, rows_size, cols_size);

    cout << "--------------------------------" << endl;

    cout << "Введите индекс для удаления столбца: ";
    cin >> user_index;
    Delete_column(user_array, rows_size, cols_size, user_index);
    Matrix_print(user_array, rows_size, cols_size);

    cout << "--------------------------------" << endl;

    bool go_forward = true;
    cout << "Выбирете направляние:" << endl;
    cout << "[0] Назад" << endl;
    cout << "[1] Вперёд" << endl;
    cin >> go_forward;

    int user_count = true;
    cout << "Введите число сдвига: " << endl;
    cin >> user_count;

    bool user_shift_rows = true;
    cout << "Сдвигать строки?" << endl;
    cout << "[0] Нет" << endl;
    cout << "[1] Да" << endl;
    cin >> user_shift_rows;

    bool user_shift_cols = true;
    cout << "Сдвигать столбцы?" << endl;
    cout << "[0] Нет" << endl;
    cout << "[1] Да" << endl;
    cin >> user_shift_cols;

    Cyclic_shift(user_array, rows_size, cols_size, user_shift_rows, user_shift_cols, user_count, go_forward);
    Matrix_print(user_array, rows_size, cols_size);

    cout << "--------------------------------" << endl;

    int size = 5;
    int** user_squere = new int* [size];
    Matrix_making(user_squere, size, size);
    Matrix_print(user_squere, size, size);

    cout << endl;

    Matrix_transpose(user_squere, size);
    Matrix_print(user_squere, size, size);
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
