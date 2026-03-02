#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), type("WrongCat")
{
    std::cout << "WrongCat default construcor called"<< std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy construcor called"<< std::endl;
    type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignement called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called"<< std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "** Wrong Miaou ! **" << std::endl;
}