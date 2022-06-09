// cmakeTry.cpp : Defines the entry point for the application.
//

#include "cmakeTry.h"

using namespace std;

int min(int* arr) {
	int min = *arr;
	while (arr != nullptr) {
		if (*arr < min) {
			min = *arr;
		}
		arr++;
	}
	return min;
}

int main()
{
	int* nums = new int[4, 5, 1, 2];
	cout << min(nums) << endl;
	


	return 0;
}
