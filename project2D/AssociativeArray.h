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
	
	typedef struct _Data
	{
		T data;
		char* name;
	} Data ;
	DynamicArray<Data> stack;

public:

	void Clear()
	{
		stack.Clear();
	}

	int Size()
	{
		return stack.Size();
	}

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