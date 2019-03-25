#include "function.h"

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
