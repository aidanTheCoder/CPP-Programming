#pragma once
#include "IntegerBuffer.h"

class STLIntegerBuffer : public IntegerBuffer {
public:
	class Iterator {
	private:
		STLIntegerBuffer* target = nullptr;
		int cursor = 0;
		int null = 0;
		inline Iterator(STLIntegerBuffer* target, int cursor) 
			: target(target), cursor(cursor), null(0) {}
		friend class STLIntegerBuffer;
	public:
		bool operator==(const Iterator& rhs) const;
		bool operator!=(const Iterator& rhs) const;
		void operator++();
		void operator++(int);
		const int& operator*();
	};
	Iterator begin();
	Iterator end();
	void copy(int other[], const int arrayLength);
};
