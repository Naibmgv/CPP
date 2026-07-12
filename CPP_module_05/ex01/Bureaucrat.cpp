#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Bureaucrat::incrementgrade()
{
    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementgrade()
{
    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat(){

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return (out);
}