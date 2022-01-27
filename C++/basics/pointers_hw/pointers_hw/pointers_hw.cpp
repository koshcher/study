// pointers_hw.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

// Task 1
void Copy_array(int* array_from, const int* size_array_from, int* array_to, const int* size_array_to) {
    for (int i = 0; i < *size_array_from; i++) {
        *(array_to + i) = *(array_from + i);
    }
}

void Array_generation(int* array, const int* size) {
    srand(time(NULL));
    for (int i = 0; i < *size; i++) {
        *(array + i) = rand() % 10;
    }
}

void Print_array(int* array, const int* size) {
    for (int i = 0; i < *size; i++) {
        cout << *(array + i) << " ";
    }
}

//Task 2
void Change_array_order(int* array, const int* size) {
    int tmp = 0;
    for (int i = 0; i < *size/2; i++) {
        tmp = *(array + i);
        *(array + i) = *(array +(*size - i - 1));
        *(array + (*size - i - 1)) = tmp;
    }
}

//Task 3
void Copy_array_changing_order(int* array_from, const int* size_array_from, int* array_to, const int* size_array_to) {
    for (int i = 0; i < *size_array_from; i++) {
        *(array_to + i) = *(array_from + +(*size_array_from - i - 1));
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    //Task 1
    const int size_one = 10;
    int* array_one = new int[size_one];
    Array_generation(array_one, &size_one);
    cout << "Первый массив: ";
    Print_array(array_one, &size_one);
    cout << endl;

    int* copy_array_one = new int[size_one];
    Copy_array(array_one, &size_one, copy_array_one, &size_one);
    cout << "Второй массив: ";
    Print_array(copy_array_one, &size_one);

    delete[] copy_array_one;
    delete[] array_one;

    //Task 2
    cout << endl << "--------------------------------------------------" << endl;
    const int size_two = 10;
    int* array_two = new int[size_two];
    Array_generation(array_two, &size_two);
    cout << "Изначаньный массив: ";
    Print_array(array_two, &size_two);
    cout << endl;
    Change_array_order(array_two, &size_two);
    cout << "Конечный массив: ";
    Print_array(array_two, &size_two);

    delete[] array_two;

    //Task 3
    cout << endl << "--------------------------------------------------" << endl;
    const int size_tree = 17;
    int* array_tree = new int[size_tree];
    Array_generation(array_tree, &size_tree);
    cout << "Первый массив: ";
    Print_array(array_tree, &size_tree);
    cout << endl;

    int* copy_array_tree = new int[size_tree];
    Copy_array_changing_order(array_tree, &size_tree, copy_array_tree, &size_tree);
    cout << "Второй массив: ";
    Print_array(copy_array_tree, &size_tree);

    delete[] copy_array_tree;
    delete[] array_tree;
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
