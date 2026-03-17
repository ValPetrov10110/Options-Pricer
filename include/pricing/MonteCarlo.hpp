#pragma once

#include <iostream>
#include <random>

class MonteCarlo{
	private:
		double S;
		double K;
		double r; 
		double sigma;
		double T;
		int numOfSimulation;
		double Z; // This is the random value from the generator and curve
		std::mt19937 rng;
		std::normal_distribution<double> dist;
		
	public:
		MonteCarlo(double S, double K, double r, double sigma, double T, int numOfSimulation);
		double calculateZ();
		double calculateCallOption();
		double calculatePutOption();
		double brownianFormula();
		double getStock();
		double getStrikePrice();
		double getInterestRate();
		double getVolatility();
		double getTime();
};
