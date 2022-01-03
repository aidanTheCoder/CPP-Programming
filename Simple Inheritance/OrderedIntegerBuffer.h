#pragma once
#include "IntegerBuffer.h"
class OrderedIntegerBuffer : public IntegerBuffer { 
public:
	int add(int value);
	int add(const int array[], int arrayLength);
	int removeFast(int index);
	int copy(const OrderedIntegerBuffer* other);
};

