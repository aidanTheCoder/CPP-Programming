#pragma once
#include <iostream>
#include <iomanip>

template <class T, int CAPACITY>
class TBuffer {
	T data[CAPACITY];
	int dataLength;
public:
	inline TBuffer(T value) {
		dataLength = 0;
		if (CAPACITY > 0)
			data[0] = value;
	}

	inline int add(const T value) {
		if (dataLength < CAPACITY) {
			data[dataLength] = value;
			++dataLength;
			return 1;
		}
		else
			return 0;
	}

	inline int add(const int array[], int arrayLength) {
		int count = 0;
		for (int i = 0; i < arrayLength; ++i)
			count += add(array[i]);
		return count;
	}

	inline void print(int numberOfColumns, int columnWidth) const {
		for (int i = 0; i < dataLength; ++i) {
			if (i > 0 && (i % numberOfColumns) == 0)
				std::cout << "\n";
			std::cout << std::setw(columnWidth) << data[i];
		}
		std::cout << std::endl;
	}

	inline int getDataLength() const { return dataLength; }

	inline T sum() {
		T sum = data[0];
		for (int i = 1; i < dataLength; ++i) 
			sum += data[i];
		return sum;
	}
};