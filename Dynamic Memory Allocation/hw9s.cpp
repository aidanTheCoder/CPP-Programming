/*
 * FILE:    hw9p.cpp
 * PROJECT: CS225 Assignment 9
 * PURPOSE: Test implementations of IntegerBuffer that use the
 *          reference type for passing another IntegerBuffer to
 *          the copy constructor and compare function
 * AUTHOR:  Michael Van Hilst
 * VERSION: October 26, 2021
 */
#include <iostream>         /* for printf() */
#include "IntegerBuffer.h"  /* homework project header file */
using std::cout;
using std::cin;
using std::endl;

void test1(IntegerBuffer& ibuf, int data[], int dataSz);
void test2(IntegerBuffer* ibuf);
void test3();
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
int myrand(void);
#define MYRAND_MAX 32768

/* DATASZ is set to exceed size of array in the IntegerBuffer */
int main(void) {
    char c;
    static const int DATASZ = 20;
    int data[DATASZ];
    fillRandom(data, DATASZ, 20, 40);
    IntegerBuffer ibuf(40);
    test1(ibuf, data, DATASZ);
    test2(&ibuf);
    test3();
    // system("pause");
    cout << "Enter q to quit: ";
    cin >> c;
    return 0;
}

void test1(IntegerBuffer& ibuf, int data[], int dataSz) {
    int i = 0;
    int index = 0;
    int result = 0;
    /* test that ibufInit is working correctly */
    cout << "Phase 1: ";
    cout << "capacity: " << ibuf.getCapacity()
         << ", length: " << ibuf.getLength() << endl;
    /* test that ibufAdd is working correctly */
    cout << "Phase 2:";
    ibuf.add(5);
    ibuf.add(17);
    ibuf.print(10, 7);
    /* test that ibufAddArray is working correctly */
    cout << "Phase 3: ";
    result = ibuf.add(data, dataSz);
    cout << "reported adding " << result << " of " << dataSz << endl;
    ibuf.print(10, 7);
    /* test that ibufClear is working correctly */
    cout << "Phase 4:" << endl;
    ibuf.clear();
    for (i = 0; i < 5; i++)
        ibuf.add(i);
    for (i = 5; i > 0; i--)
        ibuf.add(i);
    ibuf.print(10, 7);
}

void test2(IntegerBuffer* ibuf) {
    IntegerBuffer dup1(*ibuf);
    if (ibuf->getCapacity() != dup1.getCapacity())
        cout << "Copy constructor memory allocate failed!" << endl;
    if (ibuf->getLength() != dup1.getLength())
        cout << "Copy constructor data copy failed!" << endl;
    IntegerBuffer* dup2 = dup1.clone();
    if (dup1.getCapacity() != dup2->getCapacity())
        cout << "Clone memory allocate failed!" << endl;
    if (dup1.getLength() != dup2->getLength())
        cout << "Clone data copy failed!" << endl;
    cout << " ibuf before remove on dup1" << endl;
    // If the copy constructor doesn't allocate, seg fault here
    ibuf->print(10, 7);
    dup1.removeFast(5);
    dup1.removeFast(0);
    cout << " ibuf after remove on dup1" << endl;
    ibuf->print(10, 7);
    cout << " dup1 after removeFast at indexes 5 and 0 " << endl;
    dup1.print(10, 7);
    cout << " dup2 after remove on dup1" << endl;
    dup2->print(10, 7);
    if (ibuf->compare(dup1)) {
        cout << "dup1 should not be the same as ibuf!" << endl;
    }
    else {
        cout << "dup1 is not the same as ibuf (yeah!)" << endl;
    }
    if (dup2->compare(*ibuf)) {
        cout << "dup2 is the same as ibuf (yeah!)" << endl;
    }
    else {
        cout << "dup2 should be the same as ibuf!"<< endl;
    }
    // Test that copy function doesn't allow self copy
    int length = ibuf->getLength();
    ibuf->copy(ibuf);
    if (length != ibuf->getLength())
        cout << "Error: copy function not checking this != other" << endl;
    cout << " deleting dup2 " << endl;
    delete dup2;
    cout << " exiting test2 " << endl;
}

void test3() {
    cout << "Phase 5:" << endl;
    cout << "Testing try catch implementation in constructor\n";
    IntegerBuffer ibuf(-1);
    cout << "capacity: " << ibuf.getCapacity()
         << ", length: " << ibuf.getLength() << endl;
}


/* Function: fillRandom
 * Purpose:  fill an integer array with random values in a given range
 * Argument: array      - an array of integers
 * Argument: arrLen     - the number of integers to generate
 * Argument: upperBound - the highest value that could be generated
 * Returns:  nothing
 * Precondition: array points to a valid array of ints
 * Precondition: arrLen is not greater than the available space in array
 */
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
    int i;
    /* static makes this a persistent variable
     * that is initialized only once */
    static int notSeeded = 1;
    double range = 1.0 + upperBound - lowerBound;
    if (notSeeded) {
        /* if we want it seeded, the srand goes here */
        notSeeded = 0;
    }
    for (i = 0; i < arrLen; i++) {
        /* refactored the order to force doubles to be used w/o cast */
        /* a good optimizer will also recognize that (range / RAND_MAX)
         * can be done outside the loop */
        array[i] = (int)(myrand() * (range / MYRAND_MAX) + lowerBound);
    }
}

/* POSIX.1-2001 gives the following example of an implementation of rand(),
 * useful when one needs the same sequence on different machines.
 */
int myrand(void) {
    static unsigned long next = 1;
    next = next * 1103515245 + 12345;
    return((unsigned)(next / 65536) % MYRAND_MAX);
}
