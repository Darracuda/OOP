#include <memory>
#include <stdexcept>
#include "tvector.h"

using namespace std;

template<class T>
TVector<T>::TVector()
{
	data =  new T[minCount];
	count = minCount;
	length = 0;
}

template<class T>
TVector<T>::TVector(const TVector& other)
{
	// TO DO
	data = new T[minCount];
	count = minCount;
	length = 0;
}

template<class T>
void TVector<T>::InsertLast(T item)
{
	if (length >= maxCount)
		throw runtime_error("cannot add new item to the list as the maximum size reached");

	if (length >= count)
		increaseAllocation();

	data[length] = item;
	length++;
}

template<class T>
void TVector<T>::RemoveLast()
{
	if (length == 0)
		throw runtime_error("cannot remove last item in empty list");

	length--;
}

template<class T>
T TVector<T>::Last()
{
	if (length == 0)
		throw runtime_error("cannot get last item from empty list");

	return data[length-1];
}
template<class T>
T& TVector<T>::operator[](const size_t position)
{
	if (position >= length)
		throw runtime_error("invalid position");
	return data[position];
}

template<class T>
bool TVector<T>::Empty()
{
	return length == 0;
}

template<class T>
const size_t TVector<T>::Length()
{
	return length;
}

template<class T>
void TVector<T>::Clear()
{
	length = 0;
}

template<class T>
TVector<T>::~TVector()
{
	Clear();
	if (data != nullptr)
		delete data;
}

template<class T>
const size_t TVector<T>::Find(T item)
{
	for (size_t i = 0; i <= length; i++)
	{
		if (data[i] == item)
			return i;
	}
	return (size_t)-1;
}

template<class T>
void TVector<T>::RemoveAt(const size_t position)
{
	if (position >= length)
		throw runtime_error("invalid position");
}

template<class T>
void TVector<T>::increaseAllocation()
{
	size_t newCount = min(2 * count, maxCount);
	T* newData = new T[newCount];
	for (int i = 0; i < count; i++)
		newData[i] = data[i];
	delete data;
	data = newData;
	count = newCount;
}

template class TVector<int>;
template class TVector<byte*>;
