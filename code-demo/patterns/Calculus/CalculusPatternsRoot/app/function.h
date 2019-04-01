#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include <vector>

class Function
{
    friend class FunctionBuilder;
protected:
    std::string name;
    int arity;
    std::vector<Function> operands;
public:
    Function(std::string name):name(name),arity(0){}
    std::string str();
};

#endif // FUNCTION_H
