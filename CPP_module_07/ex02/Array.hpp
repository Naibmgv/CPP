#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
    public :
        Array() : _array(NULL), _n(0) {}

        Array(unsigned int n) : _array(NULL), _n(n) 
        {
            if (_n) 
                _array = new T[_n]();
        }

        Array(const Array& other) : _array(NULL), _n(other._n) 
        {
            if (other._n) 
            {
                _array = new T[other._n]();
                for (unsigned int i = 0; i < _n; i++)
                    _array[i] = other._array[i];
            }
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _n = other._n;
                if (_n) 
                {
                    _array = new T[_n]();
                    for (unsigned int i = 0; i < _n; i++)
                        _array[i] = other._array[i];
                }
                else 
                    _array = NULL;
            }
            return *this;
        }

        ~Array()
        {
            delete[] _array;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _n)
                throw std::out_of_range("Index is out of bounds(operator[])");
            return _array[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _n)
                throw std::out_of_range("Index is out of bounds(operator[])");
            return _array[index];
        }

        unsigned int size() const 
        {
            return _n;
        }
    private :

        T* _array;
        unsigned int _n;
};

#endif