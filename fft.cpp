#include "complex_header.h"

std::vector<comp::Complex<double>> fft(const std::vector<double>& values)
{
    int N = values.size();


    if (N == 1) {
        return { comp::Complex<double>(values[0], 0.0) };
    }

    std::vector<double> even_vals(N/2);
    std::vector<double> odd_vals(N/2);

    for (int i = 0; i < N/2; i++) {
        even_vals[i] = values[2*i];
        odd_vals[i]  = values[2*i + 1];
    }


    auto E = fft(even_vals);  
    auto O = fft(odd_vals);   


    std::vector<comp::Complex<double>> X(N);


    for (int k = 0; k < N/2; k++) {


        double angle = -2.0 * M_PI * k / N;


        comp::Complex<double> W = twiddle(angle);

        X[k]      = E[k] + W * O[k];
        X[k+N/2]  = E[k] - W * O[k];
    }

    return X;
}