// #include, using, etc
#pragma once
#include "DynamicArray.h"

//--------------------------------------------------------------------------------------
// Stack Templated object.
//--------------------------------------------------------------------------------------
template <typename T>
class Stack
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Stack()
	{
	}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Stack()
	{
	}

	//--------------------------------------------------------------------------------------
	// IsEmpty: A function to check if the Stack is empty or not.
	//
	// Return:
	//		bool: returns if the stack is empty or not.
	//--------------------------------------------------------------------------------------
	bool IsEmpty()
	{
		return (m_pData.Size() == 0)
	}

	//--------------------------------------------------------------------------------------
	// Size: A function to get the size of the stack.
	//
	// Return:
	//		int: return the size of the stack.
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return m_pData.Size();
	}

	//--------------------------------------------------------------------------------------
	// Push: A function to push to the next state.
	//
	// Param:
	//		value: take in T for the stack to push to.
	//--------------------------------------------------------------------------------------
	void Push(T value)
	{
		m_pData.PushBack(value);
	}

	//--------------------------------------------------------------------------------------
	// Pop: A function to pop T off the stack.
	//
	// Return:
	//		T: returns T for the value that has been popped to.
	//--------------------------------------------------------------------------------------
	T Pop()
	{
		return m_pData.PopBack();
	}

	//--------------------------------------------------------------------------------------
	// Top: A function that returns whats on the top of the stack.
	//
	// Return:
	//		T: Return T for whats on top of the stack.
	//--------------------------------------------------------------------------------------
	T Top()
	{
		int nTop = m_pData.Size() - 1;
		return m_pData[nTop];
	}

	//--------------------------------------------------------------------------------------
	// SecondLast: A function that returns whats under the top of the stack.
	//
	// Return:
	//		T: Return T for whats second last on the stack.
	//--------------------------------------------------------------------------------------
	T SecondLast()
	{
		int nSecondLast = m_pData.Size() - 2;
		return m_pData[nSecondLast];
	}

	//--------------------------------------------------------------------------------------
	// An DynamicArray of T
	//--------------------------------------------------------------------------------------
	DynamicArray<T> m_pData;
};