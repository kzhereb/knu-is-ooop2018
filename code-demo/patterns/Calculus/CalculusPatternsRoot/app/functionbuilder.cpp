#include "functionbuilder.h"

FunctionBuilder::FunctionBuilder()
{

}

void FunctionBuilder::start_build(std::string name)
{
    result = new Function(name);
}

void FunctionBuilder::add_operand(const Function &operand)
{
    result->operands.push_back(operand);
    result->arity++;
}

Function *FunctionBuilder::get_result()
{
    return result;
}

Function *FunctionBuilder::create_simple(std::string name)
{
    start_build(name);
    return get_result();
}
