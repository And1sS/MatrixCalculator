#ifndef EQUATION_H
#define EQUATION_H

#include "Matrix.h"
#include <vector>

class Equation
{
private:
    int arguments_num;

    Matrix<double> equation_matrix;
    Matrix<double> copy;

public:
    Equation(std::string file_name);
    Equation(Matrix<double> eq_matrix);

    std::vector<double> solve();
    void print_system();

    Matrix<double>* get_matrix();
};


#endif // EQUATION_H
