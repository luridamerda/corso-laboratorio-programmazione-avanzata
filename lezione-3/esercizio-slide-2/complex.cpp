#include "complex.h"

Complex::Complex(double real, double imag) : realPart(real), imagPart(imag) {}

// Overloading operatori
Complex Complex::operator+(const Complex& other) const {
    return Complex(realPart + other.realPart, imagPart + other.imagPart);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(realPart - other.realPart, imagPart - other.imagPart);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(realPart * other.realPart - imagPart * other.imagPart,
                   realPart * other.imagPart + imagPart * other.realPart);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.realPart * other.realPart + other.imagPart * other.imagPart;
    return Complex((realPart * other.realPart + imagPart * other.imagPart) / denominator,
                   (imagPart * other.realPart - realPart * other.imagPart) / denominator);
}

bool Complex::operator==(const Complex& other) const {
    return realPart == other.realPart && imagPart == other.imagPart;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Getters
double Complex::real() const {
    return realPart;
}

double Complex::imag() const {
    return imagPart;
}

// Overloading <<
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.realPart << ", " << c.imagPart << ")";
    return os;
}