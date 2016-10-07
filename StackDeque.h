/*
	Filename: StackDeque.h
	Written and Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#if !defined _STACK_DEQUE_H
#define _STACK_DEQUE_H

#include "DequeArray.h"

template < class T >
class StackDeque
{
	private:
		DequeArray<T>* da;
	
	public:
		StackDeque();
		~StackDeque();
		
		bool isEmpty();
		int size();
		void popAll();
		T* peek();
		void push(T* item);
		T* pop();
};

template < class T >
StackDeque<T>::StackDeque()
{
	da = new DequeArray<T>();
}

template < class T >
StackDeque<T>::~StackDeque()
{
	delete da;
}

template < class T >
bool StackDeque<T>::isEmpty()
{
	return da->isEmpty();
}

template < class T >
int StackDeque<T>::size()
{
	return da->size();
}

template < class T >
void StackDeque<T>::popAll()
{
	da->dequeueAll();
}

template < class T >
T* StackDeque<T>::peek()
{
	return da->peekDeque();
}

template < class T >
void StackDeque<T>::push(T* item)
{
	da->enqueue(item);
}

template < class T >
T* StackDeque<T>::pop()
{
	return da->dequeueDeque();
}

#endif