
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>

using namespace std;

template <typename TValue>
class DoubleListItem
{
public:
	TValue value;
	DoubleListItem* next;
	DoubleListItem* previos;

	DoubleListItem(const TValue& sourth) : value{ sourth }, next{ nullptr }, previos{ nullptr }
	{
	}

	void Print() {
		cout << " {" << value << "} ";
	}
};

template <typename TValue>
class DoubleList
{
private:
	DoubleListItem<TValue>* head;
	DoubleListItem<TValue>* tail;

public:
	DoubleList();
	~DoubleList();

	DoubleList(const DoubleList<TValue>& sourth);
	DoubleList(DoubleList<TValue>&& sourth);

	void Clear();

	TValue GetHead() {
		return head->value;
	}
	TValue GetTail() {
		return tail->value;
	}
	int GetSize();

	void AddFront(const TValue& sourth);
	void AddBack(const TValue& sourth);
	void Add(const TValue& find, const TValue& sourth);

	DoubleListItem<TValue>* Find(const TValue& sourth);

	void DelFront();
	void DelBack();
	void Del(const TValue& sourth);

	void Print();
	void PrintRevers();

	DoubleList<TValue>& operator =(const DoubleList<TValue>& sourth);
	DoubleList<TValue>& operator =(DoubleList<TValue>&& sourth);

	DoubleListItem<TValue>* operator ()(const TValue& sourth);

	template <typename TValue1>
	friend const DoubleList<TValue1> operator +(const DoubleList<TValue1>& sourth1, const DoubleList<TValue1>& sourth2);

	template <typename TValue1>
	friend const DoubleList<TValue1> operator *(const DoubleList<TValue1>& sourth1, const DoubleList<TValue1>& sourth2);
};

template <typename TValue>
DoubleList<TValue>::DoubleList() : head{ nullptr }, tail{ nullptr }
{
}

template <typename TValue>
DoubleList<TValue>::DoubleList(const DoubleList<TValue>& sourth)
{
	DoubleListItem<TValue>* cursor = sourth.head;

	while (cursor != nullptr) {
		AddBack(cursor->value);
		cursor = cursor->next;
	}

}

template <typename TValue>
DoubleList<TValue>::DoubleList(DoubleList<TValue>&& sourth)
{
	head = sourth.head;
	tail = sourth.tail;
	sourth.head = nullptr;
	sourth.tail = nullptr;
}

template <typename TValue>
DoubleList<TValue>::~DoubleList()
{
	Clear();
}

template <typename TValue>
void DoubleList<TValue>::Clear() {
	while (head != nullptr) {
		DelFront();
	}
}

template <typename TValue>
int DoubleList<TValue>::GetSize() {
	int size = 0;
	DoubleListItem<TValue>* cursor = head;

	while (cursor != nullptr) {
		size++;
		cursor = cursor->next;
	}
	return size;
}

template <typename TValue>
void DoubleList<TValue>::AddFront(const TValue& sourth) {
	DoubleListItem<TValue>* tmp = new DoubleListItem<TValue>{ sourth };

	if (head == nullptr) {
		head = tmp;
		tail = tmp;
		return;
	}

	head->previos = tmp;
	tmp->next = head;
	head = tmp;
}

template <typename TValue>
void DoubleList<TValue>::AddBack(const TValue& sourth) {
	DoubleListItem<TValue>* tmp = new DoubleListItem<TValue>{ sourth };

	if (head == nullptr && tail == nullptr) {
		head = tmp;
		tail = tmp;
		return;
	}

	tail->next = tmp;
	tmp->previos = tail;
	tail = tmp;
}

template <typename TValue>
DoubleListItem<TValue>* DoubleList<TValue>::Find(const TValue& sourth) {
	DoubleListItem<TValue>* cursor = head;
	while (cursor != nullptr) {
		if (cursor->value == sourth) {
			return cursor;
		}
		cursor = cursor->next;
	}

	return nullptr;
}

