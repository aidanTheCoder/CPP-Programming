#include <iostream>
#include "FileIntegerBuffer.h"
#include "Assert.h"
using namespace std;

int main() {
    FileIntegerBuffer ibuf1(32);
    FileIntegerBuffer ibuf2(32);
    int data[12] = { -4, 6, 0, 12, 478, 16, 8, 3, 6, 17, 88, 17 };
    ibuf1.add(data, 12);
    ibuf1.store("data.txt", 10, 7);
	Assert::isTrue(ibuf1 == ibuf2);
    ibuf2.load("data.txt");
	Assert::isTrue(ibuf1 == ibuf2);
    ibuf2.print(10, 7);
    system("pause");
    return 0;
}