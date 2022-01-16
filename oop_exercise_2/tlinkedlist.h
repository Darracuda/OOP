#pragma once
#include "triangle.h"

class TLinkedList
{
private:
	struct Item
	{
		Triangle triangle;
		Item* pNextItem{};
	};

	size_t length;
	Item* pFirstItem;
	Item* pLastItem;

public:
	TLinkedList();
	TLinkedList(const TLinkedList& other);
	virtual ~TLinkedList();

	const Triangle& First();
	const Triangle& Last();
	const Triangle& GetItem(size_t position);

	void InsertFirst(const Triangle& triangle);
	void InsertLast(const Triangle& triangle);
	void Insert(const Triangle& triangle, size_t position);

	void RemoveFirst();
	void RemoveLast();
	void Remove(size_t position);

	void Clear();
	bool Empty();
	size_t Length();

	friend std::ostream& operator<<(std::ostream& os, const TLinkedList& list);
};
