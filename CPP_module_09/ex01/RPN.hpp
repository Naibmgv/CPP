#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN
{
    private :
        const std::string _input;
        std::stack<int> _s;

    public :
        RPN(const std::string& input);
        RPN(const RPN& other) {
            _s = other._s;
        }
        RPN& operator=(const RPN& other){
            if (this != &other) _s = other._s;
            return *this;
        }
        ~RPN(){}

        bool calculation_and_output();
};

#endif