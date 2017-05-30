#pragma once

template<typename T>
class ListNode
{
public:

	ListNode() {};
	~ListNode() {};

	T data;
	ListNode* next;
	ListNode* prev;
};