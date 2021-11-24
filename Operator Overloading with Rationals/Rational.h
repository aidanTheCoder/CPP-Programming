#pragma once
#include <iostream>

class Rational {
	int numerator;
	int denominator;
	void normalize();
public:
	Rational();
	Rational(int first, int second) : numerator(first), denominator(second) {}
	friend std::ostream& operator<<(std::ostream& os, const Rational& result);
	operator double() const;
	Rational& operator=(const Rational & rhs);
	Rational operator+(const Rational& rhs) const;
	Rational operator-(const Rational& rhs) const;
	Rational operator*(const Rational& rhs) const;
	Rational operator/(const Rational& rhs) const;
	bool operator==(const Rational& rhs);
	bool operator!=(const Rational& rhs);
	static int getGCD(int a, int b);
};

