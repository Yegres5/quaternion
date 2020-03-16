#ifndef Complex_H
#define Complex_H

#include "imagine.h"

class Complex{
public:
    Complex():real(0), imagine({0}){}
    Complex(double a, double b):real(a), imagine{b}{}

    Complex &cojugate() const;
    Complex &reverse() const;
    double abs() const;

    Complex &operator/(const Complex &comp) const;
    Complex &operator/(const double &comp) const;
    Complex &operator*(const Complex &comp) const;
    Complex &operator*(const double &value) const;
    Complex &operator+(const Complex &comp) const;
    Complex &operator-(const Complex &comp) const;

    double getReal() const;
    double getImagine_1() const;

    friend class Quaternion;

protected:
    Complex(const double &a, Imagine::Imaginary _imagine):real(a), imagine(_imagine){}
    double getImagine();

    double real;
    Imagine::Imaginary imagine;
};

#endif // Complex_H
