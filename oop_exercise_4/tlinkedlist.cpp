#include <iostream>
#include <memory>
#include <stdexcept>
#include "tlinkedlist.h"
#include "triangle.h"

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

	shared_ptr<TLinkedListItem<T>> pCurrentItem = other.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		InsertLast(pCurrentItem->getValuePtr());
		pCurrentItem = pCurrentItem->getNextItemPtr();
	}
}

template<typename T>
shared_ptr<T> TLinkedList<T>::First()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pFirstItem->getValuePtr();
}

template<typename T>
shared_ptr<T> TLinkedList<T>::Last()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pLastItem->getValuePtr();
}

template<typename T> 
void TLinkedList<T>::InsertFirst(shared_ptr<T> pValue)
{
	shared_ptr<TLinkedListItem<T>> pNewItem(new TLinkedListItem<T>(pValue, pFirstItem));

	pFirstItem = pNewItem;
	if (Empty())
		pLastItem = pNewItem;

	length++;
}

template<typename T>
void TLinkedList<T>::InsertLast(shared_ptr<T> pValue)
{
	shared_ptr<TLinkedListItem<T>> pNewItem(new TLinkedListItem<T>(pValue, nullptr));

	if (pLastItem != nullptr)
		pLastItem->setNextItemPtr(pNewItem);
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
	shared_ptr<TLinkedListItem<T>> pCurrentItem = pFirstItem;
	shared_ptr<TLinkedListItem<T>> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->getNextItemPtr();
		i++;
	}

	shared_ptr<TLinkedListItem<T>> pNewItem(new TLinkedListItem<T>(pValue, pCurrentItem));

	pPreviousItem->setNextItemPtr(pNewItem);

	length++;
}

template<typename T>
void TLinkedList<T>::RemoveFirst()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");
	shared_ptr<TLinkedListItem<T>> pNextItem = pFirstItem->getNextItemPtr();
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

	shared_ptr<TLinkedListItem<T>> pCurrentItem = pFirstItem;
	shared_ptr<TLinkedListItem<T>> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (pCurrentItem == pLastItem)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->getNextItemPtr();
	}

	if (pPreviousItem != nullptr)
		pPreviousItem->setNextItemPtr(nullptr);
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
	shared_ptr<TLinkedListItem<T>> pCurrentItem = pFirstItem;
	shared_ptr<TLinkedListItem<T>> pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->getNextItemPtr();
		i++;
	}

	pPreviousItem->setNextItemPtr(pCurrentItem->getNextItemPtr());
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
	shared_ptr<TLinkedListItem<T>> pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			return pCurrentItem->getValuePtr();
		pCurrentItem = pCurrentItem->getNextItemPtr();
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
	shared_ptr<TLinkedListItem<T>> pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		shared_ptr<TLinkedListItem<T>> pNextItem = pCurrentItem->getNextItemPtr();
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

template<typename T2>
std::ostream& operator<<(std::ostream& os, const TLinkedList<T2>& list)
{
	shared_ptr<TLinkedListItem<T2>> pCurrentItem = list.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		os << pCurrentItem->getValuePtr()->Area();
		if (pCurrentItem != list.pLastItem)
			os << " -> ";
		pCurrentItem = pCurrentItem->getNextItemPtr();
	}
	return os;
}

template class TLinkedList<Triangle>;
template ostream& operator<<(ostream& os, const TLinkedList<Triangle>& list);
