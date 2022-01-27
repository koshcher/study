// struct_hw1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

long double i = sqrtl(-1);

struct Complex_number {
    double Re;
    double Im;
};

enum Colors { Red, Blue, Green, Pink, White, Yellow, Black };
enum Transmission_type { Mechanics, Robotic, Automatic };

struct Car {
    float length;
    float clearance;
    float engine_volume;
    int power_engine;
    float wheel_diameter;
    Colors car_color;
    Transmission_type car_transmission;
};

void Print_complex_number(const Complex_number& num) {
    cout << num.Re << " + " << num.Im << "i";
}

Complex_number Sum(const Complex_number& num1, const Complex_number& num2) {
    Complex_number result;
    result.Re = num1.Re + num2.Re;
    result.Im = num1.Im + num2.Im;
    return result;
}

Complex_number Difference(const Complex_number& num1, const Complex_number& num2) {
    Complex_number result;
    result.Re = num1.Re - num2.Re;
    result.Im = num1.Im - num2.Im;
    return result;
}

Complex_number Multiplication(const Complex_number& num1, const Complex_number& num2) {
    Complex_number result;
    result.Re = num1.Re * num2.Re - num1.Im * num2.Im;
    result.Im = num1.Re * num2.Im + num1.Im * num2.Re;
    return result;
}

Complex_number Division(const Complex_number& num1, const Complex_number& num2) {
    if (num2.Re != 0 && num2.Im != 0) {
        Complex_number result;
        result.Re = (num1.Re * num2.Re - num1.Im * num2.Im) / (num2.Re * num2.Re + num2.Im * num2.Im);
        result.Im = (num1.Im * num2.Re - num1.Re * num2.Im) / (num2.Re * num2.Re + num2.Im * num2.Im);
        return result;
    }
    cout << "Деление на ноль невозможно!";
    return num1;
}

void Rand_generation(Car* array, const int& size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i].length = (rand() % 60) / 10.0 + 1.5;
        array[i].clearance = (rand() % 150) / 10.0 + 15.0;
        array[i].engine_volume = (rand() % 50) / 10.0 + 0.9;
        array[i].power_engine = rand() % 600 + 60;
        array[i].wheel_diameter = (rand() % 160) / 10.0 + 24;
        array[i].car_color = (Colors)(rand() % 7);
        array[i].car_transmission = (Transmission_type)(rand() % 3);
    }
}

Car New_car() {
    Car new_car;

    cout << "Введите длину в метрах: ";
    cin >> new_car.length;

    cout << "Введите клиренс (высота посадки) в сантиметрах: ";
    cin >> new_car.clearance;

    cout << "Введите объём двигателя в литрах: ";
    cin >> new_car.engine_volume;

    cout << "Введите мощьность двигателя в лошадиных силах: ";
    cin >> new_car.power_engine;

    cout << "Введите диаметр колёс в дюймах: ";
    cin >> new_car.wheel_diameter;

    cout << "Выберете цвет:" << endl;
    cout << "[1] Красный" << endl;
    cout << "[2] Синий" << endl;
    cout << "[3] Зелёный" << endl;
    cout << "[4] Розовый" << endl;
    cout << "[5] Белый" << endl;
    cout << "[6] Жёлтый" << endl;
    cout << "[7] Чёрный" << endl;
    int user_car_color;
    cin >> user_car_color;
    new_car.car_color = (Colors)(user_car_color - 1);

    cout << "Выберете коробку передач:" << endl;
    cout << "[1] Механика" << endl;
    cout << "[2] Роботизированая" << endl;
    cout << "[3] Автоматическая" << endl;
    int user_car_transmission;
    cin >> user_car_transmission;
    new_car.car_transmission = (Transmission_type)(user_car_color - 1);

    return new_car;
}

void Add_car(Car*& array, int& size, const Car& new_car) {
    Car* new_array = new Car[size + 1];
    for (int i = 0; i < size; i++) {
        new_array[i] = array[i];
    }
    new_array[size] = new_car;
 
    delete[] array;
    array = new_array;
    size++;
}

void Print_car(const Car& car) {

    cout << "Длина в метрах: " << car.length << endl;
    cout << "Клиренс (высота посадки) в сантиметрах: " << car.clearance << endl;
    cout << "Объём двигателя в литрах: " << car.engine_volume << endl;
    cout << "Мощьность двигателя в лошадиных силах: " << car.power_engine << endl;
    cout << "Диаметр колёс в дюймах: " << car.wheel_diameter << endl;

    cout << "Цвет: ";
    switch (car.car_color) {
    case Red:
        cout << "Красный";
        break;
    case Blue:
        cout << "Синий";
        break;
    case Green:
        cout << "Зелёный";
        break;
    case Pink:
        cout << "Розовый";
        break;
    case White:
        cout << "Белый";
        break;
    case Yellow:
        cout << "Жёлтый";
        break;
    case Black:
        cout << "Чёрный";
        break;
    }
    cout << endl;

    cout << "Коробка передач: ";
    switch (car.car_transmission) {
    case Mechanics:
        cout << "Механика";
        break;
    case Robotic:
        cout << "Роботизированая";
        break;
    case Automatic:
        cout << "Автоматическая";
        break;
    }
}

// Поиск

