#include "AForm.hpp"
#include "Bureaucrat.hpp"

Aform::Aform(const std::string& name, const int gradeToSign,
            const int gradeToExec) : _name(name), _signed(false),
            _gradeToSign(gradeToSign),
            _gradeToExec(gradeToExec)
{
    if (_gradeToExec < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
}

Aform::Aform(const Aform& Aform) : _name(Aform._name), _signed(Aform._signed),
                                 _gradeToSign(Aform._gradeToSign), _gradeToExec(Aform._gradeToExec)
{
    
}

Aform& Aform::operator=(const Aform& other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

const std::string& Aform::getName() const
{
    return _name;
}

const bool& Aform::getsignBool() const
{
    return _signed;
}

const int& Aform::getexGrade()const
{
    return (_gradeToExec);
}

const int& Aform::getsignGrade() const
{
    return _gradeToSign;
}

const char* Aform::GradeTooLowException::what() const throw()
{
    return ("grade is too low");
}

const char* Aform::GradeTooHighException::what() const throw()
{
    return ("grade is too high");
}

const char* Aform::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

void Aform::beSigned(const Bureaucrat& bureaucrat)
{
    int grade = bureaucrat.getGrade();
    if (grade <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

void Aform::execute(Bureaucrat const & bureaucrat) const
{
    if (!_signed) throw FormNotSignedException();
    if (_gradeToExec < bureaucrat.getGrade()) throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& out, const Aform& Aform)
{
    std::string signedd;

    if (Aform.getsignBool() == true)
        signedd = " is signed";
    else
        signedd = " is not signed";
    out << Aform.getName() << signedd << ", grade to execute : " << Aform.getexGrade() << ", grade to sign : " << Aform.getsignGrade() << std::endl;
    return (out);
}

Aform::~Aform()
{

}