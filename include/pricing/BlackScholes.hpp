#pragma once

class BlackScholes{
	private:
		double S;
		double K;
		double r;
		double sigma;
		double T;
		double d1;
		double d2;

		double calculate_d1();
		double calculate_d2();
		double standardNormalCDF(double d);
		void recalculate();

	public:
		BlackScholes();
		BlackScholes(double S, double K, double r, double sigma, double T);
		void loadValues(double S, double K, double r, double sigma, double T);
		void loadCurrentStock(double S);
		void loadStrikePrice(double K);
		void loadInterestRate(double r);
		void loadTime(double T);
		void loadVolatility(double sigma);
		double calculateCallOption();
		double calculatePutOption();
		void debug();
};
