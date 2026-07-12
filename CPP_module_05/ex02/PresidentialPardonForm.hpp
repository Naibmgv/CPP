#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Aform;

class PresidentialPardonForm : public Aform
{
    public :

        PresidentialPardonForm(const std::string& target);

    protected :

        void executeAction() const;

    private :

        std::string _target;
};

#endif