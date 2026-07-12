#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
            Aform("ShrubberyCreationForm", 145, 137), _target(target)
{

}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream new_file((_target + "_shrubbery").c_str());

    if (!new_file.is_open()) throw std::runtime_error("file creation failed");

    new_file << "    *\n   ***\n  *****\n *******\n    |\n\n";
    new_file << "    *\n   ***\n  *****\n *******\n    |\n\n";
    new_file << "    *\n   ***\n  *****\n *******\n    |\n\n";
    new_file << "    *\n   ***\n  *****\n *******\n    |\n";

    new_file.close();
}