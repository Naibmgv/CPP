#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Bureaucrat boss("Boss", 1);          // grade fort
    Bureaucrat stagiaire("Stagiaire", 150); // grade faible

    std::cout << "=== Test Shrubbery ===" << std::endl;
    {
        ShrubberyCreationForm Aform("home");

        stagiaire.signForm(Aform);        // devrait échouer (145 requis)
        boss.signForm(Aform);             // devrait réussir

        stagiaire.executeForm(Aform);     // devrait échouer (grade exec 137 requis)
        boss.executeForm(Aform);          // devrait réussir -> crée home_shrubbery
    }

    std::cout << "\n=== Test Robotomy ===" << std::endl;
    {
        RobotomyRequestForm Aform("Bender");

        boss.signForm(Aform);
        boss.executeForm(Aform);          // 50/50 succès/échec
        boss.executeForm(Aform);          // on relance pour voir l'autre cas
    }

    std::cout << "\n=== Test PresidentialPardon ===" << std::endl;
    {
        PresidentialPardonForm Aform("Naib");

        boss.signForm(Aform);
        boss.executeForm(Aform);
    }

    std::cout << "\n=== Test execute sans signer ===" << std::endl;
    {
        ShrubberyCreationForm Aform("garden");
        boss.executeForm(Aform);          // devrait échouer : pas signé
    }

    return 0;
}