void Find_cars_by_length(Car* array, const int& size) {
    float user_length;
    cout << "Введите длину в метрах: ";
    cin >> user_length;

    for (int i = 0; i < size; i++) {
        if (array[i].length == user_length) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_clearance(Car* array, const int& size) {
    float user_clearance;
    cout << "Введите клиренс (высота посадки) в сантиметрах: ";
    cin >> user_clearance;

    for (int i = 0; i < size; i++) {
        if (array[i].clearance == user_clearance) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_engine_volume(Car* array, const int& size) {
    float user_engine_volume;
    cout << "Введите объём двигателя в литрах: ";
    cin >> user_engine_volume;

    for (int i = 0; i < size; i++) {
        if (array[i].engine_volume == user_engine_volume) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_power_engine(Car* array, const int& size) {
    int user_power_engine;
    cout << "Введите мощьность двигателя в лошадиных силах: ";
    cin >> user_power_engine;

    for (int i = 0; i < size; i++) {
        if (array[i].power_engine == user_power_engine) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_wheel_diameter(Car* array, const int& size) {
    float user_wheel_diameter;
    cout << "Введите диаметр колёс в дюймах: ";
    cin >> user_wheel_diameter;

    for (int i = 0; i < size; i++) {
        if (array[i].wheel_diameter == user_wheel_diameter) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_color(Car* array, const int& size) {
    int user_color;
    cout << "Выберете цвет:" << endl;
    cout << "[1] Красный" << endl;
    cout << "[2] Синий" << endl;
    cout << "[3] Зелёный" << endl;
    cout << "[4] Розовый" << endl;
    cout << "[5] Белый" << endl;
    cout << "[6] Жёлтый" << endl;
    cout << "[7] Чёрный" << endl;
    cin >> user_color;

    for (int i = 0; i < size; i++) {
        if (array[i].car_color == (Colors)(user_color - 1)) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

void Find_cars_by_transmission(Car* array, const int& size) {
    int user_transmission;
    cout << "Выберете коробку передач:" << endl;
    cout << "[1] Механика" << endl;
    cout << "[2] Роботизированая" << endl;
    cout << "[3] Автоматическая" << endl;
    cin >> user_transmission;

    for (int i = 0; i < size; i++) {
        if (array[i].car_transmission == (Transmission_type)(user_transmission - 1)) {
            Print_car(array[i]);
            cout << endl << "---------------------------" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    int user_function;
    cout << "Выберете функцию:" << endl;
    cout << "[1] Сумма" << endl;
    cout << "[2] Разница (1-е число - уменьшаемое, 2-е число - вычитаемое)" << endl;
    cout << "[3] Произведение" << endl;
    cout << "[4] Деление (1-е число - делимое, 2-е число - делитель)" << endl;
    cin >> user_function;

    if (user_function > 0 && user_function < 5) {

        Complex_number user_num1;
        Complex_number user_num2;

        cout << "Введите вещественную часть 1-го числа: ";
        cin >> user_num1.Re;
        cout << "Введите мнимую часть 1-го числа: ";
        cin >> user_num1.Im;
        cout << "Введите вещественную часть 2-го числа: ";
        cin >> user_num2.Re;
        cout << "Введите мнимую часть 2-го числа: ";
        cin >> user_num2.Im;

        typedef Complex_number(*Complex_math)(const Complex_number& num1, const Complex_number& num2);

        Complex_math complex_func[4] = { Sum, Difference, Multiplication, Division };
        cout << "Результат: ";
        Print_complex_number(complex_func[user_function - 1](user_num1, user_num2));
    }
    else {
        cout << "Вы выбрали несуществующую функцию";
    }

    cout << endl << "----------------------------" << endl;

    int cars_array_size = 20;
    Car* cars_array = new Car[cars_array_size];

    Rand_generation(cars_array, cars_array_size);

    typedef void(*Searching)(Car* array, const int& size);
    Searching searching_array[7] = { Find_cars_by_length, Find_cars_by_clearance, Find_cars_by_engine_volume, Find_cars_by_power_engine, Find_cars_by_wheel_diameter, Find_cars_by_color, Find_cars_by_transmission };

    do {
        cout << "Выберете функцию:" << endl;
        cout << "[1] Задания значений (создание автомобиля и добавление в список)" << endl;
        cout << "[2] Отображения значений" << endl;
        cout << "[3] Поиска значений по параметру" << endl;
        cout << "[любая другая цифра] Конец" << endl;
        cin >> user_function;

        switch (user_function) {
        case 1:
            Car user_car = New_car();
            Add_car(cars_array, cars_array_size, user_car);
            break;

        case 2:
            for (int i = 0; i < cars_array_size; i++) {
                Print_car(cars_array[i]);
                cout << endl << "-------------------------------" << endl;
            }
            break;

        case 3:
            int user_parametr;
            cout << "По какому параметру искать?" << endl;
            cout << "[1] Длина" << endl;
            cout << "[2] Клиренс" << endl;
            cout << "[3] Объём двигателя" << endl;
            cout << "[4] Мощьность двигателя" << endl;
            cout << "[5] Диаметр колёс" << endl;
            cout << "[6] Цвет" << endl;
            cout << "[7] Коробка передач" << endl;
            cin >> user_parametr;
            searching_array[user_parametr - 1](cars_array, cars_array_size);
            break;
        }
    } while (user_function > 0 && user_function < 4);

    delete[] cars_array;
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
