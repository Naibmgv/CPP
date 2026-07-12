#include "Bureaucrat.hpp"

int main(void)
{
    // Construction valide
    try
    {
        Bureaucrat naib("naib", 133);
        std::cout << naib << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Grade trop bas (> 150)
    try
    {
        Bureaucrat bad("bad", 200);
        std::cout << bad << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Grade trop haut (< 1)
    try
    {
        Bureaucrat bad2("bad2", 0);
        std::cout << bad2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Increment jusqu'à la limite (grade 1)
    try
    {
        Bureaucrat top("top", 2);
        top.incrementgrade();
        std::cout << top << std::endl;
        top.incrementgrade(); // doit throw
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Decrement jusqu'à la limite (grade 150)
    try
    {
        Bureaucrat bottom("bottom", 149);
        bottom.decrementgrade();
        std::cout << bottom << std::endl;
        bottom.decrementgrade(); // doit throw
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Constructeur de copie et operator=
    try
    {
        Bureaucrat original("original", 50);
        Bureaucrat copy(original);
        std::cout << copy << std::endl;

        Bureaucrat assigned("assigned", 10);
        assigned = original;
        std::cout << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}