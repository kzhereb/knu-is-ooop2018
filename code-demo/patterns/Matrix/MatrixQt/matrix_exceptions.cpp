#include "matrix_exceptions.h"


incompatible_matrices::incompatible_matrices(const std::string &what_arg) :
    std::invalid_argument(what_arg)
{

}

incompatible_matrices::incompatible_matrices(const char *what_arg):
    std::invalid_argument(what_arg)
{

}
