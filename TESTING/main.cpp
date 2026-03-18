#include "../src/pricing/BlackScholes.cpp"
#include "../src/pricing/MonteCarlo.cpp"
#include "../src/core/Analysis.cpp"
#include <cstdlib>
#include <iostream>

int main(){

	BlackScholes bs{100, 100, .0437, .2, 1};
	MonteCarlo mc{100, 100, .0437, .2, 1, 1000000};
	double blackRT{};
	double mcRT{};

	try{
		Analysis test{bs, mc};
		test.printResults();
		blackRT = test.getBlackScholesRuntime();
		mcRT = test.getMonteCarloRuntime();
	}catch(std::invalid_argument e){
		std::cout << e.what() << '\n';
		return EXIT_FAILURE;
	}

	std::cout << "\nBlackScholes Runtime: " << blackRT << "ms\n";
	std::cout << "MonteCarlo Runtime: " << mcRT << "ms\n";

	return EXIT_SUCCESS;
}
