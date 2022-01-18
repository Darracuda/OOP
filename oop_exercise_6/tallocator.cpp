#include <algorithm>
#include "tallocator.h"

TAllocator::TAllocator(int32_t size, size_t number)
{
    pMemory = (unsigned char*)malloc(size * number);
    for (size_t i = 0; i < number; i++) 
    {
        void* ptr = pMemory + i * size;
        freeBlocks.push_back(ptr);
    }
}

TAllocator::~TAllocator()
{
    freeBlocks.clear();
    usedBlocks.clear();
    delete pMemory;
}

void* TAllocator::allocate()
{
    if (freeBlocks.empty())
        throw runtime_error("No free blocks to allocate memory");
    void* ptr = freeBlocks.back();
    freeBlocks.pop_back();
    usedBlocks.push_back(ptr);
    return ptr;
}

void TAllocator::unallocate(void* ptr)
{
    if (ptr == nullptr)
        return;
    auto pos = find(usedBlocks.begin(), usedBlocks.end(), ptr);
    if (pos == usedBlocks.end())
        throw runtime_error("Bad pointer to free memory");
    usedBlocks.erase(pos);
    freeBlocks.push_back(ptr);
}
