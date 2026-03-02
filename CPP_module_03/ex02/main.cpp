#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "==== Test 1: FragTrap Construction/Destruction ====\n";
    {
        FragTrap f("Frag1");
        f.highFivesGuys();
    }  
    
    std::cout << "\n==== Test 2: Actions ====\n";
    FragTrap f2("Frag2");
    f2.attack("enemy");
    f2.takeDamage(20);
    f2.beRepaired(10);
    
    std::cout << "\n==== Test 3: Comparison with other types ====\n";
    ClapTrap c("Clap");
    ScavTrap s("Scav");
    
    std::cout << "\n==== End (all destructors) ====\n";
    return 0;
}