#include <iostream>
#include <iomanip>
#include <new>
#include "IterableIntegerBuffer.h"
using namespace std;

void IntegerBufferIterator::first() {
	cursor = 0;
}

void IntegerBufferIterator::next() {
	if (!isDone())
		++cursor;
}

bool IntegerBufferIterator::isDone() {
	return cursor == collection->dataLength;
}

int IntegerBufferIterator::currentItem() {
	if (isDone())
		return 0;
	else
		return collection->data[cursor];
}

IterableIntegerBuffer::IterableIntegerBuffer(int capacity) {
	dataLength = 0;
	try {
		data = new int[capacity];
		dataCapacity = capacity;
	} catch (const bad_alloc& e) {
		cerr << "Allocation failed: " << e.what() << endl;
		data = nullptr;
		dataCapacity = 0;
	}
}

int IterableIntegerBuffer::add(int value) {
	if (dataLength < dataCapacity) {
		data[dataLength] = value;
		++dataLength;
		return 1;
	} else
		return 0;
}

int IterableIntegerBuffer::add(const int array[], int arrayLength) {
	int count = 0;
	for (int i = 0; i < arrayLength; ++i)
		count += add(array[i]);
	return count;
}

void IterableIntegerBuffer::print(int numberOfColumns, int columnWidth) const {
	for (int i = 0; i < dataLength; ++i) {
		if (i > 0 && (i % numberOfColumns) == 0)
			cout << endl;
		cout << setw(columnWidth) << data[i];
	}
	cout << "\n";
}

Iterator* IterableIntegerBuffer::createIterator() {
	return new IntegerBufferIterator(this);
}
