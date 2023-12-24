# Simple ATM Controller
This is repository for test with Coderbyte


## Overview

The ATM Simulation project is designed to emulate the fundamental operations of an Automated Teller Machine (ATM).

## Getting Started

### Prerequisites

C++ compiler (supporting C++11 or later)
Standard Template Library (STL)

### Installation

Clone the repository and build.

```bash
git clone https://github.com/cjh1995-ros/simple_atm_controller.git

mkdir build
cd build
cmake ..
make
```

Run the compiled program

```bash
./build/example
```

For `example.cpp` case, you should input specified test case for example because we don't have real card.

```mathematica
Card Number: 123456789
Pin: 1234
Amount: 1000
Owner: CJH
If you don't insert the above information, the test will fail.

This is BearBank ATM Machine
Please insert your card
Card number(This is bcz we don't have real card):
```

### Testing

The project includes tests for the core functionalities of the ATM system. Run these tests to ensure the operations of the ATM are functioning as expected.

#### Running Tests

Compile the test files with the source code and execute the test binary to validate the ATM functionalities.

If you check `test` folder, you can easily understand the contents.