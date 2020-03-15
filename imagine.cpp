#include "imagine.h"

namespace Imagine {

double scalar(const Imaginary &i1, const Imaginary &i2){
    double sum(0);
    for (auto it1 = i1.data.begin(), it2 = i2.data.begin(); it1!=i1.data.end(); ++it1, ++it2)
        sum += *it1**it2;

    return sum;
}

Imaginary &vector(const Imaginary &i1, const Imaginary &i2){
    if (i1.data.size()>1){
        const std::vector<double> &first = i1.data, second = i2.data;
        return *new Imaginary{
                first[1]*second[2]-second[1]*first[2],
                first[2]*second[0]-second[2]*first[0],
                first[0]*second[1]-second[0]*first[1],
        };
    }
    return *new Imaginary{0};
}

double square(const Imaginary &i)
{
    return Imagine::scalar(i, i);
}

Imaginary &reverse(const Imaginary &i){
    Imaginary *im = new Imaginary(i);
    for (auto &it:im->data) it = -it;
    return *im;
}

Imaginary &Imaginary::operator/(const double &value) const
{
    Imaginary *im = new Imaginary(*this);
    for (auto &it:im->data) it = it/value;
    return *im;
}

Imaginary &Imaginary::operator*(const double &value) const
{
    Imaginary *im = new Imaginary(*this);
    for (auto &it:im->data) it = it*value;
    return *im;
}

std::vector<double>::iterator Imaginary::erase(const int &pos)
{
    return data.erase(data.begin() + pos);
}

Imaginary &Imaginary::operator+(const Imaginary &i) const
{
    Imaginary *im = new Imaginary(*this);
    im->data.resize(i.data.size());
    std::transform(data.begin(), data.end(), i.data.begin(), im->data.begin(), std::plus<double>());
    return *im;
}

Imaginary &Imaginary::operator-(const Imaginary &i) const
{
    Imaginary *im = new Imaginary(*this);
    im->data.resize(i.data.size());
    std::transform(data.begin(), data.end(), i.data.begin(), im->data.begin(), std::minus<double>());
    return *im;
}

}
