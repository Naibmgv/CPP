#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Aform("RobotomyRequestForm", 72, 45), _target(target)
{
    
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "*drilling noises*" << std::endl;

    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomy failed" << std::endl;
}