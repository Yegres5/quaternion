#ifndef QUATERNION_H
#define QUATERNION_H

#include "complex.h"

class Quaternion : public Complex
{
public:
    Quaternion():Complex(0, {0, 0, 0}){}
    Quaternion(std::initializer_list<double> l);
    Quaternion(const double &a, std::initializer_list<double> l):Complex(a, l){}

    Quaternion &operator+(const Quaternion&quat);
    Quaternion &operator-(const Quaternion&quat);
    Quaternion &operator*(const Quaternion&quat);
    Quaternion &operator/(const Quaternion&quat);

    double getImagine_2() const;
    double getImagine_3() const;
};

#endif // QUATERNION_H
