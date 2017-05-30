#pragma once
#include "ListNode.h"

template<typename T>
class LinkedList
{
public:

	LinkedList()
	{
		start = new ListNode<T>();
		end = new ListNode<T>();

		start->next = end;
		start->prev = nullptr;

		end->next = nullptr;
		end->end = start;
	};

	~LinkedList()
	{
		delete start;
		delete end;
	};

	void insert(T value, ListNode<T>* prev, ListNode<T>* next)
	{
		ListNode<T> n1 = new ListNode<T>();

		n1->data = value;
		n1->next = next;
		prev->next = n1;
		next->prev = n1;
		n1->prev = prev;
	}

	void PushBack(T value)
	{
		insert(value, end->prev, end);
	}

	void PushFront(T value)
	{
		insert(value, start, start->next);
	}

	void IndexInsert(int index, T value)
	{
		ListNode<T>* current = start;

		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
				return;

			current = current->next;
		}

		insert(value, current, current->next);
	}

	T First()
	{
		if (start->next == end)
		{
			//print an error message that this is empty
			return default;
		}
		else
		{
			T value = start->next->data;
			return value;
		}
	}

	T Last()
	{
		if (start->next == end)
		{
			//print an error message that this is empty
			return default;
		}
		else
		{
			T value = end->prev->data;
			return value;
		}
	}

	// Pop back

	// Pop Front

	//clear

	//erase: remove based on an index passed in

	//remove: remove all elements that have data which matches the value passed in

	T default;
	ListNode<T>* start;
	ListNode<T>* end;
};