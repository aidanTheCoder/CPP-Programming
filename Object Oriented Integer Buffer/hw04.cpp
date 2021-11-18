/*
* File:    hw11.c
* Project: Homework 11
* Purpose: test driver for student homework
* Author:  Michael Van Hilst
* Version: 1.0 November 11, 2017 (in the 11th hour of the 11th day ...)
*          2.0 March 29, 2019 updated with different behavior
*
* Copyright 2017,2019 (c) Michael Van Hilst All rights reserverd.
*/
#include <iostream>         /* for printf() */
#include "IntegerBuffer.h" /* homework project header file */
using std::cout;
using std::endl;

void fillRandom(int array[], int arrLen, int lowerBound, int upperBound);
int myrand(void);
#define MYRAND_MAX 32768

/* DATASZ is set to exceed size of array in the IntegerBuffer */
int main(void) {
	static const int DATASZ = 48;
	int i = 0;
	int index = 0;
	int result = 0;
	IntegerBuffer ibuf;
	int data[DATASZ];
	/* test that ibufInit is working correctly */
	cout << "Phase 1:" << endl;
	cout << "capacity: " << ibuf.getCapacity()
		 << ", length: " <<  ibuf.getLength() << endl;
	/* test that ibufAdd is working correctly */
	cout << "Phase 2:" << endl;
	ibuf.add(5);
	ibuf.add(17);
	ibuf.print(10, 7);
	/* test that ibufAddArray is working correctly */
	cout << "Phase 3:" << endl;
	fillRandom(data, DATASZ, 20, 75);
	result = ibuf.add(data, DATASZ);
	cout << "reported adding " << result << " of " << DATASZ << endl;
	ibuf.print(9, 7);

	/* test that ibufClear is working correctly */
	cout << "Phase 4:" << endl;
	ibuf.clear();
	for (i = 0; i < 5; i++)
		ibuf.add(i);
	for (i = 5; i > 0; i--)
		ibuf.add(i);
	ibuf.print(10, 7);
	/* test that ibufIndex, ibufRemoveDast and ibufRemoveStable work */
	cout << "Phase 5:" << endl;
	index = ibuf.index(2);
	ibuf.removeFast(index);
	ibuf.removeStable(ibuf.rindex(3));
	ibuf.print(10, 5);
	/* use the #ifdef NOTYET line to hide parts you haven't yet done */
#ifdef NOTYET
#endif
	system("pause");
	return 0;
}

/* Function: fillRandom
* Purpose:  fill an integer array with random values in a given range
* Argument: array      - an array of integers
* Argument: arrLen     - the number of integers to generate
* Argument: lowerBound - the lowest value that could be generated
* Argument: upperBound - the highest value that could be generated
* Returns:  nothing
* Precondition: array points to a valid array of ints
* Precondition: arrLen is not greater than the available space in array
*/
void fillRandom(int array[], int arrLen, int lowerBound, int upperBound) {
	int i;
	/* static makes this a persistent variable
	that is initialized only once */
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
