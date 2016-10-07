/*
	Filename: DequeArray.h
	Written and Modified By: Logan Davis
	Last Date Modified: 10/07/2016
*/

#if !defined NULL
#define NULL 0
#endif

#if !defined _DEQUE_ARRAY_H
#define _DEQUE_ARRAY_H

template < class T >
class DequeArray
{
	private:
		T** items;
		int max_queue;
		int front;
		int back;
		int sz;
		
		void resize();
	
	public:
		DequeArray();
		~DequeArray();
		
		bool isEmpty();
		int size();
		void dequeueAll();
		T* peek();
		void enqueue(T* item);
		T* dequeue();
		T* peekDeque();
		void enqueueDeque(T* item);
		T* dequeueDeque();
};

template < class T >
DequeArray<T>::DequeArray()
{
    max_queue = 2;
    items = new T*[max_queue];  
    front = 0;
    back = max_queue - 1;
    sz = 0;
}

template < class T >
DequeArray<T>::~DequeArray()
{
	delete[] items;
}

template < class T >
bool DequeArray<T>::isEmpty()
{
	return (sz == 0);
}

template < class T >
int DequeArray<T>::size()
{
	return sz;
}

template < class T >
void DequeArray<T>::dequeueAll()
{
	delete[] items;
	
	max_queue = 2;
	items = new T*[max_queue];
	for (int i = 0; i < max_queue; i++)
	{
		items[i] = NULL;
	}
	
	sz = 0;
	front = 0;
	back = max_queue - 1;
}

template < class T >
T* DequeArray<T>::peek()
{
	T* item = NULL;
	
	if (!isEmpty())
	{
		item = items[front];
	}
	
	return item;
}

template < class T >
void DequeArray<T>::enqueue(T* item)
{	
	if (item == NULL)
	{
		return;
	}
	
	if (sz == max_queue)
	{
		resize();
	}
	
	back++;
	if (back == max_queue)
	{
		back = 0;
	}
	items[back] = item;
	sz++;
}

template < class T >
T* DequeArray<T>::dequeue()
{
	T* item = NULL;
	
	if (!isEmpty())
	{
		item = items[front];
		items[front] = NULL;
		
		front++;
		if (front == max_queue)
		{
			front = 0;
		}
		sz--;
	}
	
	return item;
}

template < class T >
T* DequeArray<T>::peekDeque()
{
	T* item = NULL;
	
	if (!isEmpty())
	{
		item = items[back];
	}
	
	return item;
}

template < class T >
void DequeArray<T>::enqueueDeque(T* item)
{
	if (item == NULL)
	{
		return;
	}
	
	if (sz == max_queue)
	{
		resize();
	}
	
	front--;
	if (front == -1)
	{
		front = max_queue - 1;
	}
	items[front] = item;
	sz++;
}

template < class T >
T* DequeArray<T>::dequeueDeque()
{
	T* item = NULL;
	
	if (!isEmpty())
	{
		item = items[back];
		items[back] = NULL;
		
		back--;
		if (back == -1)
		{
			back = max_queue - 1;
		}
		sz--;
	}
	
	return item;
}

template < class T >
void DequeArray<T>::resize()
{
	int new_max_queue = max_queue * 2;
	T** new_items = new T*[new_max_queue];
	for (int i = 0; i < new_max_queue; i++)
	{
		new_items[i] = NULL;
	}
	
	int j = front;
	for (int i = 0; i < sz; i++)
	{
		new_items[i] = items[j];
		
		j++;
		if (j == max_queue)
		{
			j = 0;
		}
	}
	
	front = 0;
	back = sz - 1;
	
	delete[] items;
	items = new_items;
	max_queue = new_max_queue;
}

#endif