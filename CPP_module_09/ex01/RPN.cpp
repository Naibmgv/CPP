#include "RPN.hpp"

RPN::RPN(const std::string& input) : _input(input)
{

}

bool RPN::calculation_and_output()
{
    int i = 0;
    
    while (_input[i])
    {
        if (isdigit(_input[i])) 
            _s.push(_input[i] - '0');
        else if (_input[i] == '+')
        {
            if (_s.size() < 2) return false;
            int b = _s.top();
            _s.pop();
            int a = _s.top();
            _s.pop();
            int res = a + b;
            _s.push(res);
        }
        else if (_input[i] == '-')
        {
            if (_s.size() < 2) return false;
            int b = _s.top();
            _s.pop();
            int a = _s.top();
            _s.pop();
            int res = a - b;
            _s.push(res);
        }
        else if (_input[i] == '*')
        {
            if (_s.size() < 2) return false;
            int b = _s.top();
            _s.pop();
            int a = _s.top();
            _s.pop();
            int res = a * b;
            _s.push(res);
        }
        else if (_input[i] == '/')
        {
            if (_s.size() < 2) return false;
            int b = _s.top();
            _s.pop();
            int a = _s.top();
            _s.pop();
            int res = a / b;
            _s.push(res);
        }
        i++;
    }
    if (_s.size() == 1) std::cout << _s.top() << std::endl;
    else return false;
    return true;
}
