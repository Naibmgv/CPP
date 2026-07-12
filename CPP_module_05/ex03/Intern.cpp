#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

static Aform* Shrub(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static Aform* Robo(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static Aform* President(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

Aform* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string forms[3] = { 
        "shrubbery creation", 
        "robotomy request",
        "presidential pardon" };
    Aform* (*functions[3])(const std::string&);
    functions[0] = Shrub;
    functions[1] = Robo;
    functions[2] = President;
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return functions[i](target);
        }
    }
    std::cout << "ERROR : unknown form" << std::endl;
    return NULL;
}
