#include <iostream>
#include "STLIntegerBuffer.h"
using namespace std;

int main() {
    const int ARR1_LEN = 3;
    int arr1[ARR1_LEN] = { 4, 7, 3 };
    STLIntegerBuffer test;
    test.add(arr1, ARR1_LEN);
    for (auto iter = test.begin(); iter != test.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    const int ARR2_LEN = 12;
    int arr2[ARR2_LEN] = { 3, 6, 8, 9, 1, 5, 3, 2, 7, 12, 4, 8 };
    test.clear();
    test.add(arr2, ARR2_LEN);
    for (auto iter = test.begin(); iter != test.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    return 0;
}
