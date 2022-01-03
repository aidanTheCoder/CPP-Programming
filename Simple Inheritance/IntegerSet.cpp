#include "IntegerSet.h"

int IntegerSet::add(int value) {
    if (dataLength < dataCapacity && index(value) == -1)
        return IntegerBuffer::add(value);
    else
        return 0;
}

int IntegerSet::add(const int array[], int arrayLength) {
    int count = 0;
    for (int i = 0; i < arrayLength; ++i)
        count += add(array[i]);
    return count;
}

int IntegerSet::copy(const IntegerSet* other) {
    if (other == this)
        return 0;
    else {
        clear();
        add(other->data, other->dataLength);
        return 1;
    }
}
