#include "OrderedIntegerBuffer.h"

int OrderedIntegerBuffer::add(int value) {
    if(dataLength == dataCapacity)
        return 0;
    else {
        int i = 0;
        for (i = 0; i < dataLength && data[i] < value; ++i)
            ;
        for (int j = dataLength; j > i; --j)
            data[j] = data[j - 1];
        data[i] = value;
        ++dataLength;
        return 1;
    }
}
