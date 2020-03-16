#include "quaternion.h"

#include "complex.h"

Quaternion::Quaternion(std::initializer_list<double> l):
    Complex(*l.begin(), l)
{
    imagine.erase(0);
}

double Quaternion::getImagine_2() const
{
    return imagine.getValue(1);
}

double Quaternion::getImagine_3() const
{
    return imagine.getValue(2);
}

Quaternion &Quaternion::operator+(const Quaternion &quat)
{
    Complex pComp = Complex::operator+(quat);
    return *new Quaternion{pComp.real,
                pComp.imagine.getValue(0),
                pComp.imagine.getValue(1),
                pComp.imagine.getValue(2)
    };
}

Quaternion &Quaternion::operator-(const Quaternion &quat)
{
    Complex pComp = Complex::operator-(quat);
    return *new Quaternion{pComp.real,
                pComp.imagine.getValue(0),
                pComp.imagine.getValue(1),
                pComp.imagine.getValue(2)
    };
}

Quaternion &Quaternion::operator*(const Quaternion &quat)
{
    Complex pComp = Complex::operator*(quat);
    return *new Quaternion{pComp.real,
                pComp.imagine.getValue(0),
                pComp.imagine.getValue(1),
                pComp.imagine.getValue(2)
    };
}

Quaternion &Quaternion::operator/(const Quaternion &quat)
{
    Complex pComp = Complex::operator/(quat);
    return *new Quaternion{pComp.real,
                pComp.imagine.getValue(0),
                pComp.imagine.getValue(1),
                pComp.imagine.getValue(2)
    };
}
