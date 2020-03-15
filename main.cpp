#include "quaternion.h"
#include <boost/math/quaternion.hpp>
#include <random>
#include <time.h>
#include <QDebug>

using boost::math::quaternion;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool isEqual(double a, double b){
    return std::abs(a-b) < std::numeric_limits<double>::epsilon();
}

bool isEqual(Quaternion& quat1, quaternion<double> quat2){
    if (!isEqual(quat2.R_component_1(), quat1.real)) return false;
    if (!isEqual(quat2.R_component_2(), quat1.imagine.data.at(0))) return false;
    if (!isEqual(quat2.R_component_3(), quat1.imagine.data.at(1))) return false;
    if (!isEqual(quat2.R_component_4(), quat1.imagine.data.at(2))) return false;
    return true;
}

int main () {

    std::srand(std::time(nullptr));
    Quaternion compR;
    quaternion<double> boost;

    double a1, a2, a3, a4,
            b1, b2, b3, b4;
try {
    for (unsigned int i=0; i<10000000; ++i){
        a1 = fRand(-100, 100);
        a2 = fRand(-100, 100);
        a3 = fRand(-100, 100);
        a4 = fRand(-100, 100);

        b1 = fRand(-100, 100);
        b2 = fRand(-100, 100);
        b3 = fRand(-100, 100);
        b4 = fRand(-100, 100);

//       a1 = -45.2502;a2=   80.554;a3=     71.5006;a4=   -89.0711;
//       b1=-17.2016;b2=   93.4382;b3=     16.4175;b4=   -71.6118;
        Quaternion comp1{a1,a2,a3,a4};
        Quaternion comp2{b1,b2,b3,b4};
        quaternion<double> a(a1,a2,a3,a4);
        quaternion<double> b(b1,b2,b3,b4);


        //if (i%50000==0)
            qDebug() << i;

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
        qDebug() << "Operation : [" << error.what() << "]";
        qDebug() << " First vector =  [" << a1 << " " << a2 << " " << " " << a3 << " " << a4 << "]\n" <<
                    "Second vector = [" << b1 << " " << b2 << " " << " " << b3 << " " << b4 << "]";
        qDebug() << " My multiplication =    [" << compR.real << " " << compR.imagine.data.at(0) << " " << compR.imagine.data.at(1)<< " " << compR.imagine.data.at(2) << "]\n" <<
                    "Boost multiplication = [" << boost.R_component_1() << " " << boost.R_component_2() << " " << boost.R_component_2() << " " << boost.R_component_3() << "]";
    }

    return 0;
}


