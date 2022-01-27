// pointers_hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

void Array_generation(int* array, const int& size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void Array_print(int* array, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int Only_1array_values_array(int* array_a, const int& size_a, int* array_b, const int& size_b, int* res_array) {
    int counter = 0;
    for (int i = 0; i < size_a; i++) {
        bool is_in_array_b = false;
        for (int j = 0; j < size_b; j++) {
            if (array_a[i] == array_b[j]) {
                is_in_array_b = true;
            }
        }

        bool is_in_res_array = false;
        for (int j = 0; j < counter; j++) {
            if (array_a[i] == res_array[j]) {
                is_in_res_array = true;
            }
        }

        if (is_in_array_b == false && is_in_res_array == false) {
            res_array[counter] = array_a[i];
            counter++;
        }
    }
    return counter;
}

void Rewrite_array(int* array, int* rewrote_array, const int& rewrote_size) {
    for (int i = 0; i < rewrote_size; i++) {
        rewrote_array[i] = array[i];
    }
}

int Different_values_array(int* array_a, const int& size_a, int* array_b, const int& size_b, int* res_array) {
    int counter = 0;
    for (int i = 0; i < size_a; i++) {
        bool is_in_array_b = false;
        for (int j = 0; j < size_b; j++) {
            if (array_a[i] == array_b[j]) {
                is_in_array_b = true;
            }
        }

        bool is_in_res_array = false;
        for (int j = 0; j < counter; j++) {
            if (array_a[i] == res_array[j]) {
                is_in_res_array = true;
            }
        }

        if (is_in_array_b == false && is_in_res_array == false) {
            res_array[counter] = array_a[i];
            counter++;
        }
    }

    for (int i = 0; i < size_b; i++) {
        bool is_in_array_a = false;
        for (int j = 0; j < size_a; j++) {
            if (array_b[i] == array_a[j]) {
                is_in_array_a = true;
            }
        }

        bool is_in_res_array = false;
        for (int j = 0; j < counter; j++) {
            if (array_b[i] == res_array[j]) {
                is_in_res_array = true;
            }
        }

        if (is_in_array_a == false && is_in_res_array == false) {
            res_array[counter] = array_b[i];
            counter++;
        }
    }
    return counter;
}

// 3-я задача с урока
int Delete_values_from_array(int* array, const int& size, bool del_even) {
    int counter = 0;
    if (del_even == true) {
        for (int i = 0; i < size; i++) {
            if (array[i] % 2 == 0) {
                for (int j = i + 1; j < size; j++) {
                    array[j - 1] = array[j];
                }
                array[size - 1] = 1; // чтобы не попало в бесконечный цыкл, ставим любое нечётное число 
                i--;
                counter++;
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if (array[i] % 2 != 0) {
                for (int j = i + 1; j < size; j++) {
                    array[j - 1] = array[j];
                }
                array[size - 1] = 0; // чтобы не попало в бесконечный цыкл, ставим любое чётное число
                i--;
                counter++;
            }
        }
    }
    return size - counter;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int size_m1 = 0;
    cout << "|Введите размер первого массива: ";
    cin >> size_m1;
    int size_n1 = 0;
    cout << "|Введите размер второго массива: ";
    cin >> size_n1;

    int* array_a1 = new int[size_m1];
    int* array_b1 = new int[size_n1];

    Array_generation(array_a1, size_m1);
    Array_generation(array_b1, size_n1);
    cout << "|Первый массив: ";
    Array_print(array_a1, size_m1);
    cout << "|Второй массив: ";
    Array_print(array_b1, size_n1);

    int size_array_ab1 = size_m1;
    int* array_ab1 = new int[size_array_ab1];
    size_array_ab1 = Only_1array_values_array(array_a1, size_m1, array_b1, size_n1, array_ab1);

    int* rewrote_array_ab1 = new int[size_array_ab1];
    Rewrite_array(array_ab1, rewrote_array_ab1, size_array_ab1);
    delete[] array_ab1;
    array_ab1 = rewrote_array_ab1;

    cout << "|Конечный массив: ";
    Array_print(array_ab1, size_array_ab1);

    delete[] array_a1;
    delete[] array_b1;
    delete[] array_ab1;

    cout << "----------------------------------" << endl;

    int size_m2 = 0;
    cout << "|Введите размер первого массива: ";
    cin >> size_m2;
    int size_n2 = 0;
    cout << "|Введите размер второго массива: ";
    cin >> size_n2;

    int* array_a2 = new int[size_m2];
    int* array_b2 = new int[size_n2];

    Array_generation(array_a2, size_m2);
    Array_generation(array_b2, size_n2);
    cout << "|Первый массив: ";
    Array_print(array_a2, size_m2);
    cout << "|Второй массив: ";
    Array_print(array_b2, size_n2);

    int size_array_ab2 = size_m2 + size_n2;
    int* array_ab2 = new int[size_array_ab2];
    size_array_ab2 = Different_values_array(array_a2, size_m2, array_b2, size_n2, array_ab2);

    int* rewrote_array_ab2 = new int[size_array_ab2];
    Rewrite_array(array_ab2, rewrote_array_ab2, size_array_ab2);
    delete[] array_ab2;
    array_ab2 = rewrote_array_ab2;

    cout << "|Конечный массив: ";
    Array_print(array_ab2, size_array_ab2);

    delete[] array_a2;
    delete[] array_b2;
    delete[] array_ab2;

    cout << "----------------------------------" << endl;

    int size_m3 = 0;
    cout << "|Введите размер массива: ";
    cin >> size_m3;

    bool del_even = false;
    cout << "|Какие числа вы хотите удалить?" << endl;
    cout << "[1] Чётные" << endl;
    cout << "[0] Нечётные" << endl;
    cin >> del_even;

    int* array_a3 = new int[size_m3];

    Array_generation(array_a3, size_m3);
    cout << "|Изначальный массив: ";
    Array_print(array_a3, size_m3);

    size_m3 = Delete_values_from_array(array_a3, size_m3, del_even);

    int* rewrote_array_a3 = new int[size_m3];
    Rewrite_array(array_a3, rewrote_array_a3, size_m3);
    delete[] array_a3;
    array_a3 = rewrote_array_a3;

    cout << "|Конечный массив: ";
    Array_print(array_a3, size_m3);
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
