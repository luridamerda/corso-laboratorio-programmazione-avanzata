#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0);

    // Overloading operatori
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Getters
    double real() const;
    double imag() const;

    // Overloading
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

private:
    double realPart;
    double imagPart;
};

#endif // COMPLEX_H