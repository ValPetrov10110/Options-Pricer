#pragma once

#include "../pricing/BlackScholes.hpp"
#include "../pricing/MonteCarlo.hpp"

class Analysis{
private:
	BlackScholes bs;
	MonteCarlo mc;
	double bsRuntime;
	double mcRuntime;

	void validate();
	void testRuntime();
	void testBlackScholesRuntime();
	void testMonteCarloRuntime();
public:
	Analysis(BlackScholes bsModel, MonteCarlo mcModel);
	void printResults();
	double getBlackScholesRuntime();
	double getMonteCarloRuntime();
};
