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


// uses equation pi/4 = Integral(0,1,sqrt(1-x^2))
double IntegrateCalculator::calculate(int steps) {
    double sum = 0.0;
    double interval = 1.0/steps;
    double prev_y = 1;
    for (int i=0; i<steps;i++) {
        double next_x = (i+1)*interval;
        double next_y = sqrt(1-next_x*next_x);
        sum += (next_y+prev_y)/2;
        prev_y = next_y;
    }

    return sum*interval*4;

}
