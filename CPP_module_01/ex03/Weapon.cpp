#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{

}

const std::string& Weapon::getType(void) const
{
    const std::string& ref = _type;
    return ref;
}

void Weapon::setType(std::string new_type)
{
    _type = new_type;
}
