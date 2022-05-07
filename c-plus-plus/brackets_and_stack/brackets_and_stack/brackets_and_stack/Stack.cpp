#include "Stack.h"
#include <string.h>

Stack::Stack() : stack{ nullptr }, size{ 0 }
{
}

Stack::~Stack() {
	if (stack != nullptr) {
		delete[] stack;
		stack = nullptr;
		size = 0;
	}
}

void Stack::Push(const char& sourth) {
	char* tmp = new char[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = stack[i];
	}
	tmp[size] = sourth;
	size++;
	delete[] stack;
	stack = tmp;
	tmp = nullptr;
}

char Stack::Pull() {
	if (stack == nullptr) {
		return '\0';
	} 

	if (size == 1) {
		char tmp = stack[0];
		delete[] stack;
		stack = nullptr;
		size = 0;
		return tmp;
	}

	size--;
	char* tmp_array = new char[size];
	for (int i = 0; i < size; i++) {
		tmp_array[i] = stack[i];
	}
	char tmp_char = stack[size];
	delete[] stack;
	stack = tmp_array;
	tmp_array = nullptr;
	return tmp_char;
}

char Stack::Top() {
	if (stack == nullptr) {
		return '\0';
	}
	return stack[size - 1];
}

void Stack::Clear() {
	this->~Stack();
}

bool Stack::isClear() {
	if (stack == nullptr) {
		return true;
	}
	return false;
}