#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Create ClapTrap ===\n";
    ClapTrap a("A");
    a.attack("target");

    std::cout << "\n=== Create ScavTrap ===\n";
    ScavTrap s("Serena");
    s.attack("intruder");
    s.guardGate();

    std::cout << "\n=== End of scope (destruction order) ===\n";
    return 0;
}