#ifndef COMPLEX_HEADER
#define COMPLEX_HEADER

#include <iostream>
#include <cmath>
#include <vector>

namespace comp {

template <typename T>
class Complex {
private:
    T real;
    T imag;

public:
    Complex(T re = 0, T im = 0) : real(re), imag(im) {}

    T Re() const { return real; }
    T Im() const { return imag; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    friend auto abs(const Complex& obj) {
        return std::sqrt(obj.real * obj.real + obj.imag * obj.imag);
    }
};

} // namespace comp


inline double taylor_sine(double x)
{
    double term = x; 
    double sum  = x;

    for (int n = 1; n <= 15; ++n) {
        term *= -(x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        sum  += term;
    }

    if(std::abs(sum) < 1e-9) return 0;
    return sum;
}

inline double taylor_cosine(double x)
{
    double term = 1.0;
    double sum  = 1.0;

    for (int n = 1; n <= 15; ++n) {
        term *= -(x * x) / ((2.0 * n - 1.0) * (2.0 * n));
        sum  += term;
    }

    if(std::abs(sum) < 1e-5) return 0;
    return sum;
}


inline comp::Complex<double> twiddle(double arg)
{
    double c = taylor_cosine(arg);
    double s = taylor_sine(arg);
    return comp::Complex<double>(c, s);
}


#endif
