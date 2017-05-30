#pragma once
#include "LinkedList.h"
#include "GraphNode.h"
#include "Stack.h"

template <typename T>
class Graph
{
public:
	Graph() {}
	~Graph() {}

	void Insert(GraphNode<T>* node)
	{
		m_Nodes.PushBack(node);
	}

	void RemoveByNode(GraphNode<T>* node)
	{

	}

	void Remove(T data)
	{

	}

	void DrawGraph()
	{
		for (int i = 0; i < m_Nodes.Size(); ++i)
		{
			m_Nodes[i]->m_bTraversed = false;
		}

		Stack<GraphNode<T>*> stack;

		stack.Push(m_Nodes[0]);

		while (!stack.IsEmpty())
		{
			GraphNode<T>* current = stack.Pop();
			current->m_bTraversed = true;

			for (int i = 0; i < current->m_Edges.Size(); ++i)
			{
				if (!current->m_Edges[i]->m_bTraversed)
					stack->Push(current->m_Edges[i]);
			}
		}
	}

private:
	LinkedList<GraphNode<T>*> m_Nodes;
};