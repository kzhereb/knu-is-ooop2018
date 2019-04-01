#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include <vector>

class Function
{
    friend class FunctionBuilder;
protected:
    std::string _name;
    int arity;
    std::vector<Function> operands;
public:
    Function(std::string name):_name(name),arity(0){}
    std::string str() const;
    std::string name() const;
    Function const * operand(int i) const;
    bool is_constant() const;
    bool is_variable() const;

};

#endif // FUNCTION_H
