#include "../../include/pricing/MonteCarlo.hpp"
#include <random>
#include <cmath>

MonteCarlo::MonteCarlo(double S, double K, double r, double sigma, double T, int numOfSimulation) : rng(std::random_device{}()), dist(0.0, 1.0){
	this->S = S;
	this->K = K;
	this->r = r;
	this->sigma = sigma;
	this->T = T;
	this->numOfSimulation = numOfSimulation;	
}

double MonteCarlo::calculateZ(){
	return dist(rng);
}

double MonteCarlo::getStock(){
	return S;
}

double MonteCarlo::getStrikePrice(){
	return K;
}

double MonteCarlo::getInterestRate(){
	return r;
}

double MonteCarlo::getVolatility(){
	return sigma;
}

double MonteCarlo::getTime(){
	return T;
}

double MonteCarlo::calculateCallOption(){
	double total{};
	double simulatedPrice{};
	for(int i = 0; i < numOfSimulation; i++){
		Z = calculateZ();
		simulatedPrice = brownianFormula();
		double payOff = std::max(simulatedPrice - K, 0.0);
		total += payOff;
	}

	double average = total / numOfSimulation;
	return std::exp(-r * T) * average;
}

double MonteCarlo::calculatePutOption(){
	double total{};
	double simulatedPrice{};
	for(int i = 0; i < numOfSimulation; i++){
		Z = calculateZ();
		simulatedPrice = brownianFormula();
		double payOff = std::max(K - simulatedPrice, 0.0);
		total += payOff;
	}

	double average = total / numOfSimulation;
	return std::exp(-r * T) * average;

}

double MonteCarlo::brownianFormula(){
	return S * std::exp((r - (.5 * std::pow(sigma, 2))) * T + sigma * std::sqrt(T) * Z);
}

