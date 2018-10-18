#include "picalculator.h"
#include <random>
#include <cmath>
#include <ctime>

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


// uses Monte-Carlo method to calculate pi/4 = Integral(0,1,sqrt(1-x^2))
double MonteCarloCalculator::calculate(int steps) {
    int hits=0; // number of points within given area
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::seed_seq seed { rd(), static_cast<unsigned int>(time(nullptr))}; // in case random_device is not implemented, fallback to time(0)
    std::mt19937 gen(seed); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i=0;i < steps; i++) {
        double x = dis(gen);
        double y = dis(gen);
        if (x*x+y*y<1.0) {hits++;}
    }

    return 4*double(hits)/steps;

}


TwoAtanCalculator::TwoAtanCalculator(int a1,int b1,int c1, int a2,int b2,int c2):
    PiCalculator(), a1(a1), b1(b1), c1(c1),a2(a2), b2(b2), c2(c2) {
}
// uses Taylor series for atan: atan(x) = x - x^3/3 + x^5/5 - ...
double TwoAtanCalculator::atan(double x, int steps) {
    double sum = 0.0;
    double pow_x = x;
    for (int i=0; i<steps;i++) {
            sum +=pow_x/(2*i+1);
            pow_x = -pow_x*x*x;
        }
    return sum;
}
// uses https://en.wikipedia.org/wiki/Machin-like_formula
double TwoAtanCalculator::calculate(int steps) {
    double pi4 = c1*atan(double(a1)/b1, steps) + c2*atan(double(a2)/b2, steps);
    return 4*pi4;
}
