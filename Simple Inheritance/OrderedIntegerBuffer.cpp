#include "OrderedIntegerBuffer.h"

int OrderedIntegerBuffer::add(int value) {
    if (dataLength == dataCapacity)
        return 0;
    else {
        int i = 0;
        //find the spot for the new data to go
        
        for (i = 0; i < dataLength && data[i] < value; ++i)
            ;
        //move every element back 1 space
        for (int j = dataLength; j > i; --j)
            data[j] = data[j - 1];
        data[i] = value;
        ++dataLength;
        
        return 1;
    }
}

int OrderedIntegerBuffer::add(const int array[], int arrayLength) {
    int count = 0;
    for (int i = 0; i < arrayLength; ++i)
        count += add(array[i]);
    return count;
}

int OrderedIntegerBuffer::removeFast(int index) {
    return IntegerBuffer::removeStable(index);
}

int OrderedIntegerBuffer::copy(const OrderedIntegerBuffer* other) {
    if (other == this)
        return 0;
    else {
        clear();
        add(other->data, other->dataLength);
        return 1;
    }
}
