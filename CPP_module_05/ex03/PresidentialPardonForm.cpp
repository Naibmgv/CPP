#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Aform("PresidentialPardonForm", 25, 5), _target(target)
{

}

void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}