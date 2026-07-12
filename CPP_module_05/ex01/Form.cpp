#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int gradeToSign,
            const int gradeToExec) : _name(name), _signed(false),
            _gradeToSign(gradeToSign),
            _gradeToExec(gradeToExec)
{
    if (_gradeToExec < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& form) : _name(form._name), _signed(form._signed),
                                 _gradeToSign(form._gradeToSign), _gradeToExec(form._gradeToExec)
{
    
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

const std::string& Form::getName() const
{
    return _name;
}

const bool& Form::getsignBool() const
{
    return _signed;
}

const int& Form::getexGrade()const
{
    return (_gradeToExec);
}

const int& Form::getsignGrade() const
{
    return _gradeToSign;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("grade is too low");
}

const char* Form::GradeTooHighException::what()const throw()
{
    return ("grade is too high");
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    int grade = bureaucrat.getGrade();
    if (grade <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    std::string signedd;

    if (form.getsignBool() == true)
        signedd = " is signed";
    else
        signedd = " is not signed";
    out << form.getName() << signedd << ", grade to execute : " << form.getexGrade() << ", grade to sign : " << form.getsignGrade() << std::endl;
    return (out);
}

Form::~Form()
{

}
