#ifndef FUNCTIONBUILDER_H
#define FUNCTIONBUILDER_H
#include "function.h"

#include <string>


class FunctionBuilder
{
protected:
    Function* result;
public:
    FunctionBuilder();
    void start_build(std::string name);
    void add_operand(const Function& operand);
    Function* get_result();
    Function* create_simple(std::string name);
};

#endif // FUNCTIONBUILDER_H
