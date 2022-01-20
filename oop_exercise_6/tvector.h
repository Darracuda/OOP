#pragma once
template <class T>
class TVector
{
private:
	const size_t minCount = 3;
	const size_t maxCount = 10;

	T * data;
	size_t count;
	size_t length;

public:
	TVector();
	TVector(const TVector& other);
	void InsertLast(T item);
	void RemoveLast();
	T Last();
	T& operator[] (const size_t position);
	bool Empty();
	const size_t Length();
	void Clear();
	virtual ~TVector();

	const size_t Find(T item);
	void RemoveAt(const size_t position);

private:
	void increaseAllocation();
};

