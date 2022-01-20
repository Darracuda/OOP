#include <memory>
#include <stdexcept>
#include "tallocator.h"

using namespace std;

TAllocator::TAllocator(size_t size, size_t number)
{
    data = (byte*)malloc(size * number);
    for (size_t i = 0; i < number; i++) 
    {
        byte* ptr = data + i * size;
        freeBlocks.InsertLast(ptr);
    }
}

TAllocator::~TAllocator()
{
    freeBlocks.Clear();
    usedBlocks.Clear();
    free(data);
}

byte* TAllocator::allocate()
{
    if (freeBlocks.Empty())
        throw runtime_error("No free blocks to allocate memory");
    byte* ptr = freeBlocks.Last();
    freeBlocks.RemoveLast();
    usedBlocks.InsertLast(ptr);
    return ptr;
}

void TAllocator::unallocate(byte* ptr)
{
    if (ptr == nullptr)
        return;
    size_t position = usedBlocks.Find(ptr);
    if (position == (size_t)-1)
        throw runtime_error("Bad pointer to free memory");
    usedBlocks.RemoveAt(position);
    freeBlocks.InsertLast(ptr);
}
