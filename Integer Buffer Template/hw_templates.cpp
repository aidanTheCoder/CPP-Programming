#include <string>
#include <iostream>
#include "TBuffer.h"
using namespace std;

void baseTest();

int main() {
	baseTest();
	system("pause");
	return 0;
}

void baseTest() {
	TBuffer<int, 12> ib(0);
	TBuffer<double, 10> db(0.0);
	TBuffer<string, 10> sb("");
	int i_array[10] = { 12, -4, 6, 8, 6, 5, -4, -6, 11, 88 };
	ib.add(7);
	ib.add(12);
	ib.add(17);
	ib.add(i_array, 9);
	cout << "Length: " << ib.getDataLength() << endl;
	ib.print(10, 7);
	cout << "Sum: " << ib.sum() << endl;
	db.add(8.463);
	db.add(3.74);
	db.add(5.231);
	db.add(3.74);
	db.print(10, 7);
	cout << "Sum: " << db.sum() << endl;
	sb.add("John");
	sb.add("Sarah");
	sb.add("John");
	sb.add("Sarah");
	sb.add("Miguel");
	sb.add("Fred");
	sb.add("Klyde");
	sb.add("Clara");
	sb.print(10, 7);
	cout << "Sum: " << sb.sum() << endl;
}