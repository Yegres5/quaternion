#include "complex.h"

#include <cmath>
#include <algorithm>

Complex &Complex::cojugate() const
{
    return *new Complex(real, Imagine::reverse(imagine));
}

Complex &Complex::reverse() const
{
    return *new Complex(this->cojugate()/std::pow(this->abs(),2));
}

double Complex::abs() const
{
    return std::sqrt(std::pow(real,2) + Imagine::square(imagine));
}

Complex &Complex::operator/(const Complex &comp) const
{
    return *new Complex(*this*comp.reverse());
}

Complex &Complex::operator/(const double &comp) const
{
    return *new Complex(real/comp, imagine/comp);
}

Complex &Complex::operator*(const Complex &comp) const
{
    return *new Complex(real*comp.real - Imagine::scalar(imagine, comp.imagine),
                           Imagine::vector(imagine, comp.imagine)+ comp.imagine*real+imagine*comp.real);
}

Complex &Complex::operator+(const Complex &comp) const
{
    return *new Complex(real+comp.real, imagine+comp.imagine);
}

Complex &Complex::operator-(const Complex &comp) const
{
    return *new Complex(real-comp.real, imagine-comp.imagine);
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImagine_1() const
{
    return imagine.getValue(0);
}

double Complex::getImagine()
{
    //return imagine
}
