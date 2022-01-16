#include "tlinkedlist.h"

TLinkedList::TLinkedList()
{
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;
}

TLinkedList::TLinkedList(const TLinkedList& other)
{
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;

	Item* pCurrentItem = other.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		InsertLast(pCurrentItem->triangle);
		pCurrentItem = pCurrentItem->pNextItem;
	}
}

const Triangle& TLinkedList::First()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pFirstItem->triangle;
}

const Triangle& TLinkedList::Last()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pLastItem->triangle;
}

void TLinkedList::InsertFirst(const Triangle& triangle)
{
	Item* pNewItem = new Item();
	pNewItem->triangle = triangle;
	pNewItem->pNextItem = pFirstItem;

	pFirstItem = pNewItem;
	if (Empty())
		pLastItem = pNewItem;

	length++;
}

void TLinkedList::InsertLast(const Triangle& triangle)
{

	Item* pNewItem = new Item();
	pNewItem->triangle = triangle;
	pNewItem->pNextItem = nullptr;

	if (pLastItem != nullptr)
		pLastItem->pNextItem = pNewItem;
	pLastItem = pNewItem;
	if (Empty())
		pFirstItem = pNewItem;

	length++;
}

void TLinkedList::Insert(const Triangle& triangle, size_t position)
{
	if (position == 0)
	{
		InsertFirst(triangle);
		return;
	}
	else if (position == length)
	{
		InsertLast(triangle);
		return;
	}
	else if (position > length)
		throw runtime_error("Specified poition is out of range");


	int i = 0;
	Item* pCurrentItem = pFirstItem;
	Item* pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	Item* pNewItem = new Item();
	pNewItem->triangle = triangle;
	pNewItem->pNextItem = pCurrentItem;

	pPreviousItem->pNextItem = pNewItem;

	length++;
}

void TLinkedList::RemoveFirst()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");
	Item* pNextItem = pFirstItem->pNextItem;
	delete pFirstItem;
	pFirstItem = pNextItem;
	length--;
	if (Empty())
		pLastItem = nullptr;
}

void TLinkedList::RemoveLast()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");

	Item* pCurrentItem = pFirstItem;
	Item* pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (pCurrentItem == pLastItem)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
	}

	if (pPreviousItem != nullptr)
		pPreviousItem->pNextItem = nullptr;
	delete pLastItem;
	pLastItem = pPreviousItem;
	length--;
	if (Empty())
		pFirstItem = nullptr;
}

void TLinkedList::Remove(size_t position)
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
	Item* pCurrentItem = pFirstItem;
	Item* pPreviousItem = nullptr;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			break;
		pPreviousItem = pCurrentItem;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	pPreviousItem->pNextItem = pCurrentItem->pNextItem;
	delete pCurrentItem;
	length--;
}

const Triangle& TLinkedList::GetItem(size_t position)
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	if (position >= length)
		throw runtime_error("Specified position is out of range");

	int i = 0;
	Item* pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		if (i == position)
			return pCurrentItem->triangle;
		pCurrentItem = pCurrentItem->pNextItem;
		i++;
	}

	throw runtime_error("Something went wrong");
}

bool TLinkedList::Empty()
{
	return length == 0;
}

size_t TLinkedList::Length()
{
	return length;
}

void TLinkedList::Clear()
{
	Item* pCurrentItem = pFirstItem;
	while (pCurrentItem != nullptr)
	{
		Item* pNextItem = pCurrentItem->pNextItem;
		delete pCurrentItem;
		pCurrentItem = pNextItem;
	}
	pFirstItem = nullptr;
	pLastItem = nullptr;
	length = 0;
}

TLinkedList::~TLinkedList()
{
	Clear();
}

std::ostream& operator<<(std::ostream& os, const TLinkedList& list)
{
	TLinkedList::Item* pCurrentItem = list.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		os << pCurrentItem->triangle.Area();
		if (pCurrentItem != list.pLastItem)
			os << " -> ";
		pCurrentItem = pCurrentItem->pNextItem;
	}
	return os;
}
