#include <memory>
#include "tbinarytreeitem.h"
#include "triangle.h"

using namespace std;

template<class T>
inline TBinaryTreeItem<T>::TBinaryTreeItem(shared_ptr<T> pValue)
{
	this->pValue = pValue;
	count = 0;
	pLeftSubItem = nullptr;
	pRightSubItem = nullptr;
}

template<class T>
TBinaryTreeItem<T>::~TBinaryTreeItem()
{
}

template<class T>
shared_ptr<T> TBinaryTreeItem<T>::getValuePtr()
{
	return pValue;
}

template<class T>
size_t TBinaryTreeItem<T>::getCount()
{
	return count;
}

template<class T>
void TBinaryTreeItem<T>::incCount()
{
	count++;
}

template<class T>
void TBinaryTreeItem<T>::decCount()
{
	count--;
}

template<class T>
shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::getLeftSubItemPtr()
{
	return pLeftSubItem;
}

template<class T>
shared_ptr<TBinaryTreeItem<T>> TBinaryTreeItem<T>::getRightSubItemPtr()
{
	return pRightSubItem;
}

template<class T>
void TBinaryTreeItem<T>::setLeftSubItemPtr(shared_ptr<TBinaryTreeItem<T>> pLeftSubItem)
{
	this->pLeftSubItem = pLeftSubItem;
}

template<class T>
void TBinaryTreeItem<T>::setRightSubItemPtr(shared_ptr<TBinaryTreeItem<T>> pRightSubItem)
{
	this->pRightSubItem = pRightSubItem;
}

template class TBinaryTreeItem<Triangle>;
