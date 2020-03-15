#include "quaternion.h"

#include <cmath>
#include <algorithm>

Quaternion::Quaternion(std::initializer_list<double> l):real(*l.begin()), imagine(l){
    imagine.erase(0);
}

Quaternion &Quaternion::cojugate() const
{
    return *new Quaternion(real, Imagine::reverse(imagine));
}

Quaternion &Quaternion::reverse() const
{
    return *new Quaternion(this->cojugate()/std::pow(this->abs(),2));
}

double Quaternion::abs() const
{
    return std::sqrt(std::pow(real,2) + Imagine::square(imagine));
}

Quaternion &Quaternion::operator/(const Quaternion &comp) const
{
    return *new Quaternion(*this*comp.reverse());
}

Quaternion &Quaternion::operator/(const double &comp) const
{
    return *new Quaternion(real/comp, imagine/comp);
}

Quaternion &Quaternion::operator*(const Quaternion &comp) const
{
    return *new Quaternion(real*comp.real - Imagine::scalar(imagine, comp.imagine),
                           Imagine::vector(imagine, comp.imagine)+ comp.imagine*real+imagine*comp.real);
}

Quaternion &Quaternion::operator+(const Quaternion &comp) const
{
    return *new Quaternion(real+comp.real, imagine+comp.imagine);
}

Quaternion &Quaternion::operator-(const Quaternion &comp) const
{
    return *new Quaternion(real-comp.real, imagine-comp.imagine);
}
