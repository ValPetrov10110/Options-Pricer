#include "../../include/core/Analysis.hpp"

#include <chrono>
#include <cmath>

Analysis::Analysis(BlackScholes bsModel, MonteCarlo mcModel) : bs(bsModel), mc(mcModel){
	validate();
	testRuntime();
	calculateError();
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

	bsCallResult = bs.calculateCallOption();
	bsPutResult = bs.calculatePutOption();

	auto endTime = std::chrono::steady_clock::now();
	auto diff = endTime - startTime;

	bsRuntime =  std::chrono::duration<double, std::milli>(diff).count();
}

void Analysis::testMonteCarloRuntime(){
	auto startTime = std::chrono::steady_clock::now();
	
	mcCallResult = mc.calculateCallOption();
	mcPutResult = mc.calculatePutOption();

	auto endTime = std::chrono::steady_clock::now();
	auto diff = endTime - startTime;
	
	
	mcRuntime = std::chrono::duration<double, std::milli>(diff).count();
}

void Analysis::printResults(){
	std::cout << "BlackScholes runtime: " << bsRuntime << "ms\n";
	std::cout << "MonteCarlo runtime: " << mcRuntime << "ms\n";
	std::cout << "Difference: " << std::abs(bsRuntime - mcRuntime) << "ms\n";
	std::cout << "Faster model: " << (bsRuntime < mcRuntime ? "BlackScholes" : "MonteCarlo") << "\n";
	std::cout << "\n###################################\n";
	std::cout << "BlackScholes Call Value: $" << bsCallResult << "\n";
	std::cout << "BlackScholes Put Value: $" << bsPutResult << "\n";
	std::cout << "MonteCarlo Call Value: $" << mcCallResult << "\n";
	std::cout << "MonteCarlo Put Value: $" << mcPutResult << "\n";
	std::cout << "\n###################################\n";
	std::cout << "MonteCarlo call accuracy: %" << (1 - (callError / bsCallResult)) * 100 << "\n";
	std::cout << "MonteCarlo put accuracy: %" << (1 - (putError / bsPutResult)) * 100 << "\n";
}

double Analysis::getBlackScholesRuntime(){
	return bsRuntime;
}

double Analysis::getMonteCarloRuntime(){
	return mcRuntime;
}

void Analysis::calculateError(){
	callError = std::abs(bsCallResult - mcCallResult);
	putError = std::abs(bsPutResult - mcPutResult);
}
