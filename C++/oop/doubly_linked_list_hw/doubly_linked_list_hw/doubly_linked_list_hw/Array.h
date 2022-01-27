
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class ArrayItem {
public:
	T* value;
	ArrayItem* next;
	ArrayItem* previos;

	ArrayItem() : value{ nullptr }, next{ nullptr }, previos{ nullptr } {}
	ArrayItem(const T& sourth) : value{ new T{ sourth } }, next{ nullptr }, previos{ nullptr } {
	}

	void Print() {
		cout << " {" << *value << "} ";
	}

};

template <typename T>
class Array
{
private:
	ArrayItem<TValue>* head;
	ArrayItem<TValue>* tail;
	int grow = 1;

public:
	Array();
	Array(const Array<T>& sourth);
	Array(Array<T>&& sourth);
	~Array();

	int GetSize();
	int GetUpperBound();
	T GetAt(const int& index);
	Array<T>* GetData();

	void SetSize(int size, int grow = 1);
	void SetAt(const T& sourth, const int& index);
	void Add(const T& sourth);
	void InsertAt(const int& index, const T& sourth);
	void RemoveAt(const int& index, const int& count);

	bool IsEmpty();
	void FreeExtra();
	void RemoveAll();

	ArrayItem<T>* operator [](const int& index);

	Array<T>& operator =(const Array<T>& sourth);
	Array<T>& operator =(Array<T>&& sourth);

	friend Array<T> Append(const Array<T>& sourth1, const Array<T>& sourth2);
};

template <typename T>
int Array<T>::GetSize() {
}

#endif