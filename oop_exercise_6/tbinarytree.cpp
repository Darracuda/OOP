#include <iostream>
#include <memory>
#include <stdexcept>
#include "tbinarytree.h"
#include "triangle.h"

template<class T>
TBinaryTree<T>::TBinaryTree()
{
}

template<class T>
inline void TBinaryTree<T>::Push(shared_ptr<T> pValue)
{
}

template<class T>
void TBinaryTree<T>::Pop(shared_ptr<T> pValue)
{
}

template<class T>
shared_ptr<T> TBinaryTree<T>::GetItemNotLess(double area)
{
	return shared_ptr<T>();
}

template<class T>
size_t TBinaryTree<T>::Count(shared_ptr<T> pValue)
{
	return size_t();
}

template<class T>
bool TBinaryTree<T>::Empty()
{
	return false;
}

template<class T>
void TBinaryTree<T>::Clear()
{
}

template<class T>
TBinaryTree<T>::~TBinaryTree()
{
	Clear();
}

template<class T2>
inline std::ostream& operator<<(std::ostream& os, const TBinaryTree<T2>& tree)
{
	// TODO: insert return statement here
}

//template class TBinaryTree;
