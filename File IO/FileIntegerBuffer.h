#pragma once
#include <string>
#include "IntegerBuffer.h"

class FileIntegerBuffer : public IntegerBuffer {
public:
	FileIntegerBuffer(int capacity) : IntegerBuffer(capacity) {}
	inline bool operator==(IntegerBuffer& rhs) { return compare(rhs); }
	bool store(std::string filename, 
		int columnWidth, int numberOfColumns);
	int load(std::string filename);
};

