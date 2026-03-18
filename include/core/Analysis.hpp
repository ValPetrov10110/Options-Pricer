#pragma once

#include "../pricing/BlackScholes.hpp"
#include "../pricing/MonteCarlo.hpp"

class Analysis{
private:
	BlackScholes bs;
	MonteCarlo mc;
	double bsRuntime;
	double mcRuntime;
	double bsCallResult;
	double bsPutResult;
	double mcCallResult;
	double mcPutResult;
	double callError;
	double putError;

	void validate();
	void testRuntime();
	void testAccuracy();
	void testBlackScholesRuntime();
	void testMonteCarloRuntime();
	void calculateError();

public:
	Analysis(BlackScholes bsModel, MonteCarlo mcModel);
	void printResults();
	double getBlackScholesRuntime();
	double getMonteCarloRuntime();

};
