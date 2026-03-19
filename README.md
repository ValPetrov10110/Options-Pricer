## OptionsPricer
A lightweight C++ library for pricing European options using two models -- Black-Scholes and Monte Carlo simulation -- with built-in runtime benchmarking and accuracy analysis. Designed to be integrated into any CMake project as a subdirectory or Git submodule.

### Features
- **Black-Scholes** -- CLosed-form analytical pricing for European calls and puts using the standard Black-Scholes formula
- **Monte Carlo** -- Simulation-based pricing via Geometric Brownian Motion across a configurable number of paths
- **Analysis** -- Side-by-side comparison of both models including runtime benchmarking and Monte Carlo accuracy relative to Black-Scholes
- **No external dependencies** -- Uses only the C++17 standard library (`<cmath>`, `<chrono>`, `<random>`)

---

### Project Structure
```
OptionsPricer/
├── include/
│   ├── core/
│   │   └── Analysis.hpp
│   └── pricing/
│       ├── BlackScholes.hpp
│       └── MonteCarlo.hpp
├── src/
│   ├── core/
│   │   └── Analysis.cpp
│   └── pricing/
│       ├── BlackScholes.cpp
│       └── MonteCarlo.cpp
├── LICENSE
├── README.md
└── CMakeLists.txt
```

---

### Integration
OptionsPricer is intended to be used as a subdirectory or Git submodule inside a parent CMake project

1. Add as a submodule
```bash
git submodule add https://github.com/ValPetrov10110/Options-Pricer.git
```

2. Update your CMakeLists.txt
```cmake
add_subdirectory(OptionsPricer)

add_executable(RenameProjectName main.cpp)
target_link_libraries(RenameProjectName PRIVATE OptionsPricer)
```

3. Include the headers you need
```cpp
#include "pricing/BlackScholes.hpp"
#include "pricing/MonteCarlo.hpp"
#include "core/Analysis.hpp"
```

---

### Requirements
- C++17 or later
- CMake 3.15+

---

### Usage
**Black-Scholes**
```cpp
#include "pricing/BlackScholes.hpp"

// Construct with: spot price, strike, risk-free rate, volatility, time to expiry (years)
BlackScholes bs{100.0, 105.0, 0.05, 0.2, 1.0};

double call = bs.calculateCallOption();
double put = bs.calculatePutOption();

// You can also update parameters individually with the same object
bs.loadVolatility(0.25);
bs.loadTime(0.5);
double newCall = bs.calculateCallOption();

// Print all internals (d1, d2, N(d1), N(d2), call, put, etc.)
bs.debug();
```

**Monte Carlo**
```cpp
#include "pricing/MonteCarlo.hpp"

//Construct with: spot price, strike, risk-free rate, volatility, time to expiry (years), number of simulation
MonteCarlo mc{100.0, 105.0, 0.05, 0.2, 1.0, 1000000};

double call = mc.calculateCallOption();
double put = mc.calculatePutOption();
```

**Analysis**
`Analysis` takes a `BlackScholes` and `MonteCarlo` instance with matching parameters and benchmarks both models against each other
```cpp
#include "pricing/BlackScholes.hpp"
#include "pricing/MonteCarlo.hpp"
#include "core/Analysis.hpp"

BlackScholes bs{100.0, 105.0, 0.05, 0.2, 1.0};
MonteCarlo mc{100.0, 105.0, 0.05, 0.2, 1.0, 1000000};

// Throws std::invalid_argument if parameters don't match
Analysis analysis{bs, mc};

analysis.printResults();
```
**Example output:**
```
BlackScholes runtime: 0.0021ms
MonteCarlo runtime: 18.4372ms
Difference: 18.4351ms
Faster model: BlackScholes

###################################
BlackScholes Call Value: $8.0215
BlackScholes Put Value:  $10.6751
MonteCarlo Call Value:   $8.0193
MonteCarlo Put Value:    $10.6704

###################################
MonteCarlo call accuracy: %99.97
MonteCarlo put accuracy:  %99.96
```

---

### Parameters
|Parameter | Description | 
| --- | ---|
| `S` | Current stock (spot) price | 
| `K` | Strike price | 
| `r` | Risk-free interest rate |
| `sigma` | Volatility | 
| `T` | Time to expirt in years (e.g. `1.0` for 1 year) | 
| `numOfSimulation` | Number of Monte Carlo paths |

---

### License
MIT License
