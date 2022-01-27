// class_fraction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void SetNumerator(int num);
    void SetDenominator(int num);
    void GetFraction();

    Fraction Multiplication(Fraction sourth);
    Fraction Division(Fraction sourth);
    Fraction Addition(Fraction sourth);
    Fraction Subtraction(Fraction sourth);

private: 
    void Reduction();
    int FindGCD(int A, int B);
};

void Fraction::SetNumerator(int num) {
    numerator = num;
}

void Fraction::SetDenominator(int num) {
    if (num == 0) {
        cout << "Ошибка: знаменатель не может быть равен 0" << endl;
        return;
    }
    denominator = num;
}

void Fraction::GetFraction() {
    cout << numerator << "/" << denominator;
}

int Fraction::FindGCD(int A, int B) {
    if (A == 0) {
        return B;
    }
    else if (B == 0) {
        return A;
    }

    int remainder = A % B;
    int whole_part = A / B; // используем именно инт для оставления только ценой части
    return FindGCD((A - remainder) / whole_part, remainder);
}

// Может не самый лучший вариант сокращения, но я хотел написать его вручную
void Fraction::Reduction() {
    int max = numerator;
    int min = denominator;
    if (denominator > numerator) {
        max = denominator;
        min = numerator;
    }
    int gcd = FindGCD(max, min);

    numerator /= gcd;
    denominator /= gcd;
}

// Арифметические операции

Fraction Fraction::Multiplication(Fraction sourth) {
    Fraction res;
    res.numerator = numerator * sourth.numerator;
    res.denominator = denominator * sourth.denominator;
    res.Reduction();
    return res;
}

Fraction Fraction::Division(Fraction sourth) {
    Fraction res;
    res.numerator = numerator * sourth.denominator;
    res.denominator = denominator * sourth.numerator;
    res.Reduction();
    return res;
}

Fraction Fraction::Addition(Fraction sourth) {
    Fraction res;
    res.numerator = (numerator * sourth.denominator) + (sourth.numerator * denominator); 
    res.denominator = denominator * sourth.denominator; // можно использовать самый простой способ, перемножив знаменатели.
    res.Reduction(); // так как всё равно будет проведено сокращение
    return res;
}

Fraction Fraction::Subtraction(Fraction sourth) {
    Fraction res;
    res.numerator = (numerator * sourth.denominator) - (sourth.numerator * denominator);
    res.denominator = denominator * sourth.denominator; 
    res.Reduction(); 
    return res;
}



int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction a;
    a.SetNumerator(21);
    a.SetDenominator(6);

    Fraction b;
    b.SetNumerator(6);
    b.SetDenominator(4);
 
    Fraction c;

    // Умножение
    c = a.Multiplication(b);
    a.GetFraction();
    cout << " * ";
    b.GetFraction();
    cout << " = ";
    c.GetFraction();
    cout << endl;

    // Деление
    c = a.Division(b);
    a.GetFraction();
    cout << " : ";
    b.GetFraction();
    cout << " = ";
    c.GetFraction();
    cout << endl;

    // Сложение
    c = a.Addition(b);
    a.GetFraction();
    cout << " + ";
    b.GetFraction();
    cout << " = ";
    c.GetFraction();
    cout << endl;

    // Вычитание
    c = a.Subtraction(b);
    a.GetFraction();
    cout << " - ";
    b.GetFraction();
    cout << " = ";
    c.GetFraction();
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
