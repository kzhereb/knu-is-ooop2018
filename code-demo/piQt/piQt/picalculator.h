#ifndef PICALCULATOR_H
#define PICALCULATOR_H


class PiCalculator
{
public:
    PiCalculator();
    virtual ~PiCalculator();
    virtual double calculate(int steps) =0;
};


class AtanCalculator: public PiCalculator {
public:
    double calculate(int steps) override;
};


#endif // PICALCULATOR_H
