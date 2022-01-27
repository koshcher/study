
#ifndef QUEUE_H
#define QUEUE_H

#include "DoubleList.h"

template <typename TValue>
class Queue
{
private:
	DoubleList<TValue> queue;

public:
	Queue() = default;
	Queue(const Queue<TValue>& sourth);
	Queue(Queue<TValue>&& sourth);

	void Push(const TValue& sourth);
	TValue Pull();
	TValue Top();

	void Print();

	Queue<TValue>& operator =(const Queue<TValue>& sourth);
	Queue<TValue>& operator =(Queue<TValue>&& sourth);
};

template <typename TValue>
Queue<TValue>::Queue(const Queue<TValue>& sourth) : queue{ sourth.queue }{
}

template <typename TValue>
Queue<TValue>::Queue(Queue<TValue>&& sourth) {
	queue.head = sourth.queue.head;
	queue.tail = sourth.queue.tail;
	sourth.queue.head = nullptr;
	sourth.queue.tail = nullptr;
}

template <typename TValue>
Queue<TValue>& Queue<TValue>::operator =(const Queue<TValue>& sourth) {
	if (this == &sourth) {
		return *this;
	}
	
	queue.Clear();
	queue = sourth.queue;

	return *this;
}

template <typename TValue>
Queue<TValue>& Queue<TValue>::operator =(Queue<TValue>&& sourth) {
	if (this == &sourth) {
		return *this;
	}

	queue.Clear();
	queue.head = sourth.queue.head;
	queue.tail = sourth.queue.tail;
	sourth.queue.head = nullptr;
	sourth.queue.tail = nullptr;

	return *this;
}

template <typename TValue>
void Queue<TValue>::Push(const TValue& sourth) {
	queue.AddBack(sourth);
}

template <typename TValue>
TValue Queue<TValue>::Pull() {
	TValue res = queue.GetHead();
	queue.DelFront();
	return res;
}

template <typename TValue>
TValue Queue<TValue>::Top() {
	return queue.GetHead();
}

template <typename TValue>
void Queue<TValue>::Print() {
	queue.Print();
}

#endif 