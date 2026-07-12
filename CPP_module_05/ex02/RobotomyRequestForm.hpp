#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib> 
#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Aform;


class RobotomyRequestForm : public Aform
{
    public :

        RobotomyRequestForm(const std::string& target);

    protected :
        void executeAction() const;
    private :

        std::string _target;
};

#endif