#include "Zombie.hpp"

int main (void)
{
    Zombie *z = newZombie("bob");
    delete(z);
    randomChump("patrick");
}
