#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

void testBureaucratGrades()
{
    std::cout << "\n=== Test 1: Bureaucrat - grades invalides ===\n";
    try { Bureaucrat b("Nobody", 0); }
    catch (std::exception& e) { std::cout << "OK - " << e.what() << std::endl; }

    try { Bureaucrat b("Nobody", 151); }
    catch (std::exception& e) { std::cout << "OK - " << e.what() << std::endl; }
}

void testBureaucratLimits()
{
    std::cout << "\n=== Test 2: Bureaucrat - limites increment/decrement ===\n";
    try
    {
        Bureaucrat top("Top", 1);
        top.incrementgrade();
    }
    catch (std::exception& e) { std::cout << "OK - " << e.what() << std::endl; }

    try
    {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementgrade();
    }
    catch (std::exception& e) { std::cout << "OK - " << e.what() << std::endl; }
}

void testFormGrades()
{
    std::cout << "\n=== Test 3: Aform - grades invalides au constructeur ===\n";
    try { ShrubberyCreationForm bad("home"); (void)bad; }
    catch (std::exception& e) { std::cout << "erreur inattendue: " << e.what() << std::endl; }
    std::cout << "(ShrubberyCreationForm grade 145/137 -> valide, pas d'exception attendue)\n";
}

void testSignAndExecute()
{
    std::cout << "\n=== Test 4: Sign + Execute - cas de succes ===\n";
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm shrub("home");

    std::cout << shrub;
    boss.signForm(shrub);
    boss.executeForm(shrub);
}

void testSignTooLowGrade()
{
    std::cout << "\n=== Test 5: Sign - grade insuffisant ===\n";
    Bureaucrat intern("Intern", 150);
    PresidentialPardonForm ppf("Naib");

    intern.signForm(ppf); // doit echouer, grade requis 25
}

void testExecuteWithoutSigning()
{
    std::cout << "\n=== Test 6: Execute sans signature ===\n";
    Bureaucrat boss("Boss", 1);
    RobotomyRequestForm rrf("Bender");

    boss.executeForm(rrf); // doit echouer : "Form is not signed"
}

void testExecuteGradeTooLow()
{
    std::cout << "\n=== Test 7: Execute - grade insuffisant pour executer ===\n";
    Bureaucrat weakBureaucrat("Weak", 100);
    PresidentialPardonForm ppf("Naib");

    weakBureaucrat.signForm(ppf); // grade 100 <= 25 requis pour signer ? non ! doit throw
}

void testExecuteGradeTooLowRealCase()
{
    std::cout << "\n=== Test 7bis: signe avec grade suffisant, execute avec grade insuffisant ===\n";
    Bureaucrat signer("Signer", 1);
    Bureaucrat weakExecutor("Weak", 50);
    PresidentialPardonForm ppf("Naib"); // sign 25, exec 5

    signer.signForm(ppf);
    weakExecutor.executeForm(ppf); // grade 50 > 5 requis -> doit echouer
}

void testIntern()
{
    std::cout << "\n=== Test 8: Intern::makeForm ===\n";
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    Aform* forms[4];

    forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
    forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
    forms[2] = someRandomIntern.makeForm("presidential pardon", "Naib");
    forms[3] = someRandomIntern.makeForm("unknown form", "Nobody"); // doit afficher une erreur, renvoyer NULL

    for (int i = 0; i < 4; i++)
    {
        if (forms[i])
        {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
        }
        delete forms[i];
    }
}

int main()
{
    srand(time(NULL));

    testBureaucratGrades();
    testBureaucratLimits();
    testFormGrades();
    testSignAndExecute();
    testSignTooLowGrade();
    testExecuteWithoutSigning();
    testExecuteGradeTooLowRealCase();
    testIntern();

    // Ce bloc ne doit PAS compiler si executeAction() est bien protected.
    // Decommente-le pour verifier que ca casse la compilation :
    /*
    ShrubberyCreationForm direct("test");
    direct.executeAction();
    */

    return 0;
}