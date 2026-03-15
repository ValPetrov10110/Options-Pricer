#include "../../include/pricing/BlackScholes.hpp"
#include <cmath>

// The constructor for the BlackScholes model implementation
BlackScholes::BlackScholes(){
	S = 0;
	K = 0;
	r = 0;
	sigma = 0;
	T = 0; 
	d1 = calculate_d1();
	d2 = calculate_d2();
}

BlackScholes::BlackScholes(double S, double K, double r, double sigma, double T){
	this->S = S;
	this->K = K;
	this->r = r;
	this->sigma = sigma;
	this->T = T;

	//d1 = calculate_d1();
	//d2 = calculate_d2();
}

double BlackScholes::calculate_d1(){
	return (std::log(S/K)+(r+std::pow(sigma, 2))*T) / (sigma*std::sqrt(T));
}

double BlackScholes::calculate_d2(){
	return d1 - sigma*std::sqrt(T);
}

double BlackScholes::standardNormalCDF(double d){
	return 0.5 * (1.0 + std::erf(d / std::sqrt(2.0)));
}

void BlackScholes::recalculate(){
	d1 = calculate_d1();
	d2 = calculate_d2();
}

void BlackScholes::loadValues(double S, double K, double r, double sigma, double T){
	this->S = S;
	this->K = K;
	this->r = r;
	this->sigma = sigma;
	this->T = T;
}

void BlackScholes::loadCurrentStock(double S){
	this->S = S;
}

void BlackScholes::loadStrikePrice(double K){
	this->K = K;
}

void BlackScholes::loadInterestRate(double r){
	this->r = r;
}

void BlackScholes::loadTime(double T){
	this->T = T;
}

void BlackScholes::loadVolatility(double sigma){
	this->sigma = sigma;
}

double BlackScholes::calculateOption(){
	// Formula: C = SN(d1) - Ke^(-rt)N(d2)
	recalculate();
	return S*standardNormalCDF(d1) - K*std::pow(std::exp(1.0), -r*T)*standardNormalCDF(d2);
}
