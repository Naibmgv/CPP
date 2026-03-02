#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(3);

    b.beRepaired(5);

    // vider l'énergie de A
    for (int i = 0; i < 11; i++)
        a.attack("someone");

    // tuer B
    b.takeDamage(50);
    b.attack("A");
    b.beRepaired(10);

    // test copie
    ClapTrap c = a;
    ClapTrap d;
    d = b;

    return 0;
}