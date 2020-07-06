#include "complex.h"

#include <boost/math/quaternion.hpp>
#include <random>
#include <ctime>
#include <iostream>
#include "quaternion.h"

using boost::math::quaternion;
using std::cout;

double fRand(double fMin, double fMax)
{
    double f = static_cast<double>(rand()) / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool isEqual(double a, double b){
    return std::abs(a-b) < 100000*std::numeric_limits<double>::epsilon();
}

bool isEqual(const Quaternion &quat1, const quaternion<double> &quat2){
    if (!isEqual(quat2.R_component_1(), quat1.getReal())) return false;
    if (!isEqual(quat2.R_component_2(), quat1.getImagine_1())) return false;
    if (!isEqual(quat2.R_component_3(), quat1.getImagine_2())) return false;
    if (!isEqual(quat2.R_component_4(), quat1.getImagine_3())) return false;
    return true;
}

bool isEqual(Complex& quat1, std::complex<double> quat2){
    if (!isEqual(quat2.real(), quat1.getReal())) return false;
    if (!isEqual(quat2.imag(), quat1.getImagine_1())) return false;
    return true;
}

int main () {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Quaternion compR;
    quaternion<double> boost;

    double a1;
    double a2;
    double a3;
    double a4;

    double b1;
    double b2;
    double b3;
    double b4;

try {
    for (unsigned int i=0; i<1000000; ++i){
        a1 = fRand(-100, 100);
        a2 = fRand(-100, 100);
        a3 = fRand(-100, 100);
        a4 = fRand(-100, 100);

        b1 = fRand(-100, 100);
        b2 = fRand(-100, 100);
        b3 = fRand(-100, 100);
        b4 = fRand(-100, 100);

        Quaternion comp1{a1,a2,a3,a4};
        Quaternion comp2{b1,b2,b3,b4};
        quaternion<double> a(a1,a2,a3,a4);
        quaternion<double> b(b1,b2,b3,b4);

//        Complex comp1{a1,a2};
//        Complex comp2{b1,b2};
//        std::complex<double> a(a1,a2);
//        std::complex<double> b(b1,b2);

        if (i%50000==0)
            cout << i << std::endl;

        compR = comp1+comp2;
        boost = a+b;
        if (!isEqual(compR, boost))
            throw std::runtime_error("+");

        compR = comp1-comp2;
        boost = a-b;
        if (!isEqual(compR, boost))
            throw std::runtime_error("-");

        compR = comp1*comp2;
        boost = a*b;
        if (!isEqual(compR, boost))
            throw std::runtime_error("*");

        compR = comp1/comp2;
        boost = a/b;
        if (!isEqual(compR, boost))
            throw std::runtime_error("/");

    }
} catch (const std::runtime_error& error) {
    cout << "Operation : [" << error.what() << "]";
}
    return 0;
}


