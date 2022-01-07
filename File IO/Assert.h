#ifndef ASSERT_H
#define ASSERT_H
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Assert {
public:
	static void isTrue(bool actual) {
		if (actual)
			cout << "OK" << endl;
		else
			cout << "FAIL" << endl;
	}

	static void isFalse(bool actual) {
		if (actual)
			cout << "FAIL" << endl;
		else
			cout << "OK" << endl;
	}

	static void equals(int expected, int actual) {
		if (expected == actual)
			cout << "OK" << endl;
		else
			cout << "FAIL" << endl;
	}

	static void equals(string expected, string actual) {
		if (expected.compare(actual) == 0)
			cout << "OK" << endl;
		else
			cout << "FAIL" << endl;
	}
};

#endif
