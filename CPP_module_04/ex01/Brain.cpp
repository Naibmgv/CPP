#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignement called" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void    Brain::setIdeas(int index, const std::string& new_val)
{
    if (index < 0 || index >= 100)
        return;
    ideas[index] = new_val;
}

std::string Brain::getIdeas(int index)
{
    if (index < 0 || index >= 100)
        return "";
    return ideas[index];
}
