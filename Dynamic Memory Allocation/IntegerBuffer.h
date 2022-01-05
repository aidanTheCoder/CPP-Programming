#pragma once

class IntegerBuffer {
	int* data;
	int dataLength;
	int dataCapacity;
public:
	IntegerBuffer(int capacity);
	~IntegerBuffer();
	IntegerBuffer(const IntegerBuffer& instance);
	void clear();
	int add(int value);
	int add(const int array[], int arrayLength);
	int removeFast(int index);
	int removeStable(int index);
	int index(int value) const;
	int rindex(int value) const;
	void print(int numberOfColumns, int columnWidth) const;
	int getCapacity() const { return dataCapacity;  }
	int getLength() const { return dataLength;  }
	int copy(const IntegerBuffer* other);
	bool compare(const IntegerBuffer& other) const;
	IntegerBuffer* clone();
};
