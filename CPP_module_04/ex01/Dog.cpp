#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog default construcor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy construcor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignement called" << std::endl;
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

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::setIdeas(int index, const std::string& idea)
{
    brain->setIdeas(index, idea);
}

std::string Dog::getIdeas(int index)
{
    return (brain->getIdeas(index));
}

void Dog::makeSound() const
{
    std::cout << "** Woof ! **" << std::endl;
}