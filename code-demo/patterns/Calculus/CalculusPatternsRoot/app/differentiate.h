#ifndef DIFFERENTIATE_H
#define DIFFERENTIATE_H

#include "function.h"


class Differentiate
{
public:
    Differentiate();
    Function* get_derivative(Function const * func, std::string var_name);
};

#endif // DIFFERENTIATE_H
