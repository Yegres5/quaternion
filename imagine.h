#ifndef IMAGINE_H
#define IMAGINE_H

#include <initializer_list>
#include <vector>

namespace Imagine {

class Imaginary{
public:
    Imaginary(){}
    Imaginary(std::vector<double> vec):data(vec){}
    Imaginary(std::initializer_list<double> l):data(l){}

    friend double square(const Imaginary &i);
    friend Imaginary &reverse(const Imaginary &i);
    friend double scalar(const Imaginary &i1, const Imaginary &i2);
    friend Imaginary &vector(const Imaginary &i1, const Imaginary &i2);

    Imaginary &operator+(const Imaginary &i) const;
    Imaginary &operator-(const Imaginary &i) const;
    Imaginary &operator/(const double &value) const;
    Imaginary &operator*(const double &value) const;

    std::vector<double>::iterator erase (const int& pos);

//private:
    std::vector<double> data;
};

double square(const Imaginary &i);
Imaginary &reverse(const Imaginary &i);
double scalar(const Imaginary &i1, const Imaginary &i2);
Imaginary &vector(const Imaginary &i1, const Imaginary &i2);

}

#endif // IMAGINE_H
