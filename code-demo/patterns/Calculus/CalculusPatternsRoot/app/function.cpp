#include "function.h"
#include <cctype>

//Function::Function()
//{

//}

std::string Function::str() const
{
    std::string result = this->_name;
    if (arity>0){
        result += "(";
        for (int i=0;i<arity;i++) {
            if (i>0) {result+=", ";}
            result += operands[i].str();
        }
        result +=")";
    }
    return result;
}

std::string Function::name() const
{
    return _name;
}

const Function *Function::operand(int i) const
{
    return &(operands[i]);
}

bool Function::is_constant() const
{
    if (arity>0) { return false; }
    if (isdigit(_name[0])) {return true;}
    return false;
}

bool Function::is_variable() const
{
    if (is_constant()) {return false;}
    if (arity>0) { return false; }
    if (_name.size() == 1) {return true;}
    return false;
}
