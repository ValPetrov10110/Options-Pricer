#include "../../include/core/Analysis.hpp"

#include <chrono>
#include <cmath>

Analysis::Analysis(BlackScholes bsModel, MonteCarlo mcModel) : bs(bsModel), mc(mcModel){
	validate();
	testRuntime();
}

void Analysis::validate(){
	if(bs.getStock() != mc.getStock() || bs.getStrikePrice() != mc.getStrikePrice() || bs.getInterestRate() != mc.getInterestRate() || bs.getVolatility() != mc.getVolatility() || bs.getTime() != mc.getTime()){
		throw std::invalid_argument("ERROR: Different BlackScholes and MonteCarlo variables");
	}
}

void Analysis::testRuntime(){
	testBlackScholesRuntime();
	testMonteCarloRuntime();
}

void Analysis::testBlackScholesRuntime(){
	auto startTime = std::chrono::steady_clock::now();

	bs.calculateCallOption();
	bs.calculatePutOption();

	auto endTime = std::chrono::steady_clock::now();
	auto diff = endTime - startTime;

	bsRuntime =  std::chrono::duration<double, std::milli>(diff).count();
}

void Analysis::testMonteCarloRuntime(){
	auto startTime = std::chrono::steady_clock::now();
	
	mc.calculateCallOption();
	mc.calculatePutOption();

	auto endTime = std::chrono::steady_clock::now();
	auto diff = endTime - startTime;
	
	mcRuntime = std::chrono::duration<double, std::milli>(diff).count();
}

void Analysis::printResults(){
	std::cout << "BlackScholes runtime: " << bsRuntime << "ms\n";
	std::cout << "MonteCarlo runtime: " << mcRuntime << "ms\n";
	std::cout << "Difference: " << std::abs(bsRuntime - mcRuntime) << "ms\n";
	std::cout << "Faster model: " << (bsRuntime < mcRuntime ? "BlackScholes" : "MonteCarlo") << "\n";
}

double Analysis::getBlackScholesRuntime(){
	return bsRuntime;
}

double Analysis::getMonteCarloRuntime(){
	return mcRuntime;
}
