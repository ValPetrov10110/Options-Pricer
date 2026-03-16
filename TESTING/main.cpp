#include "../src/pricing/BlackScholes.cpp"
#include "../src/pricing/MonteCarlo.cpp"
#include <cstdlib>
#include <iostream>

int main(){
	MonteCarlo test{184.14, 185, 0.0427, .3909, 32/365.0, 1000000};
	std::cout << test.calculateCallOption() << " " << test.calculatePutOption() << '\n'; 


	return EXIT_SUCCESS;
}
