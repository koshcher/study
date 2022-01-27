// pointers_hw3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;

// Задание 1
int* Dynamic_memory_allocation(int size) {
    return new int[size];
}

void Dynamic_array_initialization(int* array_ptr, const int& size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        *(array_ptr + i) = rand() % 20 - 10;
    }
}

void Dynamic_array_printing(int* array_ptr, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << *(array_ptr + i) << " ";
    }
    cout << endl;
}

void Delete_dynamic_array(int* array_ptr) {
    delete[] array_ptr;
}

int* Adding_element_to_array_end(int* array_ptr, int& size, const int& element) {
    int* new_array_ptr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        *(new_array_ptr + i) = *(array_ptr + i);
    }
    *(new_array_ptr + size) = element;
    size = size + 1;
    delete[] array_ptr;
    return new_array_ptr;
}

int* Inserting_element_at_index(int* array_ptr, int& size, const int& element, const int& index) {
    int* new_array_ptr = new int[size + 1];
    int counter = 0;
    for (int i = 0; i < size + 1; i++) {
        if (i != index) {
            *(new_array_ptr + i) = *(array_ptr + counter);
            counter++;
        }
        else {
            *(new_array_ptr + i) = element;
        }
    }
    size = size + 1;
    delete[] array_ptr;
    return new_array_ptr;
}

int* Delete_element_at_index(int* array_ptr, int& size, const int& index) {
    int* new_array_ptr = new int[size - 1];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            *(new_array_ptr + counter) = *(array_ptr + i);
            counter++;
        }
    }
    size = size - 1;
    delete[] array_ptr;
    return new_array_ptr;
}

// Задание 2
bool Is_num_prime(const int& num) {
    int count = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 1) {
        return true;
    }
    else {
        return false;
    }
}

int* Remove_prime_numbers(int* array_ptr, int& size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (Is_num_prime(*(array_ptr + i)) == true) {
            counter++; // counter считывает кол-во простых чисел
        }
    }
    int new_size = counter;
    int* new_array_ptr = new int[size];
    counter = 0;
    for (int i = 0; i < size; i++) { // заполняем простыми числами
        if (Is_num_prime(*(array_ptr + i)) == true) {
            *(new_array_ptr + counter) = *(array_ptr + i);
            counter++;
        }
    }
    size = new_size;
    delete[] array_ptr;
    return new_array_ptr;
}

// Задание 3
int** Distributes_elements(int* array_ptr, int& size) {
    int zero_count = 0;
    int pozitive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < size; i++) {
        if (*(array_ptr + i) > 0) {
            pozitive_count++;
        }
        else if (*(array_ptr + i) == 0) {
            zero_count++;
        }
        else {
            negative_count++;
        }
    }

    int** values_array = new int*[4]; // будем возвращщать указатель на массив указателей на массивы с положительными, нулями и негативными значениями
    int* pozitive_ptr = new int[pozitive_count];
    int* zero_ptr = new int[zero_count];
    int* negative_ptr = new int[negative_count];
    *values_array = pozitive_ptr;
    *(values_array + 1) = zero_ptr;
    *(values_array + 2) = negative_ptr;

    int* value_counts = new int[3]; // ещё один массив с размерами массивов со значениями
    *(values_array + 3) = value_counts;
    *value_counts = pozitive_count;
    *(value_counts + 1) = zero_count;
    *(value_counts + 2) = negative_count;

    zero_count = 0;
    pozitive_count = 0;
    negative_count = 0;
    for (int i = 0; i < size; i++) {
        if (*(array_ptr + i) > 0) {
            *(pozitive_ptr + pozitive_count) = *(array_ptr + i);
            pozitive_count++;
        }
        else if (*(array_ptr + i) == 0) {
            *(zero_ptr + zero_count) = *(array_ptr + i);
            zero_count++;
        }
        else {
            *(negative_ptr + negative_count) = *(array_ptr + i);
            negative_count++;
        }
    }
    return values_array;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Задание 1: " << endl;
    int size1;
    cout << "Введите размер массива: ";
    cin >> size1;
    int* array1_ptr = Dynamic_memory_allocation(size1);
    Dynamic_array_initialization(array1_ptr, size1);
    Dynamic_array_printing(array1_ptr, size1);
    cout << "--------------------------------" << endl;
    int user_element;
    cout << "Введите элемент: ";
    cin >> user_element;
    array1_ptr = Adding_element_to_array_end(array1_ptr, size1, user_element);
    Dynamic_array_printing(array1_ptr, size1);
    cout << "--------------------------------" << endl;
    cout << "Введите элемент: ";
    cin >> user_element;
    int user_index;
    cout << "Введите индекс: ";
    cin >> user_index;
    if (user_index <= size1) { // <= так как  возможно добавить после всех элементов
        array1_ptr = Inserting_element_at_index(array1_ptr, size1, user_element, user_index);
        Dynamic_array_printing(array1_ptr, size1);
    }
    else {
        cout << "Введён недопустимый индекс!" << endl;
    }
    cout << "--------------------------------" << endl;
    cout << "Введите индекс: ";
    cin >> user_index;
    if (user_index < size1) {
        array1_ptr = Delete_element_at_index(array1_ptr, size1, user_index);
        Dynamic_array_printing(array1_ptr, size1);
    }
    else {
        cout << "Введён недопустимый индекс!" << endl;
    }
    
    cout << "--------------------------------" << endl;
    cout << "Задание 2: " << endl;
    array1_ptr = Remove_prime_numbers(array1_ptr, size1);
    Dynamic_array_printing(array1_ptr, size1);
    Delete_dynamic_array(array1_ptr);

    cout << "--------------------------------" << endl;
    cout << "Задание 3: ";
    int size3 = 20;
    int* array3_ptr = Dynamic_memory_allocation(size3);
    Dynamic_array_initialization(array3_ptr, size3);
    Dynamic_array_printing(array3_ptr, size3);

    int** values_array3_ptr = Distributes_elements(array3_ptr, size3);

    cout << endl << "Позитивные: ";
    Dynamic_array_printing(*values_array3_ptr, **(values_array3_ptr + 3));

    cout << endl << "Нули: ";
    Dynamic_array_printing(*(values_array3_ptr + 1), *(*(values_array3_ptr + 3) + 1));

    cout << endl << "Негативные: ";
    Dynamic_array_printing(*(values_array3_ptr + 2), *(*(values_array3_ptr + 3) + 2));

    Delete_dynamic_array(*values_array3_ptr);
    Delete_dynamic_array(*(values_array3_ptr + 1));
    Delete_dynamic_array(*(values_array3_ptr + 2));
    Delete_dynamic_array(*(values_array3_ptr + 3));
    delete[] values_array3_ptr;
    
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
