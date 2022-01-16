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

	shared_ptr<Item> pCurrentItem = other.pFirstItem;
	while (pCurrentItem != nullptr)
	{
		InsertLast(pCurrentItem->pTriangle);
		pCurrentItem = pCurrentItem->pNextItem;
	}
}

shared_ptr<Triangle> TLinkedList::First()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pFirstItem->pTriangle;
}

shared_ptr<Triangle> TLinkedList::Last()
{
	if (Empty())
		throw runtime_error("Cannon get the item from empty list");
	return pLastItem->pTriangle;
}

void TLinkedList::InsertFirst(shared_ptr<Triangle> pTriangle)
{
	shared_ptr<Item> pNewItem(new Item());
	pNewItem->pTriangle = pTriangle;
	pNewItem->pNextItem = pFirstItem;

	pFirstItem = pNewItem;
	if (Empty())
		pLastItem = pNewItem;

	length++;
}

void TLinkedList::InsertLast(shared_ptr<Triangle> pTriangle)
{

	shared_ptr<Item> pNewItem(new Item());
	pNewItem->pTriangle = pTriangle;
	pNewItem->pNextItem = nullptr;

	if (pLastItem != nullptr)
		pLastItem->pNextItem = pNewItem;
	pLastItem = pNewItem;
	if (Empty())
		pFirstItem = pNewItem;

	length++;
}

void TLinkedList::Insert(shared_ptr<Triangle> pTriangle, size_t position)
{
	if (position == 0)
	{
		InsertFirst(pTriangle);
		return;
	}
	else if (position == length)
	{
		InsertLast(pTriangle);
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
	pNewItem->pTriangle = pTriangle;
	pNewItem->pNextItem = pCurrentItem;

	pPreviousItem->pNextItem = pNewItem;

	length++;
}

void TLinkedList::RemoveFirst()
{
	if (Empty())
		throw runtime_error("Cannon remove the item from empty list");
	shared_ptr<Item> pNextItem = pFirstItem->pNextItem;
	pFirstItem = pNextItem;
	length--;
	if (Empty())
		pLastItem = nullptr;
}

void TLinkedList::RemoveLast()
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

shared_ptr<Triangle> TLinkedList::GetItem(size_t position)
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
			return pCurrentItem->pTriangle;
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

TLinkedList::~TLinkedList()
{
	Clear();
}

std::ostream& operator<<(std::ostream& os, const TLinkedList& list)
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
