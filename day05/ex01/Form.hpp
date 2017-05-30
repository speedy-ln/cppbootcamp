#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(std::string const &name, int signGrade, int executeGrade) throw(GradeTooHighException, GradeTooLowException);
    ~Form();
    Form(Form const &copy);
    Form &operator=(Form const &copy);

    std::string const   &getName() const;
    int                 getSignGrade() const;
    int                 getExecuteGrade() const;
    bool                isSigned() const;
    void                beSigned(Bureaucrat const &bureaucrat) throw(GradeTooLowException);

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException();
        ~GradeTooHighException() throw();
        GradeTooHighException(GradeTooHighException const &copy);
        GradeTooHighException &operator=(GradeTooHighException const &copy);
        char const   *what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException();
        ~GradeTooLowException() throw();
        GradeTooLowException(GradeTooHighException const &copy);
        GradeTooLowException &operator=(GradeTooLowException const &copy);
        char const   *what(void) const throw();
    };

private:
    std::string _name;
    bool        _signed;
    int         _signGrade;
    int         _executeGrade;
};

std::ostream    &operator<<(std::ostream &os, Form const &copy);

#endif