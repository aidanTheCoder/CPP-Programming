#pragma once

class IntegerBuffer {
protected:
	static const int dataCapacity = 32;
	int data[dataCapacity];
	int dataLength;
public:
	IntegerBuffer();
	void clear();
	int add(int value);
	int add(const int array[], int arrayLength);
};