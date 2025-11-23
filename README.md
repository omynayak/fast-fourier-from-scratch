# Cooley Tukey FFT 
A complete, ground-up implementation of the **Cooley-Tukey Fast Fourier Transform (FFT)** algorithm in C++. <br>
This project focuses on *building everything manually*, from a lightweight Complex number class to twiddle factor generation using numeric series expansions.

## Features:
- Custom Complex class (removing <complex> dependancy)
- **Maclaurin/Taylor series** implementation for:
    - sin(x)
    - cos(x)
    - sqrt(x) (effective around x = 1)
- Manual logic implementation for:
    - abs(x)
        Overloaded function for complex magnitude and absolute value of real numbers.
- Radix-2 Recursive Cooley-Tukey FFT.
- Cleanly separated code (FFT logic in `fft.cpp`, types and helpers in header).
- Minimal dependencies (<vector> only), fast to compile.

## Project Structure:
```
.
├── main.cpp
├── fft.cpp
├── complex_header.h
├── Makefile
└── README.md
```

## Build Instructions:
### Option 1: Compile Manually
You may compile the program manually using the following bash commands:

```bash
g++ main.cpp fft.cpp -o main
./main
```
### Option 2: Use the Makefile

```bash
make
./main
```

## How it works:
1. **Complex number operations**
Addition, subtraction, multiplication, magnitude etc are defined in the header class via operator overloading.

2. **Trigonometric functions using Taylor expansion**
Avoids using <cmath> for the twiddle factor. Makes use of Euler's formula: <br>
$e^{-j \frac{2\pi k}{N}} = \cos\theta - j\sin\theta$


3. **Recursive Radix-2 Cooley-Tukey Algorithm**
Splits signal into even and odd indices and recursively combines sub-FFTs using twiddle factors.

![FFT Diagram](https://www.researchgate.net/publication/321794641/figure/fig1/AS:614082222759950@1523420019485/llustration-of-Cooley-Tukey-algorithm-of-FFT.png)

## Contributing
Contributions, feedback, and suggestions are welcome! <br>
If you’d like to improve performance, precision, or add benchmarks, feel free to open an issue or PR.
