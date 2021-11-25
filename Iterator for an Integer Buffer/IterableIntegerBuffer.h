#pragma once
#include "Iterator.h"

class IterableIntegerBuffer {
	int dataCapacity;
	int* data;
	int dataLength;
	friend class IntegerBufferIterator;
public:
	IterableIntegerBuffer(int capacity);
	int add(int value);
	int add(const int array[], int arrayLength);
	void print(int numberOfColumns, int columnWidth) const;
	Iterator* createIterator();
};

class IntegerBufferIterator : public Iterator {
	IterableIntegerBuffer* collection;
	int cursor;
	IntegerBufferIterator(IterableIntegerBuffer* collection)
		: collection(collection), cursor(0) {}
	friend class IterableIntegerBuffer;
public:
	void first() override;
	void next() override;
	bool isDone() override;
	int currentItem() override;
};

