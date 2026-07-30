#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void    iter(T* array, const int len, void (*f)(T&))
{
    if (!array || !f) return ;
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

template<typename T>
void    iter(const T* array, const int len, void (*f)(const T&))
{
    if (!array || !f) return ;
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}


#endif