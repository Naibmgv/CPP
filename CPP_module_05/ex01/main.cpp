#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Cas nominal : boss (grade suffisant) signe avec succès
    try
    {
        Bureaucrat boss("Boss", 5);
        Form form("Contract", 10, 5);

        std::cout << boss << std::endl;
        std::cout << form << std::endl;

        boss.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Cas d'échec : intern (grade trop bas) ne peut pas signer
    try
    {
        Bureaucrat intern("Intern", 100);
        Form form("Contract", 10, 5);

        intern.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Form avec grade invalide (trop bas -> GradeTooHighException)
    try
    {
        Form badForm("Bad", 0, 5);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Form avec grade invalide (trop haut -> GradeTooLowException)
    try
    {
        Form badForm2("Bad2", 151, 5);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Limites d'incrément/décrément du Bureaucrat
    try
    {
        Bureaucrat top("Top", 1);
        top.incrementgrade(); // doit throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementgrade(); // doit throw
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}