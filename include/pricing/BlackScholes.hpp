#pragma once

class BlackScholes{
	private:
		double C;
		double S;
		double K;
		double r;
		double sigma;
		double T;

	public:
		BlackScholes(double S, double K, double r, double sigma, double T);
};
