#ifndef Quaternion_H
#define Quaternion_H

#include "imagine.h"

class Quaternion{
public:
    Quaternion():real(0), imagine({0,0,0}){}
    Quaternion(std::initializer_list<double> l);
    Quaternion(const double &a, std::initializer_list<double> l):real(a), imagine(l){}
    Quaternion(const double &a, Imagine::Imaginary _imagine):real(a), imagine(_imagine){}

    Quaternion &cojugate() const;
    Quaternion &reverse() const;
    double abs() const;

    Quaternion &operator/(const Quaternion &comp) const;
    Quaternion &operator/(const double &comp) const;
    Quaternion &operator*(const Quaternion &comp) const;
    Quaternion &operator*(const double &value) const;
    Quaternion &operator+(const Quaternion &comp) const;
    Quaternion &operator-(const Quaternion &comp) const;

//private:
    double real;
    Imagine::Imaginary imagine;
};

#endif // Quaternion_H
