#include <iostream>
#include <memory>
#include <stdexcept>
#include "tlinkedlist.h"

template<typename T> 
TLinkedList<T>::TLinkedList()
{
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;
}

template<typename T> 
TLinkedList<T>::TLinkedList(const TLinkedList<T>& other)
{
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;

	shared_ptr<Item> pCurrentItem = other.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		InsertLast(pCurrentItem->pValue);
		pCurrentItem = pCurrentItem->pNextItem;
	}
}

template<typename T>
shared_ptr<T> TLinkedList<T>::First()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pFirstItem->pValue;
}

template<typename T>
shared_ptr<T> TLinkedList<T>::Last()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pLastItem->pValue;
}

template<typename T> 
void TLinkedList<T>::InsertFirst(shared_ptr<T> pValue)
{
	shared_ptr<Item> pNewItem(new Item());
	pNewItem->pValue = pValue;
	pNewItem->pNextItem = pFirstItem;

	pFirstItem = pNewItem;
	if (Empty())
		pLastItem = pNewItem;

	length++;
}

template<typename T>
void TLinkedList<T>::InsertLast(shared_ptr<T> pValue)
{
	shared_ptr<Item> pNewItem(new Item());
	pNewItem->pValue = pValue;
	pNewItem->pNextItem = nullptr;

	if (pLastItem != nullptr)
		pLastItem->pNextItem = pNewItem;
	pLastItem = pNewItem;
	if (Empty())
		pFirstItem = pNewItem;

	length++;
}

template<typename T>
void TLinkedList<T>::Insert(shared_ptr<T> pValue, size_t position)
{
	if (position == 0)
	{
		InsertFirst(pValue);
		return;
	}
	else if (position == length)
	{
		InsertLast(pValue);
		return;
	}
	else if (position > length)
		throw runtime_error("Specified poition is out of range");

	int i = 0;
	shared_ptr<Item> pCurrentItem = pFirstItem;
	shared_ptr<Item> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	shared_ptr<Item> pNewItem(new Item());
	pNewItem->pValue = pValue;
	pNewItem->pNextItem = pCurrentItem;

	pPreviousItem->pNextItem = pNewItem;

	length++;
}

template<typename T>
void TLinkedList<T>::RemoveFirst()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");
	shared_ptr<Item> pNextItem = pFirstItem->pNextItem;
	pFirstItem = pNextItem;
	length--;
	if (Empty())
		pLastItem = nullptr;
}

template<typename T>
void TLinkedList<T>::RemoveLast()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");

	shared_ptr<Item> pCurrentItem = pFirstItem;
	shared_ptr<Item> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (pCurrentItem == pLastItem)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
	}

	if (pPreviousItem != nullptr)
		pPreviousItem->pNextItem = nullptr;
	pLastItem = pPreviousItem;
	length--;
	if (Empty())
		pFirstItem = nullptr;
}

template<typename T>
void TLinkedList<T>::Remove(size_t position)
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");
	if (position == 0)
	{
		RemoveFirst();
		return;
	}
	else if (position == length - 1)
	{
		RemoveLast();
		return;
	}
	else if (position >= length)
		throw runtime_error("Specified poition is out of range");

	int i = 0;
	shared_ptr<Item> pCurrentItem = pFirstItem;
	shared_ptr<Item> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	pPreviousItem->pNextItem = pCurrentItem->pNextItem;
	length--;
}

template<typename T> 
shared_ptr<T> TLinkedList<T>::GetItem(size_t position)
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	if (position >= length)
		throw runtime_error("Specified position is out of range");

	int i = 0;
	shared_ptr<Item> pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			return pCurrentItem->pValue;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	throw runtime_error("Something went wrong");
}

template<typename T>
bool TLinkedList<T>::Empty()
{
	return length == 0;
}

template<typename T>
size_t TLinkedList<T>::Length()
{
	return length;
}

template<typename T>
void TLinkedList<T>::Clear()
{
	shared_ptr<Item> pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		shared_ptr<Item> pNextItem = pCurrentItem->pNextItem;
		pCurrentItem = pNextItem;
	}
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;
}

template<typename T>
TLinkedList<T>::~TLinkedList()
{
	Clear();
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const TLinkedList<T>& list)
{
	shared_ptr<TLinkedList::Item> pCurrentItem = list.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		os << pCurrentItem->pTriangle->Area();
		if (pCurrentItem != list.pLastItem)
			os << " -> ";
		pCurrentItem = pCurrentItem->pNextItem;
	}
	return os;
}
