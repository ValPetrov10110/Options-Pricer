cmake_minimum_required(VERSION 3.15)
project(OptionsPricer)

add_library(OptionsPricer STATIC
	src/pricing/BlackScholes.cpp
	src/pricing/MonteCarlo.cpp
	src/core/Analysis.cpp)

target_include_directories(OptionsPricer PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(OptionsPricer PUBLIC cxx_std_17)
