#pragma once

class BlackScholes{
	private:
		double C;
		double S;
		double K;
		double r;
		double sigma;
		double T;
		double d1;
		double d2;

		double calculate_d1();
		double calculate_d2();
		double calculateOption();
		double standardNormalCDF(double d);
		void recalculate();

	public:
		BlackScholes(double S, double K, double r, double sigma, double T);
};
