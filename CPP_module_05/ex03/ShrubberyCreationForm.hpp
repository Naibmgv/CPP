#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class Aform;

class ShrubberyCreationForm : public Aform
{
    public :

        ShrubberyCreationForm(const std::string& target);
    protected :
    
        void executeAction() const;

    private :

        std::string _target;
};

#endif