#pragma once
#include <memory>

using namespace std;

template <class T>
class TBinaryTreeItem
{
private:
	shared_ptr<T> pValue;
	size_t count;
	shared_ptr<TBinaryTreeItem<T>> pLeftSubItem;
	shared_ptr<TBinaryTreeItem<T>> pRightSubItem;

public:
	TBinaryTreeItem(shared_ptr<T> pValue);
	virtual ~TBinaryTreeItem();

	shared_ptr<T> getValuePtr();
	size_t getCount();
	void incCount();
	void decCount();
	shared_ptr<TBinaryTreeItem<T>> getLeftSubItemPtr();
	shared_ptr<TBinaryTreeItem<T>> getRightSubItemPtr();
	void setLeftSubItemPtr(shared_ptr<TBinaryTreeItem<T>> pLeftSubItem);
	void setRightSubItemPtr(shared_ptr<TBinaryTreeItem<T>> pRightSubItem);
};
