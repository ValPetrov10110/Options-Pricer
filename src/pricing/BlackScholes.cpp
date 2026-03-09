#include "../../include/pricing/BlackScholes.hpp"

class BlackScholes{
	private:
		double C{};
		double S{};
		double K{};
		double r{};
		double sigma{};
		double T{};

	public:
		BlackScholes(double S, double K, double R, double sigma, double T){
			S = this->S;
			K = this->K;
			R = this->R;
			sigma = this->sigma;
			T = this->T;
		}

};
