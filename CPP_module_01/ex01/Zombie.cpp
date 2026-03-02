#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie()
{
    std::cout << _name << " Died." << std::endl;
}

void Zombie::setname(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}