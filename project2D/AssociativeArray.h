//#include, using etc
#pragma once
#include "DynamicArray.h"

//--------------------------------------------------------------------------------------
// AssociativeArray Templated object.
//--------------------------------------------------------------------------------------
template <typename T>
class AssociativeArray
{
private:
	
	//--------------------------------------------------------------------------------------
	// A typedef struct of T data and char pointer name.
	//--------------------------------------------------------------------------------------
	typedef struct _Data
	{
		T data;
		char* name;
	} Data ;

	//--------------------------------------------------------------------------------------
	// A DynamicArray of Data stack.
	//--------------------------------------------------------------------------------------
	DynamicArray<Data> stack;

public:

	//--------------------------------------------------------------------------------------
	// Clear: clear the array.
	//--------------------------------------------------------------------------------------
	void Clear()
	{
		stack.Clear();
	}

	//--------------------------------------------------------------------------------------
	// Size: Returns the size of the array.
	//
	// Return:
	//		int: returns an int of the size of the array.
	//--------------------------------------------------------------------------------------
	int Size()
	{
		return stack.Size();
	}

	//--------------------------------------------------------------------------------------
	// IsItem: Check an item in the array.
	//
	// Param:
	//		name: char pointer of the value to check
	//
	// Return:
	//		bool: returns bool if name is valid or not
	//--------------------------------------------------------------------------------------
	bool IsItem(char* name)
	{
		for (int i = 0; i < Size(); ++i)
		{
			if (stack[i].name == name)
			{
				return true;
			}
		}
		return false;
	}

	//--------------------------------------------------------------------------------------
	// AddItem: Add an item to the array.
	//
	// Param:
	//		name: a char pointer for the name of the data
	//		data: the data you want to add
	//
	// Return:
	//		bool: returns bool if adding was successful
	//--------------------------------------------------------------------------------------
	bool AddItem(char* name, T data)
	{
		if (IsItem(name))
		{
			return true;
		}

		Data d;
		d.name = name;
		d.data = data;
		stack.PushBack(d);
		return true;
	}

	//--------------------------------------------------------------------------------------
	// Sub-script operator returning a reference
	//
	// Param:
	//		name: the name of the data you want
	//
	// Return:
	//		T: Returns a type T
	//--------------------------------------------------------------------------------------
	T& operator [] (char* name)
	{
		for (int i = 0; i < Size(); i++)
		{
			if (stack[i].name == name)
			{
				return stack[i].data;
			}
		}

		int idx = Size();
		Data d;
		d.name = name;
		stack.PushBack(d);
		return stack[idx].data;
	}

	//--------------------------------------------------------------------------------------
	// GetItemName: get the name of an item in the array.
	//
	// Param:
	//		index: An int index in the array.
	//
	// Return:
	//		char*: Returns a char pointer for the name at the index
	//--------------------------------------------------------------------------------------
	char* GetItemName(int index)
	{
		if (index < 0)
		{
			index = 0;
		}

		for (int i = 0; i < Size(); i++)
		{
			if (i == index)
			{
				return stack[i].name;
			}
		}

		return "";
	}

	//--------------------------------------------------------------------------------------
	// Sub-script operator returning a reference
	//
	// Param:
	//		index: int index in the array.
	//
	// Return:
	//		T: return value T
	//--------------------------------------------------------------------------------------
	T& operator [] (int index)
	{
		if (index < 0)
		{
			index = 0;
		}

		for (int i = 0; i < Size(); i++)
		{
			if (i == index)
			{
				return stack[i].data;
			}
		}

		return stack[0].data;
	}
};