#pragma once
#include <memory>

using namespace std;

template <class T>
class TLinkedListItem
{
private:
	shared_ptr<T> pValue;
	shared_ptr<TLinkedListItem<T>> pNextItem;

public:
	TLinkedListItem(shared_ptr<T> pValue, shared_ptr<TLinkedListItem<T>> pNextItem);
	virtual ~TLinkedListItem();
	shared_ptr<T> getValuePtr();
	shared_ptr<TLinkedListItem<T>> getNextItemPtr();
	void setNextItemPtr(shared_ptr<TLinkedListItem<T>> pNextItem);
};
