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
        data = new int[10];
        dataCapacity = capacity;
    } catch (const bad_alloc& e) {
        cerr << "Allocation failed: " << e.what() << endl;
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

void IntegerBuffer::print(int numberOfColumns, int columnWidth) const {
    for (int i = 0; i < dataLength; ++i) {
        if (i > 0 && (i % numberOfColumns) == 0)
            cout << endl;
        cout << setw(columnWidth) << data[i];
    }
    cout << endl;
}

bool IntegerBuffer::compare(const IntegerBuffer& other) const {
    for (int i = 0; i < dataLength; ++i)
        if (other.data[i] != this->data[i])
            return false;
    return true;
}
