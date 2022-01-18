#include <memory>
#include "tlinkedlistitem.h"
#include "triangle.h"

using namespace std;

template<class T>
inline TLinkedListItem<T>::TLinkedListItem(shared_ptr<T> pValue, shared_ptr<TLinkedListItem<T>> pNextItem)
{
	this->pValue = pValue;
	this->pNextItem = pNextItem;
}

template<class T>
TLinkedListItem<T>::~TLinkedListItem()
{
}

template<class T>
shared_ptr<T> TLinkedListItem<T>::getValuePtr()
{
	return pValue;
}

template<class T>
shared_ptr<TLinkedListItem<T>> TLinkedListItem<T>::getNextItemPtr()
{
	return pNextItem;
}

template<class T>
void TLinkedListItem<T>::setNextItemPtr(shared_ptr<TLinkedListItem<T>> pNextItem)
{
	this->pNextItem = pNextItem;
}

template class TLinkedListItem<Triangle>;
