#pragma once
#include <iostream> 
#include <memory>
#include "tbinarytreeitem.h"

using namespace std;

template <class T>
class TBinaryTree
{
private:
	shared_ptr<TBinaryTreeItem<T>> pHeadItem;

public:
	TBinaryTree();
	virtual ~TBinaryTree();

	void Push(shared_ptr<T> pValue);
	void Pop(shared_ptr<T> pValue);
	shared_ptr<T> GetItemNotLess(double area);
	size_t Count(shared_ptr<T> pValue);
	bool Empty();
	void Clear();

	template <class T2>
	friend std::ostream& operator<<(std::ostream& os, const TBinaryTree<T2>& tree);
};
