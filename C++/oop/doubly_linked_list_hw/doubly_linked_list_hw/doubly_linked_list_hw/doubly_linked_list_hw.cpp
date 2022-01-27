// doubly_linked_list_hw.cpp
//

#include <iostream>
#include "Queue.h"
#include "DoubleList.h"
#include "Array.h"

using namespace std;

int main()
{
	Queue<int> my_queue;

	for (int i = 0; i < 10; i++) {
		my_queue.Push(rand() % 50 + 1);
	}
	my_queue.Print();
	cout << endl;

	for (int i = 0; i < 5; i++) {
		my_queue.Pull();
	}
	my_queue.Print();
	cout << endl;

	Queue<int> your_queue{ my_queue };
	your_queue.Print();
	cout << endl << endl;

	DoubleList<int> my_list;
	DoubleList<int> your_list;
	for (int i = 0; i < 5; i++) {
		my_list.AddBack(rand() % 50 + 1);
		your_list.AddBack(rand() % 50 + 1);
	}
	my_list.Print();
	cout << endl;
	your_list.Print();
	cout << endl;

	DoubleList<int> our_list;
	our_list = my_list + your_list;
	our_list.Print();
	cout << endl;
	our_list = my_list * your_list;
	our_list.Print();
	cout << endl;
}