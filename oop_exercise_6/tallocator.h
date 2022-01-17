#pragma once
#include <memory>

class TAllocator
{
public:
	TAllocator(size_t size, size_t number);

	void* allocate(size_t size);
	void unallocate(void* pObject);
};

