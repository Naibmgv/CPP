#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdio.h>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
    private :
        ScalarConverter() {}
        ScalarConverter(const ScalarConverter& other) {(void)other;}
        ScalarConverter& operator=(const ScalarConverter& other) 
        {
            (void)other; 
            return(*this);
        }
        ~ScalarConverter() {}

    public :
        static void convert(const std::string& literal);
};

#endif