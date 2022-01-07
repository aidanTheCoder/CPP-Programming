#include "STLIntegerBuffer.h"

bool STLIntegerBuffer::Iterator
    ::operator==(const Iterator& rhs) const {
    return cursor == target->dataLength;
}

bool STLIntegerBuffer::Iterator
    ::operator!=(const Iterator& rhs) const {
    return !(operator==(rhs));
}

void STLIntegerBuffer::Iterator::operator++() {
    ++cursor;
}

void STLIntegerBuffer::Iterator::operator++(int) {
    ++cursor;
}

const int& STLIntegerBuffer::Iterator::operator*()  {
    return target->data[cursor];
}

void STLIntegerBuffer::copy(int other[], const int arrayLength) {
    for (int i = 0; i < arrayLength; ++i)
        other[i] = data[i];
}

STLIntegerBuffer::Iterator STLIntegerBuffer::begin() {
    return STLIntegerBuffer::Iterator(this, 0);
}

STLIntegerBuffer::Iterator STLIntegerBuffer::end() {
    return STLIntegerBuffer::Iterator(this, dataLength);
}
