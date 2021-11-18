#pragma once

class IntegerBuffer
{
private:
	static const int dataCapacity = 32;
	int data[dataCapacity];
	int dataLength;
public:
	IntegerBuffer();
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
};

