#pragma once

#include "../pricing/BlackScholes.hpp"
#include "../pricing/MonteCarlo.hpp"

class Analysis{
private:

public:
	Analysis(BlackScholes bpModel, MonteCarlo mcModel);
};
