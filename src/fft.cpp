#include "../headers/complex_header.h"

comp::dyn_arr<comp::Complex<double>> fft(const comp::dyn_arr<double>& values)
{
    int N = values.size();


    if (N == 1) {
        comp::dyn_arr<comp::Complex<double>> result(1);
        result[0] = comp::Complex<double>(values[0], 0.0);
        return result;
    }

    comp::dyn_arr<double> even_vals(N / 2);
    comp::dyn_arr<double> odd_vals(N / 2);

    for (int i = 0; i < N / 2; i++) {
        even_vals[i] = values[2 * i];
        odd_vals[i]  = values[2 * i + 1];
    }

    auto E = fft(even_vals);
    auto O = fft(odd_vals);

    comp::dyn_arr<comp::Complex<double>> X(N);

    for (int k = 0; k < N / 2; k++) {
        double angle = -2.0 * M_PI * k / N;
        comp::Complex<double> W = twiddle(angle);

        X[k]      = E[k] + W * O[k];
        X[k + N / 2] = E[k] - W * O[k];
    }

    return X;
}
