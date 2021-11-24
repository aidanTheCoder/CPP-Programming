#include "Rational.h"

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::operator double() const {
    return (double)numerator / (double)denominator;
}

Rational& Rational::operator=(const Rational& rhs) {
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
    return *this;
}

Rational Rational::operator+(const Rational& rhs) const {
    Rational myRational;
    myRational.numerator = (this->numerator * rhs.denominator)
        + (rhs.numerator * this->denominator);
    myRational.denominator = this->denominator * rhs.denominator;
    myRational.normalize();
    return myRational;
}

Rational Rational::operator-(const Rational& rhs) const {
    Rational myRational;
    myRational.numerator = (this->numerator * rhs.denominator)
        - (rhs.numerator * this->denominator);
    myRational.denominator = this->denominator * rhs.denominator;
    myRational.normalize();
    return myRational;
}

Rational Rational::operator*(const Rational& rhs) const {
    Rational myRational;
    myRational.numerator = this->numerator * rhs.numerator;
    myRational.denominator = this->denominator * rhs.denominator;
    myRational.normalize();
    return myRational;
}

Rational Rational::operator/(const Rational& rhs) const {
    Rational myRational;
    myRational.numerator = this->numerator * rhs.denominator;
    myRational.denominator = this->denominator * rhs.numerator;
    myRational.normalize();
    return myRational;
}

bool Rational::operator==(const Rational& rhs) {
    Rational other(rhs.numerator, rhs.denominator);
    normalize();
    other.normalize();
    if (this->numerator == other.numerator
        && this->denominator == other.denominator)
        return true;
    else
        return false;
}

bool Rational::operator!=(const Rational& rhs) {
    Rational other(rhs.numerator, rhs.denominator);
    normalize();
    other.normalize();
    if (this->numerator != other.numerator
        && this->denominator != other.denominator)
        return true;
    else
        return false;
}

void Rational::normalize() {
    if (numerator == 0)
        denominator = 1;
    else {
        int gcd = getGCD(numerator, denominator);
        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
}

int Rational::getGCD(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

std::ostream& operator<<(std::ostream& os, const Rational& result) {
    os << result.numerator << "/" << result.denominator;
    return os;
}