#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    public :

        Form(const std::string& name, const int signgrade, const int exgrade);
        Form(const Form& form);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        const int&   getsignGrade() const;
        const int&   getexGrade() const;
        const bool&  getsignBool() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

    private : 

        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif