// brackets_and_stack.cpp

#include <iostream>
#include "Stack.h"

using namespace std;

bool AreBracketsCorrect(const char* sourth) {
	int sourth_length = strlen(sourth);
	Stack brackets;

	char top_bracket = '\0';
	int stop_index = 0;

	for (int i = 0; i < sourth_length; i++) {
		if (sourth[i] == '(' || sourth[i] == '{' || sourth[i] == '[') {
			brackets.Push(sourth[i]);
		}
		else if (sourth[i] == ')' || sourth[i] == '}' || sourth[i] == ']') {
			top_bracket = brackets.Top();
			if ((top_bracket == '(' && sourth[i] == ')') || (top_bracket == '[' && sourth[i] == ']') || (top_bracket == '{' && sourth[i] == '}')) {
				brackets.Pull();
			}
			else {
				i = sourth_length; // так мы выйдем из цикла
			}
		}
		stop_index++;
	}

	if (brackets.isClear() == false) {
		for (int i = 0; i < stop_index - 1; i++) {
			cout << sourth[i];
		}
		return false;
	}
	cout << "Brakets are Correct!";
	return true;
}

int main()
{
	char* correct_str = new char[25] { "({x-y-z}*[x+2y]-(z+4x))" };
	char* incorrect_str = new char[25]{ "([x-y-z}*[x+2y)-{z+4x)]" };
	AreBracketsCorrect(correct_str);
	cout << endl;
	AreBracketsCorrect(incorrect_str);
}
