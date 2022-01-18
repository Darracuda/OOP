#pragma once
#include <memory>
#include <vector>
#include "tbinarytree.h"

using namespace std;

class TAllocator
{
private:
	unsigned char* pMemory;
	//TBinaryTree<void*> usedBlocks;
	//TBinaryTree<void*> freeBlocks;
	vector<void*> usedBlocks;
	vector<void*> freeBlocks;

public:
	TAllocator(int32_t size, size_t number);
	virtual ~TAllocator();

	void* allocate();
	void unallocate(void* pObject);
};

