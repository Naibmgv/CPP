#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _Hit_points(10), _Energy_points(10), _Attack_damage(0)
{
    std::cout << "ClapTrap " << _name << " has been created !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : 
    _name(other._name), _Hit_points(other._Hit_points), _Energy_points(other._Energy_points),
    _Attack_damage(other._Attack_damage)
{
    std::cout << "ClapTrap " << _name << " has been created(copy constructor) !" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _Hit_points = other._Hit_points;
        _Energy_points = other._Energy_points;
        _Attack_damage = other._Attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed !" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_Hit_points <= 0 || _Energy_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is unable to attack" << std::endl;
        return ;
    }
    _Energy_points--;
    std::cout << "ClapTrap " << _name << " lost 1 Energy Point" << std::endl;
    std::cout << "ClapTrap " << _name << " attacks " << target 
        << ", causing " << _Attack_damage << " points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_Hit_points <= 0 || _Energy_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is unable to repair himself" << std::endl;
        return ;
    }
    _Energy_points--;
    std::cout << "ClapTrap " << _name << " used 1 energy point !" << std::endl;
    _Hit_points += static_cast<int>(amount);
    std::cout << "ClapTrap " << _name << " regained " << amount << " Hit Points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_Hit_points <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
        return;
    }
    _Hit_points -= amount;
    std::cout << "ClapTrap " << _name << " lost " << amount << " Hit Points" << std::endl;
}