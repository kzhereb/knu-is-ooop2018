#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

#include <stdexcept>

class incompatible_matrices: public std::invalid_argument {
public:
    explicit incompatible_matrices( const std::string& what_arg );
    explicit incompatible_matrices( const char* what_arg );
};
#endif // MATRIX_EXCEPTIONS_H