template <typename TValue>
void DoubleList<TValue>::Add(const TValue& find, const TValue& sourth) {
	DoubleListItem<TValue>* tmp = new DoubleListItem<TValue>{ sourth };

	DoubleListItem<TValue>* cursor = Find(find);

	if (cursor == nullptr) {
		cout << "Error";
		return;
	}

	tmp->previos = cursor;
	tmp->next = cursor->next;

	cursor->next = tmp;
	if (tmp->next != nullptr) {
		tmp->next->previos = tmp;
	}
	else {
		tail = tmp;
	}
}

template <typename TValue>
void DoubleList<TValue>::Print() {
	if (head == nullptr) {
		return;
	}

	DoubleListItem<TValue>* cursor = head;
	while (cursor != nullptr) {
		cursor->Print();
		cursor = cursor->next;
	}
}

template <typename TValue>
void DoubleList<TValue>::PrintRevers() {
	if (tail == nullptr) {
		return;
	}

	DoubleListItem<TValue>* cursor = tail;
	while (cursor != nullptr) {
		cursor->Print();
		cursor = cursor->previos;
	}
	cout << endl;
}

template <typename TValue>
void DoubleList<TValue>::DelFront() {
	if (head == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	DoubleListItem<TValue>* cursor = head->next;
	delete head;
	head = cursor;
	head->previos = nullptr;
}

template <typename TValue>
void DoubleList<TValue>::DelBack() {
	if (head == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	DoubleListItem<TValue>* cursor = tail->previos;
	delete tail;
	tail = cursor;
	tail->next = nullptr;
}

template <typename TValue>
void DoubleList<TValue>::Del(const TValue& sourth) {
	if (head == nullptr) {
		return;
	}

	DoubleListItem<TValue>* del_node = Find(sourth);
	if (del_node == nullptr) {
		return;
	}

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	if (del_node == head) {
		DelFront();
	}
	else if (del_node == tail) {
		DelBack();
	}
	else {

		del_node->previos->next = del_node->next;
		del_node->next->previos = del_node->previos;
		delete del_node;
	}
}

template <typename TValue>
DoubleList<TValue>& DoubleList<TValue>::operator =(const DoubleList<TValue>& sourth) {
	if (this == &sourth) {
		return *this;
	}
	Clear();

	DoubleListItem<TValue>* cursor = sourth.head;

	while (cursor != nullptr) {
		AddBack(cursor->value);
		cursor = cursor->next;
	}
	return *this;
}

template <typename TValue>
DoubleList<TValue>& DoubleList<TValue>::operator =(DoubleList<TValue>&& sourth) {
	if (this == &sourth) {
		return *this;
	}

	Clear();

	head = sourth.head;
	tail = sourth.tail;
	sourth.head = nullptr;
	sourth.tail = nullptr;
	return *this;
}

template <typename TValue1>
const DoubleList<TValue1> operator +(const DoubleList<TValue1>& sourth1, const DoubleList<TValue1>& sourth2) {
	DoubleList<TValue1> res{ sourth1 };

	DoubleListItem<TValue1>* cursor = sourth2.head;

	while (cursor != nullptr) {
		res.AddBack(cursor->value);
		cursor = cursor->next;
	}

	return res;
}

template <typename TValue1>
const DoubleList<TValue1> operator *(const DoubleList<TValue1>& sourth1, const DoubleList<TValue1>& sourth2) {
	DoubleList<TValue1> res;

	DoubleListItem<TValue1>* cursor1 = sourth1.head;
	DoubleListItem<TValue1>* cursor2 = sourth2.head;

	while (cursor1 != nullptr) {
		while (cursor2 != nullptr) {
			if (cursor1->value == cursor2->value) {
				res.AddBack(cursor1->value);
				break;
			}
			cursor2 = cursor2->next;
		}
		cursor2 = sourth2.head;
		cursor1 = cursor1->next;
	}

	return res;
}

template <typename TValue>
DoubleListItem<TValue>* DoubleList<TValue>::operator ()(const TValue& sourth) {
	return Find(sourth);
}

#endif