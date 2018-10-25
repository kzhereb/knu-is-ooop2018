#ifndef PICALCULATORRESULT_H
#define PICALCULATORRESULT_H

#include <QDateTime>

struct PiCalculatorResult {
    QDateTime timestamp;
    QString name;
    int steps;
    double result;
};

#endif // PICALCULATORRESULT_H
