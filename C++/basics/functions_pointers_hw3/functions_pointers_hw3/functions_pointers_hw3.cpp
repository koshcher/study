// functions_pointers_hw3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

template <typename NumType>
void Array_generation(NumType* array, const int& size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        *(array + i) = (rand() % 10000) / 100.0;
    }
}

template <typename NumType>
void Array_print(NumType* array, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Задание 1
template <typename NumType>
double* Copy_array_averages(NumType* array_a, const int& size) {
    double* array_b = new double[size];
    for (int k = 0; k < size; k++) {
        NumType sum = 0;
        for (int i = k; i < size; i++) {
            sum += *(array_a + i);
        }
        *(array_b + k) = (double)sum / (size - k);
    }
    return array_b;
}

// Задание 2

double f_square(const double& x) {
    return x * x - 5 * x + 10;
}

double f_sin(const double& x) {
    return x * sin(x) - x;
}

double Average_f(double a, double b, double (*f)(const double& x)) {
    double lowest = (a < b) ? a : b;
    double highest = (a > b) ? a : b;
    double sum_f = 0;
    int counter = 0;

    for (double i = lowest; i <= highest; i += 0.1) {
        sum_f += f(i);
        counter++;
    }
    return sum_f / counter;
}

double Min_max_difference_f(double a, double b, double (*f)(const double& x)) {
    double lowest = (a < b) ? a : b;
    double highest = (a > b) ? a : b;
    double max_f = f(lowest);
    double min_f = f(lowest);

    for (double i = lowest + 0.1; i <= highest; i += 0.1) {
        double f_i = f(i);
        if (f_i > max_f) {
            max_f = f_i;
        }
        else if (f_i < min_f) {
            min_f = f_i;
        }
    }
    return max_f - min_f;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int size1 = 10;
    double* array_a = new double[size1];
    Array_generation(array_a, size1);
    cout << "Начальный массив: ";
    Array_print(array_a, size1);
    double* array_b = Copy_array_averages(array_a, size1);
    cout << "Результирующий массив: ";
    Array_print(array_b, size1);

    cout << "------------------------" << endl;

    typedef double(*fs)(const double& x);
    fs fs_array[] = { f_square, f_sin };

    cout << "Выберете f: " << endl;
    cout << "[1] f(x) = x * x - 5 * x + 10" << endl;
    cout << "[2] f(x) = x * sin(x) - x;" << endl;
    int user_f;
    cin >> user_f;
    cout << "Введите первую границу: " << endl;
    double border1;
    cin >> border1;
    cout << "Введите вторую границу: " << endl;
    double border2;
    cin >> border2;

    cout << "Средние f: " << Average_f(border1, border2, fs_array[user_f - 1]) << endl;

    cout << "------------------------" << endl;

    cout << "Выберете f: " << endl;
    cout << "[1] f(x) = x * x - 5 * x + 10" << endl;
    cout << "[2] f(x) = x * sin(x) - x;" << endl;
    cin >> user_f;
    cout << "Введите первую границу: " << endl;
    cin >> border1;
    cout << "Введите вторую границу: " << endl;
    cin >> border2;

    cout << "Разница между максимальным и минимальным f: " << Min_max_difference_f(border1, border2, fs_array[user_f - 1]) << endl;

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
