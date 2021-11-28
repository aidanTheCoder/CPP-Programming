#include "IntegerSet.h"
#include <iostream>

int IntegerSet::add(int value) {
    if (index(value) == -1)
        return IntegerBuffer::add(value);
    else
        return 0;
}
