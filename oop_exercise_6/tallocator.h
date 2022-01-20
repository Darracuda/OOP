#pragma once
#include <memory>
#include <vector>
#include "tvector.h"

using namespace std;

class TAllocator
{
private:
	byte* data;
	TVector<byte*> usedBlocks;
	TVector<byte*> freeBlocks;

public:
	TAllocator(size_t size, size_t number);
	virtual ~TAllocator();

	byte* allocate();
	void unallocate(byte* ptr);
};

