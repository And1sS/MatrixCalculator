#include "Equation.h"

Equation::Equation(std::string file_name) : equation_matrix(Matrix<double>::read_from_file(file_name)), copy(equation_matrix)
{
    arguments_num = equation_matrix.get_width() - 1;
}

Equation::Equation(Matrix<double> eq_matrix) : equation_matrix(eq_matrix), copy(eq_matrix)
{
    arguments_num = equation_matrix.get_width() - 1;
}

std::vector<double> Equation::solve()
{
    std::vector<double> result(arguments_num);

    if (int temp = copy.determinant() == 0 || arguments_num > equation_matrix.get_height())
    {
        std::cout << "there is no unique solution :(" << std::endl;

        return std::vector<double>();
    }

    copy.gauss();
    copy.reverse_gauss();

    for (int i = 0; i < arguments_num; i++)
    {
        result[i] = copy.get_data()[i][arguments_num];
    }

    return result;
}

void Equation::print_system()
{
    for (int i = 0; i < equation_matrix.get_height(); i++)
    {
        for (int j = 0; j < equation_matrix.get_width(); j++)
        {
            if (j < equation_matrix.get_width() - 1)
            {
                std::cout << "( " << equation_matrix.get_data()[i][j] << " ) * X" << j;
                if(j != equation_matrix.get_width() - 2)
                    std::cout << "\t+\t";
            }
            else
            {
                std::cout << " = " << equation_matrix.get_data()[i][j] << ";";
            }
        }
        std::cout << std::endl;
    }
}

Matrix<double>* Equation::get_matrix()
{
    return &equation_matrix;
}

