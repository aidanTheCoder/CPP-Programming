#pragma once
#include "IntegerBuffer.h"

class OrderedIntegerBuffer : public IntegerBuffer {
public:
	int add(int value) override;
	inline int add(const int array[], int arrayLength) {
		return IntegerBuffer::add(array, arrayLength);
	}
	inline int removeFast(int index) override {
		return IntegerBuffer::removeStable(index);
	}
};