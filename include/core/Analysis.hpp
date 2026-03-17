#pragma once

#include "../pricing/BlackScholes.hpp"
#include "../pricing/MonteCarlo.hpp"

class Analysis{
private:
	BlackScholes bs;
	MonteCarlo mc;

	void validate();
public:
	Analysis(BlackScholes bsModel, MonteCarlo mcModel);
};
