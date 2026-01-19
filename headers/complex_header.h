#ifndef COMPLEX_HEADER
#define COMPLEX_HEADER

#define M_PI 3.14159265358979323846

#include <iostream>
#include "dyn_arr.h"

inline double sqrt(const float val){
    int i = *(long *) &val;
    i = 0x5f3759df - (i >> 1);
    float value = *(float *) &i;

    for(size_t i = 0; i < 2; i++)
        value = value * (1.5 - 0.5 * val * value * value);
    return 1/value;
}

inline double abs(const double val){
    if(val >= 0) return val;
    else return -val;
}

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
        return sqrt(obj.real * obj.real + obj.imag * obj.imag);
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

    if(abs(sum) < 1e-5) return 0;
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

    if(abs(sum) < 1e-5) return 0;
    return sum;
}


inline comp::Complex<double> twiddle(double arg)
{
    double c = taylor_cosine(arg);
    double s = taylor_sine(arg);
    return comp::Complex<double>(c, s);
}

comp::dyn_arr<comp::Complex<double>> fft(const comp::dyn_arr<double>& values);

#endif
