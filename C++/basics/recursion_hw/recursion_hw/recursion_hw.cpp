// recursion_hw.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void hanoi_towers(int quantity=64, int from=1, int to=3, int buf_peg=2) {
//quantity-число колец, from-начальное положение колец(1-3),to-конечное положение колец(1-3)

	//buf_peg - промежуточный колышек
	if (quantity != 0)
	{
		hanoi_towers(quantity - 1, from, buf_peg, to);

		cout << from << " -> " << to << endl;
		hanoi_towers(quantity - 1, buf_peg, to, from);
	}
}

bool Is_move_imposible(int x, int y, int size) {
	return ((x < 0) || (x >= size) || (y < 0) || (y >= size));
}

void Print_matrix(int array[][8], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

int steps[8][2] = { {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1} };
bool find_path(int x, int y, int desk[8][8], int desk_size = 8, int moves = 0) 
{
	if (Is_move_imposible(x, y, 8) == true) {
		return false;
	}
	if(desk[x][y] != 0) {
		return false;
	}

	if (moves == desk_size * desk_size - 1) {
		desk[x][y] = 64;
		return true;
	}

	desk[x][y] = moves + 1;
	for (int i = 0; i < 8; i++) { // 8 - кол-во ходов, которые конь может сделать из одной точки по стандарту
		if (find_path(x + steps[i][0], y + steps[i][1], desk, desk_size, moves + 1) == true) {
			return true;
		}
	}

	desk[x][y] = 0;
	return false;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int plate_quantity;
	cout << "Количество дисков: "; // чтобы можно было проверить на более меньшем кол-ве дисков
	cin >> plate_quantity;
	cout << "Перестановки: " << endl;

	hanoi_towers(plate_quantity);

	int start_row;
	cout << "Начальная строка: ";
	cin >> start_row;
	int start_col;
	cout << "Начальный столбец:  "; 
	cin >> start_col;

	const int desk_size = 8;
	int desk[desk_size][desk_size] = {};
	find_path(start_col - 1, start_row - 1, desk);
	Print_matrix(desk, desk_size);

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
