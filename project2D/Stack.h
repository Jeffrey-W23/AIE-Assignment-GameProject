#pragma once
#include "DynamicArray.h"

template <typename T>
class Stack
{
public:
	Stack()
	{
	}

	~Stack()
	{
	}

	bool IsEmpty()
	{
		return (m_pData.Size() == 0)
	}

	int Size()
	{
		return m_pData.Size();
	}

	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	T Pop()
	{
		return m_pData.PopBack();
	}

	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}

	DynamicArray<T> m_pData;
};