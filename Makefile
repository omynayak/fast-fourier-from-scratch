CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17

main: main.cpp fft.cpp complex_header.h
	$(CXX) $(CXXFLAGS) main.cpp fft.cpp -o main
