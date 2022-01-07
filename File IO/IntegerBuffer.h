#pragma once

class IntegerBuffer {
protected:
	int* data;
	int dataLength;
	int dataCapacity;
public:
	IntegerBuffer(int capacity);
	~IntegerBuffer();
	void clear();
	int add(int value);
	int add(const int array[], int arrayLength);
	void print(int numberOfColumns, int columnWidth) const;
	bool compare(const IntegerBuffer& other) const;
};