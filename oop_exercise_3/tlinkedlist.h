#pragma once
#include "triangle.h"

class TLinkedList
{
private:
	struct Item
	{
		shared_ptr<Triangle> pTriangle;
		shared_ptr<Item> pNextItem;
	};

	size_t length;
	shared_ptr<Item> pFirstItem;
	shared_ptr<Item> pLastItem;

public:
	TLinkedList();
	TLinkedList(const TLinkedList& other);
	virtual ~TLinkedList();

	shared_ptr<Triangle> First();
	shared_ptr<Triangle> Last();
	shared_ptr<Triangle> GetItem(size_t position);

	void InsertFirst(shared_ptr<Triangle> pTriangle);
	void InsertLast(shared_ptr<Triangle> pTriangle);
	void Insert(shared_ptr<Triangle> pTriangle, size_t position);

	void RemoveFirst();
	void RemoveLast();
	void Remove(size_t position);

	void Clear();
	bool Empty();
	size_t Length();

	friend std::ostream& operator<<(std::ostream& os, const TLinkedList& list);
};
