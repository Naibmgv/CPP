#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    public :
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void incrementgrade();
        void decrementgrade();

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
        int     _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif