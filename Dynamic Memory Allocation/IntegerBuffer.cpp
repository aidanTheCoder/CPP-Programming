#include <iostream>
#include <iomanip>
#include <new>
#include "IntegerBuffer.h"
using std::cout;
using std::endl;
using std::setw;
using std::cerr;
using std::bad_alloc;

IntegerBuffer::IntegerBuffer(int capacity) {
    dataLength = 0;
    try {
        data = new int[capacity];
        dataCapacity = capacity;
    } catch (const bad_alloc& e) {
        data = nullptr;
        dataCapacity = 0;
    }
}

IntegerBuffer::~IntegerBuffer() {
    dataCapacity = 0;
    dataLength = 0;
    if (data != nullptr) {
        int* mem = data;
        data = nullptr;
        delete[] mem;
    }
}

IntegerBuffer::IntegerBuffer(const IntegerBuffer& instance) : IntegerBuffer(dataCapacity) {
    this->dataCapacity = instance.dataCapacity;
    copy(this);
}

void IntegerBuffer::clear() {
    dataLength = 0;
}

int IntegerBuffer::add(int value) {
    if (dataLength < dataCapacity) {
        data[dataLength] = value;
        ++dataLength;
        return 1;
    } else {
        return 0;
    }
}

int IntegerBuffer::add(const int array[], int arrayLength) {
    int count = 0;
    for (int i = 0; i < arrayLength; ++i)
        count += add(array[i]);
    return count;
}

int IntegerBuffer::removeFast(int index) {
    if (index >= 0 && index < dataLength) {
        --dataLength;
        data[index] = data[dataLength];
        return 1;
    }
    else
        return 0;
}

int IntegerBuffer::removeStable(int index) {
    if (index >= 0 && index < dataLength) {
        --dataLength;
        for (int i = index; i < dataLength; ++i) 
            data[i] = data[i + 1];
        
        return 1;
    } else
        return 0;
 
}

int IntegerBuffer::index(int value) const {
    for (int i = 0; i < dataLength - 1; ++i)
        if (data[i] == value)
                return i;
    return -1;
}

int IntegerBuffer::rindex(int value) const {
    if (dataLength == 0)
        return -1;
    else {
        for (int i = dataLength - 1; i >= 0; --i) {
            if (data[i] == value)
                return i;
        }
        return -1;
    }
}

void IntegerBuffer::print(int numberOfColumns, int columnWidth) const {
    for (int i = 0; i < dataLength; ++i) {
        if (i > 0 && (i % numberOfColumns) == 0)
            cout << endl;
        cout << setw(columnWidth) << data[i];
    }
    cout << endl;
}

int IntegerBuffer::copy(const IntegerBuffer* other) {
    if (other == this)
        return 0;
    else {
        clear();
        add(other->data, other->dataLength);
        return 1;
    }
}

bool IntegerBuffer::compare(const IntegerBuffer& other) const {
    for (int i = 0; i < dataLength; ++i)
        if (other.data[i] != this->data[i])
            return false;
    return true;
}

IntegerBuffer* IntegerBuffer::clone() {
    return new IntegerBuffer(dataCapacity);
}
