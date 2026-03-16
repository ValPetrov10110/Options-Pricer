#include "../src/pricing/BlackScholes.cpp"
#include "../src/pricing/MonteCarlo.cpp"
#include <cstdlib>
#include <iostream>

int main(){
	MonteCarlo test{184.14, 185, 0.0427, .3909, 32/365.0, 1000000};
	std::cout << test.calculateCallOption() << " " << test.calculatePutOption() << '\n'; 

	BlackScholes testing{5.03, 6, .01, .65, 148.0/365};
	std::cout << testing.calculateCallOption();

	return EXIT_SUCCESS;
}
