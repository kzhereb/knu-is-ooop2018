#include "differentiate.h"
#include "functionbuilder.h"



Differentiate::Differentiate()
{

}

Function *Differentiate::get_derivative(const Function *func, std::string var_name)
{
    FunctionBuilder builder;
    if (func->is_constant()) {
        return builder.create_simple("0");
    }
    if (func->is_variable()) {
        if (func->name() == var_name) {
           return builder.create_simple("1");
        } else {
           return builder.create_simple("0");
        }
    }
    if (func->name() == "plus") {
        const Function* op1 = get_derivative(func->operand(0),var_name);
        const Function* op2 = get_derivative(func->operand(1),var_name);
        builder.start_build("plus");
        builder.add_operand(*op1);
        builder.add_operand(*op2);
        return builder.get_result();
    }
}
