#include "complex_header.h"

int main(void)
{
    std::vector<double>input;

    int choice;
    do {
        std::cout << "4 or 8 point fft: ";
        std::cin >> choice;
    } while(!(choice == 4 || choice == 8));

    
    std::cout << "Enter values: ";
    for (size_t i = 0; i < choice; i++)
    {
        double temp;
        std::cin >> temp;
        input.push_back(temp);
    }
    

    std::vector<comp::Complex<double>> output = fft(input);

    std::cout << "The Fast Fourier Transform is: " << std::endl;
    for(auto value : output){
        std::cout << value.Re() << " + " << value.Im() << "j\n";
    }
    std::cout << std::endl;


    return 0;
}