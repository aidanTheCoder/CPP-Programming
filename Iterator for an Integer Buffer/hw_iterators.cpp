#include <iostream>
#include "IterableIntegerBuffer.h"
#include "Iterator.h"
using namespace std;

void testIterableIntegerBuffer(int arr[], int length);

int main() {
	const int ARR1_LEN = 10;
	int arr1[ARR1_LEN] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int ARR2_LEN = 25;
	int arr2[ARR2_LEN] = { 2, 4, 6, 8, 10, 12, 14, 16, 7, 6, 22, 8,
		9, 16, 5, 2, 7, 8, 12, 2, 0, 14, 17, 19, 22 };
	testIterableIntegerBuffer(arr1, ARR1_LEN);
	testIterableIntegerBuffer(arr2, ARR2_LEN);
	system("pause");
	return 0;
}

void testIterableIntegerBuffer(int arr[], int length) {
	IterableIntegerBuffer data(32);
	data.add(arr, length);
	data.print(10, 7);
	Iterator* iter1 = data.createIterator();
	iter1->next();
	cout << "The first iterator is on " << iter1->currentItem()
		<< endl;
	Iterator* iter2 = data.createIterator();
	cout << "Using the second iterator: " << endl;
	for (iter2->first(); !iter2->isDone(); iter2->next())
		cout << iter2->currentItem() << " ";
	cout << endl;
	cout << "The first iterator is still on " << iter1->currentItem()
		<< endl;
	delete iter1;
	delete iter2;
}