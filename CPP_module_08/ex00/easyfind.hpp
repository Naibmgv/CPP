#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException : public std::exception 
{
    public:
        virtual const char* what() const throw()
        {
            return "Element not found in container";
        }
};

template <typename T>
typename T::iterator easyfind( T& container, const int& toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif