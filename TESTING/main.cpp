#include "../src/pricing/BlackScholes.cpp"
#include "../src/pricing/MonteCarlo.cpp"
#include <cstdlib>
#include <iostream>

int main(){
	MonteCarlo test{181.98, 190, 0.0427, .3389, 32/365.0, 1000000};
	std::cout << test.calculateCallOption() << " " << test.calculatePutOption() << '\n'; 

	BlackScholes testing{181.98, 190, 0.0427, .3389, 33/365.0};
	std::cout << testing.calculateCallOption();

	return EXIT_SUCCESS;
}
