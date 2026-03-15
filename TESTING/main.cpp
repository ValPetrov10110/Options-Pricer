#include "../src/pricing/BlackScholes.cpp"
#include <cstdlib>
#include <iostream>

int main(){
	BlackScholes calculation{}; // Utilizing the default constructor
	BlackScholes myCalc{70, 100, 0.05, 0.2, 1}; // Initialized with values
	double call{};
	double put{};

	calculation.loadValues(100, 100, 0.05, 0.20, 1);
	call = calculation.calculateCallOption();
	put = calculation.calculatePutOption();

	std::cout << call << " " << put << '\n';

	// Test 2
	calculation.loadValues(110, 90, 0.05, 0.20, 1.0);
	calculation.debug();

	return EXIT_SUCCESS;
}
