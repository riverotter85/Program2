#if !defined _QUEUE_DEQUE_H
#define _QUEUE_DEQUE_H

#include "DequeArray.h"

template < class T >
class QueueDeque
{
	private:
		DequeArray<T>* da;
	
	public:
		QueueDeque();
		~QueueDeque();
		
		bool isEmpty();
		int size();
		void dequeueAll();
		T* peek();
		void enqueue(T* item);
		T* dequeue();
};

template < class T >
QueueDeque<T>::QueueDeque()
{
	da = new DequeArray<T>();
}

template < class T >
QueueDeque<T>::~QueueDeque()
{
	delete da;
}

template < class T >
bool QueueDeque<T>::isEmpty()
{
	return da->isEmpty();
}

template < class T >
int QueueDeque<T>::size()
{
	return da->size();
}

template < class T >
void QueueDeque<T>::dequeueAll()
{
	da->dequeueAll();
}

template < class T >
T* QueueDeque<T>::peek()
{
	return da->peek();
}

template < class T >
void QueueDeque<T>::enqueue(T* item)
{
	da->enqueue(item);
}

template < class T >
T* QueueDeque<T>::dequeue()
{
	return da->dequeue();
}

#endif