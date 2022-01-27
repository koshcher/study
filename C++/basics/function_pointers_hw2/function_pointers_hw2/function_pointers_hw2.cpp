// function_pointers_hw2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
void Array_generation(T* array, const int& size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 10000 / 100.0;
    }
}

template <typename T>
void Array_print(T* array, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}


template <typename T>
T Max(T* array_1, const int& size_1, T* array_2, const int& size_2) {
    T max = *array_1;
    for (int i = 1; i < size_1; i++) {
        if (*(array_1 + i) > max) {
            max = *(array_1 + i);
        }
    }
    for (int i = 0; i < size_2; i++) {
        if (*(array_2 + i) > max) {
            max = *(array_2 + i);
        }
    }

    return max;
}

template <typename T>
T Min(T* array_1, const int& size_1, T* array_2, const int& size_2) {
    T min = *array_1;
    for (int i = 1; i < size_1; i++) {
        if (*(array_1 + i) < min) {
            min = *(array_1 + i);
        }
    }
    for (int i = 0; i < size_2; i++) {
        if (*(array_2 + i) < min) {
            min = *(array_2 + i);
        }
    }

    return min;
}

template <typename T>
T Average(T* array_1, const int& size_1, T* array_2, const int& size_2) {
    T sum = 0;
    for (int i = 0; i < size_1; i++) {
        sum += *(array_1 + i);
    }
    for (int i = 0; i < size_2; i++) {
        sum += *(array_2 + i);
    }

    return sum / (size_1 + size_2);
}

template <typename T>
T Action(T* array_a, const int& size_a, T* array_b, const int& size_b, T (*Function)(T* array_1, const int& size_1, T* array_2, const int& size_2)) {
    return Function(array_a, size_a, array_b, size_b);
}

int main()
{
    int user_size1;
    cout << "| Enter size 1: ";
    cin >> user_size1;
    float* user_array1 = new float[user_size1];
    Array_generation(user_array1, user_size1);
    cout << "| Array 1: ";
    Array_print(user_array1, user_size1);

    int user_size2;
    cout << "| Enter size 2: ";
    cin >> user_size2;
    float* user_array2 = new float[user_size2]; // можем поменять тип данных, но тогда надо поменять и в пользовательском типе функций
    Array_generation(user_array2, user_size2);
    cout << "| Array 2: ";
    Array_print(user_array2, user_size2);

    using function_type = float(*)(float* array_1, const int& size_1, float* array_2, const int& size_2); // здесь
    function_type functions_array[3] = { Max, Min, Average };

    int user_function;
    cout << "| Choose function: " << endl;
    cout << "| [1] Max" << endl;
    cout << "| [2] Min" << endl;
    cout << "| [3] Average" << endl;
    cin >> user_function;

    cout << "| Result: ";
    cout << Action(user_array1, user_size1, user_array2, user_size2, functions_array[user_function - 1]);
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
