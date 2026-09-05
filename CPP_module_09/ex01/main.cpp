#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Arguments missing" << std::endl;
        return 1;
    }
    if (!av[1]) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::string input = av[1];
    if (input.find_first_not_of("0123456789*/-+ ") != std::string::npos) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    if (!rpn.calculation_and_output()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}

