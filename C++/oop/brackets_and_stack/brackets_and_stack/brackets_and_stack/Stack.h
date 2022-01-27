
#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	int size;
	char* stack;

public:
	Stack();
	~Stack();

	void Push(const char& sourth);
	char Pull();
	char Top();
	void Clear();
	bool isClear();
};

#endif