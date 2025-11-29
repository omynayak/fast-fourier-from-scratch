#include "complex_header.h"

int main(void)
{
    comp::dyn_arr<double>input;

    int choice;
    do {
        std::cout << "4 or 8 point fft: ";
        std::cin >> choice;
    } while(!(choice == 4 || choice == 8));

    
    std::cout << "Enter values: ";
    for (int i = 0; i < choice; i++)
    {
        double temp;
        std::cin >> temp;
        input.push_back(temp);
    }
    

    comp::dyn_arr<comp::Complex<double>> output = fft(input);

    std::cout << "The Fast Fourier Transform is: " << std::endl;
    for(int i{}; i < output.size(); i++){
        std::cout << output[i].Re() << ((output[i].Im() >= 0)?(" +"):(" ")) << output[i].Im() << "j\n";
    }
    std::cout << std::endl;


    return 0;
}