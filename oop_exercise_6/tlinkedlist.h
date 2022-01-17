#pragma once
#include <memory>
#include "titterator.h"

using namespace std;

template <class T>
class TLinkedList
{
private:
	struct Item
	{
		shared_ptr<T> pValue;
		shared_ptr<Item> pNextItem;
	};

	size_t length;
	shared_ptr<Item> pFirstItem;
	shared_ptr<Item> pLastItem;

public:
	TLinkedList();
	TLinkedList(const TLinkedList& other);
	virtual ~TLinkedList();

	shared_ptr<T> First();
	shared_ptr<T> Last();
	shared_ptr<T> GetItem(size_t position);

	void InsertFirst(shared_ptr<T> pValue);
	void InsertLast(shared_ptr<T> pValue);
	void Insert(shared_ptr<T> pValue, size_t position);

	void RemoveFirst();
	void RemoveLast();
	void Remove(size_t position);

	void Clear();
	bool Empty();
	size_t Length();

	friend std::ostream& operator<<(std::ostream& os, const TLinkedList<T>& list);

	TIterator<Item, T> begin() { return TIterator<Item, T>(pFirstItem); }
	TIterator<Item, T> end() { return TIterator<Item, T>(pLastItem); }
};
