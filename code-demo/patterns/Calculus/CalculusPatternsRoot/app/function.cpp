#include "function.h"
#include <cctype>

//Function::Function()
//{

//}

std::string Function::str()
{
    std::string result = this->name;
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

bool Function::is_constant()
{
    if (arity>0) { return false; }
    if (isdigit(name[0])) {return true;}
    return false;
}

bool Function::is_variable()
{
    if (is_constant()) {return false;}
    if (arity>0) { return false; }
    if (name.size() == 1) {return true;}
    return false;
}
