#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Aform
{
    public :

        Aform(const std::string& name, const int signgrade, const int exgrade);
        Aform(const Aform& Aform);
        Aform& operator=(const Aform& other);
        virtual ~Aform();

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        
        const std::string& getName() const;
        const int&   getsignGrade() const;
        const int&   getexGrade() const;
        const bool&  getsignBool() const;
        
        
        class GradeTooHighException : public std::exception 
        {
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            public:
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception 
        {
            public:
            const char* what() const throw();
        };

    protected :

            virtual void executeAction() const = 0;
        
    private : 
        
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
};

std::ostream& operator<<(std::ostream& os, const Aform& Aform);

#endif