#include "picalculator.h"
#include <cmath>

PiCalculator::PiCalculator()
{

}

PiCalculator::~PiCalculator()
{

}


// uses equation pi/4 = atan(1) = 1 - 1/3 + 1/5 - ...
double AtanCalculator::calculate(int steps) {
    double sum = 0.0;
    double sign = 1.0;
    for (int i=0; i<steps;i++) {
        sum +=sign/(2*i+1);
        sign = -sign;
    }
    return sum*4;

}


