#include "../src/pricing/BlackScholes.cpp"
#include <cstdlib>
#include <iostream>

int main(){
	BlackScholes calculation{}; // Utilizing the default constructor
	BlackScholes myCalc{70, 100, 0.05, 0.2, 1}; // Initialized with values

	std::cout << calculation.calculateOption() << '\n';
	std::cout << myCalc.calculateOption() << '\n';
	return EXIT_SUCCESS;
}
