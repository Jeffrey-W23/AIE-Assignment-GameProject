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
		++nodeCount;
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
				cout << "Invalid index location!" << endl;
				return;

			current = current->next;
		}

		insert(value, current, current->next);
	}

	T First()
	{
		if (start->next == end)
		{
			cout << "This list is empty!" << endl;
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
			cout << "This list is empty!" << endl;
			return default;
		}
		else
		{
			T value = end->prev->data;
			return value;
		}
	}

	int Size()
	{
		return nodeCount;
	}

	bool empty()
	{
		if (start->next == end)
			return true;
		else
			return false;
	}

	T popBack()
	{
		ListNode<T>* n = end->prev;
		T tempData = n->data;

		if (n != start)
		{
			n->prev->next = end;
			end->prev = n->prev;

			delete n;

			--nodeCount;

			return tempData;
		}
		else
		{
			return default;
		}
	}

	T popFront()
	{
		ListNode<T>* n = start->next;
		T tempData = n->data;

		if (n != end)
		{
			n->next->prev = start;
			start->next = n->next;

			delete n;

			--nodeCount;

			return tempData;
		}
		else
		{
			return default;
		}
	}

	void clear()
	{
		while (start->next != end)
		{
			popBack();
		}
	}

	void erase(int index)
	{
		ListNode<T>* current = start;
		
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			
			current = current->next;
		}

		if (current == start || current == end)
		{
			cout << "Cannot delete start and end!" << endl;
			return;
		}
		
		current->next->prev = current->prev;
		current->prev->next = current->next;
		
		delete current;
		
		--nodeCount;
	}

	void remove(T value)
	{
		ListNode<T>* temp = nullptr;
		ListNode<T>* current = start->next;
		
		while (current->next != end)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			
			if (current->data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				
				delete current;
				
				current = temp;
				
				--nodeCount;
			}
			
			current = current->next;
		}
	}

	void printList()
	{
		ListNode<T>* current = start->next;
		
		while (current->next != end)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	T default;
	ListNode<T>* start;
	ListNode<T>* end;
	int nodeCount = 0;
};