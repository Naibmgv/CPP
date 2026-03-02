#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat default construcor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy construcor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignement called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (!brain)
            brain = new Brain();
        if (other.brain)
            *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::setIdeas(int index, const std::string& idea)
{
    brain->setIdeas(index, idea);
}

std::string Cat::getIdeas(int index)
{
    return (brain->getIdeas(index));
}

void Cat::makeSound() const
{
    std::cout << "** Miaou ! **" << std::endl;
}